/**
 * @file new.cpp
 * @author askn (K.Sato) multix.jp
 * @brief
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024 askn37 at github.com
 *
 */
#ifdef __cplusplus
#include <stdlib.h>

void * operator new      (size_t size) { return malloc(size); }
void * operator new[]    (size_t size) { return malloc(size); }
void   operator delete   (void * ptr) { free(ptr); }
void   operator delete[] (void * ptr) { free(ptr); }

/* C++11 support */
void * operator new      (size_t size, void * ptr) noexcept { (void) size; return ptr; }
void * operator new[]    (size_t size, void * ptr) noexcept { (void) size; return ptr; }

/* C++14 support */
#if (__cpp_sized_deallocation >= 201309L)
void   operator delete   (void * ptr, size_t size) noexcept { (void) size; free(ptr); }
void   operator delete[] (void * ptr, size_t size) noexcept { (void) size; free(ptr); }
#endif

#endif
// end of header

