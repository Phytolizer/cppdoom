#include "string_tools.hh"

static inline void trim_inp(std::string &s)
{
  ltrim_inp(s);
  rtrim_inp(s);
}
static inline void ltrim_inp(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](auto c) { return !std::isspace(c); }));
}
static inline void rtrim_inp(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](auto c) { return !std::isspace(c); })
              .base(),
          s.end());
}

static inline std::string trim(std::string s)
{
  trim_inp(s);
  return s;
}
static inline std::string ltrim(std::string s)
{
  ltrim_inp(s);
  return s;
}
static inline std::string rtrim(std::string s)
{
  rtrim_inp(s);
  return s;
}