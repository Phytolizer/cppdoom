//
// Created by kyle on 9/26/20.
//

#ifndef EZ_BOOM_MAP_UTIL_HH
#define EZ_BOOM_MAP_UTIL_HH

#include "gsl_aliases.hh"
#include "mobj.hh"

namespace line
{
struct Line;
}

namespace map_util
{

void unsetThingPosition(mobj::MapObject& thing);
void setThingPosition(mobj::MapObject& thing);
int pointOnLineSide(fixed::Fixed x, fixed::Fixed y, const line::Line& line);

} // namespace map_util

#endif // EZ_BOOM_MAP_UTIL_HH
