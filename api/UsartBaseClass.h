/**
 * @file UsartBaseClass.h
 * @author askn (K.Sato) multix.jp
 * @brief Half Duplex Universal Asynchronous/Synchronous Receiver/Transmitter Base Class
 * @version 0.2
 * @date 2022-12-20
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <avr/io.h>
#if defined(__cplusplus) && !defined(__AVR_TINY__)

#include "Print.h"

class UsartBaseClass : public Print {
public:
  USART_t* usart;
  uint8_t rxdh;

  inline UsartBaseClass (USART_t* _usart) : usart(_usart) {}

  size_t write (const uint8_t _c);
  using Print::write; // pull in write(str) and write(buf, size) from Print

  int read (void);

  void flush (void) {
    loop_until_bit_is_set(usart->STATUS, USART_TXCIF_bp);
  }

  size_t available (void) {
    return bit_is_set(usart->STATUS, USART_RXCIF_bp) ? 1 : 0;
  }

  size_t availableForWrite (void) {
    return bit_is_set(usart->STATUS, USART_DREIF_bp) ? 1 : 0;
  }

  /* unsupported int peek() */
  inline int peek (void) { return ~0; }

  inline uint16_t is_baud (void) { return usart->BAUD; }
  inline uint8_t status (void) { return rxdh; }

  size_t readBytes (void* _buffer, size_t _limit, char _terminate = 0, uint8_t _swevent = 0);
};

#endif

// end of code
