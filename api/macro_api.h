/**
 * @file macro_api.h
 * @author askn (K.Sato) multix.jp
 * @brief Macro/Micro API top header
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#if defined(ENABLE_MACRO_API) && !defined(DISABLE_MACRO_API)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <util/atomic.h>
#include <inttypes.h>
#include <stdbool.h>
#include <api/btools.h>
#include <api/delay_busywait.h>
#include <api/macro_digital.h>
#include <api/memspace.h>
#include <api/power.h>
#include <variant.h>

#if !defined(pinMode) && !defined(DISABLE_ALIAS_PINMODE)
  #define pinMode(PIN,DIR) pinModeMacro(PIN,DIR)
#endif

#if !defined(digitalWrite) && !defined(DISABLE_ALIAS_DIGITALWRITE)
  #define digitalWrite(PIN,OUT) digitalWriteMacro(PIN,OUT)
#endif

#if !defined(digitalRead) && !defined(DISABLE_ALIAS_DIGITALREAD)
  #define digitalRead(PIN) digitalReadMacro(PIN)
#endif

#if !defined(openDrainWrite) && !defined(DISABLE_ALIAS_OPENDRAINWRITE)
  #define openDrainWrite(PIN,OUT) openDrainWriteMacro(PIN,OUT)
#endif

#if !defined(map) && !defined(DISABLE_ALIAS_MAP)
  #define map(_X,_IMIN,_IMAX,_OMIN,_OMAX) map_long(_X,_IMIN,_IMAX,_OMIN,_OMAX)
#endif

#if !defined(interrupts) && !defined(DISABLE_ALIAS_INTERRUPTS)
  #define interrupts() __builtin_avr_sei()
#endif

#if !defined(noInterrupts) && !defined(DISABLE_ALIAS_NOINTERRUPTS)
  #define noInterrupts() __builtin_avr_cli()
#endif

#if !defined(delay) && !defined(DISABLE_ALIAS_DELAY)
  #define delay(_MS) delay_millis(_MS)
#endif

#if !defined(delayMicroseconds) && !defined(DISABLE_ALIAS_DELAYMICROSECONDS)
  #define delayMicroseconds(_US) delay_micros(_US)
#endif

#if !defined(nop) && !defined(DISABLE_ALIAS_NOP)
  #define nop() __builtin_avr_nop()
#endif

#if !defined(wdt_reset) && !defined(DISABLE_ALIAS_WDR_RESET)
  #define wdt_reset() __builtin_avr_wdr()
#endif

#if !defined(bit_set) && !defined(DISABLE_ALIAS_BIT_SET)
  #define bit_set(sfr,bit) ((sfr) |= _BV(bit))
#endif

#if !defined(bit_clear) && !defined(DISABLE_ALIAS_BIT_CLEAR)
  #define bit_clear(sfr,bit) ((sfr) &= ~_BV(bit))
#endif

#endif  /* ENABLE_MACRO_API */

// end of code
