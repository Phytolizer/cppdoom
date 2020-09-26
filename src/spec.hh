//
// Created by kyle on 9/26/20.
//

#ifndef EZ_BOOM_SPEC_HH
#define EZ_BOOM_SPEC_HH

#include "gsl_aliases.hh"
#include "mobj.hh"

namespace line
{
struct Line;
}

namespace spec
{

enum class PlayerCheck
{
    PlayerCheck,
    NoPlayerCheck,
};

void crossSpecialLine(NotNull<line::Line*> line, int side, NotNull<mobj::MapObject*> thing, PlayerCheck playerCheck);

}

#endif // EZ_BOOM_SPEC_HH
