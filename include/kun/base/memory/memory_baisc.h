#pragma once
#include "kun/base/config.h"
#include "kun/base/types.h"

// memory functions def
namespace kun::memory
{
// alignment
inline constexpr Size DEFAULT_ALIGNMENT = sizeof(Size);

KUN_INLINE void  free(void* p);
KUN_INLINE void* malloc(Size n, Size alignment = DEFAULT_ALIGNMENT);
KUN_INLINE void* realloc(void* p, Size n, Size alignment = DEFAULT_ALIGNMENT);

KUN_INLINE void* memcpy(void* dst, const void* src, Size size);
KUN_INLINE void* memmove(void* dst, const void* src, Size size);
KUN_INLINE i32   memcmp(const void* buf1, const void* buf2, Size size);
KUN_INLINE void* memset(void* dst, u8 ch, Size size);
KUN_INLINE void* memzero(void* dst, Size size);
}// namespace kun::memory

// default impl
#ifndef KUN_IMPL_MEMORY_FUNCS
    #include <memory.h>
namespace kun::memory
{
KUN_INLINE void free(void* p)
{
    #if defined(KUN_PLATFORM_WINDOWS)
    ::_aligned_free(p);
    #else
        #error default impl only support on windows, please impl it manually
    #endif
}
KUN_INLINE void* malloc(Size n, Size alignment)
{
    #if defined(KUN_PLATFORM_WINDOWS)
    return ::_aligned_malloc(n, alignment);
    #else
        #error default impl only support on windows, please impl it manually
    #endif
}
KUN_INLINE void* realloc(void* p, Size n, Size alignment)
{
    #if defined(KUN_PLATFORM_WINDOWS)
    return ::_aligned_realloc(p, n, alignment);
    #else
        #error default impl only support on windows, please impl it manually
    #endif
}

KUN_INLINE void* memcpy(void* dst, const void* src, Size size) { return ::memcpy(dst, src, size); }
KUN_INLINE void* memmove(void* dst, const void* src, Size size) { return ::memmove(dst, src, size); }
KUN_INLINE i32   memcmp(const void* buf1, const void* buf2, Size size) { return ::memcmp(buf1, buf2, size); }
KUN_INLINE void* memset(void* dst, u8 ch, Size size) { return ::memset(dst, ch, size); }
KUN_INLINE void* memzero(void* dst, Size size) { return memset(dst, 0, size); }
}// namespace kun::memory
#endif