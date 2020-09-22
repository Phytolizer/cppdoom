//
// Created by kyle on 9/19/20.
//

#include "game.hh"
#include "deh.hh"
#include "doom.hh"
#include "doom_main.hh"
#include "doomstat.hh"

bool game::boom_autoswitch;
bool game::haswolflevels = false;
bool game::netgame = false;
bool game::noblit;
bool game::nodrawers;
bool game::demoplayback;
bool game::singledemo;
bool game::netdemo;

bool game::playerInGame[defs::MAXPLAYERS];

fixed::Fixed game::forwardMove[2] = {0x19, 0x32};
fixed::Fixed game::sideMove[2] = {0x18, 0x28};

int game::max_player_corpses;
int game::default_skill;
int game::consolePlayer;

// Constants

const fixed::Fixed game::forwardMoveNormal[2] = {0x19, 0x32};
const fixed::Fixed game::sideMoveNormal[2] = {0x18, 0x28};

// Functions

int game::getHelpers()
{
  if (argMeta.dogs.has_value())
  {
    return argMeta.dogs.value();
  }
  else
  {
    return doomstat::default_dogs;
  }
}

void game::reloadDefaults()
{
  doomstat::weapon_recoil = doomstat::default_weapon_recoil;
  doomstat::player_bobbing = doomstat::default_player_bobbing;
  doomstat::variable_friction = doomstat::default_variable_friction;
  doomstat::allow_pushers = doomstat::default_allow_pushers;
  doomstat::monsters_remember = doomstat::default_monsters_remember;
  doomstat::monster_infighting = doomstat::default_monster_infighting;
  if (game::netgame)
  {
    doomstat::dogs = 0;
  }
  else
  {
    doomstat::dogs = game::getHelpers();
  }
  doomstat::dog_jumping = doomstat::default_dog_jumping;
  doomstat::distfriend = doomstat::default_distfriend;
  doomstat::monster_backing = doomstat::default_monster_backing;
  doomstat::monster_avoid_hazards = doomstat::default_monster_avoid_hazards;
  doomstat::monster_friction = doomstat::default_monster_friction;
  doomstat::help_friends = doomstat::default_help_friends;
  doomstat::monkeys = doomstat::default_monkeys;

  doom::respawnparm = argMeta.respawn;
  doom::fastparm = argMeta.fast;
  doom::nomonsters = argMeta.noMonsters;

  if (doom::startSkill == defs::Skill::SK_NONE)
  {
    doom::startSkill = static_cast<defs::Skill>(game::default_skill - 1);
  }
  game::demoplayback = false;
  game::singledemo = false;
  game::netdemo = false;

  for (std::size_t i = 1; i < defs::MAXPLAYERS; ++i)
  {
    game::playerInGame[i] = false;
  }

  game::consolePlayer = 0;
  doomstat::compatibility_level = doomstat::default_compatibility_level;
  if (argMeta.complevel.has_value())
  {
    doomstat::compatibility_level =
        static_cast<doomstat::CompLevel>(argMeta.complevel.value());
  }
  if (doomstat::compatibility_level == doomstat::CompLevel::Auto)
  {
    doomstat::compatibility_level = doomstat::CompLevel::Best;
  }
  if (doomstat::mbfFeatures())
  {
    for (std::size_t i = 0;
         i < static_cast<std::size_t>(doomstat::CompFlag::COMP_TOTAL); ++i)
    {
      doomstat::comp[i] = doomstat::default_comp[i];
    }
  }
  game::compatibility();
}

struct CompInfo
{
  doomstat::CompLevel fixIntroduced;
  doomstat::CompLevel madeOptional;
};

void game::compatibility()
{
  static constexpr const std::pair<doomstat::CompFlag, CompInfo> levels[] = {
      {doomstat::CompFlag::COMP_TELEFRAG,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_DROPOFF,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_VILE,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_PAIN,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_SKULL,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_BLAZING,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_DOORLIGHT,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_MODEL,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_GOD,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_FALLOFF,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_FLOORS,
       {doomstat::CompLevel::Boom, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_SKYMAP,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_PURSUIT,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_DOORSTUCK,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_STAYLIFT,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_ZOMBIE,
       {doomstat::CompLevel::LxDoom, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_STAIRS,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_INFCHEAT,
       {doomstat::CompLevel::Mbf, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_ZEROTAGS,
       {doomstat::CompLevel::Boom202, doomstat::CompLevel::Mbf}},
      {doomstat::CompFlag::COMP_MOVEBLOCK,
       {doomstat::CompLevel::LxDoom, doomstat::CompLevel::PrBoom2}},
      {doomstat::CompFlag::COMP_RESPAWN,
       {doomstat::CompLevel::PrBoom2, doomstat::CompLevel::PrBoom2}},
      {doomstat::CompFlag::COMP_SOUND,
       {doomstat::CompLevel::Boom, doomstat::CompLevel::PrBoom3}},
      {doomstat::CompFlag::COMP_666,
       {doomstat::CompLevel::UltDoom, doomstat::CompLevel::PrBoom4}},
      {doomstat::CompFlag::COMP_SOUL,
       {doomstat::CompLevel::PrBoom4, doomstat::CompLevel::PrBoom4}},
      {doomstat::CompFlag::COMP_MASKEDANIM,
       {doomstat::CompLevel::Doom1666, doomstat::CompLevel::PrBoom4}},
      {doomstat::CompFlag::COMP_OUCHFACE,
       {doomstat::CompLevel::PrBoom1, doomstat::CompLevel::PrBoom6}},
      {doomstat::CompFlag::COMP_MAXHEALTH,
       {doomstat::CompLevel::Boom, doomstat::CompLevel::PrBoom6}},
      {doomstat::CompFlag::COMP_TRANSLUCENCY,
       {doomstat::CompLevel::Boom, doomstat::CompLevel::PrBoom6}},
  };
  for (const auto &level : levels)
  {
    if (doomstat::compatibility_level < level.second.madeOptional)
    {
      // not optional
      doomstat::comp[static_cast<std::size_t>(level.first)] =
          doomstat::compatibility_level < level.second.fixIntroduced;
    }
  }

  deh::applyCompatibility();
}
