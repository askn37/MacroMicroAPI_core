/**
 * @file hooks.c
 * @author askn (K.Sato) multix.jp
 * @brief yield stub
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
extern void yield (void);
extern void loop (void);
extern void setup (void);
extern void reboot (void);

__attribute__ ((weak)) void yield (void) {}
__attribute__ ((weak)) void loop (void) {}
__attribute__ ((weak)) void setup (void) {}
__attribute__ ((weak)) void reboot (void) {
#include <avr/io.h>
#if defined(RSTCTRL_SWRR)
  _PROTECTED_WRITE(RSTCTRL_SWRR, 1);
#endif
  for (;;);
}

// end of code
