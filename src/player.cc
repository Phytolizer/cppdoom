//
// Created by kyle on 9/20/20.
//

#include "player.hh"

#include "enum_ops.hh"

bool player::Player::ownsWeapon(defs::WeaponType wt)
{
    return this->weaponOwned[to_underlying(wt)];
}
bool player::Player::hasAmmo(defs::AmmoType at)
{
    return ammo[to_underlying(at)] > 0;
}
int32_t player::Player::getAmmo(defs::AmmoType at)
{
    return ammo[to_underlying(at)];
}
bool player::Player::hasPower(defs::PowerType pt)
{
    return powers[to_underlying(pt)] > 0;
}
