/**
 * @file btools.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Binary tools (functions)
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#include <util/crc16.h>
#include <avr/pgmspace.h>
#include "../btools.h"

//
// Bit convert
//

uint16_t wbits (uint8_t _bits) {
  const static uint8_t PROGMEM _wide_bits[] = {
    0b00000000, 0b00000011, 0b00001100, 0b00001111,
    0b00110000, 0b00110011, 0b00111100, 0b00111111,
    0b11000000, 0b11000011, 0b11001100, 0b11001111,
    0b11110000, 0b11110011, 0b11111100, 0b11111111
  };
  return (pgm_read_byte(&_wide_bits[_bits >> 4]) << 8)
        | pgm_read_byte(&_wide_bits[_bits & 15]);
}

uint8_t bitrev (uint8_t _bits) {
  return __builtin_avr_insert_bits (0x01234567, _bits, 0);
}

uint8_t bswap8 (uint8_t _byte) {
  return __builtin_avr_swap(_byte);
}

//
// Byte convert
//

uint16_t bswap16 (uint16_t _word) {
  return __builtin_bswap16(_word);
}

uint32_t bswap32 (uint32_t _dword) {
  return __builtin_bswap32(_dword);
}

uint64_t bswap64 (uint64_t _qword) {
  return __builtin_bswap64(_qword);
}

void byterev (void* _ptr, size_t _len) {
  uint8_t *_p = (uint8_t*)_ptr;
  uint8_t *_r = _p + _len - 1;
  _len >>= 1;
  while (_len--) {
    *_p = *_p ^ *_r;
    *_r = *_r ^ *_p;
    *_p = *_p ^ *_r;
    _p++; _r--;
  }
}

char btoh (uint8_t _x) {
  _x = (_x & 15) + '0';
  if (_x > '9') _x += 7;
  return _x;
  // static char PROGMEM _hex[] = {
  //   '0','1','2','3','4','5','6','7',
  //   '8','9','A','B','C','D','E','F'
  // };
  // return pgm_read_byte(&_hex[_x & 15]);
}

uint8_t htob (char _x) {
  _x |= ' ';
  _x -= '0';
  if (_x > ('9' - '0')) _x -= 'A' - '9' - 1;
  return _x & 0x0F;
}

uint8_t stob (char _s[]) {
    return (bswap8(htob(_s[0]))) + htob(_s[1]);
}

//
// mapping values
//

short map_short (short x, short in_min, short in_max, short out_min, short out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

long map_long (long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//
// CHKSUM
//

uint8_t csm8 (void* _data, size_t _len) {
  uint8_t _chk = 0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _chk += *_p++;
  return ~_chk;
}

uint8_t bcc8 (void* _data, size_t _len) {
  uint8_t _chk = 0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _chk ^= *_p++;
  return _chk;
}

//
// CRC
//

/* x8 + x2 + x + 1 (0xE0 rev) init 0 */
/* SMBus PEC used */
uint8_t crc8 (void* _data, size_t _len) {
  uint8_t _crc = 0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc8_ccitt_update(_crc, *_p++);
  return _crc;
}

/* x8 + x2 + x + 1 (0xE0 rev) init -1 */
uint8_t crc8_ccitt (void* _data, size_t _len) {
  uint8_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc8_ccitt_update(_crc, *_p++);
  return _crc;
}

/* x8 + x5 + x4 + 1 (0x8C rev) init 0 */
uint8_t crc8_ibutton (void* _data, size_t _len) {
  uint8_t _crc = 0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc_ibutton_update(_crc, *_p++);
  return _crc;
}

/* x8 + x5 + x4 + 1 (0x31) init -1 */
uint8_t crc8_dallas (void* _data, size_t _len) {
  uint8_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc_dallas_update(_crc, *_p++);
  return _crc;
}

uint8_t _crc_dallas_update (uint8_t _crc, uint8_t _data) {
  _crc = _crc ^ _data;
  for (uint8_t i = 0; i < 8; i++) {
    if (_crc & 0x80) _crc = (_crc << 1) ^ 0x31;
    else             _crc <<= 1;
  }
  return _crc;
}

/* x16 + x15 + x2 + 1 (0xA001 rev) init -1 */
uint16_t crc16 (void* _data, size_t _len) {
  uint16_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc16_update(_crc, *_p++);
  return _crc;
}

/* x16 + x12 + x5 + 1 (0x8408 rev) init -1 */
uint16_t crc16_ccitt (void* _data, size_t _len) {
  uint16_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc_ccitt_update(_crc, *_p++);
  return _crc;
}

/* x16 + x12 + x5 + 1 (0x1021) init 0 */
uint16_t crc16_xmodem (void* _data, size_t _len) {
  uint16_t _crc = 0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc_xmodem_update(_crc, *_p++);
  return _crc;
}

/* x16 + x12 + x5 + 1 (0x1021) init -1 */
uint16_t crc16_ccitt_false (void* _data, size_t _len) {
  uint16_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc_xmodem_update(_crc, *_p++);
  return _crc;
}

/* x32 + x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1 */
/* (0xEDB88320 rev) init -1 */
uint32_t _crc32_update (uint32_t _crc, uint8_t _data) {
  _crc ^= _data;
  for (uint8_t j = 0; j < 8; j++) {
    _crc = (_crc >> 1) ^ (0xEDB88320UL & -(_crc & 1));
  }
  return _crc;
}

uint32_t crc32 (void* _data, size_t _len) {
  uint32_t _crc = ~0;
  uint8_t* _p = (uint8_t*)_data;
  while (_len--) _crc = _crc32_update(_crc, *_p++);
  return _crc;
}

// end of code

