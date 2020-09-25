//
// Created by kyle on 9/24/20.
//

#ifndef EZ_BOOM_ITEMS_HH
#define EZ_BOOM_ITEMS_HH

#include "defs.hh"
#include "info.hh"
#include "map.hh"

namespace items
{

struct WeaponInfo
{
    defs::AmmoType ammo;
    info::StateEnum upState;
    info::StateEnum downState;
    info::StateEnum readyState;
    info::StateEnum attackState;
    info::StateEnum flashState;
};

extern constinit map::map<defs::WeaponType, WeaponInfo, 11> weaponinfo;
extern constinit map::map<defs::WeaponType, int, 11> ammopershot;

} // namespace items

#endif // EZ_BOOM_ITEMS_HH
