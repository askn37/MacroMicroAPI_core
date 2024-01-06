/**
 * @file new.h
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
#pragma once
#ifdef __cplusplus
#include <stdlib.h>

void * operator new      (size_t size);
void * operator new[]    (size_t size);
void   operator delete   (void * ptr) noexcept;
void   operator delete[] (void * ptr) noexcept;

/* C++11 support */
void * operator new      (size_t size, void * ptr) noexcept;
void * operator new[]    (size_t size, void * ptr) noexcept;

/* C++14 support */
#if (__cpp_sized_deallocation >= 201309L)
void   operator delete   (void * ptr, size_t size) noexcept;
void   operator delete[] (void * ptr, size_t size) noexcept;
#endif

#endif
// end of header
