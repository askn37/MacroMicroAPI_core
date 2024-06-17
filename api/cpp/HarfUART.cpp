/**
 * @file HarfUART.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Half Duplex Universal Asynchronous Receiver/Transmitter Easy Class (method)
 * @version 0.2
 * @date 2023-12-20
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#if !defined(__AVR_TINY__)

#include "../HarfUART.h"
#include <avr/pgmspace.h>
#include <util/atomic.h>

HarfUART_Class& HarfUART_Class::initiate (const uint16_t _baudrate) {
  uint8_t _usart_ctrl_b = USART_RXEN_bm | USART_TXEN_bm;
  uint8_t _baud2x = 0;
  if (_baudrate <= 63) {
    _baud2x = 1;
    _usart_ctrl_b = USART_RXEN_bm | USART_TXEN_bm | USART_RXMODE_CLK2X_gc;
  }
  const UART_portmux_t* _mux = portmux;
  register8_t *_portmux = (register8_t*)pgm_read_ptr(&_mux->portmux_reg);
  *_portmux = (*_portmux & pgm_read_byte(&_mux->portmux_mask))
                         | pgm_read_byte(&_mux->portmux_set);
  PORT_t *_port = pgm_read_ptr(&_mux->port_reg);
  _port->DIRSET = pgm_read_byte(&_mux->tx_pin);
  _port->DIRCLR = pgm_read_byte(&_mux->rx_pin);
  (*(register8_t*)pgm_read_ptr(&_mux->rx_pin_ctrl)) = PORT_PULLUPEN_bm
                                                    | PORT_ISC_INTDISABLE_gc;
  USART_t* _usart = usart;
  _usart->BAUD = (_baudrate << _baud2x);
  _usart->CTRLA = 0;
  _usart->CTRLC = USART_CHSIZE_8BIT_gc
                | USART_PMODE_DISABLED_gc
                | USART_CMODE_ASYNCHRONOUS_gc
                | USART_SBMODE_1BIT_gc;
  _usart->CTRLB = _usart_ctrl_b;
  return *this;
}

void HarfUART_Class::end (void) {
  flush();
  const UART_portmux_t* _mux = portmux;
  usart->CTRLB = 0;
  (*(PORT_t*)pgm_read_ptr(&_mux->port_reg)).DIRCLR = pgm_read_byte(&_mux->tx_pin);
  (*(register8_t*)pgm_read_ptr(&_mux->rx_pin_ctrl)) = PORT_ISC_INPUT_DISABLE_gc;
}

#endif

// end of code
