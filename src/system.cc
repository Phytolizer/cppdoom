#include "system.hh"
#include "doom.hh"

#include <fmt/core.h>
#include <optional>

constexpr const char *EZBOOM_DIR = ".ezboom";

std::string doomExeDir()
{
  static std::optional<std::string> base;
  if (!base.has_value())
  {
    // find based on HOME env var
    const char *homeDir = std::getenv("HOME");
    if (homeDir)
    {
      base = fmt::format("{}/{}", homeDir, EZBOOM_DIR);
    }
    else
    {
      // find based on argv[0]
      auto lastSlash =
          std::find_if(argMeta.argv0.rbegin(), argMeta.argv0.rend(),
                       [](const auto &c) { return c == '/' || c == '\\'; });
      if (lastSlash == argMeta.argv0.rend())
      {
        // find based on '.'
        base = ".";
      }
      else
      {
        base = std::string{argMeta.argv0.begin(), lastSlash.base()};
      }
    }
  }
  return base.value();
}