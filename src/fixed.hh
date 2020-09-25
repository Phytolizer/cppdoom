//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_FIXED_HH
#define DOOM_FIXED_HH

#include <climits>
#include <cstdint>

#include "math.hh"

namespace fixed
{

constexpr uint8_t FRACBITS = 16;
constexpr uint32_t FRACUNIT = 1u << FRACBITS;

using Fixed = int;

constexpr Fixed fixedMul(Fixed a, Fixed b)
{
    return static_cast<Fixed>(static_cast<uint64_t>(a) * static_cast<uint64_t>(b) >> FRACBITS);
}
constexpr Fixed fixedDiv(Fixed a, Fixed b)
{
    if ((math::abs(a) >> 14) >= math::abs(b))
    {
        return ((a ^ b) >> 31) ^ INT_MAX;
    }
    return static_cast<Fixed>((static_cast<int64_t>(a) << FRACBITS) / static_cast<int64_t>(b));
}

} // namespace fixed

#endif // DOOM_FIXED_HH
