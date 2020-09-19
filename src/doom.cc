#include "doom.hh"
#include "arglex.hh"
#include "misc.hh"

#include <cstdio>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <vector>

arglex::ArgMeta argMeta;

int main(int argc, const char *const *argv)
{
  std::vector<arglex::Arg> args = arglex::lexArgs(argc, argv);
  auto parseResult = arglex::parseArgs(args);

  if (parseResult.index() == 1)
  {
    fmt::print(stderr, "{}", boost::variant2::get<1>(parseResult));
    exit(-1);
  }
  argMeta = boost::variant2::get<0>(parseResult);
  spdlog::info("Loading system defaults.");
  misc::loadDefaults();

  return 0;
}