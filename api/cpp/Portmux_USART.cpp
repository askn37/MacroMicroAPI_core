/**
 * @file Portmux.cpp
 * @author askn (K.Sato) multix.jp
 * @brief portmux definition for UART
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#include <peripheral.h>
#include <avr/pgmspace.h>
#include "../Portmux.h"
#include "../HarfUART.h"

/* USART0 */

#ifdef _PORTMUX_USART0A
const UART_portmux_t PROGMEM _portmux_usart0a = _PORTMUX_USART0A;
HarfUART_Class Serial0A {&USART0, &_portmux_usart0a};
#endif

#ifdef _PORTMUX_USART0B
const UART_portmux_t PROGMEM _portmux_usart0b = _PORTMUX_USART0B;
HarfUART_Class Serial0B {&USART0, &_portmux_usart0b};
#endif

#ifdef _PORTMUX_USART0C
const UART_portmux_t PROGMEM _portmux_usart0c = _PORTMUX_USART0C;
HarfUART_Class Serial0C {&USART0, &_portmux_usart0c};
#endif

#ifdef _PORTMUX_USART0D
const UART_portmux_t PROGMEM _portmux_usart0d = _PORTMUX_USART0D;
HarfUART_Class Serial0D {&USART0, &_portmux_usart0d};
#endif

#ifdef _PORTMUX_USART0E
const UART_portmux_t PROGMEM _portmux_usart0e = _PORTMUX_USART0E;
HarfUART_Class Serial0E {&USART0, &_portmux_usart0e};
#endif

#ifdef _PORTMUX_USART0F
const UART_portmux_t PROGMEM _portmux_usart0f = _PORTMUX_USART0F;
HarfUART_Class Serial0F {&USART0, &_portmux_usart0f};
#endif

#ifdef _PORTMUX_USART0G
const UART_portmux_t PROGMEM _portmux_usart0g = _PORTMUX_USART0G;
HarfUART_Class Serial0G {&USART0, &_portmux_usart0g};
#endif

/* USART1 */

#ifdef _PORTMUX_USART1A
const UART_portmux_t PROGMEM _portmux_usart1a = _PORTMUX_USART1A;
HarfUART_Class Serial1A {&USART1, &_portmux_usart1a};
#endif

#ifdef _PORTMUX_USART1B
const UART_portmux_t PROGMEM _portmux_usart1b = _PORTMUX_USART1B;
HarfUART_Class Serial1B {&USART1, &_portmux_usart1b};
#endif

#ifdef _PORTMUX_USART1C
const UART_portmux_t PROGMEM _portmux_usart1c = _PORTMUX_USART1C;
HarfUART_Class Serial1C {&USART1, &_portmux_usart1c};
#endif

/* USART2 */

#ifdef _PORTMUX_USART2A
const UART_portmux_t PROGMEM _portmux_usart2a = _PORTMUX_USART2A;
HarfUART_Class Serial2A {&USART2, &_portmux_usart2a};
#endif

#ifdef _PORTMUX_USART2B
const UART_portmux_t PROGMEM _portmux_usart2b = _PORTMUX_USART2B;
HarfUART_Class Serial2B {&USART2, &_portmux_usart2b};
#endif

#ifdef _PORTMUX_USART2C
const UART_portmux_t PROGMEM _portmux_usart2c = _PORTMUX_USART2C;
HarfUART_Class Serial2C {&USART2, &_portmux_usart2c};
#endif

/* USART3 */

#ifdef _PORTMUX_USART3A
const UART_portmux_t PROGMEM _portmux_usart3a = _PORTMUX_USART3A;
HarfUART_Class Serial3A {&USART3, &_portmux_usart3a};
#endif

#ifdef _PORTMUX_USART3B
const UART_portmux_t PROGMEM _portmux_usart3b = _PORTMUX_USART3B;
HarfUART_Class Serial3B {&USART3, &_portmux_usart3b};
#endif

#ifdef _PORTMUX_USART3C
const UART_portmux_t PROGMEM _portmux_usart3c = _PORTMUX_USART3C;
HarfUART_Class Serial3C {&USART3, &_portmux_usart3c};
#endif

/* USART4 */

#ifdef _PORTMUX_USART4A
const UART_portmux_t PROGMEM _portmux_usart4a = _PORTMUX_USART4A;
HarfUART_Class Serial4A {&USART4, &_portmux_usart4a};
#endif

#ifdef _PORTMUX_USART4B
const UART_portmux_t PROGMEM _portmux_usart4b = _PORTMUX_USART4B;
HarfUART_Class Serial4B {&USART4, &_portmux_usart4b};
#endif

#ifdef _PORTMUX_USART4C
const UART_portmux_t PROGMEM _portmux_usart4c = _PORTMUX_USART4C;
HarfUART_Class Serial4C {&USART4, &_portmux_usart4c};
#endif

/* USART5 */

#ifdef _PORTMUX_USART5A
const UART_portmux_t PROGMEM _portmux_usart5a = _PORTMUX_USART5A;
HarfUART_Class Serial5A {&USART5, &_portmux_usart5a};
#endif

#ifdef _PORTMUX_USART5B
const UART_portmux_t PROGMEM _portmux_usart5b = _PORTMUX_USART5B;
HarfUART_Class Serial5B {&USART5, &_portmux_usart5b};
#endif

#ifdef _PORTMUX_USART5C
const UART_portmux_t PROGMEM _portmux_usart5c = _PORTMUX_USART5C;
HarfUART_Class Serial5C {&USART5, &_portmux_usart5c};
#endif

// end of code