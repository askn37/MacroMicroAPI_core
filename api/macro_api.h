/**
 * @file macro_api.h
 * @author askn (K.Sato) multix.jp
 * @brief Macro/Micro API top header
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#if defined(ENABLE_MACRO_API) && !defined(DISABLE_MACRO_API)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <util/atomic.h>
#include <api/btools.h>
#include <inttypes.h>
#include <stdbool.h>
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

#endif  /* ENABLE_MACRO_API */

// end of code
