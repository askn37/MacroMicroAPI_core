/**
 * @file HarfUART_Class .h
 * @author askn (K.Sato) multix.jp
 * @brief Half Duplex Universal Asynchronous Receiver/Transmitter Easy Class
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/io.h>
#if defined(__cplusplus) && !defined(__AVR_TINY__)

#include "Portmux.h"
#include "UsartBaseClass.h"

#define ENABLE_CLASS_HARFUART 1

class HarfUART_Class : public UsartBaseClass {
private:
  const UART_portmux_t* portmux;

public:
  inline HarfUART_Class (USART_t* _usart, const UART_portmux_t* _portmux) :
    UsartBaseClass(_usart), portmux(_portmux) {}

  inline HarfUART_Class& begin (const uint32_t _baudrate) {
    return initiate((uint16_t)(((F_CPU / (_baudrate >> 3)) + 1) / 2));
  }

  HarfUART_Class & initiate (const uint16_t _baudrate);
  void end (void);

  explicit operator bool (void) { return true; }
};

#include <peripheral.h>

#endif

// end of code
