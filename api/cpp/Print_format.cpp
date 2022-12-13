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
 * Format Printable
 */

static int printf_putchar (char _c, FILE *_fp) {
  return ((class Print *)(fdev_get_udata(_fp)))->write((uint8_t) _c);
}

Print& Print::printf (const char *_format, ...) {
  FILE _fp;
  va_list _ap;
  fdev_setup_stream(&_fp, printf_putchar, NULL, _FDEV_SETUP_WRITE);
  fdev_set_udata(&_fp, this);
  va_start(_ap, _format);
  vfprintf(&_fp, _format, _ap);
  return *this;
}

Print& Print::printf (const PGM_t *_format, ...) {
  FILE _fp;
  va_list _ap;
  fdev_setup_stream(&_fp, printf_putchar, NULL, _FDEV_SETUP_WRITE);
  fdev_set_udata(&_fp, this);
  va_start(_ap, _format);
  vfprintf_P(&_fp, (const char *) _format, _ap);
  return *this;
}

// end of code
