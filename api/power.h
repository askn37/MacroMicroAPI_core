/**
 * @file power.h
 * @author askn (K.Sato) multix.jp
 * @brief AVR power control helper
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <avr/sleep.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void power_halt (const uint8_t mode);

#define power_down()    power_halt(SLEEP_MODE_PWR_DOWN)
#define power_idle()    power_halt(SLEEP_MODE_IDLE)
#define power_standby() power_halt(SLEEP_MODE_STANDBY)

#if defined(SLEEP_MODE_ADC)
#define power_adc()     power_halt(SLEEP_MODE_ADC)
#else
#define power_adc()     power_halt(SLEEP_MODE_IDLE) /* legacy compatible */
#endif

#ifdef __cplusplus
}
#endif

// end of code

