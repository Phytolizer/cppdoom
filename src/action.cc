//
// Created by kyle on 9/20/20.
//

#include "action.hh"
#include "defs.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "event.hh"
#include "game.hh"
#include "info.hh"
#include "items.hh"
#include "player.hh"
#include "pspr.hh"
#include "random.hh"
#include "sound.hh"
#include "tick.hh"

void action::light0(NotNull<player::Player*> player)
{
    player->extraLight = 0;
}
void action::weaponReady(NotNull<player::Player*> player, NotNull<pspr::PSpDef*> psp)
{
    if (player->state == &info::states.at(info::StateEnum::S_PLAY_ATK1) ||
        player->state == &info::states.at(info::StateEnum::S_PLAY_ATK2))
    {
        mobj::setMobjState(dynamic_cast<mobj::MapObject*>(player.get()), info::StateEnum::S_PLAY);
    }

    if (player->readyWeapon == defs::WeaponType::WP_CHAINSAW && psp->state == &info::states.at(info::StateEnum::S_SAW))
    {
        sound::startSound(dynamic_cast<mobj::MapObject*>(player.get()), info::Sfx::sfx_sawidl);
    }

    if (player->pendingWeapon != defs::WeaponType::WP_NOCHANGE || player->health == 0)
    {
        info::StateEnum newState = items::weaponinfo.at(player->readyWeapon).downState;
        pspr::setPsprite(player, pspr::PSprEnum::PS_WEAPON, newState);
        return;
    }

    if (static_cast<bool>(player->cmd.buttons & event::ButtonCode::BT_ATTACK))
    {
        if (!player->attackDown ||
            player->readyWeapon != defs::WeaponType::WP_MISSILE && player->readyWeapon != defs::WeaponType::WP_BFG)
        {
            player->attackDown = true;
            pspr::fireWeapon(player);
            return;
        }
    }
    else
    {
        player->attackDown = false;
    }

    auto angle = (128 * doomstat::levelTime) & tables::FINE_MASK;
    psp->sx = fixed::FRACUNIT + fixed::fixedMul(player->bob, tables::finecosine(angle));
    angle &= tables::FINE_ANGLES / 2 - 1;
    psp->sy = pspr::WEAPONTOP + fixed::fixedMul(player->bob, tables::finesine[angle]);

    game::done_autoswitch = false;
}
void action::doNothing()
{
    // duh
}
void action::fireOldBfg(NotNull<player::Player*> player, NotNull<pspr::PSpDef*> psp)
{
    if (doomstat::compatibility_level < doomstat::CompLevel::Mbf)
    {
        return;
    }
    if (doomstat::weapon_recoil && !(player->flags & info::MobjFlag::MF_NOCLIP))
    {
        pspr::thrust(player, tables::ANG180 + player->angle,
                     512 * pspr::recoil_values[to_underlying(defs::WeaponType::WP_PLASMA)]);
    }

    --player->ammo[to_underlying(items::weaponinfo.at(player->readyWeapon).ammo)];
    player->extraLight = 2;

    auto type = info::MobjType::MT_PLASMA1;
    for (int i = 0; i < 2; ++i)
    {
        if (i == 1)
        {
            type = info::MobjType::MT_PLASMA2;
        }

        tables::Angle angle = player->angle;
        tables::Angle angle1 = ((rando::p_random(rando::PrClass::Bfg) & 127) - 64) * (tables::ANG90 / 768) + angle;
        tables::Angle angle2 =
            ((rando::p_random(rando::PrClass::Bfg) & 127) - 64) * (tables::ANG90 / 640) + tables::ANG90;

        auto* th =
            mobj::spawnMobj(player->x, player->y,
                            player->z + 62 * fixed::FRACUNIT - player->psprites[pspr::PSprEnum::PS_WEAPON].sy, type);
        tick::setTarget(&th->target, player);
        th->angle = angle1;
        th->momX = tables::finecosine(angle1 >> tables::ANGLE_TO_FINE_SHIFT) * 25;
        th->momY = tables::finesine[angle1 >> tables::ANGLE_TO_FINE_SHIFT] * 25;
        th->momZ = tables::finetangent[angle2 >> tables::ANGLE_TO_FINE_SHIFT] * 25;
        mobj::checkMissileSpawn(th);
    }
}
void action::reFire(NotNull<player::Player*> player)
{
    // TODO(kyle)
    if (static_cast<bool>(player->cmd.buttons & event::ButtonCode::BT_ATTACK) &&
        player->pendingWeapon == defs::WeaponType::WP_NOCHANGE && player->health > 0)
    {
        player->refire = true;
        // pspr::fireWeapon(player);
    }
    else
    {
        player->refire = false;
        // pspr::checkAmmo(player);
    }
}
void action::light1(NotNull<player::Player*> player)
{
    player->extraLight = 1;
}
void action::light2(NotNull<player::Player*> player)
{
    player->extraLight = 2;
}
