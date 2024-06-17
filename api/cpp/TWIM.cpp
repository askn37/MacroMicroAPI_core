/**
 * @file TWIM.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Two-Wire-Interface for Master Easy Class
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#if !defined(__AVR_TINY__)

#include "../TWIM.h"
#include <avr/pgmspace.h>
#include <api/delay_busywait.h>

TWIM_Class& TWIM_Class::initiate (const uint8_t _baudrate, bool _pullup) {
  uint8_t _portp = PORT_ISC_INTDISABLE_gc;
  if (_pullup) _portp = PORT_PULLUPEN_bm | PORT_ISC_INTDISABLE_gc;
  register8_t *_portmux = (register8_t*)pgm_read_ptr(&portmux->portmux_reg);
  if (_portmux) {
    *_portmux = (*_portmux & pgm_read_byte(&portmux->portmux_mask))
                           | pgm_read_byte(&portmux->portmux_set);
  }
  (*(register8_t*)pgm_read_ptr(&portmux->sda_pin_ctrl)) = _portp;
  (*(register8_t*)pgm_read_ptr(&portmux->scl_pin_ctrl)) = _portp;
  PORT_t* _portx = (PORT_t*)pgm_read_ptr(&portmux->port_reg);
  uint8_t _scl_bm = pgm_read_byte(&portmux->scl_pin);
  uint8_t _sda_bm = pgm_read_byte(&portmux->sda_pin);
  _portx->DIRCLR = _scl_bm | _sda_bm;
  _portx->OUTCLR = _scl_bm | _sda_bm;
  for (uint8_t i = 0; i < 20; i++) {
    delay_micros(5);
    _portx->DIRTGL = _scl_bm;
    delay_micros(5);
    _portx->DIRTGL = _sda_bm;
  }
  /* ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { */
  TWIR->MBAUD = _baudrate;
  TWIR->MCTRLB = TWI_ACKACT_ACK_gc;
  TWIR->MCTRLA = TWI_ENABLE_bm | TWI_SMEN_bm;
  TWIR->MSTATUS = TWI_BUSSTATE_IDLE_gc;
  /* } */
  // scan(~0);
  // loop_until_is_idle();
  return *this;
}

void TWIM_Class::end (void) {
  TWIR->MCTRLB = TWI_MCMD_STOP_gc;
  TWIR->MSTATUS = TWI_BUSSTATE_IDLE_gc;
  TWIR->MCTRLA = 0;
  (*(register8_t*)pgm_read_ptr(&portmux->sda_pin_ctrl)) = PORT_ISC_INPUT_DISABLE_gc;
  (*(register8_t*)pgm_read_ptr(&portmux->scl_pin_ctrl)) = PORT_ISC_INPUT_DISABLE_gc;
}

bool TWIM_Class::scan (const uint8_t _addr) {
  return (start(_addr).stop() & (TWI_BUSERR_bm | TWI_ARBLOST_bm | TWI_RXACK_bm)) == 0;
}

TWIM_Class& TWIM_Class::start (const uint8_t _addr, size_t _count) {
  if (TWIR->MSTATUS & TWI_BUSSTATE_1_bm) TWIR->MCTRLB = TWI_MCMD_STOP_gc;
  _read_count = 0;
  _write_size = 0;
  _write_count = _count;
  TWIR->MCTRLB = TWI_ACKACT_ACK_gc;
  TWIR->MSTATUS = TWI_RIF_bm | TWI_BUSERR_bm;
  TWIR->MADDR = (_addr << 1);
  loop_until_is_write();
  return *this;
}

TWIM_Class& TWIM_Class::request (const uint8_t _addr, size_t _count) {
  _write_count = 0;
  _read_size = 0;
  _read_count = _count;
  TWIR->MCTRLB = TWI_ACKACT_ACK_gc;
  TWIR->MSTATUS = TWI_RIF_bm | TWI_BUSERR_bm;
  TWIR->MADDR = (_addr << 1) + 1;
  return *this;
}

uint8_t TWIM_Class::stop (void) {
  uint8_t _stat = TWIR->MSTATUS;
  if (_stat & TWI_BUSSTATE_1_bm) TWIR->MCTRLB = TWI_MCMD_STOP_gc;
  return _stat;
}

size_t TWIM_Class::write_byte (const uint8_t _c) {
  if ((_write_count == 0) || is_fail()) return 0;
  loop_until_is_write();
  TWIR->MDATA = _c;
  if (--_write_count == 0) {
    loop_until_is_write();
    TWIR->MCTRLB = TWI_MCMD_STOP_gc;
  }
  return 1;
}

int TWIM_Class::read_byte (void) {
  if ((_read_count == 0) || is_fail()) return ~0;
  loop_until_is_read();
  if (--_read_count == 0) TWIR->MCTRLB = TWI_MCMD_STOP_gc | TWI_ACKACT_NACK_gc;
  return _last_rx = TWIR->MDATA;
}

size_t TWIM_Class::read_bytes (void* _buff, size_t _length) {
  size_t _count = 0;
  uint8_t* _ptr = (uint8_t*)_buff;
  int _c;
  while (_length--) {
    if ((_c = read_byte()) < 0) break;
    *(_ptr++) = (uint8_t) _c;
    _count++;
  }
  return _count;
}

size_t TWIM_Class::reverse_read (void* _buff, size_t _length) {
  size_t _count = 0;
  uint8_t* _ptr = (uint8_t*)_buff;
  int _c;
  while (_length) {
    if ((_c = read_byte()) < 0) break;
    _ptr[--_length] = (uint8_t) _c;
    _count++;
  };
  return _count;
}

TWIM_Class& TWIM_Class::loop_until_is_write (void) {
  loop_until_bit_is_set(TWIR->MSTATUS, TWI_WIF_bp);
  return *this;
}

TWIM_Class& TWIM_Class::loop_until_is_read (void) {
  loop_until_bit_is_set(TWIR->MSTATUS, TWI_RIF_bp);
  return *this;
}

TWIM_Class& TWIM_Class::loop_until_busy_idle (void) {
  while ((TWIR->MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_IDLE_gc);
  return *this;
}

TWIM_Class& TWIM_Class::loop_until_is_idle (void) {
  while ((TWIR->MSTATUS & TWI_BUSSTATE_gm) != TWI_BUSSTATE_IDLE_gc);
  return *this;
}

TWIM_Class& TWIM_Class::loop_until_is_owner (void) {
  while ((TWIR->MSTATUS & TWI_BUSSTATE_gm) != TWI_BUSSTATE_OWNER_gc);
  return *this;
}

#endif

// end of code
