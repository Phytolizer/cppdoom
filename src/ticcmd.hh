//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_TICCMD_HH
#define DOOM_TICCMD_HH

#include <cstdint>

#include "event.hh"

namespace ticcmd
{

struct TicCmd
{
    int8_t forwardMove;
    int8_t sideMove;
    int16_t angleTurn;
    int16_t consistency;
    uint8_t chatChar;
    event::ButtonCode buttons;
};

} // namespace ticcmd

#endif // DOOM_TICCMD_HH
