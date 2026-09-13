/**
 * @file CVT.h
 * @author askn (K.Sato) multix.jp
 * @brief Compact Vector Table helper.
 * @version 0.1
 * @date 2026-09-11
 * @copyright Copyright (c) 2026 askn37 at github.com
 * @link Product Potal : https://askn37.github.io/
 *         MIT License : https://askn37.github.io/LICENSE.html
 */

#pragma once
#if defined(WOSFILES) && (__AVR_ARCH__ >= 102)
#include <avr/io.h>
#include <avr/interrupt.h>

#if 0
/* Configure it before including the header. */
#define CVT_NMI
#define CVT_LVL1
#define CVT_LVL0
#endif

#if defined(CVT_NVM) ||  defined(CVT_LVL1) || defined(CVT_LVL0)

  #define LVL1_vect _VECTOR(2)
  #define LVL0_vect _VECTOR(3)

#ifdef __cplusplus
  extern "C" void _startup (void) __attribute__ ((naked,used));
  extern "C" void __vector_1 (void);
  extern "C" void __vector_2 (void);
  extern "C" void __vector_3 (void);
#else
  extern void _startup (void) __attribute__ ((naked,used));
  extern void __vector_1 (void);
  extern void __vector_2 (void);
  extern void __vector_3 (void);
#endif

#define __QUOTE__(S) #S
#define _BALIGN_(S) ".balign " __QUOTE__(S) "\n" 
__attribute__ ((naked,used,section(".vectors")))
static void __CVTABLES__ (void) {
  __asm__ __volatile__ (
    _BALIGN_(_VECTOR_SIZE)
    "JMP _startup \n"
    _BALIGN_(_VECTOR_SIZE)
#ifdef CVT_NVM
    "JMP __vector_1 \n"
#else
    "RETI\n"
#endif
    _BALIGN_(_VECTOR_SIZE)
#ifdef CVT_LVL1
    "JMP __vector_2 \n"
#else
    "RETI\n"
#endif
    _BALIGN_(_VECTOR_SIZE)
#ifdef CVT_LVL0
    "JMP __vector_3 \n"
#else
    "RETI\n"
#endif
    _BALIGN_(_VECTOR_SIZE)
    :::"memory"
  );
}

#define CVT_SETUP() do { _PROTECTED_WRITE(CPUINT_CTRLA, CPUINT_CVT_bm); } while (0)
#define CVT_APPCODE CVT_SETUP()
#define CVT_BOOTCODE() do { _PROTECTED_WRITE(CPUINT_CTRLA, CPUINT_CVT_bm | CPUINT_IVSEL_bm); } while (0)

#else

#define FREESTANDING_STARTUP(...) __attribute__ ((naked,used,section(".vectors"))) __VA_ARGS__ static void _startup (void)

#endif

#endif

// end of code
