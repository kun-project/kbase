#pragma once
//-------------------------------------------------------------------------------
// -> util marco
//      KUN_EXPORT
//      KUN_IMPORT
//      KUN_INLINE
//      KUN_DBG_LEVEL
//
// -> type marco
//      KUN_CUSTOM_REAL
//
//-------------------------------------------------------------------------------
#include "config/platform.h"
#include "config/compiler.h"

// dllexport
#if defined(KUN_COMPILER_GCC) || defined(KUN_COMPILER_CLANG) || defined(KUN_COMPILER_CLANG_CL)
    #define KUN_EXPORT __attribute__((dllexport))
#elif defined(KUN_COMPILER_MSVC)
    #define KUN_EXPORT __declspec(dllexport)
#else
    #error unsupport dll export
#endif

// dllimport
#if defined(KUN_COMPILER_GCC) || defined(KUN_COMPILER_CLANG) || defined(KUN_COMPILER_CLANG_CL)
    #define KUN_IMPORT __attribute__((dllimport))
#elif defined(KUN_COMPILER_MSVC)
    #define KUN_IMPORT __declspec(dllimport)
#else
    #error unsupport dll import
#endif

// inline
#ifndef KUN_INLINE
    #if defined(KUN_COMPILER_GCC) || defined(KUN_COMPILER_CLANG)
        #define KUN_INLINE __attribute__((always_inline)) inline
    #elif defined(KUN_COMPILER_MSVC)
        #define KUN_INLINE __forceinline
    #else
        #define KUN_INLINE inline
    #endif
#endif

// debug level
// we use debug marco mark fatal error
// for Assert, we must never leave it to release version, Assert() will be hit when developer make some stupid mistakes
// for Verify, we should take care and try our best to fix it before release, but we still can find them in log for debug
// for some problems that can resume or not enough to cause program crash, we use cpp exception to handle it
//         |       KUN_Verify        |  KUN_Assert
// level 0 |       log error         |    none
// level 1 | debug break & log error |    abort
#ifndef KUN_DBG_LEVEL
    #define KUN_DBG_LEVEL 0
#endif

// custom real
// #define KUN_CUSTOM_REAL
// using real = float;
