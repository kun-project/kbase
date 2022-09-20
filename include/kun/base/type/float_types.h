#pragma once
#include <limits>
#include "kun/base/config.h"

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