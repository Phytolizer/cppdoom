//
// Created by kyle on 9/19/20.
//

#include "game.hh"
#include "doomstat.hh"

bool game::boom_autoswitch;
bool game::haswolflevels = false;
bool game::noblit;
bool game::nodrawers;

fixed::Fixed game::forwardMove[2] = {0x19, 0x32};
fixed::Fixed game::sideMove[2] = {0x18, 0x28};

int game::max_player_corpses;
int game::default_skill;

// Constants

const fixed::Fixed game::forwardMoveNormal[2] = {0x19, 0x32};
const fixed::Fixed game::sideMoveNormal[2] = {0x18, 0x28};

// Functions

void game::reloadDefaults()
{
  doomstat::weapon_recoil = doomstat::default_weapon_recoil;
  doomstat::player_bobbing = doomstat::default_player_bobbing;
  doomstat::variable_friction = doomstat::default_variable_friction;
}
