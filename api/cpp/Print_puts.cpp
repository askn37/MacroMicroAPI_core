/**
 * @file Print_format.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Print subclass (format)
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../Print.h"

/*
 * Standard write strings
 */

size_t Print::write (const void* _buffer, size_t _length) {
  size_t _n = 0;
  uint8_t *_p = (uint8_t*)_buffer;
  while (_length--) {
    if ( write(*(_p++)) ) _n++;
    else break;
  }
  return _n;
}

size_t Print::puts (const char _str[]) {
  char _c;
  size_t _n = 0;
  char* _p = (char *) _str;
  while ((_c = *_p++)) {
    if (write(_c)) _n++;
    else break;
  }
  return _n;
}

size_t Print::write (const PGM_t* _buffer, size_t _length) {
  size_t _n = 0;
  PGM_P _p = reinterpret_cast<PGM_P>(_buffer);
  while (_length--) {
    if (write(pgm_read_byte(_p++))) _n++;
    else break;
  }
  return _n;
}

size_t Print::puts (const PGM_t _str[]) {
  char _c;
  size_t _n = 0;
  PGM_P _p = reinterpret_cast<PGM_P>(_str);
  while ((_c = pgm_read_byte(_p++))) {
    if (write(_c)) _n++;
    else break;
  }
  return _n;
}

/*
 * Hex Dump
 */

uint8_t _read (uint32_t _addr, bool _prog) {
    return _prog ? pgm_read_byte(_addr) : *((uint8_t*)_addr);
}

Print& Print::_print_hex (Print_OPT_HEX_t p) {
    size_t _count = 0;
  while (p.length--) {
    uint8_t _c = _read(p.addr++, p.prog);
    write(btoh(__builtin_avr_swap(_c)));
    write(btoh(_c));
        if (p.length) {
          if (++_count == p.wrap) { puts(p.split); _count -= p.wrap; }
      else if (p.sep) write(p.sep);
        }
  }
  return *this;
}

Print& Print::printHex (const void* _source, size_t _length, char _separator, size_t _wrap, const char* _split) {
    Print_OPT_HEX_t p = {
        (uint32_t)_source
    , _split
    , _length
    , _wrap
    , _separator
    , false
    };
    return _print_hex(p);
}

Print& Print::printHex (const PGM_t* _source, size_t _length, char _separator, size_t _wrap, const char* _split) {
    Print_OPT_HEX_t p = {
        (uint32_t)_source
    , _split
    , _length
    , _wrap
    , _separator
    , true
    };
    return _print_hex(p);
}

/* Binary Dump */

Print& Print::_print_dump (Print_OPT_HEX_t p, bool _utf) {
  while (p.length > 0) {
    print(p.addr, ZFILL|HEX, 5);
        print(F(": "));
        Print_OPT_HEX_t r = {
            p.addr
        , "  "
        , (p.length > 16 ? 16 : p.length)
        , 8
        , ' '
        , p.prog
        };
        _print_hex(r);
        if (p.length < 16) {
      if (p.length < 8) write(' ');
      for (int j = p.length; j < 16; j++) print(F("   "));
        }
    print(F("  "));
    uint32_t q = p.addr;
        int s = p.length < 16 ? p.length : 16;
    for (int j = 0; j < s; j++) {
      uint8_t c = _read(q++, p.prog);

      /* UTF8 Encoding (3bytes) */
      if (_utf && 0xe0 <= c && c < 0xf0) {
        uint8_t d = _read(q++, p.prog);
        uint8_t e = _read(q++, p.prog);
        if ((d ^ 0x80) < 0x40 && (e ^ 0x80) < 0x40) write('\\');
        else c = d = e = '.';
        write(c);
        write(d);
        write(e);
        j += 2;
      }

      /* UTF8 Encoding (2bytes) */
      else if (_utf && 0xd0 <= c && c < 0xe0) {
        uint8_t d = _read(q++, p.prog);
        if ((d ^ 0x80) < 0x40) write('\\');
        else c = d = '.';
        write(c);
        write(d);
        j++;
      }

      /* ASCII */
      else if (c > 0x20 && c < 0x7F) write(c);

      /* Other */
      else write('.');
    }
        if (p.length < 16) {
            ln();
            break;
        }
    p.length -= 16;
    p.addr += 16;
    ln();
    }
    return *this;
}

Print& Print::printDump (const void* _source, size_t _length, bool _utf) {
    Print_OPT_HEX_t p = {
        (uint32_t)_source
    , 0
    , _length
    , 0
    , 0
    , false
    };
    return _print_dump(p, _utf);
}

Print& Print::printDump (const PGM_t* _source, size_t _length, bool _utf) {
    Print_OPT_HEX_t p = {
        (uint32_t)_source
    , 0
    , _length
    , 0
    , 0
    , true
    };
    return _print_dump(p, _utf);
}

// end of code
