#pragma once
#include "kun/base/config.h"
#include "kun/base/tools/debugbreak.h"

#define KUN_DEBUG_BREAK() debug_break()

// dump
namespace kun
{
void dumpAssert(const char* assert, const char* message, const char* file, Size line);
void dumpVerify(const char* verify, const char* message, const char* file, Size line);
}// namespace kun

// assert marco
#if KUN_DBG_LEVEL >= 1
    #define KUN_Assert(expr)                                                                                                                         \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpAssert(#expr, nullptr, __FILE__, __LINE__);                                                                                      \
                std::abort();                                                                                                                        \
            }                                                                                                                                        \
        }
    #define KUN_AssertMsg(expr, msg)                                                                                                                 \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpAssert(#expr, msg, __FILE__, __LINE__);                                                                                          \
                std::abort();                                                                                                                        \
            }                                                                                                                                        \
        }
#else
    #define KUN_Assert(expr)
    #define KUN_AssertMsg(expr, msg)
#endif

// verify marco
#if KUN_DBG_LEVEL >= 1
    #define KUN_Verify(expr)                                                                                                                         \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpVerify(#expr, nullptr, __FILE__, __LINE__);                                                                                      \
                KUN_DEBUG_BREAK();                                                                                                                   \
            }                                                                                                                                        \
        }
    #define KUN_Verifyf(expr, fmt, ...)                                                                                                              \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpVerify(#expr, msg, __FILE__, __LINE__);                                                                                          \
                KUN_DEBUG_BREAK();                                                                                                                   \
            }                                                                                                                                        \
        }
#else
    #define KUN_Verify(expr)                                                                                                                         \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpVerify(#expr, nullptr, __FILE__, __LINE__);                                                                                      \
            }                                                                                                                                        \
        }
    #define KUN_VerifyMsg(expr, msg)                                                                                                                 \
        {                                                                                                                                            \
            if (!(expr))                                                                                                                             \
            {                                                                                                                                        \
                dumpVerify(#expr, msg, __FILE__, __LINE__);                                                                                          \
            }                                                                                                                                        \
        }
#endif