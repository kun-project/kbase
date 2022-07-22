#pragma once
#include "kun/config.h"
#include "kun/types.h"

// memory backend def
namespace kun::memory
{
// memory backend
class IMemoryBackend
{
public:
    virtual ~IMemoryBackend() = default;

    // alloc
    virtual void  free(void* p) = 0;
    virtual void* malloc(Size n, Size alignment) = 0;
    virtual void* realloc(void* p, Size n, Size alignment) = 0;
    virtual void* malloc(Size n, Size alignment, Size offset) = 0;
    virtual void* realloc(void* p, Size n, Size alignment, Size offset) = 0;

    // memory ops
    virtual void* memcpy(void* dst, const void* src, Size size) = 0;
    virtual void* memmove(void* dst, const void* src, Size size) = 0;
    virtual i32   memcmp(const void* buf1, const void* buf2, Size size) = 0;
    virtual void* memset(void* dst, u8 ch, Size size) = 0;
    virtual void* memzero(void* dst, Size size) = 0;
};
}// namespace kun::memory

// memory backend function
namespace kun::backend
{
extern ::kun::memory::IMemoryBackend* memoryBackend();
}

// help functions
namespace kun::memory
{
// alignment
enum
{
    DEFAULT_ALIGNMENT = 4
};

KUN_INLINE void  free(void* p) { ::kun::backend::memoryBackend()->free(p); }
KUN_INLINE void* malloc(Size n, Size alignment = DEFAULT_ALIGNMENT) { return ::kun::backend::memoryBackend()->malloc(n, alignment); }
KUN_INLINE void* realloc(void* p, Size n, Size alignment = DEFAULT_ALIGNMENT) { return ::kun::backend::memoryBackend()->realloc(p, n, alignment); }
KUN_INLINE void* malloc(Size n, Size alignment, Size offset) { return ::kun::backend::memoryBackend()->malloc(n, alignment, offset); }
KUN_INLINE void* realloc(void* p, Size n, Size alignment, Size offset) { return ::kun::backend::memoryBackend()->realloc(p, n, alignment, offset); }

KUN_INLINE void* memcpy(void* dst, const void* src, Size size) { return ::kun::backend::memoryBackend()->memcpy(dst, src, size); }
KUN_INLINE void* memmove(void* dst, const void* src, Size size) { return ::kun::backend::memoryBackend()->memmove(dst, src, size); }
KUN_INLINE i32   memcmp(const void* buf1, const void* buf2, Size size) { return ::kun::backend::memoryBackend()->memcmp(buf1, buf2, size); }
KUN_INLINE void* memset(void* dst, u8 ch, Size size) { return ::kun::backend::memoryBackend()->memset(dst, ch, size); }
KUN_INLINE void* memzero(void* dst, Size size) { return ::kun::backend::memoryBackend()->memzero(dst, size); }
}// namespace kun::memory