#pragma once
#include "kun/base/config.h"
#include "kun/base/types.h"

// TODO. 使用 built-in 指令优化
namespace kun
{
// countLZero & countRZero
// 得到 bit 中左（高位起）和右（低位起）的 0 个数
template<typename T> T countLZero(T v);
template<typename T> T countRZero(T v);

// countLOne & countROne
// 得到 bit 中左（高位起）和右（低位起）的 1 个数
template<typename T> T countLOne(T v);
template<typename T> T countROne(T v);

// bitWidth
// 得到存储这个数所需要的位数
template<typename T> T bitWidth(T v);

// bitFloor & bitCeil
// 相当于得到最近的一个小于/大于该数的二次幂（2^n）
template<typename T> T bitFloor(T v);
template<typename T> T bitCeil(T v);

// bitFloorLog2 & bitCeilLog2
// 相当于得到最近的一个小于/大于该数的二次幂（2^n）的幂（n）
template<typename T> T bitFloorLog2(T v);
template<typename T> T bitCeilLog2(T v);

// popCount
// 得到 bit 中 1 的个数
template<typename T> T popCount(T v);
}// namespace kun

// countLZero & countRZero
namespace kun
{
namespace detail
{
template<typename T> KUN_INLINE T countLZero_FallBack(T v)
{
    T    ret = 0;
    auto n = std::numeric_limits<T>::digits;
    auto c = std::numeric_limits<T>::digits / 2;
    do {
        ret = static_cast<T>(v >> c);
        if (ret != 0)
        {
            n -= c;
            v = ret;
        }
        c >>= 1;
    } while (c != 0);
    return static_cast<T>(n) - static_cast<T>(v);
}
template<typename T> KUN_INLINE T countRZero_FallBack(T v)
{
    auto digits = std::numeric_limits<T>::digits;
    return digits - countLZero(static_cast<T>(static_cast<T>(~v) & static_cast<T>(v - 1)));
}
}// namespace detail

template<typename T> KUN_INLINE T countLZero(T v)
{
    static_assert(!std::is_signed_v<T>);

    return detail::countLZero_FallBack(v);
}
template<typename T> KUN_INLINE T countRZero(T v)
{
    static_assert(!std::is_signed_v<T>);

    return detail::countRZero_FallBack(v);
}
}// namespace kun

// countLOne & countROne
namespace kun
{
template<typename T> KUN_INLINE T countLOne(T v) { return countLZero(static_cast<T>(~v)); }
template<typename T> KUN_INLINE T countROne(T v) { return countRZero(static_cast<T>(~v)); }
}// namespace kun

// bitWidth
namespace kun
{
template<typename T> KUN_INLINE T bitWidth(T v) { return std::numeric_limits<T>::digits - countLZero(v); }
}// namespace kun

// bitFloor & bitCeil
namespace kun
{
template<typename T> KUN_INLINE T bitFloor(T v) { return v == 0 ? 0 : static_cast<T>(T(1) << (std::numeric_limits<T>::digits - 1 - countLZero(v))); }
template<typename T> KUN_INLINE T bitCeil(T v)
{
    return v <= 1 ? 1 : static_cast<T>(T(1) << (std::numeric_limits<T>::digits - countLZero(static_cast<T>(v - 1))));
}
}// namespace kun

// bitFloorLog2 & bitCeilLog2
namespace kun
{
template<typename T> KUN_INLINE T bitFloorLog2(T v) { return v == 0 ? 0 : std::numeric_limits<T>::digits - 1 - countLZero(v); }
template<typename T> KUN_INLINE T bitCeilLog2(T v) { return v <= 1 ? 0 : std::numeric_limits<T>::digits - countLZero(static_cast<T>(v - 1)); }
}// namespace kun

// popCount
namespace kun
{
namespace detail
{
template<typename T> KUN_INLINE T popCount_Fallback(T v)
{
    auto digits = std::numeric_limits<T>::digits;
    v = static_cast<T>(v - ((v >> 1) & static_cast<T>(0x5555'5555'5555'5555ull)));
    v = static_cast<T>((v & static_cast<T>(0x3333'3333'3333'3333ull)) + ((v >> 2) & static_cast<T>(0x3333'3333'3333'3333ull)));
    v = static_cast<T>((v + (v >> 4)) & static_cast<T>(0x0F0F'0F0F'0F0F'0F0Full));
    v = static_cast<T>(v * static_cast<T>(0x0101'0101'0101'0101ull));
    return static_cast<int>(v >> (digits - 8));
}
}// namespace detail
template<typename T> KUN_INLINE T popCount(T v)
{
    static_assert(!std::is_signed_v<T>);
    return detail::popCount_Fallback(v);
}
}// namespace kun