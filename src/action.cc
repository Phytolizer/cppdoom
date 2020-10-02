//
// Created by kyle on 9/20/20.
//

#include "action.hh"
#include "demo.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "event.hh"
#include "game.hh"
#include "game_map.hh"
#include "info.hh"
#include "items.hh"
#include "player.hh"
#include "pspr.hh"
#include "random.hh"
#include "render.hh"
#include "sound.hh"
#include "tick.hh"

void action::light0(player::Player& player)
{
    player.extraLight = 0;
}
void action::weaponReady(player::Player& player, pspr::PSpDef& psp)
{
    if (player.state == &info::states.at(info::StateEnum::S_PLAY_ATK1) ||
        player.state == &info::states.at(info::StateEnum::S_PLAY_ATK2))
    {
        mobj::setMobjState(player, info::StateEnum::S_PLAY);
    }

    if (player.readyWeapon == defs::WeaponType::WP_CHAINSAW && psp.state == &info::states.at(info::StateEnum::S_SAW))
    {
        sound::startSound(player, info::Sfx::sfx_sawidl);
    }

    if (player.pendingWeapon != defs::WeaponType::WP_NOCHANGE || player.health == 0)
    {
        info::StateEnum newState = items::weaponinfo.at(player.readyWeapon).downState;
        pspr::setPsprite(player, pspr::PSprEnum::PS_WEAPON, newState);
        return;
    }

    if (static_cast<bool>(player.cmd.buttons & event::ButtonCode::BT_ATTACK))
    {
        if (!player.attackDown ||
            player.readyWeapon != defs::WeaponType::WP_MISSILE && player.readyWeapon != defs::WeaponType::WP_BFG)
        {
            player.attackDown = true;
            pspr::fireWeapon(player);
            return;
        }
    }
    else
    {
        player.attackDown = false;
    }

    auto angle = (128 * doomstat::levelTime) & tables::FINE_MASK;
    psp.sx = fixed::FRACUNIT + fixed::fixedMul(player.bob, tables::finecosine(angle));
    angle &= tables::FINE_ANGLES / 2 - 1;
    psp.sy = pspr::WEAPONTOP + fixed::fixedMul(player.bob, tables::finesine[angle]);

    game::done_autoswitch = false;
}
void action::doNothing()
{
    // duh
}
void action::fireOldBfg(player::Player& player)
{
    if (doomstat::compatibility_level < doomstat::CompLevel::Mbf)
    {
        return;
    }
    if (doomstat::weapon_recoil && !(player.flags & info::MobjFlag::MF_NOCLIP))
    {
        pspr::thrust(player, tables::ANG180 + player.angle,
                     512 * pspr::recoil_values[to_underlying(defs::WeaponType::WP_PLASMA)]);
    }

    --player.ammo[to_underlying(items::weaponinfo.at(player.readyWeapon).ammo)];
    player.extraLight = 2;

    auto type = info::MobjType::MT_PLASMA1;
    for (int i = 0; i < 2; ++i)
    {
        if (i == 1)
        {
            type = info::MobjType::MT_PLASMA2;
        }

        tables::Angle angle = player.angle;
        tables::Angle angle1 = ((rando::p_random(rando::PrClass::Bfg) & 127) - 64) * (tables::ANG90 / 768) + angle;
        tables::Angle angle2 =
            ((rando::p_random(rando::PrClass::Bfg) & 127) - 64) * (tables::ANG90 / 640) + tables::ANG90;

        auto* th = mobj::spawnMobj(
            player.x, player.y, player.z + 62 * fixed::FRACUNIT - player.psprites[pspr::PSprEnum::PS_WEAPON].sy, type);
        tick::setTarget(th->target, player);
        th->angle = angle1;
        th->momX = tables::finecosine(angle1 >> tables::ANGLE_TO_FINE_SHIFT) * 25;
        th->momY = tables::finesine[angle1 >> tables::ANGLE_TO_FINE_SHIFT] * 25;
        th->momZ = tables::finetangent[angle2 >> tables::ANGLE_TO_FINE_SHIFT] * 25;
        mobj::checkMissileSpawn(*th);
    }
}
void action::lower(player::Player& player, pspr::PSpDef& psp)
{
    psp.sy += pspr::LOWER_SPEED;

    if (psp.sy < pspr::WEAPONBOTTOM)
    {
        // is already down
        return;
    }

    if (player.playerState == player::PlayerState::PST_DEAD)
    {
        psp.sy = pspr::WEAPONBOTTOM;
        return;
    }

    if (player.health == 0)
    {
        pspr::setPsprite(player, pspr::PSprEnum::PS_WEAPON, info::StateEnum::S_NULL);
        return;
    }

    // old weapon is lowered, so change weapon and start raising

    player.readyWeapon = player.pendingWeapon;
    pspr::bringUpWeapon(player);
}
void action::raise(player::Player& player, pspr::PSpDef& psp)
{
    psp.sy -= pspr::RAISE_SPEED;

    if (psp.sy > pspr::WEAPONTOP)
    {
        return;
    }

    psp.sy = pspr::WEAPONTOP;

    auto newState = items::weaponinfo.at(player.readyWeapon).readyState;
    pspr::setPsprite(player, pspr::PSprEnum::PS_WEAPON, newState);
}
void action::punch(player::Player& player)
{
    auto damage = (rando::p_random(rando::PrClass::Punch) % 10 + 1) * 2;

    if (player.powers[to_underlying(defs::PowerType::PW_STRENGTH)] != 0)
    {
        damage *= 10;
    }

    auto angle = player.angle;
    auto t = rando::p_random(rando::PrClass::PunchAngle);
    angle += (t - rando::p_random(rando::PrClass::PunchAngle)) << 18;

    int slope{0};
    auto computeSlope = [&]() -> int {
        return game_map::aimLineAttack(player, angle, game_map::MELEE_RANGE, info::MobjFlag::MF_NONE);
    };
    if (doomstat::mbfFeatures())
    {
        slope = game_map::aimLineAttack(player, angle, game_map::MELEE_RANGE, info::MobjFlag::MF_FRIEND);
        if (game_map::lineTarget == nullptr)
        {
            slope = computeSlope();
        }
    }
    else
    {
        slope = computeSlope();
    }

    game_map::lineAttack(player, angle, game_map::MELEE_RANGE, slope, damage);

    if (game_map::lineTarget == nullptr)
    {
        return;
    }

    sound::startSound(player, info::Sfx::sfx_punch);

    player.angle = render::pointToAngle2(player.x, player.y, game_map::lineTarget->x, game_map::lineTarget->y);
    demo::smooth_playing::reset(player);
}
