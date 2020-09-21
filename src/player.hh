//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_PLAYER_HH
#define DOOM_PLAYER_HH

#include <string>

#include "mobj.hh"
#include "pspr.hh"
#include "ticcmd.hh"

namespace player
{

enum class PlayerState
{
  PST_LIVE,
  PST_DEAD,
  PST_REBORN,
};

struct Player : mobj::MapObject
{
  PlayerState playerState;
  ticcmd::TicCmd cmd;

  fixed::Fixed viewZ;
  fixed::Fixed viewHeight;
  fixed::Fixed deltaViewHeight;
  fixed::Fixed bob;

  // only used between levels,
  // mo->health is used during levels

  int32_t health;
  int32_t armorPoints;

  /// 0..2
  int32_t armorType;

  /// powerups. invincibility and invis are tic counters
  int32_t powers[static_cast<size_t>(defs::PowerType::NUMPOWERS)];
  bool cards[static_cast<size_t>(defs::Card::NUMCARDS)];
  bool backpack;

  int frags[defs::MAXPLAYERS];
  defs::WeaponType readyWeapon;

  defs::WeaponType pendingWeapon;

  bool weaponOwned[static_cast<size_t>(defs::WeaponType::NUMWEAPONS)];
  int32_t ammo[static_cast<size_t>(defs::AmmoType::NUMAMMO)];
  int32_t maxAmmo[static_cast<size_t>(defs::AmmoType::NUMAMMO)];

  /// true if attack button was down last tic
  bool attackDown;
  bool useDown;

  /// bitflags for cheats/debug.
  /// see player::Cheat
  int32_t cheats;

  /// refiring?
  bool refire;

  /// intermission stats
  int32_t killCount;
  int32_t itemCount;
  int32_t secretCount;

  /// hint message
  std::string message;

  // for screen flashing

  int32_t damageCount;
  int32_t bonusCount;

  /// who did damage (nullptr for floors/ceilings)
  mobj::MapObject *attacker;

  /// gun flash
  bool extraLight;

  /// current PLAYPAL
  ///
  /// can be set to REDCOLORMAP for pain, for example
  int32_t fixedColormap;

  /// player skin color shift
  /// 0..3
  int32_t colormap;

  pspr::PSpDef psprites[static_cast<size_t>(pspr::PSprEnum::NUMPSPRITES)];

  /// true if secret level has been done
  bool didSecret;

  fixed::Fixed momX;
  fixed::Fixed momY;

  int32_t resurrectedKillCount;

  fixed::Fixed prevViewZ;
  tables::Angle prevViewAngle;
  tables::Angle prevViewPitch;
  /// delay next jump for a bit
  fixed::Fixed jumpTics;
};

} // namespace player

#endif // DOOM_PLAYER_HH
