/**
 * @file Print.h
 * @author askn (K.Sato) multix.jp
 * @brief Print subclass
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <api/btools.h>

#ifdef __cplusplus
#include "String.h"

typedef enum Print_OPT_enum {
  SPACE = 0,
  SIGN  = 1,
  BIN   = 2,
  OCT   = 8,
  DEC   = 10,
  HEX   = 16,
  _INT_ = 64,
  ZFILL = 128,
  ZBIN  = 194,
  ZOCT  = 200,
  ZDEC  = 202,
  ZHEX  = 208
} Print_OPT_t;

struct Print_OPT_HEX_t {
  uint32_t addr;
  const char* split;
  size_t length;
  size_t wrap;
  char sep;
  bool prog;
};

class Print {
private:
  Print& _print_integer (uint32_t _number, uint8_t _base, int8_t _direction, int8_t _offset);
  Print& _print_hex (Print_OPT_HEX_t p);
  Print& _print_dump (Print_OPT_HEX_t p, bool _utf);

public:

  virtual size_t write (uint8_t) = 0;

  /* Value and Strings */

  inline size_t write (const char _c) { return write((uint8_t) _c); }
  inline size_t write (const int _c) { return write((uint8_t) _c); }
  inline size_t write (const long _c) { return write((uint8_t) _c); }
  inline size_t write (const char* _buffer, size_t _length) {
    return write((const void*) _buffer, _length);
  }

  size_t write (const void* _buffer, size_t _length);
  size_t write (const PGM_t* _buffer, size_t _length);

  size_t puts (const char _str[]);
  size_t puts (const PGM_t _str[]);

  /* Support */

  inline Print& ln (void) { write('\r'); write('\n'); return *this; }

  /* Print */

  inline Print& print (void) { return *this; }
  inline Print& print (const char _c) { write((uint8_t) _c); return *this; }
  inline Print& print (const char _str[]) { puts(_str); return *this; }
  inline Print& print (const PGM_t _str[]) { puts(_str); return *this; }

  inline Print& println (void) { return ln(); }
  inline Print& println (char _c) { write((uint8_t) _c); return ln(); }
  inline Print& println (const char _str[]) { puts(_str); return ln(); }
  inline Print& println (const PGM_t _str[]) { puts(_str); return ln(); }

  /* Format */

  Print& printf (const char *_format, ...) __attribute__ ((format (printf, 2, 3)));
  Print& printf (const PGM_t *_format, ...);

  /* Hex Dump */
  Print& printHex (const void* _source, size_t _length, char _separator = 0, size_t _wrap = 0, const char* _split = "\r\n");
  Print& printHex (const PGM_t* _source, size_t _length, char _separator = 0, size_t _wrap = 0, const char* _split = "\r\n");

    /* Binary Dump */
  Print& printDump (const void* _source, size_t _length, bool _utf = false);
  Print& printDump (const PGM_t* _source, size_t _length, bool _utf = false);

  /* Variable */

  Print& print ( uint8_t _n, uint8_t _base, int8_t _dir = 0);
  Print& print (uint16_t _n, uint8_t _base = DEC, int8_t _dir = 0);
  Print& print (uint32_t _n, uint8_t _base = DEC, int8_t _dir = 0);

  Print& print ( int8_t _n, uint8_t _base = DEC, int8_t _dir = 0);
  Print& print (int16_t _n, uint8_t _base = DEC, int8_t _dir = 0);
  Print& print (int32_t _n, uint8_t _base = DEC, int8_t _dir = 0);

  inline Print& println ( uint8_t _n, uint8_t _base, int8_t _dir = 0) { print((uint8_t) _n, _base, _dir); return ln(); }
  inline Print& println (uint16_t _n, uint8_t _base = DEC, int8_t _dir = 0) { print((uint16_t) _n, _base, _dir); return ln(); }
  inline Print& println (uint32_t _n, uint8_t _base = DEC, int8_t _dir = 0) { print((uint32_t) _n, _base, _dir); return ln(); }

  inline Print& println ( int8_t _n, uint8_t _base, int8_t _dir = 0) { print((int8_t) _n, _base, _dir); return ln(); }
  inline Print& println (int16_t _n, uint8_t _base = DEC, int8_t _dir = 0) { print((int16_t) _n, _base, _dir); return ln(); }
  inline Print& println (int32_t _n, uint8_t _base = DEC, int8_t _dir = 0) { print((int32_t) _n, _base, _dir); return ln(); }

  Print& print (double _n, uint8_t _prec = 2, int8_t _dir = 0);
  inline Print& println (double _n, uint8_t _prec = 2, int8_t _dir = 0) { print(_n, _prec, _dir); return ln(); }
};

#endif

// end of code
