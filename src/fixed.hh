//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_FIXED_HH
#define DOOM_FIXED_HH

#include <cstdint>

namespace fixed
{

constexpr uint8_t FRACBITS = 16;
constexpr uint32_t FRACUNIT = 1u << FRACBITS;

using Fixed = int;

} // namespace fixed

#endif // DOOM_FIXED_HH
