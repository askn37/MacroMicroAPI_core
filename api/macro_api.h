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

/*
 * custom section example
 *
 * const struct struct_t nvm_init_store   PGM_ALIGN ROMEM = { INIT };
 * const struct struct_t nvm_noinit_store PGM_ALIGN NVMEM = {};
 *
 * memcpy_PF(&nvm_buffer, pgm_get_far_address(nvm_store), sizeof(nvm_buffer));
 *
 */

#define NIMEM __attribute__ ((section (".noinit")))
#define ROMEM __attribute__ ((section (".progmem.nvm")))
#define NVMEM __attribute__ ((section (".nvmem")))

#define PGM_ALIGN alignas(PROGMEM_PAGE_SIZE)

/*
 * IMPORT_BINFILE macro example
 *
 * IMPORT_BINFILE(".progmem", __QUOTE(SKETCH_PATH) "/" "foo.bin", FooBin);
 *
 * extern const uint8_t FooBin[], FooBin_end[] PROGMEM;
 * #define _sizeof_FooBin (FooBin_end - FooBin)
 */

#define __DEPLOY__(S) S
#define __DEPLOY(S)   __DEPLOY__(S)

#define __QUOTE__(S)  #S
#define __QUOTE(S)    __QUOTE__(S)

#if (PROGMEM_SIZE >= 512)
  #define __PROGMEM_SIZE_ALIGN__ ".balign 512\n"
#elif (PROGMEM_SIZE >= 256)
  #define __PROGMEM_SIZE_ALIGN__ ".balign 256\n"
#elif (PROGMEM_SIZE >= 128)
  #define __PROGMEM_SIZE_ALIGN__ ".balign 128\n"
#elif (PROGMEM_SIZE >= 64)
  #define __PROGMEM_SIZE_ALIGN__ ".balign 64\n"
#else
  #define __PROGMEM_SIZE_ALIGN__ ".balign 32\n"
#endif
#define PAGE_ALIGN(sect) __asm__ __volatile__ ( \
	".section " #sect "\n" \
	__PROGMEM_SIZE_ALIGN__ \
	".section \".text\"\n")

/* Import a binary file */
#define IMPORT_BINFILE(sect, sym, file) asm (                             \
  ".section " #sect "\n"                  /* Change section */            \
  ".balign 4\n"                           /* Word alignment */            \
  ".global " #sym "\n"                    /* Export the object address */ \
  #sym ":\n"                              /* Define the object label */   \
  ".incbin \"" file "\"\n"                /* Import the file */           \
  ".global " #sym "_end\n"                /* Export the object end */     \
  #sym "_end:\n"                          /* Define the object end */     \
  ".balign 4\n"                           /* Word alignment */            \
  ".section \".text\"\n")                 /* Restore section */

/* Import a part of binary file */
#define IMPORT_BINFILE_PART(sect, sym, file, ofs, siz) asm (              \
  ".section " #sect "\n"                  /* Change section */            \
  ".balign 4\n"                           /* Word alignment */            \
  ".global " #sym "\n"                    /* Export the object address */ \
  #sym ":\n"                              /* Define the object label */   \
  ".incbin \"" file "\"," #ofs "," #siz "\n"                              \
  ".global " #sym "_end\n"                /* Export the object end */     \
  #sym "_end:\n"                          /* Define the object end */     \
  ".balign 4\n"                           /* Word alignment */            \
  ".section \".text\"\n")                 /* Restore section */

#endif  /* ENABLE_MACRO_API */

// end of code
