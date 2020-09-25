//
// Created by kyle on 9/25/20.
//

#ifndef EZ_BOOM_GAME_MAP_HH
#define EZ_BOOM_GAME_MAP_HH

#include "fixed.hh"
#include "mobj.hh"
namespace game_map
{

bool tryMove(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y, bool dropoff);

}

#endif // EZ_BOOM_GAME_MAP_HH
