//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_STAT_HH
#define DOOM_STAT_HH

#include "defs.hh"
namespace doomstat
{

enum class CompLevel
{
  Doom12,
  Doom1666,
  Doom219,
  UltDoom,
  FinalDoom,
  DosDoom,
  TasDoom,
  Boom,
  Boom201,
  Boom202,
  LxDoom,
  Mbf,
  PrBoom1,
  PrBoom2,
  PrBoom3,
  PrBoom4,
  PrBoom5,
  PrBoom6,
  MAX_COMPATIBILITY_LEVEL,
};

enum class DemoInsurance
{
  Never,
  Always,
  DuringDemoRecording,
};

extern bool doom_weapon_toggles;
extern bool flashing_hom;
extern bool modifiedGame;

extern bool player_bobbing;
extern bool default_player_bobbing;

extern bool variable_friction;
extern bool default_variable_friction;

extern bool weapon_recoil;
extern bool default_weapon_recoil;

extern CompLevel default_compatibility_level;
extern DemoInsurance default_demo_insurance;

extern defs::GameMission gamemission;
extern defs::GameMode gamemode;
extern defs::Language language;


} // namespace doomstat

#endif // DOOM_STAT_HH
