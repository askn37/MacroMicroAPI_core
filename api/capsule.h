/**
 * @file capsule.h
 * @author askn (K.Sato) multix.jp
 * @brief typedef union capsule
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
// MIT License : https://askn37.github.io/LICENSE.html

#pragma once
// #include <api/capsule.h>

typedef union {
  uint8_t  *bptr;
  uint16_t *wptr;
  uint16_t word;
  uint8_t  bytes[2];
} capsule16_t;

typedef union {
  uint8_t  *bptrs[2];
  uint16_t *wptrs[2];
  uint32_t *dptrs[2];
  uint32_t dword;
  uint16_t words[2];
  uint8_t  bytes[4];
} capsule32_t;

typedef union {
  uint8_t  *bptrs[4];
  uint16_t *wptrs[4];
  uint32_t *dptrs[4];
  uint64_t qword;
  uint32_t dwords[2];
  uint16_t words[4];
  uint8_t  bytes[8];
} capsule64_t;

#define _CAPS16(p) ((capsule16_t*)(&p))
#define _CAPS32(p) ((capsule32_t*)(&p))
#define _CAPS64(p) ((capsule64_t*)(&p))

// end of code
