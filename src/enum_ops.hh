//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_ENUM_OPS_HH
#define DOOM_ENUM_OPS_HH

#include <type_traits>

// copied directly from stackoverflow:
// https://stackoverflow.com/a/23152590

template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator~(T a)
{
  return (T) ~(int)a;
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator|(T a, T b)
{
  return (T)((int)a | (int)b);
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator&(T a, T b)
{
  return (T)((int)a & (int)b);
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T operator^(T a, T b)
{
  return (T)((int)a ^ (int)b);
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T &operator|=(T &a, T b)
{
  return (T &)((int &)a |= (int)b);
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T &operator&=(T &a, T b)
{
  return (T &)((int &)a &= (int)b);
}
template <class T, class = std::enable_if_t<std::is_enum_v<T>>>
inline T &operator^=(T &a, T b)
{
  return (T &)((int &)a ^= (int)b);
}

#endif // DOOM_ENUM_OPS_HH
