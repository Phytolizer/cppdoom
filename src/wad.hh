//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_WAD_HH
#define DOOM_WAD_HH

#include <gsl/gsl>
#include <string_view>

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
  int32_t filePos;
  int32_t size;
  std::array<char, 8> name;
};

struct WadFileInfo
{
  std::string name;
  WadSource src;
  int handle;
};

void addDefaultExtension(gsl::not_null<std::string*> path,
                         std::string_view ext);

extern std::vector<WadFileInfo> wadfiles;

} // namespace wad

#endif // DOOM_WAD_HH
