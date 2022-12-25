/**
 * @file UsartBaseClass.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Half Duplex Universal Asynchronous/Synchronous Receiver/Transmitter Base Class (I/O)
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#if !defined(__AVR_TINY__)

#include "../UsartBaseClass.h"

size_t UsartBaseClass::write (const uint8_t _c) {
  loop_until_bit_is_set(usart->STATUS, USART_DREIF_bp);
  usart->STATUS = USART_TXCIF_bm;
  usart->TXDATAL = _c;
  return 1;
}

int UsartBaseClass::read (void) {
  int _rxd = ~0;
  if (bit_is_set(usart->STATUS, USART_RXCIF_bp)) {
    rxdh = usart->RXDATAH;
    uint8_t rxdl = usart->RXDATAL;
    if (!(rxdh & (USART_FERR_bp | USART_BUFOVF_bm | USART_PERR_bm ))) _rxd = rxdl;
  }
  return _rxd;
}

size_t UsartBaseClass::readBytes (void* _buffer, size_t _limit, char _terminate, uint8_t _swevent) {
  size_t _length = 0;
  do {
    uint16_t _busy = usart->BAUD;
    while (bit_is_clear(usart->STATUS, USART_RXCIF_bp)) {
      if (--_busy == 0) return _length;
    }
  #if defined(EVSYS_SWEVENTA)
    EVSYS_SWEVENTA = _swevent;
  #elif defined(EVSYS_STROBE)
    EVSYS_STROBE = _swevent;
  #elif defined(EVSYS_ASYNCSTROBE)
    EVSYS_ASYNCSTROBE = _swevent;
  #endif
    _swevent = 0;
    int _c = read();
    if (_c >= 0) {
      ((uint8_t*)_buffer)[_length++] = (uint8_t)_c;
      if (_terminate == (uint8_t)_c) break;
    }
    else break;
  } while (_length < _limit);
  return _length;
}

#endif

// end of code
