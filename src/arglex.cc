#include "arglex.hh"

#include <boost/algorithm/string.hpp>
#include <fmt/core.h>
#include <string>
#include <strtk.hpp>
#include <vector>

std::vector<Arg> lexArgs(int argc, const char *const *argv)
{
  std::vector<Arg> args;
  for (int i = 0; i < argc; i++)
  {
    std::string arg = argv[i];
    if (arg[0] == '-')
    {
      args.push_back(Arg{arg.substr(1), ArgType::Flag});
    }
    else
    {
      args.push_back(Arg{arg, ArgType::Positional});
    }
  }
  return args;
}

boost::variant2::variant<ArgMeta, std::string>
parseArgs(const std::vector<Arg> &args)
{
  ArgMeta argMeta;
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
        int32_t complevel;
        ++arg;
        if (arg == args.end())
        {
          return "-complevel requires an argument";
        }
        if (!strtk::parse(arg->value, "", complevel))
        {
          return fmt::format(
              "bad argument to -complevel: {} (expected integer)", arg->value);
        }
        // negative number hack (arglex is very limited)
        if (arg->type == ArgType::Flag)
        {
          complevel = -complevel;
        }
        argMeta.complevel = complevel;
      }
      else if (arg->value == "width")
      {
        uint32_t width;
        ++arg;
        if (arg == args.end())
        {
          return "-width requires an argument";
        }
        if (!strtk::parse(arg->value, "", width))
        {
          return fmt::format("bad argument to -width: {} (expected integer)",
                             arg->value);
        }
        argMeta.width = width;
      }
      else if (arg->value == "height")
      {
        uint32_t height;
        ++arg;
        if (arg == args.end())
        {
          return "-height requires an argument";
        }
        if (!strtk::parse(arg->value, "", height))
        {
          return fmt::format("bad argument to -height: {} (expected integer)",
                             arg->value);
        }
        argMeta.height = height;
      }
      else if (arg->value == "viewangle")
      {
        uint8_t viewAngle = 0;
        ++arg;
        if (arg == args.end())
        {
          return "-viewangle requires an argument";
        }
        if (!strtk::parse(arg->value, "", viewAngle) || viewAngle > '7')
        {
          return fmt::format(
              "bad argument to -viewangle: {} (expected integer 0..7)",
              arg->value);
        }
        argMeta.viewAngle = viewAngle - '0';
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
          return fmt::format(
              "bad argument to -vidmode: {} is not a valid video mode",
              arg->value);
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
        if (arg == args.end() || arg->type == ArgType::Flag)
        {
          return "-file requires an argument";
        }
        while (arg != args.end() && arg->type == ArgType::Positional)
        {
          argMeta.files.push_back(arg->value);
          ++arg;
        }
      }
      else
      {
        return fmt::format("unknown parameter -{}", arg->value);
      }
    }
  }

  return argMeta;
}

void ArgMeta::handleLooseArg(Arg arg)
{
  if (strtk::ends_with(arg.value, ".lmp"))
  {
    lmps.push_back(arg.value);
  }
  else if (strtk::ends_with(arg.value, ".deh") ||
           strtk::ends_with(arg.value, ".bex"))
  {
    dehs.push_back(arg.value);
  }
  else
  {
    wads.push_back(arg.value);
  }
}
