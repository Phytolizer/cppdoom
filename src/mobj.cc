//
// Created by kyle on 9/20/20.
//

#include "mobj.hh"

#include "doomstat.hh"
#include "game_map.hh"
#include "random.hh"
#include "sound.hh"
void mobj::setMobjState(NotNull<mobj::MapObject*> mobj, info::StateEnum state)
{
    // TODO(kyle)
}
mobj::MapObject* mobj::spawnMobj(fixed::Fixed x, fixed::Fixed y, fixed::Fixed z, info::MobjType type)
{
    // TODO(kyle)
}
void mobj::checkMissileSpawn(NotNull<mobj::MapObject*> th)
{
    // randomly offset tics so many missiles don't look uniform
    th->tics -= rando::p_random(rando::PrClass::Missile) & 0b11;
    th->tics = math::max(th->tics, 1);

    th->x += (th->momX / 2);
    th->y += (th->momY / 2);
    th->z += (th->momZ / 2);

    // not a missile?
    if (!(th->flags & info::MobjFlag::MF_MISSILE) && doomstat::mbfFeatures())
    {
        return;
    }

    if (!game_map::tryMove(th, th->x, th->y, false))
    {
        mobj::explodeMissile(th);
    }
}
void mobj::explodeMissile(NotNull<mobj::MapObject*> mo)
{
    mo->momX = 0;
    mo->momY = 0;
    mo->momZ = 0;

    mobj::setMobjState(mo, info::mobjinfo[to_underlying(mo->type)].deathState);

    // randomly offset start tic so many explosions don't look uniform
    mo->tics -= rando::p_random(rando::PrClass::Explode) & 0b11;
    mo->tics = math::max(mo->tics, 1);

    mo->flags &= ~info::MobjFlag::MF_MISSILE;

    if (mo->info->deathSound != info::Sfx::sfx_None)
    {
        sound::startSound(mo, mo->info->deathSound);
    }
}
