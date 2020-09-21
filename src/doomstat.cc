//
// Created by kyle on 9/19/20.
//

#include "doomstat.hh"

bool doomstat::doom_weapon_toggles;
bool doomstat::flashing_hom;
bool doomstat::modifiedGame;

bool doomstat::player_bobbing;
bool doomstat::default_player_bobbing;

bool doomstat::variable_friction;
bool doomstat::default_variable_friction;

bool doomstat::weapon_recoil;
bool doomstat::default_weapon_recoil;

doomstat::CompLevel doomstat::default_compatibility_level;
doomstat::DemoInsurance doomstat::default_demo_insurance;

defs::GameMission doomstat::gamemission;
defs::GameMode doomstat::gamemode = defs::GameMode::UNDETERMINED;
defs::Language doomstat::language = defs::Language::ENGLISH;
