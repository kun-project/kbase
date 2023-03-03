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

// compiler
#ifndef KUN_COMPILER_GCC
    #define KUN_COMPILER_GCC 0
#endif
#ifndef KUN_COMPILER_MSVC
    #define KUN_COMPILER_MSVC 0
#endif
#ifndef KUN_COMPILER_CLANG
    #define KUN_COMPILER_CLANG 0
#endif
#ifndef KUN_COMPILER_CLANG_CL
    #define KUN_COMPILER_CLANG_CL 0
#endif

// cxx version
#ifndef KUN_CXX_11
    #define KUN_CXX_11 0
#endif
#ifndef KUN_CXX_14
    #define KUN_CXX_14 0
#endif
#ifndef KUN_CXX_17
    #define KUN_CXX_17 0
#endif
#ifndef KUN_CXX_20
    #define KUN_CXX_20 0
#endif
#ifndef KUN_CXX_VER
    #define KUN_CXX_VER 0
#endif