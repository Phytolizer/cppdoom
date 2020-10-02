//
// Created by kyle on 9/25/20.
//

#ifndef EZ_BOOM_GAME_MAP_HH
#define EZ_BOOM_GAME_MAP_HH

#include "fixed.hh"
#include "mobj.hh"

namespace line
{
struct Line;
}

namespace game_map
{

constexpr auto MELEE_RANGE = fixed::FRACUNIT * 64;

/// indicates object pushed off ledge
extern bool fellDown;
/// if it's true, move is ok anywhere between floorz and ceilingz
extern bool floatOk;

/// ceiling of the current sector
extern fixed::Fixed tmCeilingZ;
/// floor of the current sector
extern fixed::Fixed tmFloorZ;
/// floor of the sector across the line being crossed
extern fixed::Fixed tmDropoffZ;

/// allow unsticking
extern bool tmUnstuck;
extern line::Line* ceilingLine;
extern line::Line* floorLine;
extern std::vector<line::Line> spechit;
extern mobj::MapObject* lineTarget;

bool tryMove(mobj::MapObject& thing, fixed::Fixed x, fixed::Fixed y, int dropoff);
bool checkPosition(mobj::MapObject& thing, fixed::Fixed x, fixed::Fixed y);
bool untouched(line::Line& linedef);
fixed::Fixed aimLineAttack(mobj::MapObject& thing, tables::Angle angle, fixed::Fixed distance,
                           info::MobjFlag mask);
void lineAttack(mobj::MapObject& thing, tables::Angle angle, fixed::Fixed distance, fixed::Fixed slope,
                int damage);

} // namespace game_map

#endif // EZ_BOOM_GAME_MAP_HH
