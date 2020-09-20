#ifndef DOOM_MISC_HH
#define DOOM_MISC_HH

#include <boost/variant2/variant.hpp>
#include <optional>
#include <string>

namespace misc
{

struct Default
{
  std::string name;
  void *location;
  boost::variant2::variant<bool, int, std::string, std::vector<std::string>>
      value;
  std::optional<int> min;
  std::optional<int> max;
};
constexpr int DEF_BOOL = 0;
constexpr int DEF_INT = 1;
constexpr int DEF_STR = 2;
constexpr int DEF_ARR = 3;

extern bool precache;

void loadDefaults();

std::optional<std::vector<std::byte>> readFile(std::string_view name);
} // namespace misc

#endif
