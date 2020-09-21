//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_PSPR_HH
#define DOOM_PSPR_HH

#include "fixed.hh"

namespace info {
struct State;
}

namespace pspr
{

extern int weapon_attack_alignment;

enum class PSprEnum
{
  PS_WEAPON,
  PS_FLASH,
  NUMPSPRITES,
};

struct PSpDef
{
  info::State *state;
  int32_t tics;
  fixed::Fixed sx;
  fixed::Fixed sy;
};

}

#endif // DOOM_PSPR_HH
