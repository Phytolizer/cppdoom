#include "misc.hh"

#include <boost/algorithm/string.hpp>
#include <boost/variant2/variant.hpp>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <string>

#include "config.h"
#include "demo.hh"
#include "doom.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "file.hh"
#include "game.hh"
#include "menu.hh"
#include "pspr.hh"
#include "string_tools.hh"
#include "system.hh"
#include "video.hh"

using namespace boost::variant2;

bool misc::precache = true;

const misc::Default defaults[] = {
    {"System settings", nullptr, 0, {}, {}},
    {"process_priority", &video::process_priority, 0, 0, 2},
    {"Misc settings", nullptr, 0, {}, {}},
    {"default_compatibility_level", &doomstat::default_compatibility_level, -1, -1,
     static_cast<int>(doomstat::CompLevel::MAX_COMPATIBILITY_LEVEL) - 1},
    {
        "realtic_clock_rate",
        &realtic_clock_rate,
        100,
        0,
        {},
    },
    {"menu_background", &menu::menu_background, true, {}, {}},
    {"max_player_corpses", &game::max_player_corpses, 32, -1, {}},
    {"flashing_hom", &doomstat::flashing_hom, false, {}, {}},
    {"demo_insurance", &doomstat::default_demo_insurance,
     static_cast<int>(doomstat::DemoInsurance::DuringDemoRecording), static_cast<int>(doomstat::DemoInsurance::Never),
     static_cast<int>(doomstat::DemoInsurance::DuringDemoRecording)},
    {"endoom_mode", &endoom_mode, static_cast<int>(EndoomMode::colors | EndoomMode::droplastline), 0x0,
     static_cast<int>(EndoomMode::colors | EndoomMode::nonasciichars | EndoomMode::droplastline)},
    {"level_precache", &misc::precache, true, {}, {}},
    {"demo_smoothturns", &demo::demo_smoothturns, false, {}, {}},
    {"demo_smoothturnsfactor", &demo::demo_smoothturnsfactor, 6, 1, demo::SMOOTH_PLAYING_MAXFACTOR},
    {"boom_autoswitch", &game::boom_autoswitch, true, {}, {}},
    {"Files", nullptr, 0, {}, {}},
    {"wadfiles", &wad_files, std::vector<std::string>{}, {}, {}},
    {"dehfiles", &deh_files, std::vector<std::string>{}, {}, {}},
    {"Game settings", nullptr, 0, {}, {}},
    {"default_skill", &game::default_skill, 3, 1, 5},
    {"weapon_recoil", &doomstat::default_weapon_recoil, false, {}, {}},
    {"doom_weapon_toggles", &doomstat::doom_weapon_toggles, false, {}, {}},
    {"player_bobbing", &doomstat::default_player_bobbing, true, {}, {}},
    {"weapon_attack_alignment", &pspr::weapon_attack_alignment, 0, 0, 3},
    // TODO the rest of these
};

constexpr const char* BOOM_CFG = "ezboom.cfg";

std::string defaultFile;

void loadDefaultsFromFile(file::File& f)
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

        variant<int, std::string, std::vector<std::string>> parsedParm;
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
        else if (parm[0] == '[')
        {
            auto sameLine = parm.find(']');
            if (sameLine != std::string::npos)
            {
                parm = parm.substr(1, sameLine - 1);
                std::vector<std::string> vec;
                boost::split(vec, parm, [](char c) { return c == ','; });
                std::for_each(vec.begin(), vec.end(), [](std::string& v) { boost::trim(v); });
                std::vector<std::string> finalVec;
                std::copy_if(vec.begin(), vec.end(), std::back_inserter(finalVec),
                             [](const std::string& s) { return !s.empty(); });
                parsedParm = finalVec;
            }
            else
            {
                // multiple lines
                parm = parm.substr(1);
                parm += f.readUntil(']');
                std::vector<std::string> vec;
                boost::split(vec, parm, [](char c) { return c == ','; });
                if (vec.rbegin() != vec.rend())
                {
                    // get rid of ]
                    *vec.rbegin() = vec.rbegin()->substr(0, vec.rbegin()->length() - 1);
                }
                std::for_each(vec.begin(), vec.end(), [](auto& v) { boost::trim(v); });
                std::vector<std::string> finalVec;
                std::copy_if(vec.begin(), vec.end(), std::back_inserter(finalVec),
                             [](const std::string& s) { return !s.empty(); });
                parsedParm = finalVec;
            }
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

        auto* d = std::find_if(defaults, defaults + (sizeof(defaults) / sizeof(defaults[0])),
                               [&](const auto& d) { return d.name == def; });
        if (!d || d->name != def || d->location == nullptr)
        {
            spdlog::warn("Unknown config key '{}'. Ignoring.", def);
            continue;
        }
        std::size_t index = d->value.index();
        if ((index == misc::DEF_BOOL || index == misc::DEF_INT) && !get_if<int>(&parsedParm) ||
            index == misc::DEF_STR && !get_if<std::string>(&parsedParm) ||
            index == misc::DEF_ARR && !get_if<std::vector<std::string>>(&parsedParm))
        {
            std::string expectedType = "integer";
            if (index == misc::DEF_STR)
            {
                expectedType = "string";
            }
            else if (index == misc::DEF_ARR)
            {
                expectedType = "array";
            }
            std::string receivedType = "integer";
            if (get_if<std::string>(&parsedParm))
            {
                receivedType = "string";
            }
            else if (get_if<std::vector<std::string>>(&parsedParm))
            {
                receivedType = "array";
            }
            spdlog::warn("Type mismatch: key '{}' expected {}, received {}. Ignoring.", def, expectedType,
                         receivedType);
            continue;
        }
        if (index == misc::DEF_BOOL && (*get_if<int>(&parsedParm) < 0 || *get_if<int>(&parsedParm) > 1))
        {
            spdlog::warn("Type mismatch: key '{}' expected boolean, but value {} is "
                         "out of range (0..1). Ignoring.",
                         def, parm);
            continue;
        }
        if (index == misc::DEF_INT)
        {
            int value = *get_if<int>(&parsedParm);
            bool belowMin = d->min.has_value() && value < d->min.value();
            bool aboveMax = d->max.has_value() && value > d->max.value();
            if (belowMin || aboveMax)
            {
                std::string rangeStart;
                if (d->min.has_value())
                {
                    rangeStart = fmt::format("{}", d->min.value());
                }
                std::string rangeEnd;
                if (d->max.has_value())
                {
                    rangeEnd = fmt::format("{}", d->max.value());
                }
                spdlog::warn("Range problem: key '{}' allows values in the range {}..{}, "
                             "but its value was {}. Ignoring.",
                             def, rangeStart, rangeEnd, parm);
                continue;
            }
        }
        // now parm is definitely valid

        if (index == misc::DEF_BOOL)
        {
            *reinterpret_cast<bool*>(d->location) = (*get_if<int>(&parsedParm) == 1);
        }
        else if (index == misc::DEF_INT)
        {
            *reinterpret_cast<int*>(d->location) = *get_if<int>(&parsedParm);
        }
        else if (index == misc::DEF_STR)
        {
            *reinterpret_cast<std::string*>(d->location) = *get_if<std::string>(&parsedParm);
        }
        else if (index == misc::DEF_ARR)
        {
            *reinterpret_cast<std::vector<std::string>*>(d->location) = *get_if<std::vector<std::string>>(&parsedParm);
        }
    }

    auto ezboomWad = sys::findFile(fmt::format("{}.wad", PACKAGE_TARNAME));
    if (!ezboomWad.has_value())
    {
        spdlog::error("{}.wad not found. Can't continue.", PACKAGE_TARNAME);
        //    exit(-1);
    }
    else
    {
        wad_files.insert(wad_files.begin(), ezboomWad.value());
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
        defaultFile = fmt::format("{}/{}", sys::doomExeDir(), BOOM_CFG);
    }
    spdlog::info("default file: {}", defaultFile);

    try
    {
        file::File f{defaultFile, "r"};
        loadDefaultsFromFile(f);
    }
    catch (io::IoException& e)
    {
        spdlog::warn("{}", e.what());
        spdlog::warn("Using built-in defaults.");
    }
}
std::optional<std::vector<std::byte>> misc::readFile(std::string_view name)
{
    file::File f;
    try
    {
        f = file::File{name, "r"};
    }
    catch (io::IoException& e)
    {
        return {};
    }
    std::size_t length = f.length();
    try
    {
        std::vector<std::byte> contents = f.read(length);
        return contents;
    }
    catch (io::IoException& e)
    {
        return {};
    }
}
