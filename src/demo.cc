//
// Created by kyle on 9/19/20.
//

#include "demo.hh"

#include "doom.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "path.hh"
#include "prboom.hh"
#include "system.hh"
#include "wad.hh"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

bool demo::demo_smoothturns = false;
int demo::demo_smoothturnsfactor = 6;
std::string demo::getwad_cmdline{};

bool demo::isDemoPlayback()
{
    return argMeta.playdemo.has_value() || argMeta.timedemo.has_value() || argMeta.fastdemo.has_value();
}
bool demo::demoCompatibility()
{
    return doomstat::compatibility_level < doomstat::CompLevel::Boom;
}
bool demo::tryGetWad(std::string_view name)
{
    if (getwad_cmdline.empty() || name.empty())
    {
        return false;
    }

    std::string wadname = path::findFileName(name);
    wad::addDefaultExtension(&wadname, ".wad");
    auto wadname_p = getwad_cmdline.find("%wadname%");
    std::string cmdline;
    if (wadname_p == std::string::npos)
    {
        cmdline = fmt::format("{} {}", getwad_cmdline, wadname);
    }
    else
    {
        cmdline =
            fmt::format("{}{}{}", getwad_cmdline, wadname, wadname.substr(wadname_p + std::string{"%wadname%"}.size()));
    }

    auto msg = fmt::format("The necessary WAD has not been found.\nDo you want to search for '{}'?\n\nCommand "
                           "line:\n{}\n\nBe careful! Execution of an unknown program is unsafe.",
                           wadname, cmdline);

    bool result{false};

    if (prboom::messageBox(msg, prboom::MessageBoxFlag::PRB_MB_DEFBUTTON2 | prboom::MessageBoxFlag::PRB_MB_YESNO) ==
        prboom::MessageBoxResponse::PRB_IDYES)
    {
        spdlog::info("demo::tryGetWad: trying to get {} from somewhere", name);
        auto ret = system(cmdline.data());
        if (ret == 0)
        {
            auto str = sys::findFile(name, ".wad");
            if (str.has_value())
            {
                spdlog::info("demo::tryGetWad: successfully received");
                result = true;
            }
        }
        else
        {
            spdlog::error("demo::tryGetWad: execution failed: {}", strerror(errno));
        }
    }

    return result;
}
void demo::smooth_playing::reset(NotNull<player::Player*> player)
{
    // TODO(kyle)
}
