//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_MOBJ_HH
#define DOOM_MOBJ_HH

#include <cstdint>

#include "defs.hh"
#include "doom_data.hh"
#include "enum_ops.hh"
#include "fixed.hh"
#include "gsl_aliases.hh"
#include "info.hh"
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
} // namespace player

namespace mobj
{

struct MapObject : think::Thinker
{
    fixed::Fixed x{};
    fixed::Fixed y{};
    fixed::Fixed z{};

    MapObject* next{};
    MapObject** prev{};

    tables::Angle angle{};
    info::SpriteEnum sprite{};
    int frame{};

    MapObject* bnext{};
    MapObject** bprev{};

    defs::Subsector* subsector{};

    // closest interval over all contacted sectors

    fixed::Fixed floorZ{};
    fixed::Fixed ceilingZ{};

    /// lowest floor over all contacted sectors
    fixed::Fixed dropoffZ{};

    // for movement checking

    fixed::Fixed radius{};
    fixed::Fixed height{};

    // momentums

    fixed::Fixed momX{};
    fixed::Fixed momY{};
    fixed::Fixed momZ{};

    /// if == validcount, already checked
    int32_t validcount{};

    info::MobjType type{};
    /// &mobjinfo[mobj->type]
    info::MobjInfo* info{};

    /// state tic counter
    int32_t tics{};
    info::State* state{};
    info::MobjFlag flags{};
    /// internal flags
    int32_t intFlags{};
    int32_t health{};

    /// 0..7
    int16_t moveDir{};
    /// when 0, select a new direction
    int16_t moveCount{};
    /// monster strafing
    int16_t strafeCount{};

    /// thing being chased/attacked (or nullptr).
    /// Missiles use this to track their originator
    /// and blood to track its owner (for coloration).
    MapObject* target{};

    /// Reaction time, if nonzero, don't attack yet.
    /// Used by player to stick them in place for a bit after teleporting
    int16_t reactionTime{};

    /// if nonzero, the current target will be chased even if shot by someone else
    int16_t threshold{};

    /// how long a monster pursues a target
    int16_t pursueCount{};

    /// used for torque simulation
    int16_t gear{};

    /// additional info, for players only.
    /// Will only be valid if type == MobjType::MT_PLAYER
    player::Player* player{};

    /// player number last looked for
    int16_t lastLook{};

    /// used for nightmare respawn
    doom_data::MapThing spawnPoint{};

    /// thing being chased/attacked, used for revenant missiles
    MapObject* tracer{};

    /// last known enemy
    MapObject* lastEnemy{};

    /// friction properties of sector the object is in

    int32_t friction{};
    int32_t moveFactor{};

    /// a linked list of sectors where this object appears
    defs::MSecNode* touchingSectorList{};

    fixed::Fixed prevX{};
    fixed::Fixed prevY{};
    fixed::Fixed prevZ{};

    tables::Angle pitch{};
    int32_t index{};
    int16_t patchWidth{};

    /// high word stores thing num, low word identifier num
    int32_t idenNums{};

    fixed::Fixed pad{};
};

constexpr bool alive(const mobj::MapObject& thing)
{
    return thing.health > 0 && ((thing.flags & (info::MobjFlag::MF_COUNTKILL | info::MobjFlag::MF_CORPSE |
                                                info::MobjFlag::MF_RESURRECTED)) == info::MobjFlag::MF_COUNTKILL);
}
constexpr bool sentient(const mobj::MapObject& thing)
{
    return thing.health > 0 && thing.info->seeState != info::StateEnum::S_NULL;
}
void setMobjState(MapObject& mobj, info::StateEnum state);
MapObject* spawnMobj(fixed::Fixed x, fixed::Fixed y, fixed::Fixed z, info::MobjType type);
void checkMissileSpawn(MapObject& th);
void explodeMissile(MapObject& mo);

} // namespace mobj

#endif // DOOM_MOBJ_HH
