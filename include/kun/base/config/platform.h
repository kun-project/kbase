#pragma once
//-------------------------------------------------------------------------------
// -> platform
//      KUN_PLAT_WIN32
//      KUN_PLAT_WIN64
//
// -> architecture
//      KUN_ARCH_X86
//      KUN_ARCH_X86_64
//
//-------------------------------------------------------------------------------

// windows
#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
    // platform
    #ifdef _WIN64
        #define KUN_PLAT_WIN64 1
    #else
        #define KUN_PLAT_WIN32 1
    #endif

    // architecture
    #if defined(_M_IX86) || defined(_X86_)
        #define KUN_ARCH_X86 1
    #elif defined(_M_AMD64) || defined(_AMD64_) || defined(__x86_64__)
        #define KUN_ARCH_X86_64 1
    #else
        #error Unknown processor
        #error Unknown endianness
    #endif
#endif

#include "platform_fallback.inc"
#define KUN_PLAT_WINDOWS KUN_PLAT_WIN32 || KUN_PLAT_WIN64