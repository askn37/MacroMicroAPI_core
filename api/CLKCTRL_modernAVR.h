/**
 * @file CLKCTRL_modernAVR.h
 * @author askn (K.Sato) multix.jp
 * @brief CLKCTRL for modernAVR
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/io.h>

#if defined(CLKCTRL_AUTOTUNE_bm)
/*******************************************************
 *
 * AVR Dx Production Internal Clock Speed Setup
 *
 *   modernAVR architecture 2nd generations
 *
 * CLK_MAIN :
 *
 *   CLKCTRL_CLKSEL_OSCHF_gc
 *     CLKCTRL_FREQSEL_*M_gc    1,2,3,4,8,12,
 *                              16,20,24 (,28,32) MHz
 *
 *   CLKCTRL_CLKSEL_OSC32K_gc   32.768 kHz
 *
 * Prescaler Division :
 *
 *   CLKCTRL_PDIV_*X_gc         2,4,8,16,32,64,
 *                              6,12,24,48, 10
 */

#undef CLKCTRL_USED_OSC32K
#undef _CLKCTRL_FREQSEL_
#undef _CLKCTRL_PDIV_

#if !defined(F_CPU)
  #define F_CPU 4000000L
  #warning F_CPU is undefined so assume 4000000L
#endif

extern inline void _CLKCTRL_SETUP (void) {

/* experimental overclock frequency */
#ifndef CLKCTRL_FRQSEL_28M_gc
#define CLKCTRL_FRQSEL_28M_gc (0x0A<<2)
#endif

#ifndef CLKCTRL_FRQSEL_32M_gc
#define CLKCTRL_FRQSEL_32M_gc (0x0B<<2)
#endif

/*
 * Other select
 *
 * (0x04<<2) : 8MHz -> (0x05<<2)
 * (0x0C<<2) : 20Mhz -> (0x08<<2)
 * (0x0D<<2) : 24Mhz -> (0x09<<2)
 * (0x0E<<2) : 28Mhz -> (0x0A<<2)
 * (0x0F<<2) : 32Mhz -> (0x0B<<2)
 */

/* x1 Division */
#if   (F_CPU == 32000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_32M_gc
#elif (F_CPU == 28000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
#elif (F_CPU == 24000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_24M_gc
#elif (F_CPU == 20000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
#elif (F_CPU == 16000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_16M_gc
#elif (F_CPU == 12000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
#elif (F_CPU == 8000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_8M_gc
#elif (F_CPU == 4000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_4M_gc
#elif (F_CPU == 2000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_2M_gc
#elif (F_CPU == 1000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc

/* x2 Division */
#elif (F_CPU == 14000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 10000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 6000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 500000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc

/* x4 Division */
#elif (F_CPU == 7000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 5000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 3000000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 250000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc

/* x8 Division */
#elif (F_CPU == 3500000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 2500000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 1500000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 125000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc

/* x16 Division */
#elif (F_CPU == 1750000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 1250000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 750000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 62500)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc

/* x32 Division */
#elif (F_CPU == 875000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 625000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 375000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 31250)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc

/* x64 Division */
#elif (F_CPU == 437500)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc
#elif (F_CPU == 312500)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc
#elif (F_CPU == 187500)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_12M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc
#elif (F_CPU == 15625)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc

/* x6 Division */
#elif (F_CPU == 5333333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_32M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 4666666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 3333333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 2666666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_16M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 1333333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_8M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 666666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_4M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 333333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_2M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 166666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc

/* x12 Division */
#elif (F_CPU == 2333333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_12X_gc
#elif (F_CPU == 1666666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_12X_gc
#elif (F_CPU == 83333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_12X_gc

/* x24 Division */
#elif (F_CPU == 1166666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_24X_gc
#elif (F_CPU == 833333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_24X_gc
#elif (F_CPU == 41666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_24X_gc

/* x48 Division */
#elif (F_CPU == 583333L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_48X_gc
#elif (F_CPU == 416666L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_20M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_48X_gc
#elif (F_CPU == 20833L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_48X_gc

/* x10 Division */
#elif (F_CPU == 3200000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_32M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 2800000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_28M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 1600000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_16M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 800000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_8M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 400000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_4M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 200000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_2M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc
#elif (F_CPU == 100000L)
  #define _CLKCTRL_FREQSEL_ CLKCTRL_FRQSEL_1M_gc
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc

/* CLK_MAIN = 32768Hz type */
#elif (F_CPU == 32768)
  #define CLKCTRL_USED_OSC32K
#elif (F_CPU == 16384)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 8192)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 4096)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 2048)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 1024)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 512)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc

#elif (F_CPU == 5461)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 2730)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_12X_gc
#elif (F_CPU == 1365)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_24X_gc
#elif (F_CPU == 682)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_48X_gc

#elif (F_CPU == 3276)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_10X_gc

#else
#assert This internal CPU clock is not supported
#endif

#if defined(_CLKCTRL_FREQSEL_)
  _PROTECTED_WRITE(CLKCTRL_OSCHFCTRLA, _CLKCTRL_FREQSEL_);
#endif

#if defined(CLKCTRL_USED_OSC32K)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC32K_gc);
#else
  // _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSCHF_gc);
#endif

#if defined(_CLKCTRL_PDIV_)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _CLKCTRL_PDIV_ | CLKCTRL_PEN_bm);
#else
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);
#endif

  // loop_until_bit_is_clear(CLKCTRL.MCLKSTATUS, CLKCTRL_SOSC_bp);
}

#undef _CLKCTRL_FREQSEL_
#undef _CLKCTRL_PDIV_

#elif defined(CLKCTRL_TIMEBASE_gm)
/*******************************************************
 *
 * AVR Ex Production Internal Clock Speed Setup
 *
 *   modernAVR architecture 3rd generations
 *
 * CLK_MAIN :
 *
 *   CLKCTRL_CLKSEL_OSCHF_gc     20 MHz or 16 MHz
 *     (check is FUSE.OSCCFG -> FUSE_OSCHFFRQ_bp)
 *
 *   CLKCTRL_CLKSEL_OSCULP32K_gc  32.768 kHz
 *
 * Prescaler Division :
 *
 *   CLKCTRL_PDIV_DIV*_gc         2,4,8,16,32,64,
 *                                6,12,24,48, 10
 */

#undef CLKCTRL_USED_OSC32K
#undef _CLKCTRL_PDIV_

#if !defined(F_CPU)
  #define F_CPU 2000000L
  #warning F_CPU is undefined so assume 2000000L
#endif

extern inline void _CLKCTRL_SETUP (void) {

/* CLK_MAIN = 20MHz or 16MHz type */
#if   (F_CPU == 20000000L) || (F_CPU == 16000000L)
  /* not defined */
#elif (F_CPU == 10000000L) || (F_CPU == 8000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV2_gc
#elif (F_CPU == 5000000L) || (F_CPU == 4000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV4_gc
#elif (F_CPU == 2500000L) || (F_CPU == 2000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV8_gc
#elif (F_CPU == 1250000L) || (F_CPU == 1000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV16_gc
#elif (F_CPU == 625000L) || (F_CPU == 500000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DUV32_gc
#elif (F_CPU == 312500L) || (F_CPU == 250000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV64_gc

#elif (F_CPU == 3333333L) || (F_CPU == 2666666L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV6_gc
#elif (F_CPU == 1666666L) || (F_CPU == 1333333L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV12_gc
#elif (F_CPU == 833333L) || (F_CPU == 666666L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV24_gc
#elif (F_CPU == 416666L) || (F_CPU == 333333L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV48_gc

#elif (F_CPU == 2000000L) || (F_CPU == 1600000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV10_gc

/* CLK_MAIN = 32768Hz type */
#elif (F_CPU == 32768)
  #define CLKCTRL_USED_OSC32K
#elif (F_CPU == 16384)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV2_gc
#elif (F_CPU == 8192)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV4_gc
#elif (F_CPU == 4096)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV8_gc
#elif (F_CPU == 2048)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV16_gc
#elif (F_CPU == 1024)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV32_gc
#elif (F_CPU == 512)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV64_gc

#elif (F_CPU == 5461)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV6_gc
#elif (F_CPU == 2730)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV12_gc
#elif (F_CPU == 1365)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV24_gc
#elif (F_CPU == 682)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV48_gc

#elif (F_CPU == 3276)
  #define CLKCTRL_USED_OSC32K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_DIV10_gc

#else
#error This internal CPU clock is not supported
#include BUILD_STOP
#endif

#if (F_CPU == 2000000L)

  uint8_t _pdiv =
    bit_is_set(FUSE_OSCCFG, FUSE_OSCHFFRQ_bp)
      ? CLKCTRL_PDIV_DIV8_gc    /* master clock 16 Mhz */
      : CLKCTRL_PDIV_DIV10_gc;  /* master clock 20 Mhz */
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _pdiv | CLKCTRL_PEN_bm);
  // _PROTECTED_WRITE(CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSCHF_gc);

#else

  #if defined(_CLKCTRL_PDIV_)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _CLKCTRL_PDIV_ | CLKCTRL_PEN_bm);
  #else
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);
  #endif

  #if defined(CLKCTRL_USED_OSC32K)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC32K_gc);
  #else
  // _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSCHF_gc);
  #endif

#endif

}

#undef _CLKCTRL_PDIV_

#else /* !defined(CLKCTRL_TIMEBASE_gm) */
#error This ARCHITECTURE not supported
#include BUILD_STOP
#endif /* defined(CLKCTRL_AUTOTUNE_bm) */

// end of code
