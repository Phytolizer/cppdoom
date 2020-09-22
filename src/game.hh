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
extern bool netgame;
extern bool noblit;
extern bool nodrawers;
extern bool demoplayback;
extern bool singledemo;
extern bool netdemo;

extern bool playerInGame[];

extern fixed::Fixed forwardMove[];
extern fixed::Fixed sideMove[];

extern int max_player_corpses;
extern int default_skill;
extern int consolePlayer;

// Constants

extern const fixed::Fixed forwardMoveNormal[];
extern const fixed::Fixed sideMoveNormal[];

// Functions

int getHelpers();
void reloadDefaults();
void compatibility();

} // namespace game

#endif // DOOM_GAME_HH
