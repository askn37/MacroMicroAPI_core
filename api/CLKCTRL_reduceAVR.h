/**
 * @file CLKCTRL_reduceAVR.h
 * @author askn (K.Sato) multix.jp
 * @brief CLKCTRL for reduceAVR
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#undef CLKCTRL_USED_OSC128K
#undef _CLKCTRL_PDIV_

#if !defined(F_CPU)
  #define F_CPU 1000000L
  #warning F_CPU is undefined so assume 1000000L
#endif

extern inline void _CLKCTRL_SETUP (void) {

#if (F_CPU == 8000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_1X_gc
#elif (F_CPU == 4000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 2000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 1000000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 500000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 250000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 125000L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc
#elif (F_CPU == 62500L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_128X_gc
#elif (F_CPU == 31250L)
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_256X_gc

#elif (F_CPU == 128000L)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_1X_gc
#elif (F_CPU == 64000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_2X_gc
#elif (F_CPU == 32000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_4X_gc
#elif (F_CPU == 16000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_8X_gc
#elif (F_CPU == 8000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_16X_gc
#elif (F_CPU == 4000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_32X_gc
#elif (F_CPU == 2000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_64X_gc
#elif (F_CPU == 1000)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_128X_gc
#elif (F_CPU == 500)
  #define CLKCTRL_USED_OSC128K
  #define _CLKCTRL_PDIV_ CLKCTRL_PDIV_256X_gc

#else
#assert This internal CPU clock is not supported
#endif

#if defined(CLKCTRL_USED_OSC128K)
  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC128K_gc);
#endif

  _PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, _CLKCTRL_PDIV_);

#undef _CLKCTRL_PDIV_

}

 // end of code
