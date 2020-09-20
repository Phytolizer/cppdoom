//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_MOBJ_HH
#define DOOM_MOBJ_HH

#include <cstdint>

#include "defs.hh"
#include "doom_data.hh"
#include "fixed.hh"
#include "tables.hh"
#include "think.hh"

namespace info
{
struct MobjInfo;
struct State;
enum class SpriteEnum;
enum class MobjType;
} // namespace info

namespace player
{
struct Player;
}

namespace mobj
{

enum class MobjFlag : uint64_t
{
  MF_NONE = 0x0000000000000000,
  /// Calls interactions::specialThing when touched.
  MF_SPECIAL = 0x0000000000000001,
  /// Blocks
  MF_SOLID = 0x0000000000000002,
  /// Can be shot
  MF_SHOOTABLE = 0x0000000000000004,
  /// Don't use sector links, i.e. invisible but touchable
  MF_NOSECTOR = 0x0000000000000008,
  /// Don't use block links, i.e. inert but displayable
  MF_NOBLOCKMAP = 0x0000000000000010,
  /// Deaf monster
  MF_AMBUSH = 0x0000000000000020,
  /// Will attack back
  MF_JUSTHIT = 0x0000000000000040,
  /// Will not attack before moving
  MF_JUSTATTACKED = 0x0000000000000080,
  /// Hang from ceiling upon spawning
  MF_SPAWNCEILING = 0x0000000000000100,
  /// Ignore gravity
  MF_NOGRAVITY = 0x0000000000000200,
  /// Allows jumps from high places
  MF_DROPOFF = 0x0000000000000400,
  /// Can pick up items
  MF_PICKUP = 0x0000000000000800,
  /// Player cheat
  MF_NOCLIP = 0x0000000000001000,
  /// For player, keep info about sliding along walls
  MF_SLIDE = 0x0000000000002000,
  /// Ignore gravity, can move to any height
  MF_FLOAT = 0x0000000000004000,
  /// Don't cross lines or look at heights on teleport. (???)
  MF_TELEPORT = 0x0000000000008000,
  /// Don't hit the same species, explode when blocked.
  /// <br/>
  /// Applied to player missiles and enemy fireballs/rockets/etc.
  MF_MISSILE = 0x0000000000010000,
  /// Dropped by a demon, not level spawned
  MF_DROPPED = 0x0000000000020000,
  /// Use fuzzy drawing code, e.g. for spectres
  MF_SHADOW = 0x0000000000040000,
  /// Don't bleed when shot (use puff graphic)
  MF_NOBLOOD = 0x0000000000080000,
  /// Don't stop moving halfway off a step, i.e. slide down all the way
  MF_CORPSE = 0x0000000000100000,
  /// Floating to a height for a move, so don't float to target height
  MF_INFLOAT = 0x0000000000200000,
  /// This mobj counts towards the kill percentage
  MF_COUNTKILL = 0x0000000000400000,
  /// This mobj counts towards the item percentage
  MF_COUNTITEM = 0x0000000000800000,
  /// Use special handling, this is a skull in flight
  MF_SKULLFLY = 0x0000000001000000,
  /// Don't spawn this in deathmatch mode
  MF_NOTDMATCH = 0x0000000002000000,
  /// Use a translation table to change player color in multiplayer
  MF_TRANSLATION = 0x000000000c000000,
  MF_TRANSLATION1 = 0x0000000004000000,
  MF_TRANSLATION2 = 0x0000000008000000,
  /// Docs just say ???
  MF_TRANSSHIFT = 26,
  MF_UNUSED2 = 0x0000000010000000,
  MF_UNUSED3 = 0x0000000020000000,
  /// Translucent sprite
  MF_TRANSLUCENT = 0x0000000040000000,
  MF_TOUCHY = 0x0000000100000000,
  MF_BOUNCES = 0x0000000200000000,
  MF_FRIEND = 0x0000000400000000,
  MF_RESURRECTED = 0x0000001000000000,
  MF_NO_DEPTH_TEST = 0x0000002000000000,
  MF_FOREGROUND = 0x0000004000000000,
  MF_PLAYERSPRITE = 0x0000008000000000,
  /// Not targetted when it hurts something else
  MF_NOTARGET = 0x0000010000000000,
  /// fly cheat active
  MF_FLY = 0x0000020000000000,
};

struct Mobj
{
  think::Thinker thinker;

  fixed::Fixed x;
  fixed::Fixed y;
  fixed::Fixed z;

  Mobj *next;
  Mobj **prev;

  tables::Angle angle;
  info::SpriteEnum sprite;
  int frame;

  Mobj *bnext;
  Mobj **bprev;

  defs::Subsector *subsector;

  // closest interval over all contacted sectors

  fixed::Fixed floorZ;
  fixed::Fixed ceilingZ;

  /// lowest floor over all contacted sectors
  fixed::Fixed dropoffZ;

  // for movement checking

  fixed::Fixed radius;
  fixed::Fixed height;

  // momentums

  fixed::Fixed momX;
  fixed::Fixed momY;
  fixed::Fixed momZ;

  /// if == validcount, already checked
  int32_t validcount;

  info::MobjType type;
  /// &mobjinfo[mobj->type]
  info::MobjInfo *info;

  /// state tic counter
  int32_t tics;
  info::State *state;
  uint64_t flags;
  /// internal flags
  int32_t intFlags;
  int32_t health;

  /// 0..7
  int16_t moveDir;
  /// when 0, select a new direction
  int16_t moveCount;
  /// monster strafing
  int16_t strafeCount;

  /// thing being chased/attacked (or nullptr).
  /// Missiles use this to track their originator
  /// and blood to track its owner (for coloration).
  Mobj *target;

  /// Reaction time, if nonzero, don't attack yet.
  /// Used by player to stick them in place for a bit after teleporting
  int16_t reactionTime;

  /// if nonzero, the current target will be chased even if shot by someone else
  int16_t threshold;

  /// how long a monster pursues a target
  int16_t pursueCount;

  /// used for torque simulation
  int16_t gear;

  /// additional info, for players only.
  /// Will only be valid if type == MobjType::MT_PLAYER
  player::Player *player;

  /// player number last looked for
  int16_t lastLook;

  /// used for nightmare respawn
  doom_data::MapThing spawnPoint;

  /// thing being chased/attacked, used for revenant missiles
  Mobj *tracer;

  /// last known enemy
  Mobj *lastEnemy;

  /// friction properties of sector the object is in

  int32_t friction;
  int32_t moveFactor;

  /// a linked list of sectors where this object appears
  defs::MSecNode *touchingSectorList;

  fixed::Fixed prevX;
  fixed::Fixed prevY;
  fixed::Fixed prevZ;

  tables::Angle pitch;
  int32_t index;
  int16_t patchWidth;

  /// high word stores thing num, low word identifier num
  int32_t idenNums;

  fixed::Fixed pad;
};

bool alive(const info::MobjInfo &thing);

} // namespace mobj

#endif // DOOM_MOBJ_HH
