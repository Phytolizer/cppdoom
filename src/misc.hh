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

extern bool precache;

void loadDefaults();

} // namespace misc

#endif
