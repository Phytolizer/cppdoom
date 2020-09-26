//
// Created by kyle on 9/25/20.
//

#include "game_map.hh"

#include "compatibility.hh"
#include "doomstat.hh"
#include "line.hh"
#include "map_util.hh"
#include "spec.hh"

#include <boost/range/adaptor/reversed.hpp>

bool game_map::fellDown;
bool game_map::floatOk;

fixed::Fixed game_map::tmCeilingZ;
fixed::Fixed game_map::tmFloorZ;
fixed::Fixed game_map::tmDropoffZ;

bool game_map::tmUnstuck;
line::Line* game_map::ceilingLine{nullptr};
line::Line* game_map::floorLine{nullptr};
std::vector<line::Line> game_map::spechit;

bool game_map::tryMove(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y, int dropoff)
{
    fellDown = false;
    floatOk = false;

    constexpr const auto STEPHEIGHT = 24 * fixed::FRACUNIT;
    if (!checkPosition(thing, x, y))
    {
        // solid wall/thing
        return false;
    }

    const auto HEIGHT_DIFF = tmFloorZ - tmDropoffZ;
    const auto FALL_HEIGHT = thing->z - tmFloorZ;
    const auto SECTOR_HEIGHT = tmCeilingZ - tmFloorZ;
    const auto HEAD_HEIGHT = thing->z + thing->height;

    if (!(thing->flags & info::MobjFlag::MF_NOCLIP))
    {
        // interacts with blocking lines &c

        if (static_cast<bool>(thing->flags & info::MobjFlag::MF_FLY))
        {
            // set momZ to slide up/down until unblocked
            // ex: cacodemon hits ledge

            if (HEAD_HEIGHT > tmCeilingZ)
            {
                // must fall

                // cppcheck-suppress signConversion
                thing->momZ = -8 * fixed::FRACUNIT;
                return false;
            }
            if (thing->z < tmFloorZ && HEIGHT_DIFF > STEPHEIGHT)
            {
                // must rise
                thing->momZ = 8 * fixed::FRACUNIT;
                return false;
            }
        }

        // not flying

        bool stuck = false;
        if (SECTOR_HEIGHT < thing->height)
        {
            stuck = true;
        }
        else
        {
            // theoretically could fit if it fell/raised
            floatOk = true;

            if (
                // stuck in ceiling
                !(thing->flags & info::MobjFlag::MF_TELEPORT) && tmCeilingZ < HEAD_HEIGHT &&
                    !(thing->flags & info::MobjFlag::MF_FLY) ||
                // stuck in floor
                !(thing->flags & info::MobjFlag::MF_TELEPORT) && tmFloorZ - thing->z > STEPHEIGHT)
            {
                stuck = true;
            }
        }
        if (stuck)
        {
            return tmUnstuck && !(ceilingLine != nullptr && untouched(ceilingLine) &&
                                  !(floorLine != nullptr && untouched(floorLine)));
        }

        if (!(thing->flags & (info::MobjFlag::MF_DROPOFF | info::MobjFlag::MF_FLOAT)))
        {
            if (doomstat::comp[to_underlying(doomstat::CompFlag::COMP_DROPOFF)])
            {
                if ((doomstat::compatibility_level <= doomstat::CompLevel::Boom || dropoff == 0 ||
                     (!prboomCompatibility[to_underlying(PrBoomCompatibilityFlag::NO_DROPOFF)].state &&
                      doomstat::mbfFeatures() && doomstat::compatibility_level <= doomstat::CompLevel::PrBoom2)) &&
                    HEIGHT_DIFF > STEPHEIGHT)
                {
                    // don't stand over a dropoff
                    return false;
                }
            }
            else if (dropoff == 0 || (dropoff == 2 && (HEIGHT_DIFF > 128 * fixed::FRACUNIT ||
                                                       thing->target == nullptr || thing->target->z > tmDropoffZ)))

            {
                if (!doomstat::monkeys)
                {
                    return false;
                }
                if (doomstat::mbfFeatures())
                {
                    if (thing->floorZ - tmFloorZ > STEPHEIGHT)
                    {
                        return false;
                    }
                }
                else if (HEIGHT_DIFF > STEPHEIGHT || thing->dropoffZ - tmDropoffZ > STEPHEIGHT)
                {
                    return false;
                }
            }
            else
            {
                // drop is allowed

                fellDown = !(thing->flags & info::MobjFlag::MF_NOGRAVITY) && FALL_HEIGHT > STEPHEIGHT;
            }
        }

        if (static_cast<bool>(thing->flags & info::MobjFlag::MF_BOUNCES) &&
            !(thing->flags & (info::MobjFlag::MF_MISSILE | info::MobjFlag::MF_NOGRAVITY)) && !mobj::sentient(thing) &&
            tmFloorZ - thing->z > 16 * fixed::FRACUNIT)
        {
            return false;
        }
    }

    // move ok!

    map_util::unsetThingPosition(thing);

    auto oldX = thing->x;
    auto oldY = thing->y;
    thing->floorZ = tmFloorZ;
    thing->ceilingZ = tmCeilingZ;
    thing->dropoffZ = tmDropoffZ;
    thing->x = x;
    thing->y = y;

    map_util::setThingPosition(thing);

    // spechits

    if (!(thing->flags & (info::MobjFlag::MF_TELEPORT | info::MobjFlag::MF_NOCLIP)))
    {
        for (auto& s : boost::adaptors::reverse(spechit))
        {
            if (s.special != 0)
            {
                auto oldSide = map_util::pointOnLineSide(oldX, oldY, &s);
                if (oldSide != map_util::pointOnLineSide(thing->x, thing->y, &s))
                {
                    spec::crossSpecialLine(&s, oldSide, thing, spec::PlayerCheck::PlayerCheck);
                }
            }
        }
    }

    return true;
}
bool game_map::checkPosition(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y)
{
    // TODO(kyle)
}
bool game_map::untouched(NotNull<line::Line*> linedef)
{
    // TODO(kyle)
}
