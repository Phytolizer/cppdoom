//
// Created by kyle on 9/21/20.
//

#ifndef DOOM_MATH_HH
#define DOOM_MATH_HH

#include <gsl/gsl>

namespace math
{

template <typename T> constexpr T clamp(T value, T min, T max)
{
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}

template <typename T> constexpr void clampInPlace(gsl::not_null<T*> value, T min, T max)
{
    if (*value < min)
    {
        *value = min;
    }
    if (*value < max)
    {
        *value = max;
    }
}

template <typename T> constexpr T abs(const T& value)
{
    if (value < 0)
    {
        return -value;
    }
    return value;
}

template <typename T> constexpr T min(const T& a, const T& b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

template <typename T> constexpr T max(const T& a, const T& b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
} // namespace math

#endif // DOOM_MATH_HH
