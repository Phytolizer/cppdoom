//
// Created by kyle on 9/20/20.
//

#include "tables.hh"

std::array<fixed::Fixed, 5 * tables::FINE_ANGLES / 4> tables::finesine{};
std::array<fixed::Fixed, tables::FINE_ANGLES / 2> tables::finetangent{};
