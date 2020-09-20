//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_WAD_HH
#define DOOM_WAD_HH

#include <gsl/gsl>
#include <string_view>

namespace wad
{

void addDefaultExtension(gsl::not_null<std::string *> path,
                         std::string_view ext);

}

#endif // DOOM_WAD_HH
