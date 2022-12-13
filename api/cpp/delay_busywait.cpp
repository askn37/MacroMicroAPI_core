/**
 * @file delay_busywait.h
 * @author askn (K.Sato) multix.jp
 * @brief delay busywait
 * @version 0.1
 * @date 2022-09-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../delay_busywait.h"

void _busy_loop_3_8 (uint8_t _count) {
  __asm__ __volatile__ (
    "1: DEC %0 \n"
    "BRNE 1b"
    : "=r" (_count)
    : "0" (_count)
  );
}

void _busy_loop_4_8 (uint8_t _count) {
  __asm__ __volatile__ (
    "1: DEC %0 \n"
    "NOP \n"
    "BRNE 1b"
    : "=r" (_count)
    : "0" (_count)
  );
}

void _busy_loop_4_16 (uint16_t _count) {
  __asm__ __volatile__ (
    "1: SUBI %A0, 1 \n"
        "SBCI %B0, 0 \n"
    "BRNE 1b"
    : "=d" (_count)
    : "0" (_count)
  );
}

void _busy_loop_5_16 (uint16_t _count) {
  __asm__ __volatile__ (
    "1: SUBI %A0, 1 \n"
        "SBCI %B0, 0 \n"
    "NOP \n"
    "BRNE 1b"
    : "=d" (_count)
    : "0" (_count)
  );
}

// end of code
