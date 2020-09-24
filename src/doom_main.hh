//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DOOM_MAIN_HH
#define DOOM_DOOM_MAIN_HH

#include "defs.hh"
namespace doom
{

extern bool fastparm;
extern bool nomonsters;
extern bool respawnparm;
extern defs::Skill startSkill;

void main();
void mainSetup();

} // namespace doom

#endif // DOOM_DOOM_MAIN_HH
