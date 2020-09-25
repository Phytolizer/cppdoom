//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_STAT_HH
#define DOOM_STAT_HH

#include "defs.hh"
namespace doomstat
{

enum class CompLevel
{
    Auto = -1,
    Doom12,
    Doom1666,
    Doom219,
    UltDoom,
    FinalDoom,
    DosDoom,
    TasDoom,
    Boom,
    Boom201,
    Boom202,
    LxDoom,
    Mbf,
    PrBoom1,
    PrBoom2,
    PrBoom3,
    PrBoom4,
    PrBoom5,
    PrBoom6,
    MAX_COMPATIBILITY_LEVEL,

    Best = PrBoom6,
};

enum class DemoInsurance
{
    Never,
    Always,
    DuringDemoRecording,
};

enum class MonsterInfightingLevel
{
    Never,
    OtherSpecies,
    Always,
};

enum class CompFlag
{
    /// monsters used to telefrag only on MAP30, now they only telefrag from
    /// spawners
    COMP_TELEFRAG,
    /// MBF encourages things to drop off of overhangs
    COMP_DROPOFF,
    /// original Doom archvile bugs, e.g. ghosts
    COMP_VILE,
    /// Pain Elemental lost soul limit
    COMP_PAIN,
    /// can Pain Elementals spit skulls through walls?
    COMP_SKULL,
    /// do blazing doors play the close sound twice?
    COMP_BLAZING,
    /// MBF made door lighting changes more gradual
    COMP_DOORLIGHT,
    /// improvements to game physics
    COMP_MODEL,
    /// fixes to god mode
    COMP_GOD,
    /// MBF encourages things to drop off of overhangs
    COMP_FALLOFF,
    /// fixes for moving floor bugs in Boom
    COMP_FLOORS,
    COMP_SKYMAP,
    /// MBF AI change, limited pursuit?
    COMP_PURSUIT,
    /// fix for monsters getting stuck in doors
    COMP_DOORSTUCK,
    /// MBF AI change, monsters try to stay on lifts
    COMP_STAYLIFT,
    /// prevent dead players from triggering stuff
    COMP_ZOMBIE,
    COMP_STAIRS,
    COMP_INFCHEAT,
    /// allow zero tags in wads
    COMP_ZEROTAGS,
    /// enables keygrab glitch and noclipping mancubus fireballs
    COMP_MOVEBLOCK,
    /// objects which aren't placed by the map respawn at (0,0)
    COMP_RESPAWN,
    COMP_SOUND,
    /// emulate pre-Ultimate boss death behavior
    COMP_666,
    /// enable lost soul bouncing
    COMP_SOUL,
    /// 2s mid textures don't animate
    COMP_MASKEDANIM,

    /// use Doom's buggy "Ouch" face code
    COMP_OUCHFACE,
    /// max health changes in DEH applies only to potions?
    COMP_MAXHEALTH,
    /// no predefined translucency for some things
    COMP_TRANSLUCENCY,

    COMP_NUM,
    COMP_TOTAL = 32,
};

extern bool doom_weapon_toggles;
extern bool flashing_hom;
extern bool modifiedGame;
extern int levelTime;
extern int gametic;
extern int basetic;

extern bool allow_pushers;
extern bool default_allow_pushers;

extern std::array<bool, static_cast<std::size_t>(doomstat::CompFlag::COMP_TOTAL)> comp;
extern std::array<bool, static_cast<std::size_t>(doomstat::CompFlag::COMP_TOTAL)> default_comp;

extern CompLevel compatibility_level;
extern CompLevel default_compatibility_level;

extern DemoInsurance demo_insurance;
extern DemoInsurance default_demo_insurance;

/// the distance friends tend to hover around
extern int distfriend;
extern int default_distfriend;

extern bool dog_jumping;
extern bool default_dog_jumping;

extern int dogs;
extern int default_dogs;

/// do monsters help friends?
extern bool help_friends;
extern bool default_help_friends;

/// can monsters climb stairs?
extern bool monkeys;
extern bool default_monkeys;

/// are monsters able to avoid hazards like crushers?
extern bool monster_avoid_hazards;
extern bool default_monster_avoid_hazards;

/// are monsters allowed to strafe or retreat?
extern bool monster_backing;
extern bool default_monster_backing;

extern bool monster_friction;
extern bool default_monster_friction;

extern MonsterInfightingLevel monster_infighting;
extern MonsterInfightingLevel default_monster_infighting;

extern bool monsters_remember;
extern bool default_monsters_remember;

extern bool player_bobbing;
extern bool default_player_bobbing;

extern bool variable_friction;
extern bool default_variable_friction;

extern bool weapon_recoil;
extern bool default_weapon_recoil;

extern defs::GameMission gamemission;
extern defs::GameMode gamemode;
extern defs::Language language;

bool mbfFeatures();

bool demo_compatibility();
} // namespace doomstat

#endif // DOOM_STAT_HH
