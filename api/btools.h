/**
 * @file btools.h
 * @author askn (K.Sato) multix.jp
 * @brief Binary tools
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
#include <inttypes.h>
#include <stddef.h>

#define _PTRB(p) ((int8*)&(p))
#define _PTRW(p) ((int16_t*)&(p))
#define _PTRD(p) ((int32_t*)&(p))
#define _PTRQ(p) ((int64_t*)&(p))

#define _PTR8(p) ((uint8_t*)&(p))
#define _PTR16(p) ((uint16_t*)&(p))
#define _PTR32(p) ((uint32_t*)&(p))
#define _PTR64(p) ((uint64_t*)&(p))

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifdef __cplusplus
extern "C" {
#endif

extern uint16_t wbits (uint8_t _bits);   /* Bit wide expansion */
extern uint8_t bitrev (uint8_t _bits);   /* Bits reverse */

extern uint8_t bswap8 (uint8_t _word);         /* nibble conversion */
extern uint16_t bswap16 (uint16_t _word);      /* endian conversion */
extern uint32_t bswap32 (uint32_t _dword);     /* endian conversion */
extern uint64_t bswap64 (uint64_t _qword);     /* endian conversion */

extern void byterev (void* _ptr, size_t _len); /* Bytes reverse */

extern char btoh (uint8_t _x);
extern uint8_t htob (char _x);
extern uint8_t stob (char _s[]);

extern short map_short (short x, short in_min, short in_max, short out_min, short out_max);
extern long map_long (long x, long in_min, long in_max, long out_min, long out_max);

extern uint8_t csm8 (void* _data, size_t _len);           /* byte CheckSuM (ADD) */
extern uint8_t bcc8 (void* _data, size_t _len);           /* Byte Check Code (XOR) */

extern uint8_t crc8 (void* _data, size_t _len);           /* SMBus PEC */

extern uint8_t crc8_ccitt (void* _data, size_t _len);
extern uint8_t crc8_ibutton (void* _data, size_t _len);   /* Dallas (Maxim) iButton 8-bit */

extern uint8_t crc8_dallas (void* _data, size_t _len);    /* Dallas 1-Wire SENSIRON SH3x */
extern uint8_t _crc_dallas_update (uint8_t _crc, uint8_t _data);

extern uint16_t crc16 (void* _data, size_t _len);
extern uint16_t crc16_ccitt (void* _data, size_t _len);
extern uint16_t crc16_xmodem (void* _data, size_t _len);
extern uint16_t crc16_ccitt_false (void* _data, size_t _len);

extern uint32_t crc32 (void* _data, size_t _len);
extern uint32_t _crc32_update (uint32_t _crc, uint8_t _data);

#ifdef __cplusplus
} // extern "C"
#endif

// end of code
