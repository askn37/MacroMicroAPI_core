/**
 * @file hooks.c
 * @author askn (K.Sato) multix.jp
 * @brief yield stub
 * @version 0.2
 * @date 2026-09-17
 * @copyright Copyright (c) 2026 askn37 at github.com
 * @link Product Potal : https://askn37.github.io/
 *         MIT License : https://askn37.github.io/LICENSE.html
 */

extern void yield (void);
extern void loop (void);
extern void setup (void);
extern void reboot (void);

__attribute__ ((__weak__)) void yield (void) {}
__attribute__ ((__weak__)) void loop (void) {}
__attribute__ ((__weak__)) void setup (void) {}
__attribute__ ((__weak__)) void reboot (void) {
#include <avr/io.h>
#if defined(RSTCTRL_SWRR)
  _PROTECTED_WRITE(RSTCTRL_SWRR, 1);
#endif
  for (;;);
}

// end of code
