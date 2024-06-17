/**
 * @file macro_digital.h
 * @author askn (K.Sato) multix.jp
 * @brief Macro/Micro API digital pin control
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <avr/io.h>
#include <variant.h>

#define ENABLE_MACRO_DIGITAL 1

#if defined(__AVR_TINY__)
#include <variant_macro_digital.h>
#else

/* MACRO API */

#ifdef __CONCAT3
#undef __CONCAT3
#endif
#ifndef __CONCAT3
#define __CONCAT3(A,B,C) A##B##C
#endif

#ifdef __CONCAT4
#undef __CONCAT4
#endif
#ifndef __CONCAT4
#define __CONCAT4(A,B,C,D) A##B##C##D
#endif

/* CONCAT macro parameter */

#define LOW           0
#define INPUT_PULLUP  250
#define TOGGLE        251
#define OUTPUT        252
#define INPUT         253
#define HIGH          254
#define NOT_A_PIN     255

/*
 * pinModeMacroMacro(PIN,INPUT|OUTPUT|INPUT_PULLUP) macro
 */
#define pinModeMacro(PIN,DIR) __CONCAT4(VPORTDIR_,PIN,_,DIR)

// pinModeMacro(PIN,INPUT) -> CBI VPORTx.DIR, y
#define VPORTDIR_16_253  do { __asm__ volatile ("CBI 0x00, 0"); PORTA_PIN0CTRL = 0; } while (0)
#define VPORTDIR_17_253  do { __asm__ volatile ("CBI 0x00, 1"); PORTA_PIN1CTRL = 0; } while (0)
#define VPORTDIR_18_253  do { __asm__ volatile ("CBI 0x00, 2"); PORTA_PIN2CTRL = 0; } while (0)
#define VPORTDIR_19_253  do { __asm__ volatile ("CBI 0x00, 3"); PORTA_PIN3CTRL = 0; } while (0)
#define VPORTDIR_20_253  do { __asm__ volatile ("CBI 0x00, 4"); PORTA_PIN4CTRL = 0; } while (0)
#define VPORTDIR_21_253  do { __asm__ volatile ("CBI 0x00, 5"); PORTA_PIN5CTRL = 0; } while (0)
#define VPORTDIR_22_253  do { __asm__ volatile ("CBI 0x00, 6"); PORTA_PIN6CTRL = 0; } while (0)
#define VPORTDIR_23_253  do { __asm__ volatile ("CBI 0x00, 7"); PORTA_PIN7CTRL = 0; } while (0)

#define VPORTDIR_48_253  do { __asm__ volatile ("CBI 0x04, 0"); PORTB_PIN0CTRL = 0; } while (0)
#define VPORTDIR_49_253  do { __asm__ volatile ("CBI 0x04, 1"); PORTB_PIN1CTRL = 0; } while (0)
#define VPORTDIR_50_253  do { __asm__ volatile ("CBI 0x04, 2"); PORTB_PIN2CTRL = 0; } while (0)
#define VPORTDIR_51_253  do { __asm__ volatile ("CBI 0x04, 3"); PORTB_PIN3CTRL = 0; } while (0)
#define VPORTDIR_52_253  do { __asm__ volatile ("CBI 0x04, 4"); PORTB_PIN4CTRL = 0; } while (0)
#define VPORTDIR_53_253  do { __asm__ volatile ("CBI 0x04, 5"); PORTB_PIN5CTRL = 0; } while (0)
#define VPORTDIR_54_253  do { __asm__ volatile ("CBI 0x04, 6"); PORTB_PIN6CTRL = 0; } while (0)
#define VPORTDIR_55_253  do { __asm__ volatile ("CBI 0x04, 7"); PORTB_PIN7CTRL = 0; } while (0)

#define VPORTDIR_80_253  do { __asm__ volatile ("CBI 0x08, 0"); PORTC_PIN0CTRL = 0; } while (0)
#define VPORTDIR_81_253  do { __asm__ volatile ("CBI 0x08, 1"); PORTC_PIN1CTRL = 0; } while (0)
#define VPORTDIR_82_253  do { __asm__ volatile ("CBI 0x08, 2"); PORTC_PIN2CTRL = 0; } while (0)
#define VPORTDIR_83_253  do { __asm__ volatile ("CBI 0x08, 3"); PORTC_PIN3CTRL = 0; } while (0)
#define VPORTDIR_84_253  do { __asm__ volatile ("CBI 0x08, 4"); PORTC_PIN4CTRL = 0; } while (0)
#define VPORTDIR_85_253  do { __asm__ volatile ("CBI 0x08, 5"); PORTC_PIN5CTRL = 0; } while (0)
#define VPORTDIR_86_253  do { __asm__ volatile ("CBI 0x08, 6"); PORTC_PIN6CTRL = 0; } while (0)
#define VPORTDIR_87_253  do { __asm__ volatile ("CBI 0x08, 7"); PORTC_PIN7CTRL = 0; } while (0)

#define VPORTDIR_112_253 do { __asm__ volatile ("CBI 0x0C, 0"); PORTD_PIN0CTRL = 0; } while (0)
#define VPORTDIR_113_253 do { __asm__ volatile ("CBI 0x0C, 1"); PORTD_PIN1CTRL = 0; } while (0)
#define VPORTDIR_114_253 do { __asm__ volatile ("CBI 0x0C, 2"); PORTD_PIN2CTRL = 0; } while (0)
#define VPORTDIR_115_253 do { __asm__ volatile ("CBI 0x0C, 3"); PORTD_PIN3CTRL = 0; } while (0)
#define VPORTDIR_116_253 do { __asm__ volatile ("CBI 0x0C, 4"); PORTD_PIN4CTRL = 0; } while (0)
#define VPORTDIR_117_253 do { __asm__ volatile ("CBI 0x0C, 5"); PORTD_PIN5CTRL = 0; } while (0)
#define VPORTDIR_118_253 do { __asm__ volatile ("CBI 0x0C, 6"); PORTD_PIN6CTRL = 0; } while (0)
#define VPORTDIR_119_253 do { __asm__ volatile ("CBI 0x0C, 7"); PORTD_PIN7CTRL = 0; } while (0)

#define VPORTDIR_144_253 do { __asm__ volatile ("CBI 0x10, 0"); PORTE_PIN0CTRL = 0; } while (0)
#define VPORTDIR_145_253 do { __asm__ volatile ("CBI 0x10, 1"); PORTE_PIN1CTRL = 0; } while (0)
#define VPORTDIR_146_253 do { __asm__ volatile ("CBI 0x10, 2"); PORTE_PIN2CTRL = 0; } while (0)
#define VPORTDIR_147_253 do { __asm__ volatile ("CBI 0x10, 3"); PORTE_PIN3CTRL = 0; } while (0)
#define VPORTDIR_148_253 do { __asm__ volatile ("CBI 0x10, 4"); PORTE_PIN4CTRL = 0; } while (0)
#define VPORTDIR_149_253 do { __asm__ volatile ("CBI 0x10, 5"); PORTE_PIN5CTRL = 0; } while (0)
#define VPORTDIR_150_253 do { __asm__ volatile ("CBI 0x10, 6"); PORTE_PIN6CTRL = 0; } while (0)
#define VPORTDIR_151_253 do { __asm__ volatile ("CBI 0x10, 7"); PORTE_PIN7CTRL = 0; } while (0)

#define VPORTDIR_176_253 do { __asm__ volatile ("CBI 0x14, 0"); PORTF_PIN0CTRL = 0; } while (0)
#define VPORTDIR_177_253 do { __asm__ volatile ("CBI 0x14, 1"); PORTF_PIN1CTRL = 0; } while (0)
#define VPORTDIR_178_253 do { __asm__ volatile ("CBI 0x14, 2"); PORTF_PIN2CTRL = 0; } while (0)
#define VPORTDIR_179_253 do { __asm__ volatile ("CBI 0x14, 3"); PORTF_PIN3CTRL = 0; } while (0)
#define VPORTDIR_180_253 do { __asm__ volatile ("CBI 0x14, 4"); PORTF_PIN4CTRL = 0; } while (0)
#define VPORTDIR_181_253 do { __asm__ volatile ("CBI 0x14, 5"); PORTF_PIN5CTRL = 0; } while (0)
#define VPORTDIR_182_253 do { __asm__ volatile ("CBI 0x14, 6"); PORTF_PIN6CTRL = 0; } while (0)
#define VPORTDIR_183_253 do { __asm__ volatile ("CBI 0x14, 7"); PORTF_PIN7CTRL = 0; } while (0)

#define VPORTDIR_208_253 do { __asm__ volatile ("CBI 0x18, 0"); PORTG_PIN0CTRL = 0; } while (0)
#define VPORTDIR_209_253 do { __asm__ volatile ("CBI 0x18, 1"); PORTG_PIN1CTRL = 0; } while (0)
#define VPORTDIR_210_253 do { __asm__ volatile ("CBI 0x18, 2"); PORTG_PIN2CTRL = 0; } while (0)
#define VPORTDIR_211_253 do { __asm__ volatile ("CBI 0x18, 3"); PORTG_PIN3CTRL = 0; } while (0)
#define VPORTDIR_212_253 do { __asm__ volatile ("CBI 0x18, 4"); PORTG_PIN4CTRL = 0; } while (0)
#define VPORTDIR_213_253 do { __asm__ volatile ("CBI 0x18, 5"); PORTG_PIN5CTRL = 0; } while (0)
#define VPORTDIR_214_253 do { __asm__ volatile ("CBI 0x18, 6"); PORTG_PIN6CTRL = 0; } while (0)
#define VPORTDIR_215_253 do { __asm__ volatile ("CBI 0x18, 7"); PORTG_PIN7CTRL = 0; } while (0)

#define VPORTDIR__
#define VPORTDIR__253
#define VPORTDIR_255_
#define VPORTDIR_255_253

// pinModeMacro(PIN,OUTPUT) -> SBI VPORTx.DIR, y
#define VPORTDIR_16_252  do { __asm__ volatile ("SBI 0x00, 0"); PORTA_PIN0CTRL = 0; } while (0)
#define VPORTDIR_17_252  do { __asm__ volatile ("SBI 0x00, 1"); PORTA_PIN1CTRL = 0; } while (0)
#define VPORTDIR_18_252  do { __asm__ volatile ("SBI 0x00, 2"); PORTA_PIN2CTRL = 0; } while (0)
#define VPORTDIR_19_252  do { __asm__ volatile ("SBI 0x00, 3"); PORTA_PIN3CTRL = 0; } while (0)
#define VPORTDIR_20_252  do { __asm__ volatile ("SBI 0x00, 4"); PORTA_PIN4CTRL = 0; } while (0)
#define VPORTDIR_21_252  do { __asm__ volatile ("SBI 0x00, 5"); PORTA_PIN5CTRL = 0; } while (0)
#define VPORTDIR_22_252  do { __asm__ volatile ("SBI 0x00, 6"); PORTA_PIN6CTRL = 0; } while (0)
#define VPORTDIR_23_252  do { __asm__ volatile ("SBI 0x00, 7"); PORTA_PIN7CTRL = 0; } while (0)

#define VPORTDIR_48_252  do { __asm__ volatile ("SBI 0x04, 0"); PORTB_PIN0CTRL = 0; } while (0)
#define VPORTDIR_49_252  do { __asm__ volatile ("SBI 0x04, 1"); PORTB_PIN1CTRL = 0; } while (0)
#define VPORTDIR_50_252  do { __asm__ volatile ("SBI 0x04, 2"); PORTB_PIN2CTRL = 0; } while (0)
#define VPORTDIR_51_252  do { __asm__ volatile ("SBI 0x04, 3"); PORTB_PIN3CTRL = 0; } while (0)
#define VPORTDIR_52_252  do { __asm__ volatile ("SBI 0x04, 4"); PORTB_PIN4CTRL = 0; } while (0)
#define VPORTDIR_53_252  do { __asm__ volatile ("SBI 0x04, 5"); PORTB_PIN5CTRL = 0; } while (0)
#define VPORTDIR_54_252  do { __asm__ volatile ("SBI 0x04, 6"); PORTB_PIN6CTRL = 0; } while (0)
#define VPORTDIR_55_252  do { __asm__ volatile ("SBI 0x04, 7"); PORTB_PIN7CTRL = 0; } while (0)

#define VPORTDIR_80_252  do { __asm__ volatile ("SBI 0x08, 0"); PORTC_PIN0CTRL = 0; } while (0)
#define VPORTDIR_81_252  do { __asm__ volatile ("SBI 0x08, 1"); PORTC_PIN1CTRL = 0; } while (0)
#define VPORTDIR_82_252  do { __asm__ volatile ("SBI 0x08, 2"); PORTC_PIN2CTRL = 0; } while (0)
#define VPORTDIR_83_252  do { __asm__ volatile ("SBI 0x08, 3"); PORTC_PIN3CTRL = 0; } while (0)
#define VPORTDIR_84_252  do { __asm__ volatile ("SBI 0x08, 4"); PORTC_PIN4CTRL = 0; } while (0)
#define VPORTDIR_85_252  do { __asm__ volatile ("SBI 0x08, 5"); PORTC_PIN5CTRL = 0; } while (0)
#define VPORTDIR_86_252  do { __asm__ volatile ("SBI 0x08, 6"); PORTC_PIN6CTRL = 0; } while (0)
#define VPORTDIR_87_252  do { __asm__ volatile ("SBI 0x08, 7"); PORTC_PIN7CTRL = 0; } while (0)

#define VPORTDIR_112_252 do { __asm__ volatile ("SBI 0x0C, 0"); PORTD_PIN0CTRL = 0; } while (0)
#define VPORTDIR_113_252 do { __asm__ volatile ("SBI 0x0C, 1"); PORTD_PIN1CTRL = 0; } while (0)
#define VPORTDIR_114_252 do { __asm__ volatile ("SBI 0x0C, 2"); PORTD_PIN2CTRL = 0; } while (0)
#define VPORTDIR_115_252 do { __asm__ volatile ("SBI 0x0C, 3"); PORTD_PIN3CTRL = 0; } while (0)
#define VPORTDIR_116_252 do { __asm__ volatile ("SBI 0x0C, 4"); PORTD_PIN4CTRL = 0; } while (0)
#define VPORTDIR_117_252 do { __asm__ volatile ("SBI 0x0C, 5"); PORTD_PIN5CTRL = 0; } while (0)
#define VPORTDIR_118_252 do { __asm__ volatile ("SBI 0x0C, 6"); PORTD_PIN6CTRL = 0; } while (0)
#define VPORTDIR_119_252 do { __asm__ volatile ("SBI 0x0C, 7"); PORTD_PIN7CTRL = 0; } while (0)

#define VPORTDIR_144_252 do { __asm__ volatile ("SBI 0x10, 0"); PORTE_PIN0CTRL = 0; } while (0)
#define VPORTDIR_145_252 do { __asm__ volatile ("SBI 0x10, 1"); PORTE_PIN1CTRL = 0; } while (0)
#define VPORTDIR_146_252 do { __asm__ volatile ("SBI 0x10, 2"); PORTE_PIN2CTRL = 0; } while (0)
#define VPORTDIR_147_252 do { __asm__ volatile ("SBI 0x10, 3"); PORTE_PIN3CTRL = 0; } while (0)
#define VPORTDIR_148_252 do { __asm__ volatile ("SBI 0x10, 4"); PORTE_PIN4CTRL = 0; } while (0)
#define VPORTDIR_149_252 do { __asm__ volatile ("SBI 0x10, 5"); PORTE_PIN5CTRL = 0; } while (0)
#define VPORTDIR_150_252 do { __asm__ volatile ("SBI 0x10, 6"); PORTE_PIN6CTRL = 0; } while (0)
#define VPORTDIR_151_252 do { __asm__ volatile ("SBI 0x10, 7"); PORTE_PIN7CTRL = 0; } while (0)

#define VPORTDIR_176_252 do { __asm__ volatile ("SBI 0x14, 0"); PORTF_PIN0CTRL = 0; } while (0)
#define VPORTDIR_177_252 do { __asm__ volatile ("SBI 0x14, 1"); PORTF_PIN1CTRL = 0; } while (0)
#define VPORTDIR_178_252 do { __asm__ volatile ("SBI 0x14, 2"); PORTF_PIN2CTRL = 0; } while (0)
#define VPORTDIR_179_252 do { __asm__ volatile ("SBI 0x14, 3"); PORTF_PIN3CTRL = 0; } while (0)
#define VPORTDIR_180_252 do { __asm__ volatile ("SBI 0x14, 4"); PORTF_PIN4CTRL = 0; } while (0)
#define VPORTDIR_181_252 do { __asm__ volatile ("SBI 0x14, 5"); PORTF_PIN5CTRL = 0; } while (0)
#define VPORTDIR_182_252 do { __asm__ volatile ("SBI 0x14, 6"); PORTF_PIN6CTRL = 0; } while (0)
#define VPORTDIR_183_252 do { __asm__ volatile ("SBI 0x14, 7"); PORTF_PIN7CTRL = 0; } while (0)

#define VPORTDIR_208_252 do { __asm__ volatile ("SBI 0x18, 0"); PORTG_PIN0CTRL = 0; } while (0)
#define VPORTDIR_209_252 do { __asm__ volatile ("SBI 0x18, 1"); PORTG_PIN1CTRL = 0; } while (0)
#define VPORTDIR_210_252 do { __asm__ volatile ("SBI 0x18, 2"); PORTG_PIN2CTRL = 0; } while (0)
#define VPORTDIR_211_252 do { __asm__ volatile ("SBI 0x18, 3"); PORTG_PIN3CTRL = 0; } while (0)
#define VPORTDIR_212_252 do { __asm__ volatile ("SBI 0x18, 4"); PORTG_PIN4CTRL = 0; } while (0)
#define VPORTDIR_213_252 do { __asm__ volatile ("SBI 0x18, 5"); PORTG_PIN5CTRL = 0; } while (0)
#define VPORTDIR_214_252 do { __asm__ volatile ("SBI 0x18, 6"); PORTG_PIN6CTRL = 0; } while (0)
#define VPORTDIR_215_252 do { __asm__ volatile ("SBI 0x18, 7"); PORTG_PIN7CTRL = 0; } while (0)

// pinModeMacro(PIN,INPUT_PULLUP) -> CBI VPORTx.DIR, y; PORTx.PINnCTRL=PORT_PULLEN
#define VPORTDIR_16_250  do { __asm__ volatile ("CBI 0x00, 0"); PORTA_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_17_250  do { __asm__ volatile ("CBI 0x00, 1"); PORTA_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_18_250  do { __asm__ volatile ("CBI 0x00, 2"); PORTA_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_19_250  do { __asm__ volatile ("CBI 0x00, 3"); PORTA_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_20_250  do { __asm__ volatile ("CBI 0x00, 4"); PORTA_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_21_250  do { __asm__ volatile ("CBI 0x00, 5"); PORTA_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_22_250  do { __asm__ volatile ("CBI 0x00, 6"); PORTA_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_23_250  do { __asm__ volatile ("CBI 0x00, 7"); PORTA_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_48_250  do { __asm__ volatile ("CBI 0x04, 0"); PORTB_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_49_250  do { __asm__ volatile ("CBI 0x04, 1"); PORTB_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_50_250  do { __asm__ volatile ("CBI 0x04, 2"); PORTB_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_51_250  do { __asm__ volatile ("CBI 0x04, 3"); PORTB_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_52_250  do { __asm__ volatile ("CBI 0x04, 4"); PORTB_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_53_250  do { __asm__ volatile ("CBI 0x04, 5"); PORTB_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_54_250  do { __asm__ volatile ("CBI 0x04, 6"); PORTB_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_55_250  do { __asm__ volatile ("CBI 0x04, 7"); PORTB_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_80_250  do { __asm__ volatile ("CBI 0x08, 0"); PORTC_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_81_250  do { __asm__ volatile ("CBI 0x08, 1"); PORTC_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_82_250  do { __asm__ volatile ("CBI 0x08, 2"); PORTC_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_83_250  do { __asm__ volatile ("CBI 0x08, 3"); PORTC_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_84_250  do { __asm__ volatile ("CBI 0x08, 4"); PORTC_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_85_250  do { __asm__ volatile ("CBI 0x08, 5"); PORTC_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_86_250  do { __asm__ volatile ("CBI 0x08, 6"); PORTC_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_87_250  do { __asm__ volatile ("CBI 0x08, 7"); PORTC_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_112_250 do { __asm__ volatile ("CBI 0x0C, 0"); PORTD_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_113_250 do { __asm__ volatile ("CBI 0x0C, 1"); PORTD_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_114_250 do { __asm__ volatile ("CBI 0x0C, 2"); PORTD_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_115_250 do { __asm__ volatile ("CBI 0x0C, 3"); PORTD_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_116_250 do { __asm__ volatile ("CBI 0x0C, 4"); PORTD_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_117_250 do { __asm__ volatile ("CBI 0x0C, 5"); PORTD_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_118_250 do { __asm__ volatile ("CBI 0x0C, 6"); PORTD_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_119_250 do { __asm__ volatile ("CBI 0x0C, 7"); PORTD_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_144_250 do { __asm__ volatile ("CBI 0x10, 0"); PORTE_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_145_250 do { __asm__ volatile ("CBI 0x10, 1"); PORTE_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_146_250 do { __asm__ volatile ("CBI 0x10, 2"); PORTE_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_147_250 do { __asm__ volatile ("CBI 0x10, 3"); PORTE_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_148_250 do { __asm__ volatile ("CBI 0x10, 4"); PORTE_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_149_250 do { __asm__ volatile ("CBI 0x10, 5"); PORTE_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_150_250 do { __asm__ volatile ("CBI 0x10, 6"); PORTE_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_151_250 do { __asm__ volatile ("CBI 0x10, 7"); PORTE_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_176_250 do { __asm__ volatile ("CBI 0x14, 0"); PORTF_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_177_250 do { __asm__ volatile ("CBI 0x14, 1"); PORTF_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_178_250 do { __asm__ volatile ("CBI 0x14, 2"); PORTF_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_179_250 do { __asm__ volatile ("CBI 0x14, 3"); PORTF_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_180_250 do { __asm__ volatile ("CBI 0x14, 4"); PORTF_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_181_250 do { __asm__ volatile ("CBI 0x14, 5"); PORTF_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_182_250 do { __asm__ volatile ("CBI 0x14, 6"); PORTF_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_183_250 do { __asm__ volatile ("CBI 0x14, 7"); PORTF_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR_208_250 do { __asm__ volatile ("CBI 0x18, 0"); PORTG_PIN0CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_209_250 do { __asm__ volatile ("CBI 0x18, 1"); PORTG_PIN1CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_210_250 do { __asm__ volatile ("CBI 0x18, 2"); PORTG_PIN2CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_211_250 do { __asm__ volatile ("CBI 0x18, 3"); PORTG_PIN3CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_212_250 do { __asm__ volatile ("CBI 0x18, 4"); PORTG_PIN4CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_213_250 do { __asm__ volatile ("CBI 0x18, 5"); PORTG_PIN5CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_214_250 do { __asm__ volatile ("CBI 0x18, 6"); PORTG_PIN6CTRL = PORT_PULLUPEN_bm; } while (0)
#define VPORTDIR_215_250 do { __asm__ volatile ("CBI 0x18, 7"); PORTG_PIN7CTRL = PORT_PULLUPEN_bm; } while (0)

#define VPORTDIR__
#define VPORTDIR__252
#define VPORTDIR__250
#define VPORTDIR_255_
#define VPORTDIR_255_252
#define VPORTDIR_255_250

/*
 * pinControlRegister(PIN) macro
 */
#define pinControlRegister(PIN) __CONCAT3(PINCTRL_,PIN,_)

#define PINCTRL_16_  PORTA_PIN0CTRL
#define PINCTRL_17_  PORTA_PIN1CTRL
#define PINCTRL_18_  PORTA_PIN2CTRL
#define PINCTRL_19_  PORTA_PIN3CTRL
#define PINCTRL_20_  PORTA_PIN4CTRL
#define PINCTRL_21_  PORTA_PIN5CTRL
#define PINCTRL_22_  PORTA_PIN6CTRL
#define PINCTRL_23_  PORTA_PIN7CTRL

#define PINCTRL_48_  PORTB_PIN0CTRL
#define PINCTRL_49_  PORTB_PIN1CTRL
#define PINCTRL_50_  PORTB_PIN2CTRL
#define PINCTRL_51_  PORTB_PIN3CTRL
#define PINCTRL_52_  PORTB_PIN4CTRL
#define PINCTRL_53_  PORTB_PIN5CTRL
#define PINCTRL_54_  PORTB_PIN6CTRL
#define PINCTRL_55_  PORTB_PIN7CTRL

#define PINCTRL_80_  PORTC_PIN0CTRL
#define PINCTRL_81_  PORTC_PIN1CTRL
#define PINCTRL_82_  PORTC_PIN2CTRL
#define PINCTRL_83_  PORTC_PIN3CTRL
#define PINCTRL_84_  PORTC_PIN4CTRL
#define PINCTRL_85_  PORTC_PIN5CTRL
#define PINCTRL_86_  PORTC_PIN6CTRL
#define PINCTRL_87_  PORTC_PIN7CTRL

#define PINCTRL_112_ PORTD_PIN0CTRL
#define PINCTRL_113_ PORTD_PIN1CTRL
#define PINCTRL_114_ PORTD_PIN2CTRL
#define PINCTRL_115_ PORTD_PIN3CTRL
#define PINCTRL_116_ PORTD_PIN4CTRL
#define PINCTRL_117_ PORTD_PIN5CTRL
#define PINCTRL_118_ PORTD_PIN6CTRL
#define PINCTRL_119_ PORTD_PIN7CTRL

#define PINCTRL_144_ PORTE_PIN0CTRL
#define PINCTRL_145_ PORTE_PIN1CTRL
#define PINCTRL_146_ PORTE_PIN2CTRL
#define PINCTRL_147_ PORTE_PIN3CTRL
#define PINCTRL_148_ PORTE_PIN4CTRL
#define PINCTRL_149_ PORTE_PIN5CTRL
#define PINCTRL_150_ PORTE_PIN6CTRL
#define PINCTRL_151_ PORTE_PIN7CTRL

#define PINCTRL_176_ PORTF_PIN0CTRL
#define PINCTRL_177_ PORTF_PIN1CTRL
#define PINCTRL_178_ PORTF_PIN2CTRL
#define PINCTRL_179_ PORTF_PIN3CTRL
#define PINCTRL_180_ PORTF_PIN4CTRL
#define PINCTRL_181_ PORTF_PIN5CTRL
#define PINCTRL_182_ PORTF_PIN6CTRL
#define PINCTRL_183_ PORTF_PIN7CTRL

#define PINCTRL_208_ PORTG_PIN0CTRL
#define PINCTRL_209_ PORTG_PIN1CTRL
#define PINCTRL_210_ PORTG_PIN2CTRL
#define PINCTRL_211_ PORTG_PIN3CTRL
#define PINCTRL_212_ PORTG_PIN4CTRL
#define PINCTRL_213_ PORTG_PIN5CTRL
#define PINCTRL_214_ PORTG_PIN6CTRL
#define PINCTRL_215_ PORTG_PIN7CTRL

#define PINCTRL__
#define PINCTRL_255_

/*
 * pinPosition(PIN) macro
 */
#define pinPosition(PIN) (PIN & 7)

/*
 * portRegister(PIN) macro
 */
#define portRegister(PIN) __CONCAT3(PORTREG_,PIN,_)

#define PORTREG_16_  PORTA
#define PORTREG_17_  PORTA
#define PORTREG_18_  PORTA
#define PORTREG_19_  PORTA
#define PORTREG_20_  PORTA
#define PORTREG_21_  PORTA
#define PORTREG_22_  PORTA
#define PORTREG_23_  PORTA

#define PORTREG_48_  PORTB
#define PORTREG_49_  PORTB
#define PORTREG_50_  PORTB
#define PORTREG_51_  PORTB
#define PORTREG_52_  PORTB
#define PORTREG_53_  PORTB
#define PORTREG_54_  PORTB
#define PORTREG_55_  PORTB

#define PORTREG_80_  PORTC
#define PORTREG_81_  PORTC
#define PORTREG_82_  PORTC
#define PORTREG_83_  PORTC
#define PORTREG_84_  PORTC
#define PORTREG_85_  PORTC
#define PORTREG_86_  PORTC
#define PORTREG_87_  PORTC

#define PORTREG_112_ PORTD
#define PORTREG_113_ PORTD
#define PORTREG_114_ PORTD
#define PORTREG_115_ PORTD
#define PORTREG_116_ PORTD
#define PORTREG_117_ PORTD
#define PORTREG_118_ PORTD
#define PORTREG_119_ PORTD

#define PORTREG_144_ PORTE
#define PORTREG_145_ PORTE
#define PORTREG_146_ PORTE
#define PORTREG_147_ PORTE
#define PORTREG_148_ PORTE
#define PORTREG_149_ PORTE
#define PORTREG_150_ PORTE
#define PORTREG_151_ PORTE

#define PORTREG_176_ PORTF
#define PORTREG_177_ PORTF
#define PORTREG_178_ PORTF
#define PORTREG_179_ PORTF
#define PORTREG_180_ PORTF
#define PORTREG_181_ PORTF
#define PORTREG_182_ PORTF
#define PORTREG_183_ PORTF

#define PORTREG_208_ PORTG
#define PORTREG_209_ PORTG
#define PORTREG_210_ PORTG
#define PORTREG_211_ PORTG
#define PORTREG_212_ PORTG
#define PORTREG_213_ PORTG
#define PORTREG_214_ PORTG
#define PORTREG_215_ PORTG

#define PORTREG__
#define PORTREG_255_

/*
 * portRegister(PIN) macro
 */
#define portIntrruptVector(PIN) __CONCAT3(PORTVECT_,PIN,_)

#define PORTVECT_16_  PORTA_PORT_vect
#define PORTVECT_17_  PORTA_PORT_vect
#define PORTVECT_18_  PORTA_PORT_vect
#define PORTVECT_19_  PORTA_PORT_vect
#define PORTVECT_20_  PORTA_PORT_vect
#define PORTVECT_21_  PORTA_PORT_vect
#define PORTVECT_22_  PORTA_PORT_vect
#define PORTVECT_23_  PORTA_PORT_vect

#define PORTVECT_48_  PORTB_PORT_vect
#define PORTVECT_49_  PORTB_PORT_vect
#define PORTVECT_50_  PORTB_PORT_vect
#define PORTVECT_51_  PORTB_PORT_vect
#define PORTVECT_52_  PORTB_PORT_vect
#define PORTVECT_53_  PORTB_PORT_vect
#define PORTVECT_54_  PORTB_PORT_vect
#define PORTVECT_55_  PORTB_PORT_vect

#define PORTVECT_80_  PORTC_PORT_vect
#define PORTVECT_81_  PORTC_PORT_vect
#define PORTVECT_82_  PORTC_PORT_vect
#define PORTVECT_83_  PORTC_PORT_vect
#define PORTVECT_84_  PORTC_PORT_vect
#define PORTVECT_85_  PORTC_PORT_vect
#define PORTVECT_86_  PORTC_PORT_vect
#define PORTVECT_87_  PORTC_PORT_vect

#define PORTVECT_112_ PORTD_PORT_vect
#define PORTVECT_113_ PORTD_PORT_vect
#define PORTVECT_114_ PORTD_PORT_vect
#define PORTVECT_115_ PORTD_PORT_vect
#define PORTVECT_116_ PORTD_PORT_vect
#define PORTVECT_117_ PORTD_PORT_vect
#define PORTVECT_118_ PORTD_PORT_vect
#define PORTVECT_119_ PORTD_PORT_vect

#define PORTVECT_144_ PORTE_PORT_vect
#define PORTVECT_145_ PORTE_PORT_vect
#define PORTVECT_146_ PORTE_PORT_vect
#define PORTVECT_147_ PORTE_PORT_vect
#define PORTVECT_148_ PORTE_PORT_vect
#define PORTVECT_149_ PORTE_PORT_vect
#define PORTVECT_150_ PORTE_PORT_vect
#define PORTVECT_151_ PORTE_PORT_vect

#define PORTVECT_176_ PORTF_PORT_vect
#define PORTVECT_177_ PORTF_PORT_vect
#define PORTVECT_178_ PORTF_PORT_vect
#define PORTVECT_179_ PORTF_PORT_vect
#define PORTVECT_180_ PORTF_PORT_vect
#define PORTVECT_181_ PORTF_PORT_vect
#define PORTVECT_182_ PORTF_PORT_vect
#define PORTVECT_183_ PORTF_PORT_vect

#define PORTVECT_208_ PORTG_PORT_vect
#define PORTVECT_209_ PORTG_PORT_vect
#define PORTVECT_210_ PORTG_PORT_vect
#define PORTVECT_211_ PORTG_PORT_vect
#define PORTVECT_212_ PORTG_PORT_vect
#define PORTVECT_213_ PORTG_PORT_vect
#define PORTVECT_214_ PORTG_PORT_vect
#define PORTVECT_215_ PORTG_PORT_vect

#define PORTVECT__
#define PORTVECT_255_

/*
 * digitalWriteMacro(PIN,LOW|HIGH|TOGGLE) macro
 */
#define digitalWriteMacro(PIN,OUT) __CONCAT4(VPORTOUT_,PIN,_,OUT)

// digitalWriteMacro(PIN,LOW) -> CBI VPORTx.OUT, y
#define VPORTOUT_16_0  do { __asm__ volatile ("CBI 0x01, 0"); } while (0)
#define VPORTOUT_17_0  do { __asm__ volatile ("CBI 0x01, 1"); } while (0)
#define VPORTOUT_18_0  do { __asm__ volatile ("CBI 0x01, 2"); } while (0)
#define VPORTOUT_19_0  do { __asm__ volatile ("CBI 0x01, 3"); } while (0)
#define VPORTOUT_20_0  do { __asm__ volatile ("CBI 0x01, 4"); } while (0)
#define VPORTOUT_21_0  do { __asm__ volatile ("CBI 0x01, 5"); } while (0)
#define VPORTOUT_22_0  do { __asm__ volatile ("CBI 0x01, 6"); } while (0)
#define VPORTOUT_23_0  do { __asm__ volatile ("CBI 0x01, 7"); } while (0)

#define VPORTOUT_48_0  do { __asm__ volatile ("CBI 0x05, 0"); } while (0)
#define VPORTOUT_49_0  do { __asm__ volatile ("CBI 0x05, 1"); } while (0)
#define VPORTOUT_50_0  do { __asm__ volatile ("CBI 0x05, 2"); } while (0)
#define VPORTOUT_51_0  do { __asm__ volatile ("CBI 0x05, 3"); } while (0)
#define VPORTOUT_52_0  do { __asm__ volatile ("CBI 0x05, 4"); } while (0)
#define VPORTOUT_53_0  do { __asm__ volatile ("CBI 0x05, 5"); } while (0)
#define VPORTOUT_54_0  do { __asm__ volatile ("CBI 0x05, 6"); } while (0)
#define VPORTOUT_55_0  do { __asm__ volatile ("CBI 0x05, 7"); } while (0)

#define VPORTOUT_80_0  do { __asm__ volatile ("CBI 0x09, 0"); } while (0)
#define VPORTOUT_81_0  do { __asm__ volatile ("CBI 0x09, 1"); } while (0)
#define VPORTOUT_82_0  do { __asm__ volatile ("CBI 0x09, 2"); } while (0)
#define VPORTOUT_83_0  do { __asm__ volatile ("CBI 0x09, 3"); } while (0)
#define VPORTOUT_84_0  do { __asm__ volatile ("CBI 0x09, 4"); } while (0)
#define VPORTOUT_85_0  do { __asm__ volatile ("CBI 0x09, 5"); } while (0)
#define VPORTOUT_86_0  do { __asm__ volatile ("CBI 0x09, 6"); } while (0)
#define VPORTOUT_87_0  do { __asm__ volatile ("CBI 0x09, 7"); } while (0)

#define VPORTOUT_112_0 do { __asm__ volatile ("CBI 0x0D, 0"); } while (0)
#define VPORTOUT_113_0 do { __asm__ volatile ("CBI 0x0D, 1"); } while (0)
#define VPORTOUT_114_0 do { __asm__ volatile ("CBI 0x0D, 2"); } while (0)
#define VPORTOUT_115_0 do { __asm__ volatile ("CBI 0x0D, 3"); } while (0)
#define VPORTOUT_116_0 do { __asm__ volatile ("CBI 0x0D, 4"); } while (0)
#define VPORTOUT_117_0 do { __asm__ volatile ("CBI 0x0D, 5"); } while (0)
#define VPORTOUT_118_0 do { __asm__ volatile ("CBI 0x0D, 6"); } while (0)
#define VPORTOUT_119_0 do { __asm__ volatile ("CBI 0x0D, 7"); } while (0)

#define VPORTOUT_144_0 do { __asm__ volatile ("CBI 0x11, 0"); } while (0)
#define VPORTOUT_145_0 do { __asm__ volatile ("CBI 0x11, 1"); } while (0)
#define VPORTOUT_146_0 do { __asm__ volatile ("CBI 0x11, 2"); } while (0)
#define VPORTOUT_147_0 do { __asm__ volatile ("CBI 0x11, 3"); } while (0)
#define VPORTOUT_148_0 do { __asm__ volatile ("CBI 0x11, 4"); } while (0)
#define VPORTOUT_149_0 do { __asm__ volatile ("CBI 0x11, 5"); } while (0)
#define VPORTOUT_150_0 do { __asm__ volatile ("CBI 0x11, 6"); } while (0)
#define VPORTOUT_151_0 do { __asm__ volatile ("CBI 0x11, 7"); } while (0)

#define VPORTOUT_176_0 do { __asm__ volatile ("CBI 0x15, 0"); } while (0)
#define VPORTOUT_177_0 do { __asm__ volatile ("CBI 0x15, 1"); } while (0)
#define VPORTOUT_178_0 do { __asm__ volatile ("CBI 0x15, 2"); } while (0)
#define VPORTOUT_179_0 do { __asm__ volatile ("CBI 0x15, 3"); } while (0)
#define VPORTOUT_180_0 do { __asm__ volatile ("CBI 0x15, 4"); } while (0)
#define VPORTOUT_181_0 do { __asm__ volatile ("CBI 0x15, 5"); } while (0)
#define VPORTOUT_182_0 do { __asm__ volatile ("CBI 0x15, 6"); } while (0)
#define VPORTOUT_183_0 do { __asm__ volatile ("CBI 0x15, 7"); } while (0)

#define VPORTOUT_208_0 do { __asm__ volatile ("CBI 0x19, 0"); } while (0)
#define VPORTOUT_209_0 do { __asm__ volatile ("CBI 0x19, 1"); } while (0)
#define VPORTOUT_210_0 do { __asm__ volatile ("CBI 0x19, 2"); } while (0)
#define VPORTOUT_211_0 do { __asm__ volatile ("CBI 0x19, 3"); } while (0)
#define VPORTOUT_212_0 do { __asm__ volatile ("CBI 0x19, 4"); } while (0)
#define VPORTOUT_213_0 do { __asm__ volatile ("CBI 0x19, 5"); } while (0)
#define VPORTOUT_214_0 do { __asm__ volatile ("CBI 0x19, 6"); } while (0)
#define VPORTOUT_215_0 do { __asm__ volatile ("CBI 0x19, 7"); } while (0)

// digitalWriteMacro(PIN,HIGH) -> SBI VPORTx.OUT, y
#define VPORTOUT_16_254  do { __asm__ volatile ("SBI 0x01, 0"); } while (0)
#define VPORTOUT_17_254  do { __asm__ volatile ("SBI 0x01, 1"); } while (0)
#define VPORTOUT_18_254  do { __asm__ volatile ("SBI 0x01, 2"); } while (0)
#define VPORTOUT_19_254  do { __asm__ volatile ("SBI 0x01, 3"); } while (0)
#define VPORTOUT_20_254  do { __asm__ volatile ("SBI 0x01, 4"); } while (0)
#define VPORTOUT_21_254  do { __asm__ volatile ("SBI 0x01, 5"); } while (0)
#define VPORTOUT_22_254  do { __asm__ volatile ("SBI 0x01, 6"); } while (0)
#define VPORTOUT_23_254  do { __asm__ volatile ("SBI 0x01, 7"); } while (0)

#define VPORTOUT_48_254  do { __asm__ volatile ("SBI 0x05, 0"); } while (0)
#define VPORTOUT_49_254  do { __asm__ volatile ("SBI 0x05, 1"); } while (0)
#define VPORTOUT_50_254  do { __asm__ volatile ("SBI 0x05, 2"); } while (0)
#define VPORTOUT_51_254  do { __asm__ volatile ("SBI 0x05, 3"); } while (0)
#define VPORTOUT_52_254  do { __asm__ volatile ("SBI 0x05, 4"); } while (0)
#define VPORTOUT_53_254  do { __asm__ volatile ("SBI 0x05, 5"); } while (0)
#define VPORTOUT_54_254  do { __asm__ volatile ("SBI 0x05, 6"); } while (0)
#define VPORTOUT_55_254  do { __asm__ volatile ("SBI 0x05, 7"); } while (0)

#define VPORTOUT_80_254  do { __asm__ volatile ("SBI 0x09, 0"); } while (0)
#define VPORTOUT_81_254  do { __asm__ volatile ("SBI 0x09, 1"); } while (0)
#define VPORTOUT_82_254  do { __asm__ volatile ("SBI 0x09, 2"); } while (0)
#define VPORTOUT_83_254  do { __asm__ volatile ("SBI 0x09, 3"); } while (0)
#define VPORTOUT_84_254  do { __asm__ volatile ("SBI 0x09, 4"); } while (0)
#define VPORTOUT_85_254  do { __asm__ volatile ("SBI 0x09, 5"); } while (0)
#define VPORTOUT_86_254  do { __asm__ volatile ("SBI 0x09, 6"); } while (0)
#define VPORTOUT_87_254  do { __asm__ volatile ("SBI 0x09, 7"); } while (0)

#define VPORTOUT_112_254 do { __asm__ volatile ("SBI 0x0D, 0"); } while (0)
#define VPORTOUT_113_254 do { __asm__ volatile ("SBI 0x0D, 1"); } while (0)
#define VPORTOUT_114_254 do { __asm__ volatile ("SBI 0x0D, 2"); } while (0)
#define VPORTOUT_115_254 do { __asm__ volatile ("SBI 0x0D, 3"); } while (0)
#define VPORTOUT_116_254 do { __asm__ volatile ("SBI 0x0D, 4"); } while (0)
#define VPORTOUT_117_254 do { __asm__ volatile ("SBI 0x0D, 5"); } while (0)
#define VPORTOUT_118_254 do { __asm__ volatile ("SBI 0x0D, 6"); } while (0)
#define VPORTOUT_119_254 do { __asm__ volatile ("SBI 0x0D, 7"); } while (0)

#define VPORTOUT_144_254 do { __asm__ volatile ("SBI 0x11, 0"); } while (0)
#define VPORTOUT_145_254 do { __asm__ volatile ("SBI 0x11, 1"); } while (0)
#define VPORTOUT_146_254 do { __asm__ volatile ("SBI 0x11, 2"); } while (0)
#define VPORTOUT_147_254 do { __asm__ volatile ("SBI 0x11, 3"); } while (0)
#define VPORTOUT_148_254 do { __asm__ volatile ("SBI 0x11, 4"); } while (0)
#define VPORTOUT_149_254 do { __asm__ volatile ("SBI 0x11, 5"); } while (0)
#define VPORTOUT_150_254 do { __asm__ volatile ("SBI 0x11, 6"); } while (0)
#define VPORTOUT_151_254 do { __asm__ volatile ("SBI 0x11, 7"); } while (0)

#define VPORTOUT_176_254 do { __asm__ volatile ("SBI 0x15, 0"); } while (0)
#define VPORTOUT_177_254 do { __asm__ volatile ("SBI 0x15, 1"); } while (0)
#define VPORTOUT_178_254 do { __asm__ volatile ("SBI 0x15, 2"); } while (0)
#define VPORTOUT_179_254 do { __asm__ volatile ("SBI 0x15, 3"); } while (0)
#define VPORTOUT_180_254 do { __asm__ volatile ("SBI 0x15, 4"); } while (0)
#define VPORTOUT_181_254 do { __asm__ volatile ("SBI 0x15, 5"); } while (0)
#define VPORTOUT_182_254 do { __asm__ volatile ("SBI 0x15, 6"); } while (0)
#define VPORTOUT_183_254 do { __asm__ volatile ("SBI 0x15, 7"); } while (0)

#define VPORTOUT_208_254 do { __asm__ volatile ("SBI 0x19, 0"); } while (0)
#define VPORTOUT_209_254 do { __asm__ volatile ("SBI 0x19, 1"); } while (0)
#define VPORTOUT_210_254 do { __asm__ volatile ("SBI 0x19, 2"); } while (0)
#define VPORTOUT_211_254 do { __asm__ volatile ("SBI 0x19, 3"); } while (0)
#define VPORTOUT_212_254 do { __asm__ volatile ("SBI 0x19, 4"); } while (0)
#define VPORTOUT_213_254 do { __asm__ volatile ("SBI 0x19, 5"); } while (0)
#define VPORTOUT_214_254 do { __asm__ volatile ("SBI 0x19, 6"); } while (0)
#define VPORTOUT_215_254 do { __asm__ volatile ("SBI 0x19, 7"); } while (0)

// digitalWriteMacro(PIN,TOGGLE) -> SBI VPORTx.IN, y
#define VPORTOUT_16_251  do { __asm__ volatile ("SBI 0x02, 0"); } while (0)
#define VPORTOUT_17_251  do { __asm__ volatile ("SBI 0x02, 1"); } while (0)
#define VPORTOUT_18_251  do { __asm__ volatile ("SBI 0x02, 2"); } while (0)
#define VPORTOUT_19_251  do { __asm__ volatile ("SBI 0x02, 3"); } while (0)
#define VPORTOUT_20_251  do { __asm__ volatile ("SBI 0x02, 4"); } while (0)
#define VPORTOUT_21_251  do { __asm__ volatile ("SBI 0x02, 5"); } while (0)
#define VPORTOUT_22_251  do { __asm__ volatile ("SBI 0x02, 6"); } while (0)
#define VPORTOUT_23_251  do { __asm__ volatile ("SBI 0x02, 7"); } while (0)

#define VPORTOUT_48_251  do { __asm__ volatile ("SBI 0x06, 0"); } while (0)
#define VPORTOUT_49_251  do { __asm__ volatile ("SBI 0x06, 1"); } while (0)
#define VPORTOUT_50_251  do { __asm__ volatile ("SBI 0x06, 2"); } while (0)
#define VPORTOUT_51_251  do { __asm__ volatile ("SBI 0x06, 3"); } while (0)
#define VPORTOUT_52_251  do { __asm__ volatile ("SBI 0x06, 4"); } while (0)
#define VPORTOUT_53_251  do { __asm__ volatile ("SBI 0x06, 5"); } while (0)
#define VPORTOUT_54_251  do { __asm__ volatile ("SBI 0x06, 6"); } while (0)
#define VPORTOUT_55_251  do { __asm__ volatile ("SBI 0x06, 7"); } while (0)

#define VPORTOUT_80_251  do { __asm__ volatile ("SBI 0x0A, 0"); } while (0)
#define VPORTOUT_81_251  do { __asm__ volatile ("SBI 0x0A, 1"); } while (0)
#define VPORTOUT_82_251  do { __asm__ volatile ("SBI 0x0A, 2"); } while (0)
#define VPORTOUT_83_251  do { __asm__ volatile ("SBI 0x0A, 3"); } while (0)
#define VPORTOUT_84_251  do { __asm__ volatile ("SBI 0x0A, 4"); } while (0)
#define VPORTOUT_85_251  do { __asm__ volatile ("SBI 0x0A, 5"); } while (0)
#define VPORTOUT_86_251  do { __asm__ volatile ("SBI 0x0A, 6"); } while (0)
#define VPORTOUT_87_251  do { __asm__ volatile ("SBI 0x0A, 7"); } while (0)

#define VPORTOUT_112_251 do { __asm__ volatile ("SBI 0x0E, 0"); } while (0)
#define VPORTOUT_113_251 do { __asm__ volatile ("SBI 0x0E, 1"); } while (0)
#define VPORTOUT_114_251 do { __asm__ volatile ("SBI 0x0E, 2"); } while (0)
#define VPORTOUT_115_251 do { __asm__ volatile ("SBI 0x0E, 3"); } while (0)
#define VPORTOUT_116_251 do { __asm__ volatile ("SBI 0x0E, 4"); } while (0)
#define VPORTOUT_117_251 do { __asm__ volatile ("SBI 0x0E, 5"); } while (0)
#define VPORTOUT_118_251 do { __asm__ volatile ("SBI 0x0E, 6"); } while (0)
#define VPORTOUT_119_251 do { __asm__ volatile ("SBI 0x0E, 7"); } while (0)

#define VPORTOUT_144_251 do { __asm__ volatile ("SBI 0x12, 0"); } while (0)
#define VPORTOUT_145_251 do { __asm__ volatile ("SBI 0x12, 1"); } while (0)
#define VPORTOUT_146_251 do { __asm__ volatile ("SBI 0x12, 2"); } while (0)
#define VPORTOUT_147_251 do { __asm__ volatile ("SBI 0x12, 3"); } while (0)
#define VPORTOUT_148_251 do { __asm__ volatile ("SBI 0x12, 4"); } while (0)
#define VPORTOUT_149_251 do { __asm__ volatile ("SBI 0x12, 5"); } while (0)
#define VPORTOUT_150_251 do { __asm__ volatile ("SBI 0x12, 6"); } while (0)
#define VPORTOUT_151_251 do { __asm__ volatile ("SBI 0x12, 7"); } while (0)

#define VPORTOUT_176_251 do { __asm__ volatile ("SBI 0x16, 0"); } while (0)
#define VPORTOUT_177_251 do { __asm__ volatile ("SBI 0x16, 1"); } while (0)
#define VPORTOUT_178_251 do { __asm__ volatile ("SBI 0x16, 2"); } while (0)
#define VPORTOUT_179_251 do { __asm__ volatile ("SBI 0x16, 3"); } while (0)
#define VPORTOUT_180_251 do { __asm__ volatile ("SBI 0x16, 4"); } while (0)
#define VPORTOUT_181_251 do { __asm__ volatile ("SBI 0x16, 5"); } while (0)
#define VPORTOUT_182_251 do { __asm__ volatile ("SBI 0x16, 6"); } while (0)
#define VPORTOUT_183_251 do { __asm__ volatile ("SBI 0x16, 7"); } while (0)

#define VPORTOUT_208_251 do { __asm__ volatile ("SBI 0x1A, 0"); } while (0)
#define VPORTOUT_209_251 do { __asm__ volatile ("SBI 0x1A, 1"); } while (0)
#define VPORTOUT_210_251 do { __asm__ volatile ("SBI 0x1A, 2"); } while (0)
#define VPORTOUT_211_251 do { __asm__ volatile ("SBI 0x1A, 3"); } while (0)
#define VPORTOUT_212_251 do { __asm__ volatile ("SBI 0x1A, 4"); } while (0)
#define VPORTOUT_213_251 do { __asm__ volatile ("SBI 0x1A, 5"); } while (0)
#define VPORTOUT_214_251 do { __asm__ volatile ("SBI 0x1A, 6"); } while (0)
#define VPORTOUT_215_251 do { __asm__ volatile ("SBI 0x1A, 7"); } while (0)

#define VPORTOUT__
#define VPORTOUT__0
#define VPORTOUT__254
#define VPORTOUT__251
#define VPORTOUT_255_
#define VPORTOUT_255_0
#define VPORTOUT_255_254
#define VPORTOUT_255_251

/*
 * digitalReadMacro(PIN) macro
 */
#define digitalReadMacro(PIN) __CONCAT3(VPORTIN_,PIN,_)

// digitalReadMacro(PIN) -> VPORTx.IN & PINn_bm
#define VPORTIN_16_  (VPORTA_IN & PIN0_bm)
#define VPORTIN_17_  (VPORTA_IN & PIN1_bm)
#define VPORTIN_18_  (VPORTA_IN & PIN2_bm)
#define VPORTIN_19_  (VPORTA_IN & PIN3_bm)
#define VPORTIN_20_  (VPORTA_IN & PIN4_bm)
#define VPORTIN_21_  (VPORTA_IN & PIN5_bm)
#define VPORTIN_22_  (VPORTA_IN & PIN6_bm)
#define VPORTIN_23_  (VPORTA_IN & PIN7_bm)

#define VPORTIN_48_  (VPORTB_IN & PIN0_bm)
#define VPORTIN_49_  (VPORTB_IN & PIN1_bm)
#define VPORTIN_50_  (VPORTB_IN & PIN2_bm)
#define VPORTIN_51_  (VPORTB_IN & PIN3_bm)
#define VPORTIN_52_  (VPORTB_IN & PIN4_bm)
#define VPORTIN_53_  (VPORTB_IN & PIN5_bm)
#define VPORTIN_54_  (VPORTB_IN & PIN6_bm)
#define VPORTIN_55_  (VPORTB_IN & PIN7_bm)

#define VPORTIN_80_  (VPORTC_IN & PIN0_bm)
#define VPORTIN_81_  (VPORTC_IN & PIN1_bm)
#define VPORTIN_82_  (VPORTC_IN & PIN2_bm)
#define VPORTIN_83_  (VPORTC_IN & PIN3_bm)
#define VPORTIN_84_  (VPORTC_IN & PIN4_bm)
#define VPORTIN_85_  (VPORTC_IN & PIN5_bm)
#define VPORTIN_86_  (VPORTC_IN & PIN6_bm)
#define VPORTIN_87_  (VPORTC_IN & PIN7_bm)

#define VPORTIN_112_ (VPORTD_IN & PIN0_bm)
#define VPORTIN_113_ (VPORTD_IN & PIN1_bm)
#define VPORTIN_114_ (VPORTD_IN & PIN2_bm)
#define VPORTIN_115_ (VPORTD_IN & PIN3_bm)
#define VPORTIN_116_ (VPORTD_IN & PIN4_bm)
#define VPORTIN_117_ (VPORTD_IN & PIN5_bm)
#define VPORTIN_118_ (VPORTD_IN & PIN6_bm)
#define VPORTIN_119_ (VPORTD_IN & PIN7_bm)

#define VPORTIN_144_ (VPORTE_IN & PIN0_bm)
#define VPORTIN_145_ (VPORTE_IN & PIN1_bm)
#define VPORTIN_146_ (VPORTE_IN & PIN2_bm)
#define VPORTIN_147_ (VPORTE_IN & PIN3_bm)
#define VPORTIN_148_ (VPORTE_IN & PIN4_bm)
#define VPORTIN_149_ (VPORTE_IN & PIN5_bm)
#define VPORTIN_150_ (VPORTE_IN & PIN6_bm)
#define VPORTIN_151_ (VPORTE_IN & PIN7_bm)

#define VPORTIN_176_ (VPORTF_IN & PIN0_bm)
#define VPORTIN_177_ (VPORTF_IN & PIN1_bm)
#define VPORTIN_178_ (VPORTF_IN & PIN2_bm)
#define VPORTIN_179_ (VPORTF_IN & PIN3_bm)
#define VPORTIN_180_ (VPORTF_IN & PIN4_bm)
#define VPORTIN_181_ (VPORTF_IN & PIN5_bm)
#define VPORTIN_182_ (VPORTF_IN & PIN6_bm)
#define VPORTIN_183_ (VPORTF_IN & PIN7_bm)

#define VPORTIN_208_ (VPORTG_IN & PIN0_bm)
#define VPORTIN_209_ (VPORTG_IN & PIN1_bm)
#define VPORTIN_210_ (VPORTG_IN & PIN2_bm)
#define VPORTIN_211_ (VPORTG_IN & PIN3_bm)
#define VPORTIN_212_ (VPORTG_IN & PIN4_bm)
#define VPORTIN_213_ (VPORTG_IN & PIN5_bm)
#define VPORTIN_214_ (VPORTG_IN & PIN6_bm)
#define VPORTIN_215_ (VPORTG_IN & PIN7_bm)

#define VPORTIN__
#define VPORTIN_255_

/*
 * openDrainWriteMacro(PIN,LOW|HIGH|TOGGLE) macro
 */
#define openDrainWriteMacro(PIN,OUT) __CONCAT4(VPORTCHG_,PIN,_,OUT)

// openDrainWriteMacro(PIN,LOW) -> pinModeMacro(PIN,OUTPUT) -> SBI VPORTx.DIR, y
#define VPORTCHG_16_0  do { __asm__ volatile ("SBI 0x00, 0"); } while (0)
#define VPORTCHG_17_0  do { __asm__ volatile ("SBI 0x00, 1"); } while (0)
#define VPORTCHG_18_0  do { __asm__ volatile ("SBI 0x00, 2"); } while (0)
#define VPORTCHG_19_0  do { __asm__ volatile ("SBI 0x00, 3"); } while (0)
#define VPORTCHG_20_0  do { __asm__ volatile ("SBI 0x00, 4"); } while (0)
#define VPORTCHG_21_0  do { __asm__ volatile ("SBI 0x00, 5"); } while (0)
#define VPORTCHG_22_0  do { __asm__ volatile ("SBI 0x00, 6"); } while (0)
#define VPORTCHG_23_0  do { __asm__ volatile ("SBI 0x00, 7"); } while (0)

#define VPORTCHG_48_0  do { __asm__ volatile ("SBI 0x04, 0"); } while (0)
#define VPORTCHG_49_0  do { __asm__ volatile ("SBI 0x04, 1"); } while (0)
#define VPORTCHG_50_0  do { __asm__ volatile ("SBI 0x04, 2"); } while (0)
#define VPORTCHG_51_0  do { __asm__ volatile ("SBI 0x04, 3"); } while (0)
#define VPORTCHG_52_0  do { __asm__ volatile ("SBI 0x04, 4"); } while (0)
#define VPORTCHG_53_0  do { __asm__ volatile ("SBI 0x04, 5"); } while (0)
#define VPORTCHG_54_0  do { __asm__ volatile ("SBI 0x04, 6"); } while (0)
#define VPORTCHG_55_0  do { __asm__ volatile ("SBI 0x04, 7"); } while (0)

#define VPORTCHG_80_0  do { __asm__ volatile ("SBI 0x08, 0"); } while (0)
#define VPORTCHG_81_0  do { __asm__ volatile ("SBI 0x08, 1"); } while (0)
#define VPORTCHG_82_0  do { __asm__ volatile ("SBI 0x08, 2"); } while (0)
#define VPORTCHG_83_0  do { __asm__ volatile ("SBI 0x08, 3"); } while (0)
#define VPORTCHG_84_0  do { __asm__ volatile ("SBI 0x08, 4"); } while (0)
#define VPORTCHG_85_0  do { __asm__ volatile ("SBI 0x08, 5"); } while (0)
#define VPORTCHG_86_0  do { __asm__ volatile ("SBI 0x08, 6"); } while (0)
#define VPORTCHG_87_0  do { __asm__ volatile ("SBI 0x08, 7"); } while (0)

#define VPORTCHG_112_0 do { __asm__ volatile ("SBI 0x0C, 0"); } while (0)
#define VPORTCHG_113_0 do { __asm__ volatile ("SBI 0x0C, 1"); } while (0)
#define VPORTCHG_114_0 do { __asm__ volatile ("SBI 0x0C, 2"); } while (0)
#define VPORTCHG_115_0 do { __asm__ volatile ("SBI 0x0C, 3"); } while (0)
#define VPORTCHG_116_0 do { __asm__ volatile ("SBI 0x0C, 4"); } while (0)
#define VPORTCHG_117_0 do { __asm__ volatile ("SBI 0x0C, 5"); } while (0)
#define VPORTCHG_118_0 do { __asm__ volatile ("SBI 0x0C, 6"); } while (0)
#define VPORTCHG_119_0 do { __asm__ volatile ("SBI 0x0C, 7"); } while (0)

#define VPORTCHG_144_0 do { __asm__ volatile ("SBI 0x10, 0"); } while (0)
#define VPORTCHG_145_0 do { __asm__ volatile ("SBI 0x10, 1"); } while (0)
#define VPORTCHG_146_0 do { __asm__ volatile ("SBI 0x10, 2"); } while (0)
#define VPORTCHG_147_0 do { __asm__ volatile ("SBI 0x10, 3"); } while (0)
#define VPORTCHG_148_0 do { __asm__ volatile ("SBI 0x10, 4"); } while (0)
#define VPORTCHG_149_0 do { __asm__ volatile ("SBI 0x10, 5"); } while (0)
#define VPORTCHG_150_0 do { __asm__ volatile ("SBI 0x10, 6"); } while (0)
#define VPORTCHG_151_0 do { __asm__ volatile ("SBI 0x10, 7"); } while (0)

#define VPORTCHG_176_0 do { __asm__ volatile ("SBI 0x14, 0"); } while (0)
#define VPORTCHG_177_0 do { __asm__ volatile ("SBI 0x14, 1"); } while (0)
#define VPORTCHG_178_0 do { __asm__ volatile ("SBI 0x14, 2"); } while (0)
#define VPORTCHG_179_0 do { __asm__ volatile ("SBI 0x14, 3"); } while (0)
#define VPORTCHG_180_0 do { __asm__ volatile ("SBI 0x14, 4"); } while (0)
#define VPORTCHG_181_0 do { __asm__ volatile ("SBI 0x14, 5"); } while (0)
#define VPORTCHG_182_0 do { __asm__ volatile ("SBI 0x14, 6"); } while (0)
#define VPORTCHG_183_0 do { __asm__ volatile ("SBI 0x14, 7"); } while (0)

#define VPORTCHG_208_0 do { __asm__ volatile ("SBI 0x18, 0"); } while (0)
#define VPORTCHG_209_0 do { __asm__ volatile ("SBI 0x18, 1"); } while (0)
#define VPORTCHG_210_0 do { __asm__ volatile ("SBI 0x18, 2"); } while (0)
#define VPORTCHG_211_0 do { __asm__ volatile ("SBI 0x18, 3"); } while (0)
#define VPORTCHG_212_0 do { __asm__ volatile ("SBI 0x18, 4"); } while (0)
#define VPORTCHG_213_0 do { __asm__ volatile ("SBI 0x18, 5"); } while (0)
#define VPORTCHG_214_0 do { __asm__ volatile ("SBI 0x18, 6"); } while (0)
#define VPORTCHG_215_0 do { __asm__ volatile ("SBI 0x18, 7"); } while (0)

#define VPORTCHG__
#define VPORTCHG__0
#define VPORTCHG_255_
#define VPORTCHG_255_0

// openDrainWriteMacro(PIN,HIGH) -> pinModeMacro(PIN,INPUT) -> CBI VPORTx.DIR, y
#define VPORTCHG_16_254  do { __asm__ volatile ("CBI 0x00, 0"); } while (0)
#define VPORTCHG_17_254  do { __asm__ volatile ("CBI 0x00, 1"); } while (0)
#define VPORTCHG_18_254  do { __asm__ volatile ("CBI 0x00, 2"); } while (0)
#define VPORTCHG_19_254  do { __asm__ volatile ("CBI 0x00, 3"); } while (0)
#define VPORTCHG_20_254  do { __asm__ volatile ("CBI 0x00, 4"); } while (0)
#define VPORTCHG_21_254  do { __asm__ volatile ("CBI 0x00, 5"); } while (0)
#define VPORTCHG_22_254  do { __asm__ volatile ("CBI 0x00, 6"); } while (0)
#define VPORTCHG_23_254  do { __asm__ volatile ("CBI 0x00, 7"); } while (0)

#define VPORTCHG_48_254  do { __asm__ volatile ("CBI 0x04, 0"); } while (0)
#define VPORTCHG_49_254  do { __asm__ volatile ("CBI 0x04, 1"); } while (0)
#define VPORTCHG_50_254  do { __asm__ volatile ("CBI 0x04, 2"); } while (0)
#define VPORTCHG_51_254  do { __asm__ volatile ("CBI 0x04, 3"); } while (0)
#define VPORTCHG_52_254  do { __asm__ volatile ("CBI 0x04, 4"); } while (0)
#define VPORTCHG_53_254  do { __asm__ volatile ("CBI 0x04, 5"); } while (0)
#define VPORTCHG_54_254  do { __asm__ volatile ("CBI 0x04, 6"); } while (0)
#define VPORTCHG_55_254  do { __asm__ volatile ("CBI 0x04, 7"); } while (0)

#define VPORTCHG_80_254  do { __asm__ volatile ("CBI 0x08, 0"); } while (0)
#define VPORTCHG_81_254  do { __asm__ volatile ("CBI 0x08, 1"); } while (0)
#define VPORTCHG_82_254  do { __asm__ volatile ("CBI 0x08, 2"); } while (0)
#define VPORTCHG_83_254  do { __asm__ volatile ("CBI 0x08, 3"); } while (0)
#define VPORTCHG_84_254  do { __asm__ volatile ("CBI 0x08, 4"); } while (0)
#define VPORTCHG_85_254  do { __asm__ volatile ("CBI 0x08, 5"); } while (0)
#define VPORTCHG_86_254  do { __asm__ volatile ("CBI 0x08, 6"); } while (0)
#define VPORTCHG_87_254  do { __asm__ volatile ("CBI 0x08, 7"); } while (0)

#define VPORTCHG_112_254 do { __asm__ volatile ("CBI 0x0C, 0"); } while (0)
#define VPORTCHG_113_254 do { __asm__ volatile ("CBI 0x0C, 1"); } while (0)
#define VPORTCHG_114_254 do { __asm__ volatile ("CBI 0x0C, 2"); } while (0)
#define VPORTCHG_115_254 do { __asm__ volatile ("CBI 0x0C, 3"); } while (0)
#define VPORTCHG_116_254 do { __asm__ volatile ("CBI 0x0C, 4"); } while (0)
#define VPORTCHG_117_254 do { __asm__ volatile ("CBI 0x0C, 5"); } while (0)
#define VPORTCHG_118_254 do { __asm__ volatile ("CBI 0x0C, 6"); } while (0)
#define VPORTCHG_119_254 do { __asm__ volatile ("CBI 0x0C, 7"); } while (0)

#define VPORTCHG_144_254 do { __asm__ volatile ("CBI 0x10, 0"); } while (0)
#define VPORTCHG_145_254 do { __asm__ volatile ("CBI 0x10, 1"); } while (0)
#define VPORTCHG_146_254 do { __asm__ volatile ("CBI 0x10, 2"); } while (0)
#define VPORTCHG_147_254 do { __asm__ volatile ("CBI 0x10, 3"); } while (0)
#define VPORTCHG_148_254 do { __asm__ volatile ("CBI 0x10, 4"); } while (0)
#define VPORTCHG_149_254 do { __asm__ volatile ("CBI 0x10, 5"); } while (0)
#define VPORTCHG_150_254 do { __asm__ volatile ("CBI 0x10, 6"); } while (0)
#define VPORTCHG_151_254 do { __asm__ volatile ("CBI 0x10, 7"); } while (0)

#define VPORTCHG_176_254 do { __asm__ volatile ("CBI 0x14, 0"); } while (0)
#define VPORTCHG_177_254 do { __asm__ volatile ("CBI 0x14, 1"); } while (0)
#define VPORTCHG_178_254 do { __asm__ volatile ("CBI 0x14, 2"); } while (0)
#define VPORTCHG_179_254 do { __asm__ volatile ("CBI 0x14, 3"); } while (0)
#define VPORTCHG_180_254 do { __asm__ volatile ("CBI 0x14, 4"); } while (0)
#define VPORTCHG_181_254 do { __asm__ volatile ("CBI 0x14, 5"); } while (0)
#define VPORTCHG_182_254 do { __asm__ volatile ("CBI 0x14, 6"); } while (0)
#define VPORTCHG_183_254 do { __asm__ volatile ("CBI 0x14, 7"); } while (0)

#define VPORTCHG_208_254 do { __asm__ volatile ("CBI 0x18, 0"); } while (0)
#define VPORTCHG_209_254 do { __asm__ volatile ("CBI 0x18, 1"); } while (0)
#define VPORTCHG_210_254 do { __asm__ volatile ("CBI 0x18, 2"); } while (0)
#define VPORTCHG_211_254 do { __asm__ volatile ("CBI 0x18, 3"); } while (0)
#define VPORTCHG_212_254 do { __asm__ volatile ("CBI 0x18, 4"); } while (0)
#define VPORTCHG_213_254 do { __asm__ volatile ("CBI 0x18, 5"); } while (0)
#define VPORTCHG_214_254 do { __asm__ volatile ("CBI 0x18, 6"); } while (0)
#define VPORTCHG_215_254 do { __asm__ volatile ("CBI 0x18, 7"); } while (0)

#define VPORTCHG__
#define VPORTCHG__254
#define VPORTCHG_255_254

// openDrainWriteMacro(PIN,TOGGLE) -> PORTx.DIRTGL = PINn_bm
#define VPORTCHG_16_251  do { PORTA_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_17_251  do { PORTA_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_18_251  do { PORTA_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_19_251  do { PORTA_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_20_251  do { PORTA_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_21_251  do { PORTA_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_22_251  do { PORTA_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_23_251  do { PORTA_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_48_251  do { PORTB_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_49_251  do { PORTB_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_50_251  do { PORTB_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_51_251  do { PORTB_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_52_251  do { PORTB_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_53_251  do { PORTB_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_54_251  do { PORTB_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_55_251  do { PORTB_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_80_251  do { PORTC_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_81_251  do { PORTC_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_82_251  do { PORTC_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_83_251  do { PORTC_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_84_251  do { PORTC_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_85_251  do { PORTC_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_86_251  do { PORTC_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_87_251  do { PORTC_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_112_251 do { PORTD_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_113_251 do { PORTD_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_114_251 do { PORTD_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_115_251 do { PORTD_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_116_251 do { PORTD_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_117_251 do { PORTD_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_118_251 do { PORTD_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_119_251 do { PORTD_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_144_251 do { PORTE_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_145_251 do { PORTE_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_146_251 do { PORTE_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_147_251 do { PORTE_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_148_251 do { PORTE_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_149_251 do { PORTE_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_150_251 do { PORTE_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_151_251 do { PORTE_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_176_251 do { PORTF_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_177_251 do { PORTF_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_178_251 do { PORTF_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_179_251 do { PORTF_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_180_251 do { PORTF_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_181_251 do { PORTF_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_182_251 do { PORTF_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_183_251 do { PORTF_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG_208_251 do { PORTG_DIRTGL = PIN0_bm; } while (0)
#define VPORTCHG_209_251 do { PORTG_DIRTGL = PIN1_bm; } while (0)
#define VPORTCHG_210_251 do { PORTG_DIRTGL = PIN2_bm; } while (0)
#define VPORTCHG_211_251 do { PORTG_DIRTGL = PIN3_bm; } while (0)
#define VPORTCHG_212_251 do { PORTG_DIRTGL = PIN4_bm; } while (0)
#define VPORTCHG_213_251 do { PORTG_DIRTGL = PIN5_bm; } while (0)
#define VPORTCHG_214_251 do { PORTG_DIRTGL = PIN6_bm; } while (0)
#define VPORTCHG_215_251 do { PORTG_DIRTGL = PIN7_bm; } while (0)

#define VPORTCHG__
#define VPORTCHG__251
#define VPORTCHG_255_251

#endif

// end of code
