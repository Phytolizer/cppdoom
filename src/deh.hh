//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DEH_HH
#define DOOM_DEH_HH

#include "info.hh"
#include "think.hh"

#include <cstddef>
#include <string>

namespace deh
{

extern think::ActionF codeptr[];
extern std::string spriteNames[];
extern std::string musicNames[];
extern std::string soundNames[];

void buildBexTables();

} // namespace deh

#endif // DOOM_DEH_HH
