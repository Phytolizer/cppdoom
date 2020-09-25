//
// Created by kyle on 9/21/20.
//

#include "interactions.hh"

#include <cstdint>

#include "defs.hh"

int interactions::max_soul = 200;
int interactions::mega_health = 200;
int interactions::god_health = 100;
int interactions::idfa_armor = 200;
int interactions::idfa_armor_class = 2;
int interactions::idkfa_armor = 200;
int interactions::idkfa_armor_class = 2;
int interactions::initial_health = 100;
int interactions::initial_bullets = 50;
int interactions::maxhealth = 100;
int interactions::maxhealthbonus = 200;
int interactions::max_armor = 200;
int interactions::green_armor_class = 1;
int interactions::blue_armor_class = 2;
int interactions::soul_health = 100;
int interactions::bfgcells = 40;
int interactions::monsters_infight = 0;
int interactions::maxammo[static_cast<std::size_t>(defs::AmmoType::NUMAMMO)] = {200, 50, 300, 50};
int interactions::clipammo[static_cast<std::size_t>(defs::AmmoType::NUMAMMO)] = {10, 4, 20, 1};
