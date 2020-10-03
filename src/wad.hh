//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_WAD_HH
#define DOOM_WAD_HH

#include "gsl_aliases.hh"

#include <string>
#include <string_view>
#include <vector>

namespace wad
{

enum class WadSource
{
    SOURCE_IWAD = 0,
    SOURCE_PRE,
    SOURCE_AUTO_LOAD,
    SOURCE_PWAD,
    SOURCE_LMP,
    SOURCE_NET,
    SOURCE_DEH,
    SOURCE_ERR,
};

struct WadInfo
{
    std::array<char, 4> identification;
    int32_t numLumps;
    int32_t infoTableOffset;
};

struct FileLump
{
    int32_t filePos{0};
    int32_t size{0};
    std::array<char, 8> name{};
};

struct WadFileInfo
{
    std::string name;
    WadSource src;
    int handle;
};

enum class LumpInfoNamespace
{
    NS_GLOBAL = 0,
    NS_SPRITES,
    NS_FLATS,
    NS_COLORMAPS,
    NS_PRBOOM,
    NS_DEMOS,
    NS_HIRES,
};

enum class LumpFlags
{
    LUMP_NONE = 0x0,
    LUMP_STATIC = 0x1,
    LUMP_CM2RGB = 0x2,
    LUMP_PRBOOM = 0x4,
};

struct LumpInfo
{
    std::array<char, 9> name{};
    int32_t size{0};

    int32_t index{0};
    int32_t next{0};

    LumpInfoNamespace liNamespace{LumpInfoNamespace::NS_GLOBAL};
    WadFileInfo* wadFile{nullptr};
    int32_t position{0};
    WadSource source{WadSource::SOURCE_IWAD};
    LumpFlags flags{0};
};

extern std::vector<WadFileInfo> wadfiles;
extern std::vector<LumpInfo> lumpinfo;

int findNumFromName(std::string_view name, LumpInfoNamespace ns, int lump);
static inline int findNumFromName(std::string_view name, int lump)
{
    return findNumFromName(name, LumpInfoNamespace::NS_GLOBAL, lump);
}
void addDefaultExtension(std::string& path, std::string_view ext);
void init();
void addFile(WadFileInfo& wadfile);
void extractFileBase(std::string_view path, char* dest);

} // namespace wad

#endif // DOOM_WAD_HH
