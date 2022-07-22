#pragma once
#include "kun/config.h"
#include "kun/traits.h"

// traits def
namespace kun::memory
{
template<typename A, typename B = A> struct memory_traits
{
    // in case A == B
    static constexpr bool call_ctor = true;   // need call ctor explicit
    static constexpr bool call_dtor = true;   // need call dtor explicit
    static constexpr bool use_realloc = false;// can type use realloc

    // need call copy or move operator
    static constexpr bool call_copy = true;
    static constexpr bool call_move = true;
    static constexpr bool call_assign = true;
    static constexpr bool call_move_assign = true;

    // need call compare operator
    static constexpr bool call_compare = true;
};
template<typename T> struct memory_traits<T, T>
{
    static constexpr bool call_ctor = !std::is_trivially_constructible_v<T>;
    static constexpr bool call_dtor = !std::is_trivially_destructible_v<T>;
    static constexpr bool use_realloc = std::is_trivial_v<T> && std::is_trivially_destructible_v<T>;

    static constexpr bool call_copy = !std::is_trivially_copyable_v<T>;
    static constexpr bool call_move = !std::is_trivially_move_constructible_v<T>;
    static constexpr bool call_assign = !std::is_trivially_assignable_v<std::add_lvalue_reference_t<T>, std::add_lvalue_reference_t<T>>;
    static constexpr bool call_move_assign = !std::is_trivially_move_assignable_v<T>;

    static constexpr bool call_compare = !std::is_trivial_v<T>;
};
template<typename T> struct memory_traits<T*, T*>
{
    static constexpr bool call_ctor = false;
    static constexpr bool call_dtor = false;
    static constexpr bool use_realloc = true;

    static constexpr bool call_copy = false;
    static constexpr bool call_move = false;
    static constexpr bool call_assign = false;
    static constexpr bool call_move_assign = false;

    static constexpr bool call_compare = false;
};
template<typename A, typename B> struct memory_traits<const A, B> : public memory_traits<A, B>
{
};
}// namespace kun::memory

// impl for basic type
namespace kun::memory
{
#define KUN_IMPL_BASIC_MEM_POLICY(dst, src)                                                                                                          \
    template<> struct memory_traits<dst, src>                                                                                                        \
    {                                                                                                                                                \
        static constexpr bool call_ctor = false;                                                                                                     \
        static constexpr bool call_dtor = false;                                                                                                     \
        static constexpr bool use_realloc = true;                                                                                                    \
                                                                                                                                                     \
        static constexpr bool call_copy = false;                                                                                                     \
        static constexpr bool call_move = false;                                                                                                     \
        static constexpr bool call_assign = false;                                                                                                   \
        static constexpr bool call_move_assign = false;                                                                                              \
                                                                                                                                                     \
        static constexpr bool call_compare = true;                                                                                                   \
    };

KUN_IMPL_BASIC_MEM_POLICY(u8, i8)
KUN_IMPL_BASIC_MEM_POLICY(i8, u8)
KUN_IMPL_BASIC_MEM_POLICY(u16, i16)
KUN_IMPL_BASIC_MEM_POLICY(i16, u16)
KUN_IMPL_BASIC_MEM_POLICY(u32, i32)
KUN_IMPL_BASIC_MEM_POLICY(i32, u32)
KUN_IMPL_BASIC_MEM_POLICY(u64, i64)
KUN_IMPL_BASIC_MEM_POLICY(i64, u64)

#undef KUN_IMPL_BASIC_MEM_POLICY
}// namespace kun::memory