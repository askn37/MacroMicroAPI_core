/**
 * @file CLKCTRL_megaAVR.h
 * @author askn (K.Sato) multix.jp
 * @brief CLKCTRL for megaAVR
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/io.h>

/*******************************************************
 *
 * megaAVR/tinyAVR Production Internal Clock Speed Setup
 *
 *   modernAVR architecture 1st generations
 *
 * CLK_MAIN :
 *
 *   CLKCTRL_CLKSEL_OSC20M_gc     20 MHz or 16 MHz
 *     (check is FUSE.OSCCFG -> FUSE_FREQSEL_gm)
 *
 *   CLKCTRL_CLKSEL_OSCULP32K_gc  32.768 kHz
 *
 * Prescaler Division :
 *
 *   CLKCTRL_PDIV_*X_gc           2,4,8,16,32,64,
 *                                6,12,24,48, 10
 */
#if defined(CLKCTRL_LOCK_bm)

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
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 5000000L) || (F_CPU == 4000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 2500000L) || (F_CPU == 2000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 1250000L) || (F_CPU == 1000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 625000L) || (F_CPU == 500000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 312500L) || (F_CPU == 250000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc

#elif (F_CPU == 3333333L) || (F_CPU == 2666666L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_6X_gc
#elif (F_CPU == 1666666L) || (F_CPU == 1333333L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_12X_gc
#elif (F_CPU == 833333L) || (F_CPU == 666666L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_24X_gc
#elif (F_CPU == 416666L) || (F_CPU == 333333L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_48X_gc

#elif (F_CPU == 2000000L) || (F_CPU == 1600000L)
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

#if (F_CPU == 2000000L)

  uint8_t _pdiv =
    ((FUSE_OSCCFG & FUSE_FREQSEL_gm) == FREQSEL_16MHZ_gc)
      ? CLKCTRL_PDIV_8X_gc    /* master clock 16 Mhz */
      : CLKCTRL_PDIV_10X_gc;  /* master clock 20 Mhz */
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _pdiv | CLKCTRL_PEN_bm);
  // _PROTECTED_WRITE(CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);

#else

  #if defined(_CLKCTRL_PDIV_)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _CLKCTRL_PDIV_ | CLKCTRL_PEN_bm);
  #else
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, 0);
  #endif

  #if defined(CLKCTRL_USED_OSC32K)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSCULP32K_gc);
  #else
  // _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);
  #endif

#endif

}

#undef _CLKCTRL_PDIV_

#else
#assert This ARCHITECTURE not supported
#endif

// end of code
