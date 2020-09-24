//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_PSPR_HH
#define DOOM_PSPR_HH

#include "fixed.hh"
#include "gsl_aliases.hh"
#include "info.hh"

namespace info
{
struct State;
}

namespace pspr
{

extern int weapon_attack_alignment;

constexpr const auto WEAPONTOP = fixed::FRACUNIT * 32;

enum class PSprEnum
{
  PS_WEAPON,
  PS_FLASH,
  NUMPSPRITES,
};

struct PSpDef
{
  info::State* state;
  int32_t tics;
  fixed::Fixed sx;
  fixed::Fixed sy;
};

void setPsprite(NotNull<player::Player*> player, PSprEnum position,
                info::StateEnum state);
void fireWeapon(NotNull<player::Player*> player);

} // namespace pspr

#endif // DOOM_PSPR_HH
