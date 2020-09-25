#include "arglex.hh"

#include <boost/algorithm/string.hpp>
#include <fmt/core.h>
#include <regex>
#include <string>
#include <strtk.hpp>
#include <vector>

#include "compatibility.hh"
#include "doomstat.hh"
#include "string_tools.hh"

using namespace boost::variant2;
using namespace arglex;

std::vector<Arg> arglex::lexArgs(int argc, const char* const* argv)
{
    std::vector<Arg> args{};
    gsl::span cArgs{argv, static_cast<size_t>(argc)};
    std::transform(cArgs.begin(), cArgs.end(), std::back_inserter(args), [](auto cArg) { return lexArg(cArg); });
    return args;
}

variant<ArgMeta, std::string> arglex::parseArgs(const std::vector<Arg>& args)
{
    ArgMeta argMeta;
    argMeta.argv0 = args[0].value;
    bool firstSwitch = false;

    for (auto arg = next(args.begin()); arg != args.end(); ++arg)
    {
        if (arg->type == ArgType::Positional)
        {
            // positional args
            if (!firstSwitch)
            {
                argMeta.handleLooseArg(*arg);
            }
            else
            {
                return fmt::format("unexpected positional argument: {}", arg->value);
            }
        }
        else
        {
            // flags
            firstSwitch = true;

            if (arg->value == "complevel")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-complevel requires an argument";
                }
                auto complevel = string_tools::parseString<uint32_t>(arg->value);

                if (!complevel.has_value() ||
                    complevel.value() >= static_cast<uint32_t>(doomstat::CompLevel::MAX_COMPATIBILITY_LEVEL))
                {
                    return fmt::format("bad argument to -complevel: {} (expected integer)", arg->value);
                }
                // negative number hack (arglex is very limited)
                if (arg->type == ArgType::Flag)
                {
                    complevel.value() = -complevel.value();
                }
                argMeta.complevel = complevel.value();
            }
            else if (arg->value == "width")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-width requires an argument";
                }
                auto width = string_tools::parseString<uint32_t>(arg->value);
                if (!width.has_value())
                {
                    return fmt::format("bad argument to -width: {} (expected integer)", arg->value);
                }
                argMeta.width = width.value();
            }
            else if (arg->value == "height")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-height requires an argument";
                }
                auto height = string_tools::parseString<uint32_t>(arg->value);
                if (!height.has_value())
                {
                    return fmt::format("bad argument to -height: {} (expected integer)", arg->value);
                }
                argMeta.height = height.value();
            }
            else if (arg->value == "viewangle")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-viewangle requires an argument";
                }
                auto viewAngle = string_tools::parseString<uint8_t>(arg->value);
                if (!viewAngle.has_value() || viewAngle > 7)
                {
                    return fmt::format("bad argument to -viewangle: {} (expected integer 0..7)", arg->value);
                }
                argMeta.viewAngle = viewAngle;
            }
            else if (arg->value == "vidmode")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-vidmode requires an argument";
                }
                std::string mode = arg->value;
                if (mode == "8" || boost::iequals(mode, "8bit"))
                {
                    argMeta.vidMode = VideoMode::Mode8;
                }
                else if (mode == "15" || boost::iequals(mode, "15bit"))
                {
                    argMeta.vidMode = VideoMode::Mode15;
                }
                else if (mode == "16" || boost::iequals(mode, "16bit"))
                {
                    argMeta.vidMode = VideoMode::Mode16;
                }
                else if (mode == "32" || boost::iequals(mode, "32bit"))
                {
                    argMeta.vidMode = VideoMode::Mode32;
                }
                else if (boost::iequals(mode, "gl") || boost::iequals(mode, "opengl"))
                {
                    argMeta.vidMode = VideoMode::ModeGL;
                }
                else
                {
                    return fmt::format("bad argument to -vidmode: {} is not a valid video mode", arg->value);
                }
            }
            else if (arg->value == "fullscreen")
            {
                argMeta.fullscreen = true;
            }
            else if (arg->value == "nofullscreen")
            {
                argMeta.fullscreen = false;
            }
            else if (arg->value == "window")
            {
                argMeta.tempFullscreen = false;
            }
            else if (arg->value == "nowindow")
            {
                argMeta.tempFullscreen = true;
            }
            else if (arg->value == "iwad")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-iwad requires an argument";
                }
                argMeta.iwad = arg->value;
            }
            else if (arg->value == "file")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-file requires an argument";
                }
                argMeta.files.push_back(arg->value);
                while (next(arg) != args.end() && next(arg)->type == ArgType::Positional)
                {
                    argMeta.files.push_back(next(arg)->value);
                    ++arg;
                }
            }
            else if (arg->value == "deh")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-deh requires an argument";
                }
                argMeta.dehs.push_back(arg->value);
            }
            else if (arg->value == "loadgame")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-loadgame requires an argument";
                }
                argMeta.loadGame = arg->value;
            }
            else if (arg->value == "warp")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-warp requires an argument";
                }
                Warp warp{};
                if (!string_tools::parseString<uint8_t>(arg->value, &warp.first))
                {
                    return fmt::format("bad argument to -warp: {} (expected integer)", arg->value);
                }
                if (next(arg) != args.end() && next(arg)->type == ArgType::Positional)
                {
                    ++arg;
                    warp.second = string_tools::parseString<uint8_t>(arg->value);
                    if (warp.second.has_value())
                    {
                        return fmt::format("bad second argument to -warp: {} (expected integer)", arg->value);
                    }
                }
                argMeta.warp = warp;
            }
            else if (arg->value == "skill")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-skill requires an argument";
                }
                auto skill = string_tools::parseString<uint8_t>(arg->value);
                if (!skill.has_value() || skill < 1 || skill > 5)
                {
                    return fmt::format("bad argument to -skill: {} (expected an integer 1..5)", arg->value);
                }
                argMeta.skill = skill.value();
            }
            else if (arg->value == "respawn")
            {
                argMeta.respawn = true;
            }
            else if (arg->value == "fast")
            {
                argMeta.fast = true;
            }
            else if (arg->value == "nomonsters")
            {
                argMeta.noMonsters = true;
            }
            else if (arg->value == "net")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-net requires an argument";
                }
                argMeta.net = arg->value;
            }
            else if (arg->value == "port")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-port requires an argument";
                }
                auto port = string_tools::parseString<uint32_t>(arg->value);
                if (!port.has_value())
                {
                    return fmt::format("bad argument to -port: {} (expected integer)", arg->value);
                }
                argMeta.port = port.value();
            }
            else if (arg->value == "solo-net")
            {
                argMeta.soloNet = true;
            }
            else if (arg->value == "record")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-record requires an argument";
                }
                argMeta.record = arg->value;
            }
            else if (arg->value == "recordfrom")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-recordfrom requires an argument";
                }
                argMeta.recordFrom = arg->value;
            }
            else if (arg->value == "recordfromto")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-recordfromto requires 2 arguments";
                }
                RecordFromTo recordFromTo;
                recordFromTo.from = arg->value;
                ++arg;
                if (arg == args.end())
                {
                    return "-recordfromto requires 2 arguments";
                }
                recordFromTo.to = arg->value;
                argMeta.recordFromTo = recordFromTo;
            }
            else if (arg->value == "playdemo")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-playdemo requires an argument";
                }
                argMeta.playdemo = arg->value;
            }
            else if (arg->value == "timedemo")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-timedemo requires an argument";
                }
                argMeta.timedemo = arg->value;
            }
            else if (arg->value == "fastdemo")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-fastdemo requires an argument";
                }
                argMeta.fastdemo = arg->value;
            }
            else if (arg->value == "ffmap")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-ffmap requires an argument";
                }
                auto ffmap = string_tools::parseString<uint8_t>(arg->value);
                if (!ffmap.has_value())
                {
                    return fmt::format("bad argument to -ffmap: {} (expected integer)", arg->value);
                }
                argMeta.ffmap = ffmap.value();
            }
            else if (arg->value == "nosound")
            {
                argMeta.noSound = true;
            }
            else if (arg->value == "nosfx")
            {
                argMeta.noSfx = true;
            }
            else if (arg->value == "nomusic")
            {
                argMeta.noMusic = true;
            }
            else if (arg->value == "nojoy")
            {
                argMeta.noJoy = true;
            }
            else if (arg->value == "nomouse")
            {
                argMeta.noMouse = true;
            }
            else if (arg->value == "noaccel")
            {
                argMeta.noAccel = true;
            }
            else if (arg->value == "1" || arg->value == "2" || arg->value == "3")
            {
                argMeta.scaleFactor = arg->value[0] - '0';
            }
            else if (arg->value == "config")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-config requires an argument";
                }
                argMeta.config = arg->value;
            }
            else if (arg->value == "save")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-save requires an argument";
                }
                argMeta.save = arg->value;
            }
            else if (arg->value == "devparm")
            {
                argMeta.devparm = true;
            }
            else if (arg->value == "debugfile")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-debugfile requires an argument";
                }
                argMeta.debugFile = arg->value;
            }
            else if (arg->value == "nodraw")
            {
                argMeta.noDraw = true;
            }
            else if (arg->value == "noblit")
            {
                argMeta.noBlit = true;
            }
            else if (arg->value == "bexout")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-bexout requires an argument";
                }
                argMeta.bexOut = arg->value;
            }
            else if (arg->value == "turbo")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-turbo requires an argument";
                }
                uint32_t turbo = 0;
                if (!string_tools::parseString<uint32_t>(arg->value, &turbo))
                {
                    return fmt::format("bad argument to -turbo: {} (expected integer)", arg->value);
                }
                argMeta.turbo = turbo;
            }
            else if (arg->value == "dogs")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-dogs requires an argument";
                }
                uint8_t dogs = 0;
                if (!string_tools::parseString<uint8_t>(arg->value, &dogs))
                {
                    return fmt::format("bad argument to -dogs: {} (expected integer)");
                }
                argMeta.dogs = dogs;
            }
            else if (arg->value == "emulate")
            {
                ++arg;
                if (arg == args.end())
                {
                    return "-emulate requires an argument";
                }
                std::array<uint8_t, 4> b{0, 0, 0, 0};
                std::regex parserRegex{R"((\d+)\.(\d+)\.(\d+)\.(\d+))"};
                std::smatch sm;
                if (!std::regex_match(arg->value, sm, parserRegex))
                {
                    return fmt::format("bad argument to -emulate: {} (expected format "
                                       "n.n.n.n, where n represents numbers)");
                }
                for (int i = 0; i < 4; ++i)
                {
                    if (!string_tools::parseString<uint8_t>(sm[i + 1].str(), &gsl::at(b, i)))
                    {
                        return fmt::format("bad argument to -emulate: number {} is not between 0 and 255",
                                           sm[i + 1].str());
                    }
                }
                argMeta.emulate = (b[0] << 24) + (b[1] << 16) + (b[2] << 8) + b[3];
            }
            else
            {
                // check PrBoom compatibility flags
                bool isPrBoomCompatFlag = false;
                for (auto& comp : prboomCompatibility)
                {
                    if (arg->value == comp.cmd)
                    {
                        comp.state = true;
                        isPrBoomCompatFlag = true;
                    }
                }
                if (!isPrBoomCompatFlag)
                {
                    return fmt::format("unknown parameter -{}", arg->value);
                }
            }
        }
    }

    if ((argMeta.record.has_value() || argMeta.recordFrom.has_value() || argMeta.recordFromTo.has_value()) &&
        (argMeta.playdemo.has_value() || argMeta.timedemo.has_value() || argMeta.fastdemo.has_value()))
    {
        return "cannot record and play back a demo at the same time";
    }

    return argMeta;
}
Arg arglex::lexArg(const std::string& arg)
{
    if (arg[0] == '-')
    {
        return Arg{arg.substr(1), ArgType::Flag};
    }
    return Arg{arg, ArgType::Positional};
}

void ArgMeta::handleLooseArg(const Arg& arg)
{
    if (strtk::ends_with(arg.value, ".lmp"))
    {
        lmps.push_back(arg.value);
    }
    else if (strtk::ends_with(arg.value, ".deh") || strtk::ends_with(arg.value, ".bex"))
    {
        dehs.push_back(arg.value);
    }
    else
    {
        wads.push_back(arg.value);
    }
}
