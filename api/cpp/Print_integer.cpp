/**
 * @file Print_integer.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Print subclass (inreger)
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#include "../Print.h"

Print& Print::_print_integer (uint32_t _number, uint8_t _base, int8_t _direction, int8_t _offset) {
  uint8_t _buff[(uint8_t)_offset + 1];
  int8_t _size = _offset;
  uint8_t _sign = 0;
  uint8_t _len = 0;

  if (_base & ZFILL) {
    _sign = ZFILL;
    _base &= ~(ZFILL | _INT_);
    if (_direction < 0) _direction = 0;
    _number &= (1L << _offset) - 1;
  }

  if ((_base & ~(ZFILL | _INT_)) <= SIGN) {
    if ((_base & ~(ZFILL | _INT_)) == SIGN) _sign = 2;
    _base = 10 + (_base & _INT_);
  }

  if (_base & _INT_) {
    if (0 > (int32_t) _number) {
      _sign |= 1;
      _number = - _number;
    }
  }
  _base &= ~(ZFILL | _INT_);

  do {
    uint8_t _d = _number % _base;
    _number /= _base;
    _buff[--_offset] = btoh(_d);
  } while (_number);

  /* before sign */
  if (_sign == 2) { _buff[--_offset] = '+'; }
  else if (_sign && !(_sign & ZFILL)) { _buff[--_offset] = '-'; }

  _size -= _offset;
  _len = _size;

  /* before padding */
  for (;_len < _direction; _len++) write(_sign == ZFILL ? '0' : ' ');

  _len += write((const char*)&_buff[_offset], _size);

  /* after padding */
  if (_direction < 0) {
    _len = _size;
    _direction = - _direction;
    for (;_len < _direction; _len++) write(' ');
  }
  return *this;
}

Print& Print::print ( uint8_t _n, uint8_t _base, int8_t _dir) {
  return _print_integer ((uint32_t)_n, _base, _dir, 8);
}
Print& Print::print (uint16_t _n, uint8_t _base, int8_t _dir) {
  return _print_integer ((uint32_t)_n, _base, _dir, 16);
}
Print& Print::print (uint32_t _n, uint8_t _base, int8_t _dir) {
  return _print_integer ((uint32_t)_n, _base, _dir, 32);
}

Print& Print::print ( int8_t _n, uint8_t _base, int8_t _dir) {
  if (_base == DEC) _base = SPACE;
  return _print_integer ((uint32_t)((int32_t)_n), _base | _INT_, _dir, 8);
}
Print& Print::print (int16_t _n, uint8_t _base, int8_t _dir) {
  if (_base == DEC) _base = SPACE;
  return _print_integer ((uint32_t)((int32_t)_n), _base | _INT_, _dir, 16);
}
Print& Print::print (int32_t _n, uint8_t _base, int8_t _dir) {
  if (_base == DEC) _base = SPACE;
  return _print_integer ((uint32_t)_n, _base | _INT_, _dir, 32);
}

// end of code
