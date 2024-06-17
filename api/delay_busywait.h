/**
 * @file delay_busywait.h
 * @author askn (K.Sato) multix.jp
 * @brief delay busywait
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <inttypes.h>

#define ENABLE_DELAY_BUSYWAIT 1

#ifndef __OPTIMIZE__
  #warning "Compiler optimizations disabled; functions from <api/delay_busywait.h> won't work as designed"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Wait in absolute time according to F_CPU */
/* argument must be a static integer */
static __inline__ __attribute__((__always_inline__)) void delay_micros (uint32_t _us);
static __inline__ __attribute__((__always_inline__)) void delay_millis (uint32_t _ms);

void delay_micros (uint32_t _us) {
  if (F_CPU >= 1000000L) {
    __builtin_avr_delay_cycles((F_CPU / 1000000L) * _us);
  }
  else {
    __builtin_avr_delay_cycles((F_CPU * _us) / 1000000L);
  }
}

void delay_millis (uint32_t _ms) {
  if (F_CPU >= 1000000L) {
    __builtin_avr_delay_cycles((F_CPU / 1000L) * _ms);
  }
  else {
    __builtin_avr_delay_cycles((F_CPU * _ms) / 1000L);
  }
}

extern void _busy_loop_3_8 (uint8_t _count);
extern void _busy_loop_4_8 (uint8_t _count);
extern void _busy_loop_4_16 (uint16_t _count);
extern void _busy_loop_5_16 (uint16_t _count);

#ifdef __cplusplus
}
#endif

// end of code
