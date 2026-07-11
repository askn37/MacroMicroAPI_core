/**
 * @file Arduino.h
 * @author askn (K.Sato) multix.jp
 * @brief Arduino API compatible select header
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#if defined(ENABLE_MACRO_API) && !defined(DISABLE_MACRO_API)

#include <api/macro_api.h>
#include <peripheral.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void yield (void);
extern void setup (void);
extern void loop (void);
extern void reboot (void);

#ifdef __cplusplus
} // extern "C"
#endif

#if defined(ENABLE_USBLOADER)
#include <SerialUSB.h>
#endif

#endif  /* ENABLE_MACRO_API */

// end of header