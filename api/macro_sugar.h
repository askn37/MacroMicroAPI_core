/**
 * @file macro_sugar.h
 * @author askn (K.Sato) multix.jp
 * @brief Macro/Micro API syntax sugar header
 * @version 0.2
 * @date 2026-09-17
 * @copyright Copyright (c) 2026 askn37 at github.com
 * @link Product Potal : https://askn37.github.io/
 *         MIT License : https://askn37.github.io/LICENSE.html
 */

#pragma once
#if defined(ENABLE_MACRO_API) && !defined(DISABLE_MACRO_API) && (__AVR_ARCH__ >= 102)
#include <avr/io.h>

#ifdef __MSS_USART_RS485_INT__
/* RS485 Mode internal transmitter select */
/* Not present in AVR_LA */
  #ifndef USART_RS485_gm
#define USART_RS485_gm      0x03    /* RS485 Mode internal transmitter group mask. */
#define USART_RS485_gp      0       /* RS485 Mode internal transmitter group position. */
#define USART_RS485_0_bm    (1<<0)  /* RS485 Mode internal transmitter bit 0 mask. */
#define USART_RS485_0_bp    0       /* RS485 Mode internal transmitter bit 0 position. */
#define USART_RS485_1_bm    (1<<1)  /* RS485 Mode internal transmitter bit 1 mask. */
#define USART_RS485_1_bp    1       /* RS485 Mode internal transmitter bit 1 position. */

/* RS485 Mode internal transmitter select bit group configurations*/
typedef enum USART_RS485_ALT_enum
{
    USART_RS485_OFF_gc  = (0x00<<0),  /* RS485 Mode disabled */
    USART_RS485_EXT_gc  = (0x01<<0),  /* RS485 Mode External drive */
    USART_RS485_INT_gc  = (0x02<<0)   /* RS485 Mode Internal drive */
} USART_RS485_ALT_t;
  #endif
#endif

#ifdef __MSS_CLKCTRL_CLKSEL_OSCX__
/* AVR_Dx/Ex/Lx/Sx style */
  #if !defined (__ASSEMBLER__)
/* Clock select bit group configurations*/
typedef enum CLKCTRL_CLKSEL_ALT_enum
{
    CLKCTRL_CLKSEL_OSCHF_gc  = (CLKCTRL_CLKSEL_OSC20M_gv    << CLKCTRL_CLKSEL_gp), /* 20MHz oscillator */
    CLKCTRL_CLKSEL_OSC32K_gc = (CLKCTRL_CLKSEL_OSCULP32K_gv << CLKCTRL_CLKSEL_gp), /* 32KHz oscillator */
} CLKCTRL_CLKSEL_ALT_t;
  #endif
#endif

#ifdef __MSS_CLKCTRL_CLKSEL_OSCN__
/* tinyAVR-0/1/2, megaAVR-0 style */
  #if !defined (__ASSEMBLER__)
/* Clock select bit group configurations*/
typedef enum CLKCTRL_CLKSEL_ALT_enum
{
    CLKCTRL_CLKSEL_OSC20M_gc    = (CLKCTRL_CLKSEL_OSCHF_gv  << CLKCTRL_CLKSEL_gp), /* Internal high-frequency oscillator */
    CLKCTRL_CLKSEL_OSCULP32K_gc = (CLKCTRL_CLKSEL_OSC32K_gv << CLKCTRL_CLKSEL_gp), /* Internal 32.768 kHz oscillator */
} CLKCTRL_CLKSEL_ALT_t;
  #endif
#endif

#ifdef __MSS_CLKSEL_TINY01__
/* tinyAVR-0/1/2, megaAVR-0 style */
  #if !defined (__ASSEMBLER__)
/* Clock Select */
typedef enum TCB_CLKSEL_ALT_enum
{
    TCB_CLKSEL_DIV1_gc    = (0x00<<1),  /* CLK_PER (No Prescaling) */
    TCB_CLKSEL_DIV2_gc    = (0x01<<1),  /* CLK_PER/2 (From Prescaler) */
    TCB_CLKSEL_TCA0_gc    = (0x02<<1),  /* Use CLK_TCA from TCA0 */
} TCB_CLKSEL_ALT_t;

typedef enum RTC_CLKSEL_ALT_enum
{
    RTC_CLKSEL_OSC32K_gc  = (0x00<<0),  /* Internal 32kHz OSC */
    RTC_CLKSEL_OSC1K_gc   = (0x01<<0),  /* Internal 1kHz OSC */
    RTC_CLKSEL_XOSC32K_gc = (0x02<<0),  /* 32KHz Crystal OSC */
//  RTC_CLKSEL_EXTCLK_gc  = (0x03<<0)   /* External Clock */
} RTC_CLKSEL_ALT_t;
  #endif
#endif

#ifdef __MSS_CLKCTRL_PDIV_NX__
  #if !defined (__ASSEMBLER__)
/* Prescaler division select */
/* tinyAVR, megaAVR, AVR_DA/DB/DD style label */
typedef enum CLKCTRL_PDIV_ALT_enum
{
    CLKCTRL_PDIV_2X_gc  = (CLKCTRL_PDIV_DIV2_gv  << CLKCTRL_PDIV_gp), /* Divide by 2 */
    CLKCTRL_PDIV_4X_gc  = (CLKCTRL_PDIV_DIV4_gv  << CLKCTRL_PDIV_gp), /* Divide by 4 */
    CLKCTRL_PDIV_8X_gc  = (CLKCTRL_PDIV_DIV8_gv  << CLKCTRL_PDIV_gp), /* Divide by 8 */
    CLKCTRL_PDIV_16X_gc = (CLKCTRL_PDIV_DIV16_gv << CLKCTRL_PDIV_gp), /* Divide by 16 */
    CLKCTRL_PDIV_32X_gc = (CLKCTRL_PDIV_DIV32_gv << CLKCTRL_PDIV_gp), /* Divide by 32 */
    CLKCTRL_PDIV_64X_gc = (CLKCTRL_PDIV_DIV64_gv << CLKCTRL_PDIV_gp), /* Divide by 64 */
    CLKCTRL_PDIV_6X_gc  = (CLKCTRL_PDIV_DIV6_gv  << CLKCTRL_PDIV_gp), /* Divide by 6 */
    CLKCTRL_PDIV_10X_gc = (CLKCTRL_PDIV_DIV10_gv << CLKCTRL_PDIV_gp), /* Divide by 10 */
    CLKCTRL_PDIV_12X_gc = (CLKCTRL_PDIV_DIV12_gv << CLKCTRL_PDIV_gp), /* Divide by 12 */
    CLKCTRL_PDIV_24X_gc = (CLKCTRL_PDIV_DIV24_gv << CLKCTRL_PDIV_gp), /* Divide by 24 */
    CLKCTRL_PDIV_48X_gc = (CLKCTRL_PDIV_DIV48_gv << CLKCTRL_PDIV_gp)  /* Divide by 48 */
} CLKCTRL_PDIV_ALT_t;

  #endif
#endif

#ifdef __MSS_CLKCTRL_PDIV_DIVN__
  #if !defined (__ASSEMBLER__)
/* Prescaler division select */
/* AVR_DU/EA/EB/LA/SD style label */
typedef enum CLKCTRL_PDIV_DIV_enum
{
    CLKCTRL_PDIV_DIV2_gc  = (CLKCTRL_PDIV_2X_gv  << CLKCTRL_PDIV_gp), /* 2X */
    CLKCTRL_PDIV_DIV4_gc  = (CLKCTRL_PDIV_4X_gv  << CLKCTRL_PDIV_gp), /* 4X */
    CLKCTRL_PDIV_DIV8_gc  = (CLKCTRL_PDIV_8X_gv  << CLKCTRL_PDIV_gp), /* 8X */
    CLKCTRL_PDIV_DIV16_gc = (CLKCTRL_PDIV_16X_gv << CLKCTRL_PDIV_gp), /* 16X */
    CLKCTRL_PDIV_DIV32_gc = (CLKCTRL_PDIV_32X_gv << CLKCTRL_PDIV_gp), /* 32X */
    CLKCTRL_PDIV_DIV64_gc = (CLKCTRL_PDIV_64X_gv << CLKCTRL_PDIV_gp), /* 64X */
    CLKCTRL_PDIV_DIV6_gc  = (CLKCTRL_PDIV_6X_gv  << CLKCTRL_PDIV_gp), /* 6X */
    CLKCTRL_PDIV_DIV10_gc = (CLKCTRL_PDIV_10X_gv << CLKCTRL_PDIV_gp), /* 10X */
    CLKCTRL_PDIV_DIV12_gc = (CLKCTRL_PDIV_12X_gv << CLKCTRL_PDIV_gp), /* 12X */
    CLKCTRL_PDIV_DIV24_gc = (CLKCTRL_PDIV_24X_gv << CLKCTRL_PDIV_gp), /* 24X */
    CLKCTRL_PDIV_DIV48_gc = (CLKCTRL_PDIV_48X_gv << CLKCTRL_PDIV_gp)  /* 48X */
} CLKCTRL_PDIV_DIV_t;
  #endif
#endif

#ifdef __MSS_EVSYS_CH__
/* EVSYS_CH0_bm -- AVR_LA/SD style label */
  #ifndef EVSYS_CH0_bm
/* EVSYS - Event System */
/* EVSYS.SWEVENTA  bit masks and bit positions */
#define EVSYS_CH0_bm  0x01  /* Channel 0 Select bit mask. */
#define EVSYS_CH0_bp  0     /* Channel 0 Select bit position. */
#define EVSYS_CH1_bm  0x02  /* Channel 1 Select bit mask. */
#define EVSYS_CH1_bp  1     /* Channel 1 Select bit position. */
#define EVSYS_CH2_bm  0x04  /* Channel 2 Select bit mask. */
#define EVSYS_CH2_bp  2     /* Channel 2 Select bit position. */
#define EVSYS_CH3_bm  0x08  /* Channel 3 Select bit mask. */
#define EVSYS_CH3_bp  3     /* Channel 3 Select bit position. */
#define EVSYS_CH4_bm  0x10  /* Channel 4 Select bit mask. */
#define EVSYS_CH4_bp  4     /* Channel 4 Select bit position. */
#define EVSYS_CH5_bm  0x20  /* Channel 5 Select bit mask. */
#define EVSYS_CH5_bp  5     /* Channel 5 Select bit position. */
    #ifdef EVSYS_CHANNEL6
#define EVSYS_CH6_bm  0x40  /* Channel 6 Select bit mask. */
#define EVSYS_CH6_bp  6     /* Channel 6 Select bit position. */
#define EVSYS_CH7_bm  0x80  /* Channel 7 Select bit mask. */
#define EVSYS_CH7_bp  7     /* Channel 7 Select bit position. */
      #ifdef EVSYS_CHANNEL8
/* EVSYS.SWEVENTB  bit masks and bit positions */
#define EVSYS_CH8_bm  0x01  /* Channel 8 Select bit mask. */
#define EVSYS_CH8_bp  0     /* Channel 8 Select bit position. */
#define EVSYS_CH9_bm  0x02  /* Channel 9 Select bit mask. */
#define EVSYS_CH9_bp  1     /* Channel 9 Select bit position. */
      #endif
    #endif
  #endif
#endif

#ifdef __MSS_EVSYS_SWEVENTN__
  #ifdef EVSYS_STROBE
#define EVSYS_SWEVENTA  EVSYS_STROBE
  #endif
/* EVSYS_SWEVENTA_CH0_gc -- tinyAVR, megaAVR, AVR_DA/DB/DD/DU/EA/EB */
  #if !defined (__ASSEMBLER__)
typedef enum EVSYS_SWEVENTA_ALT_enum
{
    EVSYS_SWEVENTA_CH0_gc = (0x01<<0),  /* Software event on channel 0 */
    EVSYS_SWEVENTA_CH1_gc = (0x02<<0),  /* Software event on channel 1 */
    EVSYS_SWEVENTA_CH2_gc = (0x04<<0),  /* Software event on channel 2 */
    EVSYS_SWEVENTA_CH3_gc = (0x08<<0),  /* Software event on channel 3 */
    #ifdef EVSYS_CHANNEL4
    EVSYS_SWEVENTA_CH4_gc = (0x10<<0),  /* Software event on channel 4 */
    EVSYS_SWEVENTA_CH5_gc = (0x20<<0),  /* Software event on channel 5 */
      #ifdef EVSYS_CHANNEL6
    EVSYS_SWEVENTA_CH6_gc = (0x20<<0),  /* Software event on channel 6 */
    EVSYS_SWEVENTA_CH7_gc = (0x40<<0),  /* Software event on channel 7 */
      #endif
    #endif
} EVSYS_SWEVENTA_ALT_t;
  #endif
#endif

#ifdef __MSS_CCL_TRUTH_BM__
  #ifndef CCL_TRUTH_gm
/* CCL.TRUTH0  bit masks and bit positions */
#define CCL_TRUTH_gm    0xFF    /* Truth Table group mask. */
#define CCL_TRUTH_gp    0       /* Truth Table group position. */
#define CCL_TRUTH_0_bm  (1<<0)  /* Truth Table bit 0 mask. */
#define CCL_TRUTH_0_bp  0       /* Truth Table bit 0 position. */
#define CCL_TRUTH_1_bm  (1<<1)  /* Truth Table bit 1 mask. */
#define CCL_TRUTH_1_bp  1       /* Truth Table bit 1 position. */
#define CCL_TRUTH_2_bm  (1<<2)  /* Truth Table bit 2 mask. */
#define CCL_TRUTH_2_bp  2       /* Truth Table bit 2 position. */
#define CCL_TRUTH_3_bm  (1<<3)  /* Truth Table bit 3 mask. */
#define CCL_TRUTH_3_bp  3       /* Truth Table bit 3 position. */
#define CCL_TRUTH_4_bm  (1<<4)  /* Truth Table bit 4 mask. */
#define CCL_TRUTH_4_bp  4       /* Truth Table bit 4 position. */
#define CCL_TRUTH_5_bm  (1<<5)  /* Truth Table bit 5 mask. */
#define CCL_TRUTH_5_bp  5       /* Truth Table bit 5 position. */
#define CCL_TRUTH_6_bm  (1<<6)  /* Truth Table bit 6 mask. */
#define CCL_TRUTH_6_bp  6       /* Truth Table bit 6 position. */
#define CCL_TRUTH_7_bm  (1<<7)  /* Truth Table bit 7 mask. */
#define CCL_TRUTH_7_bp  7       /* Truth Table bit 7 position. */
  #endif
#endif

#ifdef __MSS_AVRNOX_FUSES__
  #ifdef FUSE_APPEND
/* FUSE - Fuses */
#define FUSE_CODESIZE  FUSE_APPEND
#define FUSE_BOOTSIZE  FUSE_BOOTEND
  #endif

/* GPR - General Purpose Registers */
  #ifdef GPIOR0
#define GPR_GPR0  GPIOR0
#define GPR_GPR1  GPIOR1
#define GPR_GPR2  GPIOR2
#define GPR_GPR3  GPIOR3
  #endif
#endif

#if !defined(SLEEP_MODE_ADC) && defined(SLEEP_MODE_STANDBY)
#define SLEEP_MODE_ADC  SLEEP_MODE_STANDBY
#endif

#ifdef __MSS_ENABLE_RBC__
/* Backward compatibility not recommended */
#endif

#endif  /* ENABLE_MACRO_API */

// end of code
