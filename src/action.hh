//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_ACTION_HH
#define DOOM_ACTION_HH

#include <boost/variant2/variant.hpp>

#include "gsl_aliases.hh"

namespace player
{
struct Player;
}

namespace mobj
{
struct MapObject;
}

namespace pspr
{
struct PSpDef;
}

namespace action
{

using VoidAction = void (*)();
using PlayerAction = void (*)(player::Player&);
using PlayerPsprAction = void (*)(player::Player&, pspr::PSpDef&);
using MapObjectAction = void (*)(mobj::MapObject);
using Action = boost::variant2::variant<VoidAction, PlayerAction, PlayerPsprAction, MapObjectAction>;

// TODO(kyle): action functions go here!

void doNothing();
void light0(player::Player& player);
void reFire(player::Player& player);
void light1(player::Player& player);
void light2(player::Player& player);
void weaponReady(player::Player& player, pspr::PSpDef& psp);
void fireOldBfg(player::Player& player);
void lower(player::Player& player, pspr::PSpDef& psp);
void raise(player::Player& player, pspr::PSpDef& psp);
void punch(player::Player& player);

} // namespace action

#endif // DOOM_ACTION_HH
