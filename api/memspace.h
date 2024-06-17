/**
 * @file memspace.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2022-12-19
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once

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
#define CODEMEM __attribute__ ((section (".text")))
#define DATAMEM __attribute__ ((section (".data")))
#define PRODSIG __attribute__ ((section (".signature")))
#define USERSIG __attribute__ ((section (".user_signatures")))
#define BOOTSIG __attribute__ ((section (".boot_signatures")))

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

// end of code
