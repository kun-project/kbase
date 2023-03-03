#pragma once
//-------------------------------------------------------------------------------
// -> compiler
//      KUN_COMPILER_GCC
//      KUN_COMPILER_MSVC
//      KUN_COMPILER_CLANG
//      KUN_COMPILER_CLANG_CL
//
// -> cxx version
//      KUN_CXX_11
//      KUN_CXX_14
//      KUN_CXX_17
//      KUN_CXX_20
//      KUN_CXX_VER
//
//-------------------------------------------------------------------------------

#include "platform.h"

// compiler def
#if defined(__clang__) && !defined(_MSC_VER)
    #define KUN_COMPILER_CLANG 1
#elif defined(__GNUC__)
    #define KUN_COMPILER_GCC 1
#elif defined(_MSC_VER)
    #if defined(__clang__)
        #define KUN_COMPILER_CLANG_CL 1
    #else
        #define KUN_COMPILER_MSVC 1
    #endif
#endif

// cxx 11
#if !defined(KUN_CXX_11) && defined(__cplusplus)
    #if (__cplusplus >= 201103L)
        #define KUN_CXX_11 1
    #elif defined(__GNUC__) && defined(__GXX_EXPERIMENTAL_CXX0X__)
        #define KUN_CXX_11 1
    #elif defined(_MSC_VER) && _MSC_VER >= 1600
        #define KUN_CXX_11 1
    #endif
#endif

// cxx 14
#if !defined(KUN_CXX_14) && defined(__cplusplus)
    #if (__cplusplus >= 201402L)
        #define KUN_CXX_14 1
    #elif defined(_MSC_VER) && (_MSC_VER >= 1900)
        #define KUN_CXX_14 1
    #endif
#endif

// cxx 17
#if !defined(KUN_CXX_17) && defined(__cplusplus)
    #if (__cplusplus >= 201703L)
        #define KUN_CXX_17 1
    #elif defined(_MSVC_LANG) && (_MSVC_LANG >= 201703L)
        #define KUN_CXX_17 1
    #endif
#endif

// cxx 20
#if !defined(KUN_CXX_20) && defined(__cplusplus)
    #if (__cplusplus >= 202002L)
        #define KUN_CXX_20 1
    #elif defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L)
        #define KUN_CXX_20 1
    #endif
#endif

// cxx version
#if defined(KUN_CXX_20)
    #define KUN_CXX_VER 20
#elif defined(KUN_CXX_17)
    #define KUN_CXX_VER 17
#elif defined(KUN_CXX_14)
    #define KUN_CXX_VER 14
    #error unsupport cpp version, must be 17+
#elif defined(KUN_CXX_11)
    #define KUN_CXX_VER 11
    #error unsupport cpp version, must be 17+
#else
    #error unknown cpp version
#endif

// fall back
#include "compiler_fallback.inc"
