//
// Created by kyle on 9/26/20.
//

#ifndef EZ_BOOM_LINE_HH
#define EZ_BOOM_LINE_HH

#include <array>
#include <cstdint>

#include "defs.hh"
#include "fixed.hh"

namespace sector
{
struct Sector;
} // namespace sector

namespace vertex
{
struct Vertex;
} // namespace vertex

namespace line
{

enum class SlopeType
{
    ST_HORIZONTAL,
    ST_VERTICAL,
    ST_POSITIVE,
    ST_NEGATIVE,
};

enum class RenderFlags
{
    RF_NONE = 0x0,
    RF_TOP_TILE = 0x1,
    RF_MID_TILE = 0x2,
    RF_BOT_TILE = 0x4,
    RF_IGNORE = 0x8,
    RF_CLOSED = 0x10,
    RF_ISOLATED = 0x20,
};

struct Line
{
    int32_t lineId{0};
    vertex::Vertex* v1{nullptr};
    vertex::Vertex* v2{nullptr};
    fixed::Fixed dx{0};
    fixed::Fixed dy{0};
    float texelLength{0};
    uint16_t flags{0};
    int16_t special{0};
    int16_t tag{0};
    std::array<uint16_t, 2> sideNum{0, 0};
    std::array<fixed::Fixed, 4> boundingBox{0, 0, 0, 0};
    SlopeType slopeType{SlopeType::ST_HORIZONTAL};
    sector::Sector* frontSector{nullptr};
    sector::Sector* backSector{nullptr};
    int32_t validCount{0};
    void* specialData{nullptr};
    int32_t tranLump{0};
    int32_t firstTag{0};
    int32_t nextTag{0};
    int32_t r_validCount{0};
    RenderFlags renderFlags{RenderFlags::RF_NONE};
    defs::DegenMobj soundOrigin{};
};

} // namespace line

#endif // EZ_BOOM_LINE_HH
