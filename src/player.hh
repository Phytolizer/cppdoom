//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_PLAYER_HH
#define DOOM_PLAYER_HH

#include <map>
#include <string>

#include "defs.hh"
#include "enum_ops.hh"
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

    int32_t playerHealth;
    int32_t armorPoints;

    /// 0..2
    int32_t armorType;

    /// powerups. invincibility and invis are tic counters
    std::array<int32_t, to_underlying(defs::PowerType::NUMPOWERS)> powers;
    std::array<bool, to_underlying(defs::Card::NUMCARDS)> cards;
    bool backpack;

    std::array<int, defs::MAXPLAYERS> frags;
    defs::WeaponType readyWeapon;

    defs::WeaponType pendingWeapon;

    std::array<bool, to_underlying(defs::WeaponType::NUMWEAPONS)> weaponOwned;
    std::array<int32_t, to_underlying(defs::AmmoType::NUMAMMO)> ammo;
    std::array<int32_t, to_underlying(defs::AmmoType::NUMAMMO)> maxAmmo;

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
    mobj::MapObject* attacker;

    /// gun flash
    uint8_t extraLight;

    /// current PLAYPAL
    ///
    /// can be set to REDCOLORMAP for pain, for example
    int32_t fixedColormap;

    /// player skin color shift
    /// 0..3
    int32_t colormap;

    std::map<pspr::PSprEnum, pspr::PSpDef> psprites;

    /// true if secret level has been done
    bool didSecret;

    fixed::Fixed playerMomX;
    fixed::Fixed playerMomY;

    int32_t resurrectedKillCount;

    fixed::Fixed prevViewZ;
    tables::Angle prevViewAngle;
    tables::Angle prevViewPitch;
    /// delay next jump for a bit
    fixed::Fixed jumpTics;

    bool ownsWeapon(defs::WeaponType wt);
    bool hasAmmo(defs::AmmoType at);
    int32_t getAmmo(defs::AmmoType at);
    bool hasPower(defs::PowerType pt);
};

} // namespace player

#endif // DOOM_PLAYER_HH
