//
// Created by kyle on 9/25/20.
//

#include "game_map.hh"

#include "compatibility.hh"
#include "doomstat.hh"

bool game_map::fellDown;
bool game_map::floatOk;

fixed::Fixed game_map::tmCeilingZ;
fixed::Fixed game_map::tmFloorZ;
fixed::Fixed game_map::tmDropoffZ;

bool game_map::tmUnstuck;
line::Line* game_map::ceilingLine{nullptr};
line::Line* game_map::floorLine{nullptr};

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
    }
}
bool game_map::checkPosition(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y)
{
    // TODO(kyle)
}
bool game_map::untouched(NotNull<line::Line*> linedef)
{
    // TODO(kyle)
}
