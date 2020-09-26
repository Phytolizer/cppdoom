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

bool tryMove(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y, int dropoff);
bool checkPosition(NotNull<mobj::MapObject*> thing, fixed::Fixed x, fixed::Fixed y);
bool untouched(NotNull<line::Line*> linedef);

}

#endif // EZ_BOOM_GAME_MAP_HH
