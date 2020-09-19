#include "misc.hh"
#include "doom.hh"
#include "file.hh"
#include "string_tools.hh"
#include "system.hh"

#include <fmt/core.h>
#include <fmt/os.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>
#include <strtk.hpp>

constexpr const char *BOOM_CFG = "ezboom.cfg";

std::string defaultFile;

void loadDefaultsFromFile(file::File &f)
{
  std::size_t lineNum = 0;
  while (!f.eof())
  {
    lineNum++;
    std::string line = f.readLine();
    line = trim(line);
    if (line.length() == 0 || !std::isalnum(line[0]))
    {
      continue;
    }

    std::string def;
    std::string parm;
  }
}

void misc::loadDefaults()
{
  if (argMeta.config.has_value())
  {
    defaultFile = argMeta.config.value();
  }
  else
  {
    defaultFile = fmt::format("{}/{}", doomExeDir(), BOOM_CFG);
  }
  spdlog::info("default file: {}", defaultFile);

  try
  {
    file::File f{defaultFile, "r"};
    loadDefaultsFromFile(f);
  }
  catch (io::IoException &e)
  {
    spdlog::warn("{}", e.what());
    spdlog::warn("Using built-in defaults.");
  }
}
