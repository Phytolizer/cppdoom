//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DEH_HH
#define DOOM_DEH_HH

#include "info.hh"
#include "think.hh"

#include <cstddef>
#include <optional>
#include <string>

namespace deh
{

extern std::vector<think::ActionF> codeptr;
extern std::vector<std::string> spriteNames;
extern std::vector<std::string> musicNames;
extern std::vector<std::string> soundNames;
extern std::optional<int> dehMaxSoul;
extern std::optional<int> dehMegaHealth;
extern std::optional<int> dehMaxHealth;

void buildBexTables();
void applyCompatibility();

} // namespace deh

#endif // DOOM_DEH_HH
