//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_ENUM_OPS_HH
#define DOOM_ENUM_OPS_HH

#include <type_traits>

// copied directly from stackoverflow:
// https://stackoverflow.com/a/23152590
// added some enable_if and static_cast myself

template <class T, class = std::enable_if_t<std::is_enum_v<T>>> constexpr T operator~(T a)
{
    return static_cast<T>(~static_cast<int>(a));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> constexpr T operator|(T a, T b)
{
    return static_cast<T>(static_cast<int>(a) | static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> constexpr T operator&(T a, T b)
{
    return static_cast<T>(static_cast<int>(a) & static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> constexpr T operator^(T a, T b)
{
    return static_cast<T>(static_cast<int>(a) ^ static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> inline T& operator|=(T& a, T b)
{
    return (T&)((int&)(a) |= static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> inline T& operator&=(T& a, T b)
{
    return (T&)((int&)(a) &= static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>> inline T& operator^=(T& a, T b)
{
    return (T&)((int&)(a) ^= static_cast<int>(b));
}
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>> inline bool operator!(T x)
{
    return static_cast<int>(x) == 0;
}

template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
constexpr typename std::underlying_type<T>::type to_underlying(T x)
{
    return static_cast<typename std::underlying_type<T>::type>(x);
}

#endif // DOOM_ENUM_OPS_HH
