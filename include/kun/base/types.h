#pragma once
#include <limits>
#include "kun/base/config.h"

// integer types
namespace kun
{
using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

// size type
using Size = std::size_t;

// integer limits
#define KUN_INT_CONSTANTS(size)                                                                                                                      \
    inline constexpr i##size I##size##_Min = std::numeric_limits<i##size>::min();                                                                    \
    inline constexpr i##size I##size##_MAX = std::numeric_limits<i##size>::max();                                                                    \
    inline constexpr u##size U##size##_Min = std::numeric_limits<u##size>::min();                                                                    \
    inline constexpr u##size U##size##_MAX = std::numeric_limits<u##size>::max();

KUN_INT_CONSTANTS(8)
KUN_INT_CONSTANTS(16)
KUN_INT_CONSTANTS(32)
KUN_INT_CONSTANTS(64)

#undef KUN_INT_CONSTANTS
}// namespace kun

// float types
namespace kun
{
// float types
#ifndef KUN_CUSTOM_REAL
using real = float;
#endif

// float constants
inline constexpr real REAL_MIN = std::numeric_limits<real>::min();
inline constexpr real REAL_MAX = std::numeric_limits<real>::max();
inline constexpr real REAL_NAN = std::numeric_limits<real>::quiet_NaN();
inline constexpr real REAL_SNAN = std::numeric_limits<real>::signaling_NaN();
inline constexpr real REAL_EPSILON = std::numeric_limits<real>::epsilon();
inline constexpr real REAL_INFINITY = std::numeric_limits<real>::infinity();
inline constexpr real REAL_TOLERANCE = ((real)0.00001);

}// namespace kun
