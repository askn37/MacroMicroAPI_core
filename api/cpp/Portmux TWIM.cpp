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
#include "../TWIM.h"

/* TWI0 */

#ifdef _PORTMUX_TWI0A
const TWI_portmux_t PROGMEM _portmux_twi0a = _PORTMUX_TWI0A;
TWIM_Class Wire0A {&TWI0, &_portmux_twi0a};
#endif

#ifdef _PORTMUX_TWI0B
const TWI_portmux_t PROGMEM _portmux_twi0b = _PORTMUX_TWI0B;
TWIM_Class Wire0B {&TWI0, &_portmux_twi0b};
#endif

#ifdef _PORTMUX_TWI0C
const TWI_portmux_t PROGMEM _portmux_twi0c = _PORTMUX_TWI0C;
TWIM_Class Wire0C {&TWI0, &_portmux_twi0c};
#endif

#ifdef _PORTMUX_TWI0D
const TWI_portmux_t PROGMEM _portmux_twi0d = _PORTMUX_TWI0D;
TWIM_Class Wire0D {&TWI0, &_portmux_twi0d};
#endif

/* TWI1 */

#ifdef _PORTMUX_TWI1A
const TWI_portmux_t PROGMEM _portmux_twi1a = _PORTMUX_TWI1A;
TWIM_Class Wire1A {&TWI1, &_portmux_twi1a};
#endif

#ifdef _PORTMUX_TWI1B
const TWI_portmux_t PROGMEM _portmux_twi1b = _PORTMUX_TWI1B;
TWIM_Class Wire1B {&TWI1, &_portmux_twi1b};
#endif

#ifdef _PORTMUX_TWI1C
const TWI_portmux_t PROGMEM _portmux_twi1c = _PORTMUX_TWI1C;
TWIM_Class Wire1C {&TWI1, &_portmux_twi1c};
#endif

#ifdef _PORTMUX_TWI1D
const TWI_portmux_t PROGMEM _portmux_twi1d = _PORTMUX_TWI1D;
TWIM_Class Wire1D {&TWI1, &_portmux_twi1d};
#endif

// end of code