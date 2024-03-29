#pragma once
#include <type_traits>

namespace kun
{
// is detected
template<typename, template<typename...> class Op, typename... T> struct is_detected_impl : std::false_type
{
};
template<template<typename...> class Op, typename... T> struct is_detected_impl<std::void_t<Op<T...>>, Op, T...> : std::true_type
{
};
template<template<typename...> class Op, typename... T> using is_detected = is_detected_impl<void, Op, T...>;
template<template<typename...> class Op, typename... T> static constexpr bool is_detected_v = is_detected<Op, T...>::value;

// has op
namespace detail
{
template<typename X, typename Y> using has_add = decltype(std::declval<const X&>() + std::declval<const Y&>());
template<typename X, typename Y> using has_sub = decltype(std::declval<const X&>() - std::declval<const Y&>());
template<typename X, typename Y> using has_mul = decltype(std::declval<const X&>() * std::declval<const Y&>());
template<typename X, typename Y> using has_div = decltype(std::declval<const X&>() / std::declval<const Y&>());

template<typename X, typename Y> using has_less = decltype((std::declval<const X&>() < std::declval<const Y&>()) == true);
template<typename X, typename Y> using has_less_equal = decltype((std::declval<const X&>() <= std::declval<const Y&>()) == true);
template<typename X, typename Y> using has_greater = decltype((std::declval<const X&>() > std::declval<const Y&>()) == true);
template<typename X, typename Y> using has_greater_equal = decltype((std::declval<const X&>() >= std::declval<const Y&>()) == true);
template<typename X, typename Y> using has_equal = decltype((std::declval<const X&>() == std::declval<const Y&>()) == true);
template<typename X, typename Y> using has_not_equal = decltype((std::declval<const X&>() != std::declval<const Y&>()) == true);
}// namespace detail

template<typename X, typename Y = X> inline constexpr bool has_add_v = is_detected_v<detail::has_add, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_sub_v = is_detected_v<detail::has_sub, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_mul_v = is_detected_v<detail::has_mul, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_div_v = is_detected_v<detail::has_div, X, Y>;

template<typename X, typename Y = X> inline constexpr bool has_less_v = is_detected_v<detail::has_less, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_less_equal_v = is_detected_v<detail::has_less_equal, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_greater_v = is_detected_v<detail::has_greater, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_greater_equal_v = is_detected_v<detail::has_greater_equal, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_equal_v = is_detected_v<detail::has_equal, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_not_equal_v = is_detected_v<detail::has_not_equal, X, Y>;

// ctor
namespace detail
{
template<typename T> using has_default_ctor = decltype(new T());
}// namespace detail
template<typename T> inline constexpr bool has_default_ctor_v = is_detected_v<detail::has_default_ctor, T>;

// copy & move & assign
namespace detail
{
template<typename X, typename Y = X> using has_assign = decltype(std::declval<X&>() = (std::declval<const Y&>()));
template<typename X, typename Y = X> using has_move_assign = decltype(std::declval<X&>() = (std::move(std::declval<Y&&>())));
template<typename X, typename Y = X> using has_copy_ctor = decltype(new X(std::declval<const Y&>()));
template<typename X, typename Y = X> using has_move_ctor = decltype(new X(std::declval<Y&&>()));
}// namespace detail
template<typename X, typename Y = X> inline constexpr bool has_assign_v = is_detected_v<detail::has_assign, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_move_assign_v = is_detected_v<detail::has_move_assign, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_copy_ctor_v = is_detected_v<detail::has_copy_ctor, X, Y>;
template<typename X, typename Y = X> inline constexpr bool has_move_ctor_v = is_detected_v<detail::has_move_ctor, X, Y>;

}// namespace kun
