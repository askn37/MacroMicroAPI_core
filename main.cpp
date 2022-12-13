/**
 * @file main.cpp
 * @author askn (K.Sato) multix.jp
 * @brief Arduino API compatible main function
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <variant.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void loop (void);
extern void setup (void);

#ifdef __cplusplus
} // extern "C"
#endif

__attribute__((OS_main,weak,used))
int main (void) {
  initVariant();
  __builtin_avr_sei();
  setup();
  for (;;) loop();
}

// end of code
