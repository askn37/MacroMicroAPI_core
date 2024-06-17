/**
 * @file Portmux.h
 * @author askn (K.Sato) multix.jp
 * @brief portmux struct
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <avr/io.h>

#if defined(__AVR_TINY__)
#include <variant_io.h>
#endif

#ifdef __cplusplus

struct UART_portmux_t {
  register8_t* portmux_reg;
  uint8_t      portmux_mask;
  uint8_t      portmux_set;
  PORT_t*      port_reg;
  uint8_t      tx_pin;
  uint8_t      rx_pin;
  register8_t* rx_pin_ctrl;
};

struct USART_portmux_t {
  register8_t* portmux_reg;
  uint8_t      portmux_mask;
  uint8_t      portmux_set;
  PORT_t*      port_reg;
  uint8_t      tx_pin;
  uint8_t      rx_pin;
  uint8_t      xck_pin;
  uint8_t      xdir_pin;
  register8_t* tx_pin_ctrl;
  register8_t* rx_pin_ctrl;
  register8_t* xck_pin_ctrl;
};

struct SPI_portmux_t {
  register8_t* portmux_reg;
  uint8_t      portmux_mask;
  uint8_t      portmux_set;
  PORT_t*      port_reg;
  uint8_t      mosi_pin;
  uint8_t      miso_pin;
  uint8_t      sck_pin;
  uint8_t      ss_pin;
  register8_t* mosi_pin_ctrl;
  register8_t* miso_pin_ctrl;
  register8_t* sck_pin_ctrl;
  register8_t* ss_pin_ctrl;
};

struct TWI_portmux_t {
  register8_t* portmux_reg;
  uint8_t      portmux_mask;
  uint8_t      portmux_set;
  PORT_t*      port_reg;
  uint8_t      sda_pin;
  uint8_t      scl_pin;
  register8_t* sda_pin_ctrl;
  register8_t* scl_pin_ctrl;
};

/* Calculated baud rate table for UART */

typedef enum UART_BAUD_enum : uint16_t {
  UART_FAST = 32,

#if (F_CPU >= 2400L) && (F_CPU < 4914900L)
  UART_300     = (((F_CPU * 8) /     300) + 1) / 2,
#elif (F_CPU >= 9600L) && (F_CPU < 19659600L)
  UART_1200    = (((F_CPU * 8) /    1200) + 1) / 2,
#endif

#if (F_CPU >= 19200L) && (F_CPU < 39319200L)
  UART_2400    = (((F_CPU * 8) /    2400) + 1) / 2,
#endif

#if (F_CPU >= 38400L)
  UART_4800    = (((F_CPU * 8) /    4800) + 1) / 2,
#endif

#if (F_CPU >= 76800L)
  UART_9600    = (((F_CPU * 8) /    9600) + 1) / 2,
#endif

#if (F_CPU >= 153600L)
  UART_19200   = (((F_CPU * 8) /   19200) + 1) / 2,
#endif

#if (F_CPU >= 278400L)
  UART_38400   = (((F_CPU * 8) /   38400) + 1) / 2,
#endif

#if (F_CPU >= 460800L)
  UART_57600   = (((F_CPU * 8) /   57600) + 1) / 2,
#endif

#if (F_CPU >= 921600L)
  UART_115200  = (((F_CPU * 8) /  115200) + 1) / 2,
#endif

#if (F_CPU >= 1843200L)
  UART_230400  = (((F_CPU * 8) /  230400) + 1) / 2,
#endif

#if (F_CPU >= 3686400L)
  UART_460800  = (((F_CPU * 8) /  460800) + 1) / 2,
#endif

#if (F_CPU >= 4000000L)
  UART_500000  = (((F_CPU * 8) /  500000) + 1) / 2,
#endif

#if (F_CPU >= 8000000L)
  UART_1000000 = (((F_CPU * 8) / 1000000) + 1) / 2,
#endif

#if (F_CPU >= 12000000L)
  UART_1500000 = (((F_CPU * 8) / 1500000) + 1) / 2,
#endif

#if (F_CPU >= 16000000L)
  UART_2000000 = (((F_CPU * 8) / 2000000) + 1) / 2,
#endif

#if (F_CPU >= 24000000L)
  UART_3000000 = (((F_CPU * 8) / 3000000) + 1) / 2,
#endif

#if defined(CONSOLE_BAUD) && (F_CPU >= CONSOLE_BAUD * 8)
  UART_CONSOLE_BAUD = (((F_CPU * 8) / CONSOLE_BAUD) + 1) / 2,
#elif (F_CPU < 4800L)
  UART_CONSOLE_BAUD = UART_300,
#elif (F_CPU < 19200L)
  UART_CONSOLE_BAUD = UART_1200,
#elif (F_CPU < 38400L)
  UART_CONSOLE_BAUD = UART_2400,
#else
  UART_CONSOLE_BAUD = UART_9600,
#endif

  UART_SLOW = 65535
} UART_BAUD_t;

/* Calculated baud rate table for TWI */

/* SMBus under limit */
#if (F_CPU <= 1000000L)
#define _TWI_MIN 0
#else
#define _TWI_MIN 3
#endif

#define _TWI_RATE 2350
#define _TWI_TICK (4000000L / (F_CPU / 5))

typedef enum TWI_BAUD_enum : uint8_t {
  TWI_FAST = _TWI_MIN,
  TWI_SLOW = 255,

#define _TWI_10K_ (F_CPU / (10L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_10K_ < _TWI_MIN)
  TWI_10K  = _TWI_MIN,
#elif (_TWI_10K_ > 255)
  TWI_10K  = TWI_SLOW,
#else
  TWI_10K  = _TWI_10K_,
#endif
#undef _TWI_10K_

#define _TWI_50K_ (F_CPU / (50L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_50K_ < _TWI_MIN)
  TWI_50K  = _TWI_MIN,
#elif (_TWI_50K_ > 255)
  TWI_50K  = TWI_SLOW,
#else
  TWI_50K  = _TWI_50K_,
#endif
#undef _TWI_50K_

#define _TWI_100K_ (F_CPU / (100L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_100K_ < _TWI_MIN)
  TWI_100K  = _TWI_MIN,
#elif (_TWI_100K_ > 255)
  TWI_100K  = TWI_SLOW,
#else
  TWI_100K  = _TWI_100K_,
#endif
#undef _TWI_100K_

#define _TWI_200K_ (F_CPU / (200L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_200K_ < _TWI_MIN)
  TWI_200K  = _TWI_MIN,
#elif (_TWI_200K_ > 255)
  TWI_200K  = TWI_SLOW,
#else
  TWI_200K  = _TWI_200K_,
#endif
#undef _TWI_200K_

#define _TWI_400K_ (F_CPU / (400L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_400K_ < _TWI_MIN)
  TWI_400K  = _TWI_MIN,
#elif (_TWI_400K_ > 255)
  TWI_400K  = TWI_SLOW,
#else
  TWI_400K  = _TWI_400K_,
#endif
#undef _TWI_400K_

#define _TWI_1M_ (F_CPU / (1000L * _TWI_RATE) - _TWI_TICK)
#if (_TWI_1M_ < _TWI_MIN)
  TWI_1M  = _TWI_MIN,
#elif (_TWI_1M_ > 255)
  TWI_1M  = TWI_SLOW,
#else
  TWI_1M  = _TWI_1M_,
#endif
#undef _TWI_1M_
#undef _TWI_RATE

  TWI_LM    = TWI_10K,
  TWI_SM    = TWI_100K,
  TWI_FM    = TWI_400K,
  TWI_FMP   = TWI_1M
} TWI_BAUD_t;

#endif

// end of code
