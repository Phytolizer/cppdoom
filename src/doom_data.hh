//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DOOM_DATA_HH
#define DOOM_DOOM_DATA_HH

#include <cstdint>

#include "doom_type.hh"

namespace doom_data
{

struct PACKEDATTR MapThing
{
  int16_t x;
  int16_t y;
  int16_t angle;
  int16_t type;
  int16_t options;
};

}

#endif // DOOM_DOOM_DATA_HH
