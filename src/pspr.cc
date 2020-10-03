//
// Created by kyle on 9/19/20.
//

#include "pspr.hh"

#include <spdlog/spdlog.h>

#include "defs.hh"
#include "doomstat.hh"
#include "enemy.hh"
#include "enum_ops.hh"
#include "info.hh"
#include "interactions.hh"
#include "items.hh"
#include "mobj.hh"
#include "player.hh"

int pspr::weapon_attack_alignment;
std::array<std::array<int, 10>, 2> pspr::weapon_preferences{};

void pspr::setPsprite(NotNull<player::Player*> player, pspr::PSprEnum position, info::StateEnum stateNum)
{
    PSpDef* psp = &player->psprites[position];

    do
    {
        if (stateNum == info::StateEnum::S_NULL)
        {
            psp->state = nullptr;
            break;
        }
        info::State* state = &info::states.at(stateNum);
        psp->state = state;
        psp->tics = state->durationTics;

        if (state->misc1 != 0)
        {
            psp->sx = state->misc1 << fixed::FRACBITS;
            psp->sy = state->misc2 << fixed::FRACBITS;
        }

        if (state->action.index() == 2)
        {
            boost::variant2::get<2>(state->action)(player, psp);
            if (psp->state == nullptr)
            {
                break;
            }
        }
        stateNum = psp->state->nextState;
    } while (psp->tics == 0);
}
void pspr::fireWeapon(NotNull<player::Player*> player)
{
    if (!checkAmmo(player))
    {
        // not enough ammo
        return;
    }

    mobj::setMobjState(player, info::StateEnum::S_PLAY_ATK1);
    auto newState = items::weaponinfo.at(player->readyWeapon).attackState;
    setPsprite(player, pspr::PSprEnum::PS_WEAPON, newState);
    enemy::noiseAlert(player, player);
}
void pspr::thrust(NotNull<player::Player*> player, tables::Angle angle, fixed::Fixed move)
{
    // TODO(kyle)
}
bool pspr::checkAmmo(NotNull<player::Player*> player)
{
    auto ammo = items::weaponinfo.at(player->readyWeapon).ammo;

    int count = 1;
    if (player->readyWeapon == defs::WeaponType::WP_BFG)
    {
        count = interactions::bfgcells;
    }
    else if (player->readyWeapon == defs::WeaponType::WP_SUPERSHOTGUN)
    {
        count = 2;
    }

    if (ammo == defs::AmmoType::AM_NOAMMO || player->ammo[to_underlying(ammo)] >= count)
    {
        return true;
    }

    if (doomstat::demo_compatibility())
    {
        player->pendingWeapon = switchWeapon(player);
        setPsprite(player, PSprEnum::PS_WEAPON, items::weaponinfo.at(player->readyWeapon).downState);
    }

    return false;
}
defs::WeaponType pspr::switchWeapon(NotNull<player::Player*> player)
{
    auto prefs = weapon_preferences[static_cast<std::size_t>(doomstat::demo_compatibility())];
    auto currentWeapon = player->readyWeapon;
    auto newWeapon = currentWeapon;
    std::size_t j = 0;
    for (auto i = to_underlying(defs::WeaponType::NUMWEAPONS) + 1; newWeapon == currentWeapon && i > 0; --i)
    {
        switch (prefs[j])
        {
        case 1:
            if (!player->hasPower(defs::PowerType::PW_STRENGTH))
            {
                break;
            }
        // fallthrough
        case 0:
            newWeapon = defs::WeaponType::WP_FIST;
            break;
        case 2:
            if (player->hasAmmo(defs::AmmoType::AM_CLIP))
            {
                newWeapon = defs::WeaponType::WP_PISTOL;
            }
            break;
        case 3:
            if (player->ownsWeapon(defs::WeaponType::WP_SHOTGUN) && player->hasAmmo(defs::AmmoType::AM_SHELL))
            {
                newWeapon = defs::WeaponType::WP_SHOTGUN;
            }
            break;
        case 4:
            if (player->ownsWeapon(defs::WeaponType::WP_CHAINGUN) && player->hasAmmo(defs::AmmoType::AM_CLIP))
            {
                newWeapon = defs::WeaponType::WP_CHAINGUN;
            }
            break;
        case 5:
            if (player->ownsWeapon(defs::WeaponType::WP_MISSILE) && player->hasAmmo(defs::AmmoType::AM_MISL))
            {
                newWeapon = defs::WeaponType::WP_MISSILE;
            }
            break;
        case 6:
            if (player->ownsWeapon(defs::WeaponType::WP_PLASMA) && doomstat::gamemode != defs::GameMode::SHAREWARE &&
                player->hasAmmo(defs::AmmoType::AM_CELL))
            {
                newWeapon = defs::WeaponType::WP_PLASMA;
            }
            break;
        case 7:
            if (player->ownsWeapon(defs::WeaponType::WP_BFG) && doomstat::gamemode != defs::GameMode::SHAREWARE &&
                player->getAmmo(defs::AmmoType::AM_CELL) >= (doomstat::demo_compatibility() ? 41 : 40))
            {
                newWeapon = defs::WeaponType::WP_BFG;
            }
            break;
        case 8:
            if (player->ownsWeapon(defs::WeaponType::WP_CHAINSAW))
            {
                newWeapon = defs::WeaponType::WP_CHAINSAW;
            }
            break;
        case 9:
            if (player->ownsWeapon(defs::WeaponType::WP_SUPERSHOTGUN) &&
                doomstat::gamemode == defs::GameMode::COMMERCIAL &&
                player->getAmmo(defs::AmmoType::AM_SHELL) >= (doomstat::demo_compatibility() ? 3 : 2))
            {
                newWeapon = defs::WeaponType::WP_SUPERSHOTGUN;
            }
            break;
        default:
            spdlog::error("pspr::switchWeapon: invalid weapon preference {}", j);
            exit(-1);
        }
    }
    return newWeapon;
}
