#pragma once
#include "kun/base/config.h"
#include "kun/base/types.h"

// memory functions def
namespace kun::memory
{
// alignment
inline constexpr Size DEFAULT_ALIGNMENT = sizeof(Size);

void  free(void* p);
void* malloc(Size n, Size alignment = DEFAULT_ALIGNMENT);
void* realloc(void* p, Size n, Size alignment = DEFAULT_ALIGNMENT);

void* memcpy(void* dst, const void* src, Size size);
void* memmove(void* dst, const void* src, Size size);
i32   memcmp(const void* buf1, const void* buf2, Size size);
void* memset(void* dst, u8 ch, Size size);
void* memzero(void* dst, Size size);
}// namespace kun::memory
