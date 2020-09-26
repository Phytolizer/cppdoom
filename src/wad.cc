//
// Created by kyle on 9/20/20.
//

#include "wad.hh"

#include "config.h"
#include "demo.hh"
#include "doomdef.hh"
#include "swap.hh"
#include "system.hh"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <boost/algorithm/string.hpp>
#include <fcntl.h>
#include <memory>
#include <spdlog/spdlog.h>

std::vector<wad::WadFileInfo> wad::wadfiles;
std::vector<wad::LumpInfo> wad::lumpinfo;

void wad::addDefaultExtension(gsl::not_null<std::string*> path, std::string_view ext)
{
    for (auto p = path->rbegin(); p != path->rend(); --p)
    {
        if (*p == '/' || *p == '\\')
        {
            break;
        }
        if (*p == '.')
        {
            return;
        }
    }
    if (ext[0] != '.')
    {
        *path += ".";
    }
    *path += ext;
}
int wad::findNumFromName(std::string_view name, wad::LumpInfoNamespace ns, int lump)
{
    // TODO(kyle)
}
void wad::init()
{
    for (auto& wadfile : wadfiles)
    {
        addFile(&wadfile);
    }

    if (lumpinfo.empty())
    {
        spdlog::error("wad::init: no files found");
        exit(-1);
    }

    // TODO(kyle)
}
void wad::addFile(NotNull<wad::WadFileInfo*> wadfile)
{
    wadfile->handle = open(wadfile->name.data(), O_RDONLY | O_BINARY);

#ifdef HAVE_NET
    if (wadfile->handle == -1 && net::getWad(wadfile->name.data()))
    {
        wadfile->handle = open(wadfile->name, O_RDONLY | O_BINARY);
    }
#endif

    if (wadfile->handle == -1 && wadfile->name.size() > 4 && wadfile->src == WadSource::SOURCE_PWAD &&
        boost::iequals(wadfile->name.substr(wadfile->name.size() - 4), ".wad") && demo::tryGetWad(wadfile->name))
    {
        wadfile->handle = open(wadfile->name.data(), O_RDONLY | O_BINARY);
    }
    if (wadfile->handle == -1)
    {
        if (wadfile->name.size() <= 4 || (!boost::iequals(wadfile->name.substr(wadfile->name.size() - 4), ".lmp") &&
                                          !boost::iequals(wadfile->name.substr(wadfile->name.size() - 4), ".gwa")))
        {
            spdlog::error("wad::addFile: couldn't open {}", wadfile->name);
        }
        return;
    }
    spdlog::info("adding {}", wadfile->name);
    auto startLump = lumpinfo.size();

    LumpFlags flags{0};

    if (wadfile->src == WadSource::SOURCE_AUTO_LOAD)
    {
        auto len = std::string{PACKAGE_TARNAME ".wad"}.size();
        auto lenFile = wadfile->name.size();
        if (lenFile >= len && boost::iequals(wadfile->name.substr(lenFile - len), PACKAGE_TARNAME ".wad"))
        {
            flags = LumpFlags::LUMP_PRBOOM;
        }
    }

    std::vector<FileLump> fileInfo2Free{};
    WadInfo header{};
    if (wadfile->name.size() <= 4 || (!boost::iequals(wadfile->name.substr(wadfile->name.size() - 4), ".wad") &&
                                      !boost::iequals(wadfile->name.substr(wadfile->name.size() - 4), ".gwa")))
    {
        // single lump file

        fileInfo2Free.push_back({});
        fileInfo2Free.back().filePos = 0;
        fileInfo2Free.back().size = LITTLE_LONG(sys::fileLength(wadfile->handle));
        extractFileBase(wadfile->name, fileInfo2Free.back().name.data());
        lumpinfo.push_back({});
    }
    else
    {
        // WAD file

        sys::read(wadfile->handle, &header, sizeof(header));
        auto identification = std::string{header.identification.begin(), header.identification.end()};
        if (identification != "IWAD" && identification != "PWAD")
        {
            spdlog::error("wad::addFile, wad file {} doesn't have IWAD/PWAD id", wadfile->name);
            exit(-1);
        }
        header.numLumps = LITTLE_LONG(header.numLumps);
        header.infoTableOffset = LITTLE_LONG(header.infoTableOffset);
        fileInfo2Free.resize(header.numLumps);
        lseek(wadfile->handle, header.infoTableOffset, SEEK_SET);
        sys::read(wadfile->handle, fileInfo2Free.data(), header.numLumps * sizeof(FileLump));
        lumpinfo.resize(lumpinfo.size() + header.numLumps);
    }

    for (auto i = startLump; i < lumpinfo.size(); ++i)
    {
        auto& fileinfo = fileInfo2Free[i - startLump];
        auto& lump = lumpinfo[i];
        lump.flags = flags;
        lump.wadFile = wadfile;
        lump.position = LITTLE_LONG(fileinfo.filePos);
        lump.size = LITTLE_LONG(fileinfo.size);
        if (wadfile->src == WadSource::SOURCE_LMP)
        {
            lump.liNamespace = LumpInfoNamespace::NS_DEMOS;
        }
        else
        {
            lump.liNamespace = LumpInfoNamespace::NS_GLOBAL;
        }
        memcpy(lump.name.data(), fileinfo.name.data(), 8);
        lump.name[8] = '\0';
        lump.source = wadfile->src;
    }
}
void wad::extractFileBase(std::string_view path, char* dest)
{
    // TODO(kyle)
}
