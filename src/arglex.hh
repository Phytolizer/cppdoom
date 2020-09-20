#ifndef DOOM_ARGLEX_HH
#define DOOM_ARGLEX_HH

#include <boost/variant2/variant.hpp>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace arglex
{

struct RecordFromTo
{
  std::string from;
  std::string to;
};

struct Warp
{
  uint8_t episode;
  uint8_t map;
};

enum class VideoMode
{
  Mode8,
  Mode15,
  Mode16,
  Mode32,
  ModeGL,
};

enum class ArgType
{
  Flag,
  Positional,
};

struct Arg
{
  std::string value;
  ArgType type;
};

struct ArgMeta
{
  std::string argv0;

  std::optional<std::string> record;
  std::optional<std::string> recordFrom;
  std::optional<RecordFromTo> recordFromTo;

  std::optional<std::string> playdemo;
  std::optional<std::string> timedemo;
  std::optional<std::string> fastdemo;

  std::vector<std::string> wads;
  std::vector<std::string> dehs;
  std::vector<std::string> lmps;

  std::optional<int32_t> complevel;

  std::optional<uint32_t> width;
  std::optional<uint32_t> height;
  std::optional<uint8_t> viewAngle;
  std::optional<VideoMode> vidMode;

  bool fullscreen;
  /// fullscreen for this session only
  bool tempFullscreen;

  std::optional<std::string> iwad;
  std::vector<std::string> files;

  std::optional<std::string> loadGame;
  std::optional<Warp> warp;
  std::optional<uint8_t> skill;

  bool respawn;
  bool fast;
  bool noMonsters;

  std::optional<std::string> net;
  std::optional<uint32_t> port;

  bool soloNet;

  std::optional<uint8_t> ffmap;

  bool noSound;
  bool noSfx;
  bool noMusic;
  bool noJoy;
  bool noMouse;
  bool noAccel;

  std::optional<uint8_t> scaleFactor;

  std::optional<std::string> config;
  std::optional<std::string> save;

  bool devparm;
  std::optional<std::string> debugFile;
  bool noDrawers;
  bool noBlit;
  std::optional<std::string> bexOut;

  void handleLooseArg(const Arg& arg);
};

std::vector<Arg> lexArgs(int argc, const char *const *argv);
boost::variant2::variant<ArgMeta, std::string>
parseArgs(const std::vector<Arg> &args);

} // namespace arglex

#endif
