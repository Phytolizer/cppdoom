#include "system.hh"

#include <filesystem>
#include <fmt/core.h>
#include <optional>
#include <spdlog/spdlog.h>

#include "config.hh"
#include "doom.hh"
#include "string_tools.hh"

constexpr const char *EZBOOM_DIR = ".ezboom";

#ifdef _WIN32
constexpr char PATH_SEPARATOR = ';';
#else
constexpr char PATH_SEPARATOR = ':';
#endif

std::string sys::doomExeDir()
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
std::optional<std::string> sys::findFile(std::string_view fname,
                                         std::string_view ext)
{
  return internal::findFileInternal(fname, ext);
}
std::string sys::getVersionString()
{
  return fmt::format("{} v{}", PACKAGE_NAME, PACKAGE_VERSION);
}
std::string sys::sigString(int signum)
{
  return fmt::format("signal {}", signum);
}
struct SearchPath
{
  std::string dir;
  std::string sub;
  std::string env;
  std::string (*fun)();
};
std::optional<std::string>
sys::internal::findFileInternal(std::string_view fname, std::string_view ext)
{
  static const std::vector<SearchPath> initialSearch = {
      {
          {},
          {},
          {},
          doomExeDir,
      },
      {
          {},
      },
      {
          {},
          {},
          "DOOMWADDIR",
      },
      {DOOMWADDIR},
      {{}, "doom", "HOME"},
      {{}, "doom/iwad", "HOME"},
      {{}, {}, "HOME"},
      {"/usr/local/share/games/doom"},
      {"/usr/local/share/doom"},
      {"/usr/share/doom"},
  };
  static std::vector<SearchPath> search;

  if (search.empty())
  {
    search = initialSearch;
    const char *dwpp = std::getenv("DOOMWADPATH");
    if (dwpp)
    {
      std::string dwp = dwpp;
      std::size_t start = 0;
      while (true)
      {
        auto sep = dwp.find(PATH_SEPARATOR, start);
        if (sep != std::string::npos)
        {
          SearchPath additionalPath{dwp.substr(start, sep - start)};
          start = sep + 1;
          search.push_back(additionalPath);
        }
        else
        {
          break;
        }
      }
    }
  }

  for (const auto &s : search)
  {
    std::string dir;
    if (!s.env.empty())
    {
      const char *d = std::getenv(s.env.data());
      if (d == nullptr)
      {
        continue;
      }
      dir = d;
    }
    else if (s.fun)
    {
      dir = s.fun();
    }
    else
    {
      dir = s.dir;
    }
    std::string sub = s.sub;
    std::string path = fmt::format(
        "{}{}{}{}{}", dir, !string_tools::hasTrailingSlash(dir) ? "/" : "", sub,
        !string_tools::hasTrailingSlash(sub) ? "/" : "", fname);
    if (!ext.empty() && !std::filesystem::exists(path))
    {
      path += ext;
    }
    if (std::filesystem::exists(path))
    {
      spdlog::info("found {}", path);
      return path;
    }
  }
  // not found
  return {};
}
