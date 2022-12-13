/**
 * @file Print_float.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Print subclass (float)
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <math.h>
#include "../Print.h"

/*
 * Float Variable Printable
 */

Print& Print::print (double _number, uint8_t _prec, int8_t _direction) {
  uint8_t _buff[17];
  uint8_t _size = 16;
  int8_t _offset = 16;
  int8_t _digit = 0;
  _buff[16] = 0;
  bool _sign = false;
  int8_t _len = 0;

  if (isnan(_number)) return print("nan");
  if (isinf(_number)) return print("inf");
  if (_number > 4294967295.0 || _number < -4294967295.0) return print ("ovf");
  if (_number < 0.0) {
    _sign = true;
    _number = - _number;
  }

  double _round = 0.5;
  uint32_t _scale = 1;
  for (; _digit < _prec; _digit++) {
    _round /= 10.0;
    _scale *= 10;
  }
  _number += _round;

  if (_digit > 0) {
    do {
      uint8_t _d = (uint32_t)(_number * _scale) % 10;
      _scale /= 10;
      _buff[--_offset] = btoh(_d);
      if (_offset <= 1) return print ("inf");
      _digit--;
    } while (_digit > 0);
    _buff[--_offset] = '.';
  }

  do {
    uint8_t _d = (uint32_t)(_number) % 10;
    _number = floor(_number / 10);
    _buff[--_offset] = btoh(_d);
    if (_offset <= 1) return print ("inf");
  } while ((uint32_t)_number > 0.0);

  if (_sign) _buff[--_offset] = '-';

  _size -= _offset;
  _len = _size;

  /* before padding */
  for (;_len < _direction; _len++) write(' ');

  _len += write((const char*)&_buff[_offset], _size);

  /* after padding */
  if (_direction < 0) {
    _len = _size;
    _direction = - _direction;
    for (;_len < _direction; _len++) write(' ');
  }

  return *this;
}

// end of code
