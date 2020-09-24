//
// Created by kyle on 9/19/20.
//

#ifndef CPPDOOM_GAME_HH
#define CPPDOOM_GAME_HH

#include "defs.hh"
#include "fixed.hh"
#include <array>

namespace game
{

extern bool boom_autoswitch;
extern bool haswolflevels;
extern bool netgame;
extern bool noblit;
extern bool nodrawers;
extern bool demoplayback;
extern bool singledemo;
extern bool netdemo;
extern bool done_autoswitch;

extern std::array<bool, defs::MAXPLAYERS> playerInGame;

extern std::array<fixed::Fixed, 2> forwardMove;
extern std::array<fixed::Fixed, 2> sideMove;

extern int max_player_corpses;
extern int default_skill;
extern int consolePlayer;

// Constants

extern const std::array<fixed::Fixed, 2> forwardMoveNormal;
extern const std::array<fixed::Fixed, 2> sideMoveNormal;

// Functions

int getHelpers();
void reloadDefaults();
void compatibility();

} // namespace game

#endif // DOOM_GAME_HH
