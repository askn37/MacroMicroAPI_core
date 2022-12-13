/**
 * @file power.h
 * @author askn (K.Sato) multix.jp
 * @brief AVR power control helper
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/sleep.h>

#ifdef __cplusplus
extern "C" {
#endif

#define power_down()    power_halt(SLEEP_MODE_PWR_DOWN)
#define power_idle()    power_halt(SLEEP_MODE_IDLE)
#define power_standby() power_halt(SLEEP_MODE_STANDBY)

#if defined(SLEEP_MODE_ADC)
#define power_adc()     power_halt(SLEEP_MODE_ADC)
#else
#define power_adc()     power_halt(SLEEP_MODE_IDLE) /* legacy compatible */
#endif

void power_halt (const uint8_t mode) {
  set_sleep_mode(mode);
  sleep_enable();
  __builtin_avr_sei();
  sleep_cpu();
  sleep_disable();
}

#ifdef __cplusplus
}
#endif

// end of code

