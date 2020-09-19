#ifndef DOOM_STRING_TOOLS_HH
#define DOOM_STRING_TOOLS_HH

#include <gsl/gsl>
#include <limits>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
std::optional<T> parseString(std::string_view s)
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

template <> std::optional<uint8_t> parseString<uint8_t>(std::string_view s)
{
  std::stringstream ss{s.data()};
  uint8_t value;
  int temp;
  ss >> temp;
  if (temp < std::numeric_limits<uint8_t>::min() ||
      temp > std::numeric_limits<uint8_t>::max() || std::to_string(temp) != s)
  {
    return {};
  }
  else
  {
    value = temp;
    return value;
  }
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
bool parseString(std::string_view s, gsl::not_null<T *> v)
{
  std::stringstream ss{s.data()};
  ss >> *v;
  return std::to_string(*v) == s;
}

template <>
bool parseString<uint8_t>(std::string_view s, gsl::not_null<uint8_t *> v)
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

static inline void trim_inp(std::string &s);
static inline void ltrim_inp(std::string &s);
static inline void rtrim_inp(std::string &s);

static inline std::string trim(std::string s);
static inline std::string ltrim(std::string s);
static inline std::string rtrim(std::string s);

#endif
