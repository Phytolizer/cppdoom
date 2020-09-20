//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_STAT_HH
#define DOOM_STAT_HH

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

extern CompLevel default_compatibility_level;
extern bool flashing_hom;
extern DemoInsurance default_demo_insurance;
extern bool default_weapon_recoil;
extern bool default_player_bobbing;
extern bool doom_weapon_toggles;

} // namespace doomstat

#endif // DOOM_STAT_HH
