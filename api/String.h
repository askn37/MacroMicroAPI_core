/**
 * @file String.h
 * @author askn (K.Sato) multix.jp
 * @brief Strung subclass
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <avr/pgmspace.h>

#ifdef __cplusplus

class PGM_t;
#define F(pmem_str) (reinterpret_cast<const PGM_t *>(PSTR(pmem_str)))
#define P(pmem_ptr) (reinterpret_cast<const PGM_t *>(pmem_ptr))

#endif

// end of code
