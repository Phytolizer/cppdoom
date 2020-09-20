//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_TICCMD_HH
#define DOOM_TICCMD_HH

#include <cstdint>
namespace ticcmd
{

struct TicCmd
{
  int8_t forwardMove;
  int8_t sideMove;
  int16_t angleTurn;
  int16_t consistency;
  uint8_t chatChar;
  uint8_t buttons;
};

}

#endif // DOOM_TICCMD_HH
