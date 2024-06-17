/**
 * @file TWIM.h
 * @author askn (K.Sato) multix.jp
 * @brief Two-Wire-Interface for Master Easy Class
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <avr/io.h>
#if defined(__cplusplus) && !defined(__AVR_TINY__)

#include <avr/pgmspace.h>
#include <util/atomic.h>
#include "Portmux.h"
#include "Print.h"

#define ENABLE_CLASS_TWI 1

class TWIM_Class : public Print {
private:
  TWI_t* TWIR;
  const TWI_portmux_t* portmux;
  size_t _read_count, _read_size, _write_count, _write_size;
  uint8_t _last_rx;

public:
  inline TWIM_Class (TWI_t* _twi, const TWI_portmux_t* _portmux) : TWIR(_twi), portmux(_portmux) {}

  inline TWIM_Class& begin (const uint32_t _baudrate = 100000L, bool _pullup = true) {
    return initiate((F_CPU / (2.25 * _baudrate)), _pullup);
  }

  TWIM_Class& initiate (const uint8_t _baudrate, bool _pullup = true);
  void end (void);

  bool scan (const uint8_t _addr);
  TWIM_Class& start (const uint8_t _addr, size_t _count = ~0);
  TWIM_Class& request (const uint8_t _addr, size_t _count);
  uint8_t stop (void);

  size_t write_byte (const uint8_t _c);

  size_t write (const uint8_t _c) { return write_byte(_c); }
  using Print::write; // pull in write(str) and write(buf, size) from Print

  inline TWIM_Class& send (const char _c) { _write_size += write_byte((uint8_t)_c); return *this; }
  inline TWIM_Class& send (const int _c) { _write_size += write_byte((uint8_t)_c); return *this; }
  inline TWIM_Class& send (const long _c) { _write_size += write_byte((uint8_t)_c); return *this; }
  inline TWIM_Class& send (const uint8_t* _buffer, size_t _length) {
    _write_size += write(_buffer, _length);
    return *this;
  }
  inline TWIM_Class& send (const PGM_t* _buffer, size_t _length) {
    _write_size += write(_buffer, _length);
    return *this;
  }

  int read_byte (void);
  size_t read_bytes (void* _buff, size_t _length);

  int read (void) { return read_byte(); }
  inline void flush (void) {}

  inline uint8_t last_read (void) { return _last_rx; }

  inline size_t available (void) {
    return ((_read_count != 0) && !is_fail()) ? 1 : 0;
  }

  inline size_t availableForWrite (void) {
    return ((_read_count == SIZE_MAX) && is_ack()) ? 1 : 0;
  }

  /* replace gets(char*) */
  size_t read (void* _buff, size_t _length);
  inline TWIM_Class& recv (void* _buff, size_t _length) {
    _read_size += read_bytes(_buff, _length);
    return *this;
  }
  size_t reverse_read (void* _buff, size_t _length);
  inline TWIM_Class& reverse_recv (void* _buff, size_t _length) {
    _read_size += reverse_read(_buff, _length);
    return *this;
  }

  inline size_t write_size (void) { return _write_size; }
  inline size_t read_size (void) { return _read_size; }

  /* unsupported int peek() */
  inline int peek (void) { return ~0; }

  inline uint8_t is_status (void) { return TWIR->MSTATUS; }
  inline bool is_ack (void) {
    return (TWIR->MSTATUS & (TWI_BUSERR_bm | TWI_ARBLOST_bm | TWI_RXACK_bm)) == 0;
  }
  inline bool is_fail (void) {
    return (TWIR->MSTATUS & (TWI_BUSERR_bm | TWI_ARBLOST_bm | TWI_RXACK_bm));
  }
  inline bool is_idle (void) { return (TWIR->MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_IDLE_gc; }
  inline bool is_owner (void) { return (TWIR->MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_OWNER_gc; }
  inline bool is_busy (void) { return (TWIR->MSTATUS & TWI_BUSSTATE_gm) == TWI_BUSSTATE_BUSY_gc; }
  inline uint8_t is_baud (void) { return TWIR->MBAUD; }
  inline uint8_t is_count (void) { return _read_count; }

  TWIM_Class& loop_until_is_write (void);
  TWIM_Class& loop_until_is_read (void);
  TWIM_Class& loop_until_busy_idle (void);
  TWIM_Class& loop_until_is_idle (void);
  TWIM_Class& loop_until_is_owner (void);

  /* Wire class compatible methods */
  inline void setClock (uint32_t /*frequency*/ ) {}
  inline void beginTransmission (uint8_t address) { start((const uint8_t)address); }
  inline uint8_t endTransmission (bool sendStop = true) { if (sendStop) stop(); return 0; }
  inline uint8_t requestFrom (uint8_t address, size_t quantity, bool /* sendStop */ = true) {
    request(address, quantity);
    return quantity;
  }

  explicit operator bool (void) { return true; }
};

#include <peripheral.h>

#endif

// end of code

