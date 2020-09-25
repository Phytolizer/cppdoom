//
// Created by kyle on 9/25/20.
//

#include "tick.hh"
void tick::setTarget(NotNull<mobj::MapObject**> mop, mobj::MapObject* target)
{
    if (*mop != nullptr)
    {
        --(*mop)->references;
    }
    *mop = target;
    if (*mop != nullptr)
    {
        ++target->references;
    }
}
