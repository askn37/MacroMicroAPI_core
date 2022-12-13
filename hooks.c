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

__attribute__ ((weak)) void yield (void) {}
__attribute__ ((weak)) void loop (void) {}
__attribute__ ((weak)) void setup (void) {}

// end of code
