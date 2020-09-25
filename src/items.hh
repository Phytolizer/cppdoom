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

constinit auto weaponinfo = map::map<defs::WeaponType, WeaponInfo, 11>{{{
    {defs::WeaponType::WP_FIST,
     {
         defs::AmmoType::AM_NOAMMO,
         info::StateEnum::S_PUNCHUP,
         info::StateEnum::S_PUNCHDOWN,
         info::StateEnum::S_PUNCH,
         info::StateEnum::S_PUNCH1,
         info::StateEnum::S_NULL,
     }},
    {defs::WeaponType::WP_PISTOL,
     {
         defs::AmmoType::AM_CLIP,
         info::StateEnum::S_PISTOLUP,
         info::StateEnum::S_PISTOLDOWN,
         info::StateEnum::S_PISTOL,
         info::StateEnum::S_PISTOL1,
         info::StateEnum::S_PISTOLFLASH,
     }},
    {defs::WeaponType::WP_SHOTGUN,
     {
         defs::AmmoType::AM_SHELL,
         info::StateEnum::S_SGUNUP,
         info::StateEnum::S_SGUNDOWN,
         info::StateEnum::S_SGUN,
         info::StateEnum::S_SGUN1,
         info::StateEnum::S_SGUNFLASH1,
     }},
    {defs::WeaponType::WP_CHAINGUN,
     {
         defs::AmmoType::AM_CLIP,
         info::StateEnum::S_CHAINUP,
         info::StateEnum::S_CHAINDOWN,
         info::StateEnum::S_CHAIN,
         info::StateEnum::S_CHAIN1,
         info::StateEnum::S_CHAINFLASH1,
     }},
    {defs::WeaponType::WP_MISSILE,
     {
         defs::AmmoType::AM_MISL,
         info::StateEnum::S_MISSILEUP,
         info::StateEnum::S_MISSILEDOWN,
         info::StateEnum::S_MISSILE,
         info::StateEnum::S_MISSILE1,
         info::StateEnum::S_MISSILEFLASH1,
     }},
    {defs::WeaponType::WP_PLASMA,
     {
         defs::AmmoType::AM_CELL,
         info::StateEnum::S_PLASMAUP,
         info::StateEnum::S_PLASMADOWN,
         info::StateEnum::S_PLASMA,
         info::StateEnum::S_PLASMA1,
         info::StateEnum::S_PLASMAFLASH1,
     }},
    {defs::WeaponType::WP_BFG,
     {
         defs::AmmoType::AM_CELL,
         info::StateEnum::S_BFGUP,
         info::StateEnum::S_BFGDOWN,
         info::StateEnum::S_BFG,
         info::StateEnum::S_BFG1,
         info::StateEnum::S_BFGFLASH1,
     }},
    {defs::WeaponType::WP_CHAINSAW,
     {
         defs::AmmoType::AM_NOAMMO,
         info::StateEnum::S_SAWUP,
         info::StateEnum::S_SAWDOWN,
         info::StateEnum::S_SAW,
         info::StateEnum::S_SAW1,
         info::StateEnum::S_NULL,
     }},
    {defs::WeaponType::WP_SUPERSHOTGUN,
     {
         defs::AmmoType::AM_SHELL,
         info::StateEnum::S_DSGUNUP,
         info::StateEnum::S_DSGUNDOWN,
         info::StateEnum::S_DSGUN,
         info::StateEnum::S_DSGUN1,
         info::StateEnum::S_DSGUNFLASH1,
     }},
    {defs::WeaponType::WP_NOCHANGE,
     {
         defs::AmmoType::AM_NOAMMO,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
     }},
    {defs::WeaponType::NUMWEAPONS,
     {
         defs::AmmoType::AM_NOAMMO,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
         info::StateEnum::S_NULL,
     }},
}}};

} // namespace items

constinit auto ammopershot = map::map<defs::WeaponType, int, 11>{{{
    {defs::WeaponType::WP_FIST, 0},
    {defs::WeaponType::WP_PISTOL, 1},
    {defs::WeaponType::WP_SHOTGUN, 1},
    {defs::WeaponType::WP_CHAINGUN, 1},
    {defs::WeaponType::WP_MISSILE, 1},
    {defs::WeaponType::WP_PLASMA, 1},
    {defs::WeaponType::WP_BFG, 40},
    {defs::WeaponType::WP_CHAINSAW, 0},
    {defs::WeaponType::WP_SUPERSHOTGUN, 2},
    {defs::WeaponType::WP_NOCHANGE, 0},
    {defs::WeaponType::NUMWEAPONS, 0},
}}};

#endif // EZ_BOOM_ITEMS_HH
