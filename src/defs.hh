//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DEFS_HH
#define DOOM_DEFS_HH

#include "fixed.hh"
#include "think.hh"
#include <cstdint>
#include <vector>

namespace mobj
{
struct MapObject;
}

namespace defs
{

/// Each sector has a DegenMobj in its center for sound origin purposes
struct DegenMobj
{
  think::Thinker thinker;
  fixed::Fixed x;
  fixed::Fixed y;
  fixed::Fixed z;
};

struct Sector;

struct MSecNode
{
  /// sector containing this object
  Sector *sector;
  /// this object
  mobj::MapObject *thing;
  /// prev MSecNode for this thing
  MSecNode *tprev;
  /// next MSecNode for this thing
  MSecNode *tnext;
  /// prev MSecNode for this sector
  MSecNode *sprev;
  /// next MSecNode for this sector
  MSecNode *snext;
  /// used in search algs
  bool visited;
};

struct Vertex
{
  fixed::Fixed x;
  fixed::Fixed y;

  // pseudovertexes
  // dummies that have their coordinates modified to get moved towards the
  // linedef assoc'd with their seg by projecting them using law of cosines in
  // setup::removeSlimeTrails. They are only used in rendering

  fixed::Fixed px;
  fixed::Fixed py;
};

enum class SlopeType
{
  ST_HORIZONTAL,
  ST_VERTICAL,
  ST_POSITIVE,
  ST_NEGATIVE,
};

enum class RFlag
{
  RF_TOP_TILE = 0x01,
  RF_MID_TILE = 0x02,
  RF_BOT_TILE = 0x04,
  RF_IGNORE = 0x08,
  RF_CLOSED = 0x10,
  RF_ISOLATED = 0x20,
};

struct Line
{
  /// needed for OpenGL
  int32_t lineId;
  // vertices, line goes from v1 to v2

  Vertex *v1;
  Vertex *v2;

  // precalculated v2-v1 for side checking

  fixed::Fixed dx;
  fixed::Fixed dy;

  double texelLength;

  /// animation related
  uint16_t flags;
  int16_t special;
  int16_t tag;
  /// sidedefs
  uint16_t sidenum[2];
  /// bounding box for linedef's extent
  fixed::Fixed boundingBox[4];
  /// to aid move clipping
  SlopeType slopeType;

  // front and back sector

  Sector *frontSector;
  Sector *backSector;

  // if == validcount, already checked
  int32_t validCount;
  /// Thinker for reversible actions
  void *specialData;
  /// translucency filter, -1 = none
  int32_t tranLump;
  int32_t firstTag;
  int32_t nextTag;
  /// if == gametic, r_flags already done
  int32_t r_validCount;
  RFlag rFlags;
  /// sound origin for switches/buttons
  DegenMobj soundOrigin;
};

struct Sector
{
  /// needed for OpenGL
  int sectorId;
  uint32_t flags;
  fixed::Fixed floorHeight;
  fixed::Fixed ceilingHeight;
  int nextTag;
  int firstTag;
  /// 0 = untraversed; 1, 2 = sndlines - 1
  int soundTraversed;
  /// thing that made a sound (or nullptr)
  mobj::MapObject *soundTarget;
  /// mapblock bounding box for height changes
  int blockBox[4];
  /// bounding box, in map units
  int boundingBox[4];
  /// origin for any sounds played by the sector
  DegenMobj soundOrigin;
  /// if == validcount, already checked (??)
  int validCount;
  /// list of mobjs in sector
  std::vector<mobj::MapObject> thingList;

  int friction;
  int moveFactor;

  void *floorData;
  void *ceilingData;
  void *lightingData;

  // below is lockout machinery for stair building

  /// -2 on first locked, -1 after thinker done, 0 normally
  int32_t stairLock;
  /// -1 or number of sector with prev step
  int32_t prevSec;
  /// -1 or number of next step's sector
  int32_t nextSec;

  // flats can be drawn at another sector's height

  /// other sector, or -1 for no sector
  int32_t heightSec;

  // colormaps

  int32_t bottomMap;
  int32_t midMap;
  int32_t topMap;

  /// list of mobjs that are at least partially in this sector
  /// thingList is a subset of touchingThingList
  std::vector<MSecNode> touchingThingList;

  int32_t lineCount;
  Line **lines;

  int32_t sky;

  // floor and ceiling texture offsets

  fixed::Fixed floorXOffs;
  fixed::Fixed floorYOffs;
  fixed::Fixed ceilingXOffs;
  fixed::Fixed ceilingYOffs;

  // support light levels coming from another sector

  int32_t floorLightSec;
  int32_t ceilingLightSec;

  int16_t floorPic;
  int16_t ceilingPic;
  int16_t lightLevel;
  int16_t special;
  /// remember if sector WAS secret for automap
  int16_t oldSpecial;
  int16_t tag;

  /// for segs::fixWiggle
  int32_t cachedHeight;
  int32_t scaleIndex;

  int32_t InterpSectorFloor;
  int32_t InterpSectorCeiling;
  int32_t InterpFloorPanning;
  int32_t InterpCeilingPanning;
  int32_t fakeGroup[2];
};

struct Subsector
{
  Sector *sector;
  int numLines;
  int firstLine;
};

enum class PowerType
{
  PW_INVULNERABILITY,
  PW_STRENGTH,
  PW_INVISIBILITY,
  PW_IRONFEET,
  PW_ALLMAP,
  PW_INFRARED,
  NUMPOWERS,
};

enum class Card
{
  IT_BLUECARD,
  IT_YELLOWCARD,
  IT_REDCARD,
  IT_BLUESKULL,
  IT_YELLOWSKULL,
  IT_REDSKULL,
  NUMCARDS,
};

enum class WeaponType
{
  WP_FIST,
  WP_PISTOL,
  WP_SHOTGUN,
  WP_CHAINGUN,
  WP_MISSILE,
  WP_PLASMA,
  WP_BFG,
  WP_CHAINSAW,
  WP_SUPERSHOTGUN,
  NUMWEAPONS,
  /// no pending weapon change
  WP_NOCHANGE
};

enum class AmmoType
{
  /// pistol/chaingun ammo
  AM_CLIP,
  /// shotgun/ssg ammo
  AM_SHELL,
  /// plasma/bfg ammo
  AM_CELL,
  /// missile launcher
  AM_MISL,
  NUMAMMO,
  /// unlimited ammo, for chainsaw/fist
  AM_NOAMMO
};

enum class GameMode
{
  SHAREWARE,
  REGISTERED,
  COMMERCIAL,
  RETAIL,
  UNDETERMINED,
};

enum class GameMission
{
  DOOM,
  DOOM2,
  TNT,
  PLUT,
  NERVE,
  HACX,
  CHEX,
  NONE,
};

enum class Language
{
  ENGLISH,
  FRENCH,
  GERMAN,
  UNKNOWN,
};

enum class Skill {
  SK_NONE = -1,
  SK_BABY,
  SK_EASY,
  SK_MEDIUM,
  SK_HARD,
  SK_NIGHTMARE,
};

constexpr const int MAXPLAYERS = 4;

} // namespace defs

#endif // DOOM_DEFS_HH
