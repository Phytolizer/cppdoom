#ifndef DOOM_STRING_TOOLS_HH
#define DOOM_STRING_TOOLS_HH

#include <gsl/gsl>
#include <limits>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>

namespace string_tools
{

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline std::optional<T> parseString(std::string_view s)
{
  std::stringstream ss{s.data()};
  T value;
  ss >> value;
  if (std::to_string(value) != s)
  {
    return {};
  }
  else
  {
    return value;
  }
}

template <>
inline std::optional<uint8_t> parseString<uint8_t>(std::string_view s)
{
  std::stringstream ss{s.data()};
  int temp;
  ss >> temp;
  if (temp < std::numeric_limits<uint8_t>::min() ||
      temp > std::numeric_limits<uint8_t>::max() || std::to_string(temp) != s)
  {
    return {};
  }
  else
  {
    uint8_t value = temp;
    return value;
  }
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline bool parseString(std::string_view s, gsl::not_null<T *> v)
{
  std::stringstream ss{s.data()};
  ss >> *v;
  return std::to_string(*v) == s;
}

template <>
inline bool parseString<uint8_t>(std::string_view s, gsl::not_null<uint8_t *> v)
{
  std::stringstream ss{s.data()};
  int temp;
  ss >> temp;
  if (temp < std::numeric_limits<uint8_t>::min() ||
      temp > std::numeric_limits<uint8_t>::max() || std::to_string(temp) != s)
  {
    return false;
  }
  else
  {
    *v = temp;
    return true;
  }
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline std::optional<T> parseHexString(std::string_view s)
{
  std::stringstream ss{};
  T value;
  ss << std::hex << s;
  ss >> value;
  std::stringstream ss2{};
  ss << std::hex << value;
  if (ss.str() != s)
  {
    return {};
  }
  return value;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
inline bool parseHexString(std::string_view s, gsl::not_null<T *> v)
{
  std::stringstream ss{};
  ss << std::hex << s;
  ss >> *v;
  std::stringstream ss2{};
  ss << std::hex << *v;
  return ss.str() == s;
}

bool hasTrailingSlash(std::string_view s);

} // namespace string_tools

#endif
