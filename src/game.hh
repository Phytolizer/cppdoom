//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_GAME_HH
#define DOOM_GAME_HH

#include "fixed.hh"

namespace game
{

extern bool boom_autoswitch;
extern bool haswolflevels;
extern bool noblit;
extern bool nodrawers;

extern fixed::Fixed forwardMove[];
extern fixed::Fixed sideMove[];

extern int max_player_corpses;
extern int default_skill;

// Constants

extern const fixed::Fixed forwardMoveNormal[];
extern const fixed::Fixed sideMoveNormal[];

// Functions

void reloadDefaults();

} // namespace game

#endif // DOOM_GAME_HH
