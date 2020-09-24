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
using PlayerAction = void (*)(NotNull<player::Player*>);
using PlayerPsprAction = void (*)(NotNull<player::Player*>,
                                  NotNull<pspr::PSpDef*>);
using MapObjectAction = void (*)(NotNull<mobj::MapObject*>);
using Action = boost::variant2::variant<VoidAction, PlayerAction,
                                        PlayerPsprAction, MapObjectAction>;

// TODO(kyle): action functions go here!

void doNothing();
void light0(NotNull<player::Player*> player);
void weaponReady(NotNull<player::Player*> player, pspr::PSpDef* psp);

} // namespace action

#endif // DOOM_ACTION_HH
