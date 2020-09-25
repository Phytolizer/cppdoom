//
// Created by kyle on 9/24/20.
//

#ifndef EZBOOM_COMPATIBILITY_HH
#define EZBOOM_COMPATIBILITY_HH

#include <array>
#include <cstdint>
#include <string_view>

struct PrBoomCompatibility
{
    uint32_t maxVer;
    uint32_t minVer;
    bool state;
    std::string_view cmd;
};

enum class PrBoomCompatibilityFlag
{
    MONSTER_AVOID_HAZARDS,
    REMOVE_SLIME_TRAILS,
    NO_DROPOFF,
    TRUNCATED_SECTOR_SPECIALS,
    BOOM_BRAINAWAKE,
    PRBOOM_FRICTION,
    REJECT_PAD_WITH_FF,
    FORCE_LXDOOM_DEMO_COMPATIBILITY,
    ALLOW_SSG_DIRECT,
    TREAT_NO_CLIPPING_THINGS_AS_NOT_BLOCKING,
    FORCE_INCORRECT_PROCESSING_OF_RESPAWN_FRAME_ENTRY,
    FORCE_CORRECT_CODE_FOR_3_KEYS_DOORS_IN_MBF,
    UNINITIALIZE_CRUSH_FIELD_FOR_STAIRS,
    FORCE_BOOM_FINDNEXTHIGHESTFLOOR,
    ALLOW_SKY_TRANSFER_IN_BOOM,
    APPLY_GREEN_ARMOR_CLASS_TO_ARMOR_BONUSES,
    APPLY_BLUE_ARMOR_CLASS_TO_MEGASPHERE,
    FORCE_INCORRECT_BOBBING_IN_BOOM,
    BOOM_DEH_PARSER,
    MBF_REMOVE_THINKER_IN_KILLMOBJ,
    DO_NOT_INHERIT_FRIENDLYNESS_FLAG_ON_SPAWN,
    DO_NOT_USE_MISC12_FRAME_PARAMETERS_IN_A_MUSHROOM,
    APPLY_MBF_CODEPOINTERS_TO_ANY_COMPLEVEL,
    RESET_MONSTERSPAWNER_PARAMS_AFTER_LOADING,
    MAX
};

inline constinit std::array prboomCompatibility{
    PrBoomCompatibility{0xffffffff, 0x02020615, false, "-force-monster-avoid-hazards"},
    PrBoomCompatibility{0x00000000, 0x02040601, false, "-force-remove-slime-trails"},
    PrBoomCompatibility{0x02020200, 0x02040801, false, "-force-no-dropoff"},
    PrBoomCompatibility{0x00000000, 0x02040801, false, "-force-truncated-sector-specials"},
    PrBoomCompatibility{0x00000000, 0x02040802, false, "-force-boom-brainawake"},
    PrBoomCompatibility{0x00000000, 0x02040802, false, "-force-prboom-friction"},
    PrBoomCompatibility{0x02020500, 0x02040000, false, "-reject-pad-with-ff"},
    PrBoomCompatibility{0xffffffff, 0x02040802, false, "-force-lxdoom-demo-compatibility"},
    PrBoomCompatibility{0x00000000, 0x0202061b, false, "-allow-ssg-direct"},
    PrBoomCompatibility{0x00000000, 0x02040601, false, "-treat-no-clipping-things-as-not-blocking"},
    PrBoomCompatibility{0x00000000, 0x02040803, false, "-force-incorrect-processing-of-respawn-frame-entry"},
    PrBoomCompatibility{0x00000000, 0x02040601, false, "-force-correct-code-for-3-keys-doors-in-mbf"},
    PrBoomCompatibility{0x00000000, 0x02040601, false, "-uninitialize-crush-field-for-stairs"},
    PrBoomCompatibility{0x00000000, 0x02040802, false, "-force-boom-findnexthighestfloor"},
    PrBoomCompatibility{0x00000000, 0x02040802, false, "-allow-sky-transfer-in-boom"},
    PrBoomCompatibility{0x00000000, 0x02040803, false, "-apply-green-armor-class-to-armor-bonuses"},
    PrBoomCompatibility{0x00000000, 0x02040803, false, "-apply-blue-armor-class-to-megasphere"},
    PrBoomCompatibility{0x02020200, 0x02050003, false, "-force-incorrect-bobbing-in-boom"},
    PrBoomCompatibility{0xffffffff, 0x00000000, false, "-boom-deh-parser"},
    PrBoomCompatibility{0x00000000, 0x02050007, false, "-mbf-remove-thinker-in-killmobj"},
    PrBoomCompatibility{0x00000000, 0x02050007, false, "-do-not-inherit-friendlyness-flag-on-spawn"},
    PrBoomCompatibility{0x00000000, 0x02050007, false, "-do-not-use-misc12-frame-parameters-in-a-mushroom"},
    PrBoomCompatibility{0x00000000, 0x02050102, false, "-apply-mbf-codepointers-to-any-complevel"},
    PrBoomCompatibility{0x00000000, 0x02050104, false, "-reset-monsterspawner-params-after-loading"},
};

#endif // DOOM_COMPATIBILITY_HH
