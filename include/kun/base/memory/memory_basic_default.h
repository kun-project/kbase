#pragma once
#include "kun/base/memory/memory_baisc.h"

#ifndef KUN_IMPL_MEMORY_FUNCS

    #include <memory.h>

namespace kun::memory
{
KUN_INLINE void free(void* p)
{
    #if KUN_PLAT_WINDOWS
    ::_aligned_free(p);
    #else
        #error default impl of memory only support on windows, please impl it manually
    #endif
}
KUN_INLINE void* malloc(Size n, Size alignment)
{
    #if KUN_PLAT_WINDOWS
    return ::_aligned_malloc(n, alignment);
    #else
        #error default impl of memory only support on windows, please impl it manually
    #endif
}
KUN_INLINE void* realloc(void* p, Size n, Size alignment)
{
    #if KUN_PLAT_WINDOWS
    return ::_aligned_realloc(p, n, alignment);
    #else
        #error default impl of memory only support on windows, please impl it manually
    #endif
}

KUN_INLINE void* memcpy(void* dst, const void* src, Size size) { return ::memcpy(dst, src, size); }
KUN_INLINE void* memmove(void* dst, const void* src, Size size) { return ::memmove(dst, src, size); }
KUN_INLINE i32   memcmp(const void* buf1, const void* buf2, Size size) { return ::memcmp(buf1, buf2, size); }
KUN_INLINE void* memset(void* dst, u8 ch, Size size) { return ::memset(dst, ch, size); }
KUN_INLINE void* memzero(void* dst, Size size) { return memset(dst, 0, size); }
}// namespace kun::memory

#endif