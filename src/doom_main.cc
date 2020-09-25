//
// Created by kyle on 9/20/20.
//

#include "doom_main.hh"

#include <filesystem>
#include <fstream>
#include <spdlog/spdlog.h>
#include <strtk.hpp>

#include "config.h"
#include "deh.hh"
#include "doom.hh"
#include "doomstat.hh"
#include "file.hh"
#include "game.hh"
#include "gsl_aliases.hh"
#include "math.hh"
#include "render/main.hh"
#include "swap.hh"
#include "system.hh"
#include "tables.hh"
#include "version.hh"
#include "wad.hh"

bool autoStart;
bool nomusicparm;
bool nosfxparm;

bool doom::fastparm;
bool doom::nomonsters;
bool doom::respawnparm;

int startEpisode;
int startMap;

defs::Skill doom::startSkill;

std::string basesavegame{};
std::string doomverstr{};

constexpr const char* const DEVSTR = "Development mode ON.";

void doom::main()
{
    doom::mainSetup();
}

void normalizeSlashes(NotNull<std::string*> s)
{
    if (s->empty())
    {
        return;
    }

    auto p = s->rbegin();
    if (*p == '/' || *p == '\\')
    {
        s->erase(p.base());
    }
    // ensure p is valid
    p = s->rbegin();
    while (p != s->rend())
    {
        ++p;
        if (*p == '\\')
        {
            *p = '/';
        }
    }
}

constexpr std::array standard_iwads = {
    "doom2f.wad",    "doom2.wad",     "plutonia.wad", "tnt.wad",  "doom.wad", "doom1.wad",    "doomu.wad",
    "freedoom2.wad", "freedoom1.wad", "freedm.wad",   "hacx.wad", "chex.wad", "bfgdoom2.wad", "bfgdoom.wad",
};

std::optional<std::string> findIwadFile()
{
    if (argMeta.iwad.has_value())
    {
        return sys::findFile(argMeta.iwad.value(), ".wad");
    }

    for (const auto& std_iwad : standard_iwads)
    {
        auto iwad = sys::findFile(std_iwad, ".wad");
        if (iwad.has_value())
        {
            return iwad;
        }
    }

    return {};
}

bool bfgedition = false;

void checkIwad(std::string_view iwad)
{
    {
        std::ifstream f{iwad.data()};
        if (!f.good())
        {
            spdlog::error("checkIwad: IWAD {} not readable", iwad);
            exit(-1);
        }
    }

    file::File f;
    try
    {
        f = file::File{iwad, "rb"};
    }
    catch (io::IoException& e)
    {
        spdlog::error("checkIwad: Can't open IWAD {}", iwad);
        exit(-1);
    }

    wad::WadInfo header{};
    try
    {
        f.readTo<wad::WadInfo>(&header);
    }
    catch (io::IoException& e)
    {
        spdlog::error("encountered error reading IWAD {}: {}", iwad, e.what());
        exit(-1);
    }

    bool noiwad = std::string{header.identification.begin(), header.identification.end()} != "IWAD";
    header.numLumps = LITTLE_LONG(header.numLumps);
    header.infoTableOffset = LITTLE_LONG(header.infoTableOffset);
    auto length = header.numLumps;
    auto fileInfo = std::vector<wad::FileLump>{static_cast<size_t>(length)};
    try
    {
        f.seekTo(header.infoTableOffset);
        f.readToArr<wad::FileLump>(&fileInfo);
    }
    catch (io::IoException& e)
    {
        spdlog::error("checkIwad: failed to read directory {}: {}", iwad, e.what());
        exit(-1);
    }
    --length;
    int ud = 0;
    int rg = 0;
    int sw = 0;
    int cm = 0;
    int sc = 0;
    int hx = 0;
    int cq = 0;
    for (; length > 0; length--)
    {
        if (fileInfo[length].name[0] == 'E' && fileInfo[length].name[2] == 'M' && fileInfo[length].name[4] == '\0')
        {
            char ep = fileInfo[length].name[1];
            if (ep == '4')
            {
                ++ud;
            }
            else if (ep == '3' || ep == '2')
            {
                ++rg;
            }
            else if (ep == '1')
            {
                ++sw;
            }
        }
        else if (fileInfo[length].name[0] == 'M' && fileInfo[length].name[1] == 'A' &&
                 fileInfo[length].name[2] == 'P' && fileInfo[length].name[5] == '\0')
        {
            ++cm;
            if (fileInfo[length].name[3] == '3' && (fileInfo[length].name[4] == '1' || fileInfo[length].name[4] == '2'))
            {
                ++sc;
            }
        }

        auto name = std::string{fileInfo[length].name.begin(), fileInfo[length].name.end()};
        if (name == "DMENUPIC")
        {
            bfgedition = true;
        }
        if (name.substr(0, 4) == "HACX")
        {
            ++hx;
        }
        if (name.substr(0, 5) == "W94_1" || name == "POSSH0M0")
        {
            ++cq;
        }
    }
    if (noiwad && !bfgedition && cq < 2)
    {
        spdlog::error("checkIwad: IWAD tag for {} not present", iwad);
        exit(-1);
    }
    doomstat::gamemode = defs::GameMode::UNDETERMINED;
    game::haswolflevels = false;
    if (cm >= 30 || (cm >= 20 && hx))
    {
        doomstat::gamemode = defs::GameMode::COMMERCIAL;
        game::haswolflevels = sc >= 2;
    }
    else if (ud >= 9)
    {
        doomstat::gamemode = defs::GameMode::RETAIL;
    }
    else if (rg >= 18)
    {
        doomstat::gamemode = defs::GameMode::REGISTERED;
    }
    else if (sw >= 9)
    {
        doomstat::gamemode = defs::GameMode::SHAREWARE;
    }
}

void addFile(std::string_view file, wad::WadSource source)
{
    std::string f{file};
    wad::addDefaultExtension(&f, ".wad");
    wad::wadfiles.push_back(wad::WadFileInfo{f, source, 0});

    if (strtk::ends_with(f, "nerve.wad"))
    {
        doomstat::gamemission = defs::GameMission::NERVE;
    }

    std::string gwaFilename{f};
    gwaFilename[gwaFilename.length() - 3] = 'g';
    gwaFilename[gwaFilename.length() - 2] = 'w';
    gwaFilename[gwaFilename.length() - 1] = 'a';
    wad::wadfiles.push_back(wad::WadFileInfo{gwaFilename, source, 0});
}

void addIwad(std::string_view iwad)
{
    if (iwad.empty())
    {
        return;
    }

    spdlog::info("IWAD found: {}", iwad);
    checkIwad(iwad);

    switch (doomstat::gamemode)
    {
    case defs::GameMode::RETAIL:
    case defs::GameMode::REGISTERED:
    case defs::GameMode::SHAREWARE:
        if (strtk::ends_with(iwad.data(), "chex.wad"))
        {
            doomstat::gamemission = defs::GameMission::CHEX;
        }
        else
        {
            doomstat::gamemission = defs::GameMission::DOOM;
        }
        break;
    case defs::GameMode::COMMERCIAL:
        doomstat::gamemission = defs::GameMission::DOOM2;
        if (strtk::ends_with(iwad.data(), "doom2f.wad"))
        {
            doomstat::language = defs::Language::FRENCH;
        }
        else if (strtk::ends_with(iwad.data(), "tnt.wad"))
        {
            doomstat::gamemission = defs::GameMission::TNT;
        }
        else if (strtk::ends_with(iwad.data(), "plutonia.wad"))
        {
            doomstat::gamemission = defs::GameMission::PLUT;
        }
        else if (strtk::ends_with(iwad.data(), "hacx.wad"))
        {
            doomstat::gamemission = defs::GameMission::HACX;
        }
        break;
    default:
        doomstat::gamemission = defs::GameMission::NONE;
        break;
    }
    if (doomstat::gamemode == defs::GameMode::UNDETERMINED)
    {
        spdlog::warn("Unknown game version, may not work");
    }
    addFile(iwad, wad::WadSource::SOURCE_IWAD);
}

void identifyVersion()
{
    {
        const char* p = std::getenv("DOOMSAVEDIR");
        std::string path;
        if (p == nullptr)
        {
            path = sys::doomExeDir();
        }
        else
        {
            path = p;
        }
        basesavegame = path;
    }
    if (argMeta.save.has_value())
    {
        if (std::filesystem::is_directory(argMeta.save.value()))
        {
            basesavegame = argMeta.save.value();
            normalizeSlashes(&basesavegame);
        }
        else
        {
            spdlog::error("-save path does not exist, using {} instead.", basesavegame);
        }
    }
    auto iwad = findIwadFile();

    if (iwad.has_value())
    {
        addIwad(iwad.value());
    }
    else
    {
        spdlog::error("identifyVersion: IWAD not found");
        exit(-1);
    }
}

constexpr void turboScale(gsl::not_null<fixed::Fixed*> value, unsigned int scale)
{
    *value = static_cast<fixed::Fixed>(*value * scale) / 100;
}

void doom::mainSetup()
{
    deh::buildBexTables();

    identifyVersion();

    nomonsters = argMeta.noMonsters;
    respawnparm = argMeta.respawn;
    fastparm = argMeta.fast;

    switch (doomstat::gamemode)
    {
    case defs::GameMode::RETAIL:
        if (doomstat::gamemission == defs::GameMission::CHEX)
        {
            doomverstr = "Chex(R) Quest";
        }
        else
        {
            doomverstr = "The Ultimate DOOM";
        }
        break;
    case defs::GameMode::SHAREWARE:
        doomverstr = "DOOM Shareware";
        break;
    case defs::GameMode::REGISTERED:
        doomverstr = "DOOM Registered";
        break;
    case defs::GameMode::COMMERCIAL:
        switch (doomstat::gamemission)
        {
        case defs::GameMission::PLUT:
            doomverstr = "Final DOOM - The Plutonia Experiment";
            break;
        case defs::GameMission::TNT:
            doomverstr = "Final DOOM - TNT: Evilution";
            break;
        case defs::GameMission::HACX:
            doomverstr = "HACX - Twitch 'n Kill";
            break;
        default:
            doomverstr = "DOOM 2: Hell on Earth";
        }
        break;
    default:
        doomverstr = "Public DOOM";
    }

    if (bfgedition)
    {
        doomverstr += " (BFG Edition)";
    }

    spdlog::info("{} (built {}), playing: {}", PACKAGE_NAME, version_date, doomverstr);

    if (argMeta.devparm)
    {
        spdlog::info("{}", DEVSTR);
    }

    if (argMeta.turbo.has_value())
    {
        auto turbo = argMeta.turbo.value();
        math::clampInPlace<decltype(turbo)>(&turbo, 10, 400);
        spdlog::info("turbo scale: {}", turbo);
        turboScale(&game::forwardMove[0], turbo);
        turboScale(&game::forwardMove[1], turbo);
        turboScale(&game::sideMove[0], turbo);
        turboScale(&game::sideMove[1], turbo);
    }

    doomstat::modifiedGame = false;

    startSkill = defs::Skill::SK_NONE;
    startEpisode = 1;
    startMap = 1;
    autoStart = false;

    if (argMeta.skill.has_value())
    {
        // this is a valid skill, it's validated in arglex
        startSkill = static_cast<defs::Skill>(argMeta.skill.value() - 1);
        autoStart = true;
    }
    if (argMeta.warp.has_value())
    {
        const auto& warp = argMeta.warp.value();
        startMap = 0;
        autoStart = true;
        if (doomstat::gamemode == defs::GameMode::COMMERCIAL)
        {
            // use warp.first, as there is no episode/map separation in doom 2
            startMap = warp.first;
            // if warp.second was set, it is ignored
            // (example invocation: ezboom -iwad doom2 -warp 1 2, will take player to
            // MAP01)
        }
        else
        {
            startEpisode = warp.first;
            if (warp.second.has_value())
            {
                startMap = warp.second.value();
            }
        }
    }

    nomusicparm = argMeta.noSound || argMeta.noMusic;
    nosfxparm = argMeta.noSound || argMeta.noSfx;

    game::nodrawers = argMeta.noDraw;
    game::noblit = argMeta.noBlit;

    if (argMeta.viewAngle.has_value())
    {
        render::viewAngleOffset = static_cast<int>((8 - argMeta.viewAngle.value()) * tables::ANG45);
    }

    game::reloadDefaults();
}
