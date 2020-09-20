#include "misc.hh"

#include <boost/algorithm/string.hpp>
#include <boost/variant2/variant.hpp>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <string>

#include "demo.hh"
#include "doom.hh"
#include "enum_ops.hh"
#include "file.hh"
#include "game.hh"
#include "menu.hh"
#include "pspr.hh"
#include "stat.hh"
#include "string_tools.hh"
#include "system.hh"
#include "video.hh"

using namespace boost::variant2;

bool misc::precache = true;

const misc::Default defaults[] = {
    {"System settings", nullptr, 0, {}, {}},
    {"process_priority", &video::process_priority, 0, 0, 2},
    {"Misc settings", nullptr, 0, {}, {}},
    {"default_compatibility_level", &stat::default_compatibility_level, -1, -1,
     static_cast<int>(stat::CompLevel::MAX_COMPATIBILITY_LEVEL) - 1},
    {
        "realtic_clock_rate",
        &realtic_clock_rate,
        100,
        0,
        {},
    },
    {"menu_background", &menu::menu_background, true, {}, {}},
    {"max_player_corpses", &game::max_player_corpses, 32, -1, {}},
    {"flashing_hom", &stat::flashing_hom, false, {}, {}},
    {"demo_insurance", &stat::default_demo_insurance,
     static_cast<int>(stat::DemoInsurance::DuringDemoRecording),
     static_cast<int>(stat::DemoInsurance::Never),
     static_cast<int>(stat::DemoInsurance::DuringDemoRecording)},
    {"endoom_mode", &endoom_mode,
     static_cast<int>(EndoomMode::colors | EndoomMode::droplastline), 0x0,
     static_cast<int>(EndoomMode::colors | EndoomMode::nonasciichars |
                      EndoomMode::droplastline)},
    {"level_precache", &misc::precache, true, {}, {}},
    {"demo_smoothturns", &demo::demo_smoothturns, false, {}, {}},
    {"demo_smoothturnsfactor", &demo::demo_smoothturnsfactor, 6, 1,
     demo::SMOOTH_PLAYING_MAXFACTOR},
    {"boom_autoswitch", &game::boom_autoswitch, true, {}, {}},
    {"Files", nullptr, 0, {}, {}},
    {"wadfiles", &wad_files, std::vector<std::string>{}, {}, {}},
    {"dehfiles", &deh_files, std::vector<std::string>{}, {}, {}},
    {"Game settings", nullptr, 0, {}, {}},
    {"default_skill", &game::default_skill, 3, 1, 5},
    {"weapon_recoil", &stat::default_weapon_recoil, false, {}, {}},
    {"doom_weapon_toggles", &stat::doom_weapon_toggles, false, {}, {}},
    {"player_bobbing", &stat::default_player_bobbing, true, {}, {}},
    {"weapon_attack_alignment", &pspr::weapon_attack_alignment, 0, 0, 3},
    // TODO the rest of these
};

constexpr const char *BOOM_CFG = "ezboom.cfg";

std::string defaultFile;

void loadDefaultsFromFile(file::File &f)
{
  std::size_t lineNum = 0;
  while (!f.eof())
  {
    lineNum++;
    std::string line = f.readLine();
    boost::trim(line);
    if (line.length() == 0 || !std::isalnum(line[0]))
    {
      continue;
    }

    std::string def;
    std::string parm;

    size_t i = 0;
    for (; i < line.length() && !isspace(line[i]); i += 1)
      ;
    if (i == line.length())
    {
      spdlog::warn("Line {} in the config file is invalid (no space could be "
                   "found). Ignoring.",
                   lineNum);
      continue;
    }
    def = line.substr(0, i);
    boost::trim(def);
    while (i < line.length() && isspace(line[i]))
    {
      i += 1;
    }
    if (i == line.length())
    {
      spdlog::warn("Line {} in the config file is invalid (no value for key "
                   "'{}'). Ignoring.",
                   lineNum, def);
      continue;
    }
    parm = line.substr(i);
    boost::trim(parm);

    if (def.empty() || parm.empty())
    {
      spdlog::warn("Line {} in the config file is invalid (missing key/value). "
                   "Ignoring.",
                   lineNum);
      continue;
    }

    variant<std::string, int> parsedParm;
    if (parm[0] == '"')
    {
      boost::trim_if(parm, [](auto c) { return c == '"'; });
      parsedParm = parm;
    }
    else if (parm[0] == '0' && parm.length() > 1 && parm[1] == 'x')
    {
      parm = parm.substr(2);
      auto parseRes = string_tools::parseHexString<int>(parm);
      if (!parseRes.has_value())
      {
        spdlog::warn("Line {} in the config file is invalid (invalid hex "
                     "literal 0x{}). Ignoring.",
                     lineNum, parm);
        continue;
      }
      parsedParm = parseRes.value();
    }
    else
    {
      auto parseRes = string_tools::parseHexString<int>(parm);
      if (!parseRes.has_value())
      {
        spdlog::warn("Line {} in the config file is invalid (invalid integer "
                     "literal {}). Ignoring.",
                     lineNum, parm);
        continue;
      }
      parsedParm = parseRes.value();
    }
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
