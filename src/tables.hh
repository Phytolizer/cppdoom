//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_TABLES_HH
#define DOOM_TABLES_HH

#include "fixed.hh"
#include <cstdint>

namespace tables
{

constexpr const uint16_t FINE_ANGLES = 0x2000;
constexpr const uint16_t FINE_MASK = FINE_ANGLES - 1;

constexpr const uint8_t ANGLE_TO_FINE_SHIFT = 19;

constexpr const uint32_t ANG45 = 0x20000000;
constexpr const uint32_t ANG90 = 0x40000000;
constexpr const uint32_t ANG180 = 0x80000000;
constexpr const uint32_t ANG270 = 0xc0000000;
constexpr const uint32_t ANG1 = ANG45 / 45;
constexpr const uint32_t ANGLE_MAX = 0xffffffff;
constexpr const double PI = 3.14159265358979323846;

constexpr const uint16_t SLOPE_RANGE = 0x800;
constexpr const uint8_t SLOPE_BITS = 11;
constexpr const uint8_t DBITS = fixed::FRACBITS - SLOPE_BITS;

using Angle = uint32_t;

}

#endif // DOOM_TABLES_HH
