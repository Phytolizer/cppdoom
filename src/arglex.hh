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
    uint8_t first;
    std::optional<uint8_t> second;
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
    std::vector<std::string> wads;
    std::vector<std::string> dehs;
    std::vector<std::string> lmps;
    std::vector<std::string> files;
    std::string argv0;
    std::optional<std::string> record;
    std::optional<std::string> recordFrom;
    std::optional<std::string> playdemo;
    std::optional<std::string> timedemo;
    std::optional<std::string> fastdemo;
    std::optional<std::string> iwad;
    std::optional<std::string> loadGame;
    std::optional<std::string> net;
    std::optional<std::string> config;
    std::optional<std::string> save;
    std::optional<std::string> debugFile;
    std::optional<std::string> bexOut;
    std::optional<RecordFromTo> recordFromTo;
    std::optional<int32_t> complevel;
    std::optional<uint32_t> width;
    std::optional<uint32_t> height;
    std::optional<VideoMode> vidMode;
    std::optional<uint32_t> turbo;
    std::optional<uint32_t> port;
    std::optional<uint32_t> emulate;
    bool respawn = false;
    bool fast = false;
    bool noMonsters = false;
    bool soloNet = false;
    bool noSound = false;
    bool noSfx = false;
    bool noMusic = false;
    bool noJoy = false;
    bool noMouse = false;
    bool noAccel = false;
    bool devparm = false;
    bool noDraw = false;
    bool noBlit = false;
    std::optional<uint8_t> viewAngle;
    std::optional<bool> fullscreen;
    /// fullscreen for this session only
    std::optional<bool> tempFullscreen;
    std::optional<uint8_t> skill;
    std::optional<uint8_t> ffmap;
    std::optional<uint8_t> scaleFactor;
    std::optional<uint8_t> dogs;
    std::optional<Warp> warp;

    void handleLooseArg(const Arg& arg);
};

std::vector<Arg> lexArgs(int argc, const char* const* argv);
boost::variant2::variant<ArgMeta, std::string> parseArgs(const std::vector<Arg>& args);

Arg lexArg(const std::string& arg);
} // namespace arglex

#endif
