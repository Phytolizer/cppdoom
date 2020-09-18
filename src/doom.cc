#include "arglex.hh"

#include <cstdio>
#include <fmt/core.h>
#include <vector>

int main(int argc, const char *const *argv)
{
  std::vector<Arg> args = lexArgs(argc, argv);
  auto parseResult = parseArgs(args);
  if (parseResult.index() == 1)
  {
    fmt::print(stderr, "{}", boost::variant2::get<1>(parseResult));
    exit(-1);
  }
  ArgMeta argMeta = boost::variant2::get<0>(parseResult);

  return 0;
}