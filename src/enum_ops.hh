//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_ENUM_OPS_HH
#define DOOM_ENUM_OPS_HH

#include <type_traits>

// copied directly from stackoverflow:
// https://stackoverflow.com/a/23152590
// added some enable_if and static_cast myself

template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator~(T a)
{
  return static_cast<T>(~static_cast<int>(a));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator|(T a, T b)
{
  return static_cast<T>(static_cast<int>(a) | static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator&(T a, T b)
{
  return static_cast<T>(static_cast<int>(a) & static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator^(T a, T b)
{
  return static_cast<T>(static_cast<int>(a) ^ static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T& operator|=(T& a, T b)
{
  return static_cast<T&>(reinterpret_cast<int&>(a) |= static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T& operator&=(T& a, T b)
{
  return static_cast<T&>(static_cast<int&>(a) &= static_cast<int>(b));
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T& operator^=(T& a, T b)
{
  return static_cast<T&>(static_cast<int&>(a) ^= static_cast<int>(b));
}

#endif // DOOM_ENUM_OPS_HH
