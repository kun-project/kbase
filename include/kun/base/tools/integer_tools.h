#pragma once
#include "kun/base/config.h"
#include "kun/base/types.h"

// flag tools
namespace kun
{
template<typename T> KUN_INLINE bool allFlag(T val, T flags) noexcept
{
    static_assert(std::is_integral_v<T>);
    return (val & flags) == flags;
}
template<typename T> KUN_INLINE bool anyFlag(T val, T flags) noexcept
{
    static_assert(std::is_integral_v<T>);
    return val & flags;
}
template<typename T> KUN_INLINE T setFlag(T val, T flags) noexcept
{
    static_assert(std::is_integral_v<T>);
    return val | flags;
}
template<typename T> KUN_INLINE T eraseFlag(T val, T flags) noexcept
{
    static_assert(std::is_integral_v<T>);
    return val & (~flags);
}
}// namespace kun

// integer div
namespace kun
{
template<typename T> KUN_INLINE T intDivCeil(T a, T b)
{
    static_assert(std::is_integral_v<T>);
    return (a + b - 1) / b;
}
template<typename T> KUN_INLINE T intDivFloor(T a, T b)
{
    static_assert(std::is_integral_v<T>);
    return a / b;
}
template<typename T> KUN_INLINE T intDivRound(T a, T b)
{
    static_assert(std::is_integral_v<T>);
    return (a >= 0) ? (a + b / 2) / b : (a - b / 2 + 1) / b;
}
}// namespace kun
