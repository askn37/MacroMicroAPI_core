/**
 * @file power.cpp
 * @author askn (K.Sato) multix.jp
 * @brief AVR power control helper
 * @version 0.1
 * @date 2023-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <avr/sleep.h>
#include <api/power.h>

void power_halt (const uint8_t mode) {
  set_sleep_mode(mode);
  sleep_enable();
  __builtin_avr_sei();
  sleep_cpu();
  sleep_disable();
}

// end of code

