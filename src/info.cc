//
// Created by kyle on 9/20/20.
//

#include "info.hh"

constinit std::array<const char* const, to_underlying(info::SpriteEnum::NUMSPRITES) + 1> info::sprnames{
    "TROO",
    "SHTG",
    "PUNG",
    "PISG",
    "PISF",
    "SHTF",
    "SHT2",
    "CHGG",
    "CHGF",
    "MISG",
    "MISF",
    "SAWG",
    "PLSG",
    "PLSF",
    "BFGG",
    "BFGF",
    "BLUD",
    "PUFF",
    "BAL1",
    "BAL2",
    "PLSS",
    "PLSE",
    "MISL",
    "BFS1",
    "BFE1",
    "BFE2",
    "TFOG",
    "IFOG",
    "PLAY",
    "POSS",
    "SPOS",
    "VILE",
    "FIRE",
    "FATB",
    "FBXP",
    "SKEL",
    "MANF",
    "FATT",
    "CPOS",
    "SARG",
    "HEAD",
    "BAL7",
    "BOSS",
    "BOS2",
    "SKUL",
    "SPID",
    "BSPI",
    "APLS",
    "APBX",
    "CYBR",
    "PAIN",
    "SSWV",
    "KEEN",
    "BBRN",
    "BOSF",
    "ARM1",
    "ARM2",
    "BAR1",
    "BEXP",
    "FCAN",
    "BON1",
    "BON2",
    "BKEY",
    "RKEY",
    "YKEY",
    "BSKU",
    "RSKU",
    "YSKU",
    "STIM",
    "MEDI",
    "SOUL",
    "PINV",
    "PSTR",
    "PINS",
    "MEGA",
    "SUIT",
    "PMAP",
    "PVIS",
    "CLIP",
    "AMMO",
    "ROCK",
    "BROK",
    "CELL",
    "CELP",
    "SHEL",
    "SBOX",
    "BPAK",
    "BFUG",
    "MGUN",
    "CSAW",
    "LAUN",
    "PLAS",
    "SHOT",
    "SGN2",
    "COLU",
    "SMT2",
    "GOR1",
    "POL2",
    "POL5",
    "POL4",
    "POL3",
    "POL1",
    "POL6",
    "GOR2",
    "GOR3",
    "GOR4",
    "GOR5",
    "SMIT",
    "COL1",
    "COL2",
    "COL3",
    "COL4",
    "CAND",
    "CBRA",
    "COL6",
    "TRE1",
    "TRE2",
    "ELEC",
    "CEYE",
    "FSKU",
    "COL5",
    "TBLU",
    "TGRN",
    "TRED",
    "SMBT",
    "SMGT",
    "SMRT",
    "HDB1",
    "HDB2",
    "HDB3",
    "HDB4",
    "HDB5",
    "HDB6",
    "POB1",
    "POB2",
    "BRS1",
    "TLMP",
    "TLP2",
    "TNT1", // invisible sprite                                 phares 3/9/98
    "DOGS", /* killough 7/19/98: Marine's best friend :) */
    "PLS1", // killough 7/19/98: first  of two plasma fireballs in the beta
    "PLS2", // killough 7/19/98: second of two plasma fireballs in the beta
    "BON3", // killough 7/11/98: evil sceptre in the beta version
    "BON4", // killough 7/11/98: unholy bible in the beta version
    "BLD2", // blood splats from Doom Retro, unsused in PrBoom+

    // 100 extra sprite names to use in dehacked patches
    "SP00",
    "SP01",
    "SP02",
    "SP03",
    "SP04",
    "SP05",
    "SP06",
    "SP07",
    "SP08",
    "SP09",
    "SP10",
    "SP11",
    "SP12",
    "SP13",
    "SP14",
    "SP15",
    "SP16",
    "SP17",
    "SP18",
    "SP19",
    "SP20",
    "SP21",
    "SP22",
    "SP23",
    "SP24",
    "SP25",
    "SP26",
    "SP27",
    "SP28",
    "SP29",
    "SP30",
    "SP31",
    "SP32",
    "SP33",
    "SP34",
    "SP35",
    "SP36",
    "SP37",
    "SP38",
    "SP39",
    "SP40",
    "SP41",
    "SP42",
    "SP43",
    "SP44",
    "SP45",
    "SP46",
    "SP47",
    "SP48",
    "SP49",
    "SP50",
    "SP51",
    "SP52",
    "SP53",
    "SP54",
    "SP55",
    "SP56",
    "SP57",
    "SP58",
    "SP59",
    "SP60",
    "SP61",
    "SP62",
    "SP63",
    "SP64",
    "SP65",
    "SP66",
    "SP67",
    "SP68",
    "SP69",
    "SP70",
    "SP71",
    "SP72",
    "SP73",
    "SP74",
    "SP75",
    "SP76",
    "SP77",
    "SP78",
    "SP79",
    "SP80",
    "SP81",
    "SP82",
    "SP83",
    "SP84",
    "SP85",
    "SP86",
    "SP87",
    "SP88",
    "SP89",
    "SP90",
    "SP91",
    "SP92",
    "SP93",
    "SP94",
    "SP95",
    "SP96",
    "SP97",
    "SP98",
    "SP99",
    "",
};

constinit std::array<info::MobjInfo, to_underlying(info::MobjType::NUMMOBJTYPES)> info::mobjinfo{
    MobjInfo{
        // MT_PLAYER
        -1,                      // doomednum
        StateEnum::S_PLAY,       // spawnstate
        100,                     // spawnhealth
        StateEnum::S_PLAY_RUN1,  // seestate
        Sfx::sfx_None,           // seesound
        0,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_PLAY_PAIN,  // painstate
        255,                     // painchance
        Sfx::sfx_plpain,         // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_PLAY_ATK1,  // missilestate
        StateEnum::S_PLAY_DIE1,  // deathstate
        StateEnum::S_PLAY_XDIE1, // xdeathstate
        Sfx::sfx_pldeth,         // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        56 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_DROPOFF | MobjFlag::MF_PICKUP |
            MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL           // raisestate
    },

    MobjInfo{
        // MT_POSSESSED
        3004,                                                                 // doomednum
        StateEnum::S_POSS_STND,                                               // spawnstate
        20,                                                                   // spawnhealth
        StateEnum::S_POSS_RUN1,                                               // seestate
        Sfx::sfx_posit1,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_pistol,                                                      // attacksound
        StateEnum::S_POSS_PAIN,                                               // painstate
        200,                                                                  // painchance
        Sfx::sfx_popain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_POSS_ATK1,                                               // missilestate
        StateEnum::S_POSS_DIE1,                                               // deathstate
        StateEnum::S_POSS_XDIE1,                                              // xdeathstate
        Sfx::sfx_podth1,                                                      // deathsound
        8,                                                                    // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        100,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_posact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_POSS_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_SHOTGUY
        9,                                                                    // doomednum
        StateEnum::S_SPOS_STND,                                               // spawnstate
        30,                                                                   // spawnhealth
        StateEnum::S_SPOS_RUN1,                                               // seestate
        Sfx::sfx_posit2,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_SPOS_PAIN,                                               // painstate
        170,                                                                  // painchance
        Sfx::sfx_popain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_SPOS_ATK1,                                               // missilestate
        StateEnum::S_SPOS_DIE1,                                               // deathstate
        StateEnum::S_SPOS_XDIE1,                                              // xdeathstate
        Sfx::sfx_podth2,                                                      // deathsound
        8,                                                                    // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        100,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_posact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_SPOS_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_VILE
        64,                                                                   // doomednum
        StateEnum::S_VILE_STND,                                               // spawnstate
        700,                                                                  // spawnhealth
        StateEnum::S_VILE_RUN1,                                               // seestate
        Sfx::sfx_vilsit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_VILE_PAIN,                                               // painstate
        10,                                                                   // painchance
        Sfx::sfx_vipain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_VILE_ATK1,                                               // missilestate
        StateEnum::S_VILE_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_vildth,                                                      // deathsound
        15,                                                                   // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        500,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_vilact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_NULL                                                     // raisestate
    },

    MobjInfo{
        // MT_FIRE
        -1,                                                                          // doomednum
        StateEnum::S_FIRE1,                                                          // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags  // killough 2/21/98
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_UNDEAD
        66,                                                                   // doomednum
        StateEnum::S_SKEL_STND,                                               // spawnstate
        300,                                                                  // spawnhealth
        StateEnum::S_SKEL_RUN1,                                               // seestate
        Sfx::sfx_skesit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_SKEL_PAIN,                                               // painstate
        100,                                                                  // painchance
        Sfx::sfx_popain,                                                      // painsound
        StateEnum::S_SKEL_FIST1,                                              // meleestate
        StateEnum::S_SKEL_MISS1,                                              // missilestate
        StateEnum::S_SKEL_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_skedth,                                                      // deathsound
        10,                                                                   // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        500,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_skeact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_SKEL_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_TRACER
        -1,                                                                                             // doomednum
        StateEnum::S_TRACER,                                                                            // spawnstate
        1000,                                                                                           // spawnhealth
        StateEnum::S_NULL,                                                                              // seestate
        Sfx::sfx_skeatk,                                                                                // seesound
        8,                                                                                              // reactiontime
        Sfx::sfx_None,                                                                                  // attacksound
        StateEnum::S_NULL,                                                                              // painstate
        0,                                                                                              // painchance
        Sfx::sfx_None,                                                                                  // painsound
        StateEnum::S_NULL,                                                                              // meleestate
        StateEnum::S_NULL,                                                                              // missilestate
        StateEnum::S_TRACEEXP1,                                                                         // deathstate
        StateEnum::S_NULL,                                                                              // xdeathstate
        Sfx::sfx_barexp,                                                                                // deathsound
        10 * fixed::FRACUNIT,                                                                           // speed
        11 * fixed::FRACUNIT,                                                                           // radius
        8 * fixed::FRACUNIT,                                                                            // height
        100,                                                                                            // mass
        10,                                                                                             // damage
        Sfx::sfx_None,                                                                                  // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                                               // raisestate
    },

    MobjInfo{
        // MT_SMOKE
        -1,                                                                          // doomednum
        StateEnum::S_SMOKE1,                                                         // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags             // phares
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_FATSO
        67,                                                                   // doomednum
        StateEnum::S_FATT_STND,                                               // spawnstate
        600,                                                                  // spawnhealth
        StateEnum::S_FATT_RUN1,                                               // seestate
        Sfx::sfx_mansit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_FATT_PAIN,                                               // painstate
        80,                                                                   // painchance
        Sfx::sfx_mnpain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_FATT_ATK1,                                               // missilestate
        StateEnum::S_FATT_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_mandth,                                                      // deathsound
        8,                                                                    // speed
        48 * fixed::FRACUNIT,                                                 // radius
        64 * fixed::FRACUNIT,                                                 // height
        1000,                                                                 // mass
        0,                                                                    // damage
        Sfx::sfx_posact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_FATT_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_FATSHOT
        -1,                     // doomednum
        StateEnum::S_FATSHOT1,  // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_firsht,        // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_FATSHOTX1, // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_firxpl,        // deathsound
        20 * fixed::FRACUNIT,   // speed
        6 * fixed::FRACUNIT,    // radius
        8 * fixed::FRACUNIT,    // height
        100,                    // mass
        8,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags \\ killough 2/21/98
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_CHAINGUY
        65,                                                                   // doomednum
        StateEnum::S_CPOS_STND,                                               // spawnstate
        70,                                                                   // spawnhealth
        StateEnum::S_CPOS_RUN1,                                               // seestate
        Sfx::sfx_posit2,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_CPOS_PAIN,                                               // painstate
        170,                                                                  // painchance
        Sfx::sfx_popain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_CPOS_ATK1,                                               // missilestate
        StateEnum::S_CPOS_DIE1,                                               // deathstate
        StateEnum::S_CPOS_XDIE1,                                              // xdeathstate
        Sfx::sfx_podth2,                                                      // deathsound
        8,                                                                    // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        100,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_posact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_CPOS_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_TROOP
        3001,                    // doomednum
        StateEnum::S_TROO_STND,  // spawnstate
        60,                      // spawnhealth
        StateEnum::S_TROO_RUN1,  // seestate
        Sfx::sfx_bgsit1,         // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_TROO_PAIN,  // painstate
        200,                     // painchance
        Sfx::sfx_popain,         // painsound
        StateEnum::S_TROO_ATK1,  // meleestate
        StateEnum::S_TROO_ATK1,  // missilestate
        StateEnum::S_TROO_DIE1,  // deathstate
        StateEnum::S_TROO_XDIE1, // xdeathstate
        Sfx::sfx_bgdth1,         // deathsound
        8,                       // speed
        20 * fixed::FRACUNIT,    // radius
        56 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_bgact,          // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE |
            MobjFlag::MF_COUNTKILL, // killough |MobjFlag::MF_TRANSLUCENT,   // flags     // phares
        StateEnum::S_TROO_RAISE1    // raisestate
    },

    MobjInfo{
        // MT_SERGEANT
        3002,                                                                 // doomednum
        StateEnum::S_SARG_STND,                                               // spawnstate
        150,                                                                  // spawnhealth
        StateEnum::S_SARG_RUN1,                                               // seestate
        Sfx::sfx_sgtsit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_sgtatk,                                                      // attacksound
        StateEnum::S_SARG_PAIN,                                               // painstate
        180,                                                                  // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_SARG_ATK1,                                               // meleestate
        StateEnum::S_NULL,                                                    // missilestate
        StateEnum::S_SARG_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_sgtdth,                                                      // deathsound
        10,                                                                   // speed
        30 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        400,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_dmact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_SARG_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_SHADOWS
        58,                                                                                         // doomednum
        StateEnum::S_SARG_STND,                                                                     // spawnstate
        150,                                                                                        // spawnhealth
        StateEnum::S_SARG_RUN1,                                                                     // seestate
        Sfx::sfx_sgtsit,                                                                            // seesound
        8,                                                                                          // reactiontime
        Sfx::sfx_sgtatk,                                                                            // attacksound
        StateEnum::S_SARG_PAIN,                                                                     // painstate
        180,                                                                                        // painchance
        Sfx::sfx_dmpain,                                                                            // painsound
        StateEnum::S_SARG_ATK1,                                                                     // meleestate
        StateEnum::S_NULL,                                                                          // missilestate
        StateEnum::S_SARG_DIE1,                                                                     // deathstate
        StateEnum::S_NULL,                                                                          // xdeathstate
        Sfx::sfx_sgtdth,                                                                            // deathsound
        10,                                                                                         // speed
        30 * fixed::FRACUNIT,                                                                       // radius
        56 * fixed::FRACUNIT,                                                                       // height
        400,                                                                                        // mass
        0,                                                                                          // damage
        Sfx::sfx_dmact,                                                                             // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_SHADOW | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_SARG_RAISE1                                                                    // raisestate
    },

    MobjInfo{
        // MT_HEAD
        3005,                   // doomednum
        StateEnum::S_HEAD_STND, // spawnstate
        400,                    // spawnhealth
        StateEnum::S_HEAD_RUN1, // seestate
        Sfx::sfx_cacsit,        // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_HEAD_PAIN, // painstate
        128,                    // painchance
        Sfx::sfx_dmpain,        // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_HEAD_ATK1, // missilestate
        StateEnum::S_HEAD_DIE1, // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_cacdth,        // deathsound
        8,                      // speed
        31 * fixed::FRACUNIT,   // radius
        56 * fixed::FRACUNIT,   // height
        400,                    // mass
        0,                      // damage
        Sfx::sfx_dmact,         // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_FLOAT | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_HEAD_RAISE1    // raisestate
    },

    MobjInfo{
        // MT_BRUISER
        3003,                                                                 // doomednum
        StateEnum::S_BOSS_STND,                                               // spawnstate
        1000,                                                                 // spawnhealth
        StateEnum::S_BOSS_RUN1,                                               // seestate
        Sfx::sfx_brssit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_BOSS_PAIN,                                               // painstate
        50,                                                                   // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_BOSS_ATK1,                                               // meleestate
        StateEnum::S_BOSS_ATK1,                                               // missilestate
        StateEnum::S_BOSS_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_brsdth,                                                      // deathsound
        8,                                                                    // speed
        24 * fixed::FRACUNIT,                                                 // radius
        64 * fixed::FRACUNIT,                                                 // height
        1000,                                                                 // mass
        0,                                                                    // damage
        Sfx::sfx_dmact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_BOSS_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_BRUISERSHOT
        -1,                    // doomednum
        StateEnum::S_BRBALL1,  // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_firsht,       // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_BRBALLX1, // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_firxpl,       // deathsound
        15 * fixed::FRACUNIT,  // speed
        6 * fixed::FRACUNIT,   // radius
        8 * fixed::FRACUNIT,   // height
        100,                   // mass
        8,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags  killough 2/21/98
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_KNIGHT
        69,                                                                   // doomednum
        StateEnum::S_BOS2_STND,                                               // spawnstate
        500,                                                                  // spawnhealth
        StateEnum::S_BOS2_RUN1,                                               // seestate
        Sfx::sfx_kntsit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_BOS2_PAIN,                                               // painstate
        50,                                                                   // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_BOS2_ATK1,                                               // meleestate
        StateEnum::S_BOS2_ATK1,                                               // missilestate
        StateEnum::S_BOS2_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_kntdth,                                                      // deathsound
        8,                                                                    // speed
        24 * fixed::FRACUNIT,                                                 // radius
        64 * fixed::FRACUNIT,                                                 // height
        1000,                                                                 // mass
        0,                                                                    // damage
        Sfx::sfx_dmact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_BOS2_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_SKULL
        3006,                                                                                      // doomednum
        StateEnum::S_SKULL_STND,                                                                   // spawnstate
        100,                                                                                       // spawnhealth
        StateEnum::S_SKULL_RUN1,                                                                   // seestate
        Sfx::sfx_None,                                                                             // seesound
        8,                                                                                         // reactiontime
        Sfx::sfx_sklatk,                                                                           // attacksound
        StateEnum::S_SKULL_PAIN,                                                                   // painstate
        256,                                                                                       // painchance
        Sfx::sfx_dmpain,                                                                           // painsound
        StateEnum::S_NULL,                                                                         // meleestate
        StateEnum::S_SKULL_ATK1,                                                                   // missilestate
        StateEnum::S_SKULL_DIE1,                                                                   // deathstate
        StateEnum::S_NULL,                                                                         // xdeathstate
        Sfx::sfx_firxpl,                                                                           // deathsound
        8,                                                                                         // speed
        16 * fixed::FRACUNIT,                                                                      // radius
        56 * fixed::FRACUNIT,                                                                      // height
        50,                                                                                        // mass
        3,                                                                                         // damage
        Sfx::sfx_dmact,                                                                            // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_FLOAT | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                                          // raisestate
    },

    MobjInfo{
        // MT_SPIDER
        7,                                                                    // doomednum
        StateEnum::S_SPID_STND,                                               // spawnstate
        3000,                                                                 // spawnhealth
        StateEnum::S_SPID_RUN1,                                               // seestate
        Sfx::sfx_spisit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_shotgn,                                                      // attacksound
        StateEnum::S_SPID_PAIN,                                               // painstate
        40,                                                                   // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_SPID_ATK1,                                               // missilestate
        StateEnum::S_SPID_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_spidth,                                                      // deathsound
        12,                                                                   // speed
        128 * fixed::FRACUNIT,                                                // radius
        100 * fixed::FRACUNIT,                                                // height
        1000,                                                                 // mass
        0,                                                                    // damage
        Sfx::sfx_dmact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_NULL                                                     // raisestate
    },

    MobjInfo{
        // MT_BABY
        68,                                                                   // doomednum
        StateEnum::S_BSPI_STND,                                               // spawnstate
        500,                                                                  // spawnhealth
        StateEnum::S_BSPI_SIGHT,                                              // seestate
        Sfx::sfx_bspsit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_BSPI_PAIN,                                               // painstate
        128,                                                                  // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_BSPI_ATK1,                                               // missilestate
        StateEnum::S_BSPI_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_bspdth,                                                      // deathsound
        12,                                                                   // speed
        64 * fixed::FRACUNIT,                                                 // radius
        64 * fixed::FRACUNIT,                                                 // height
        600,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_bspact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_BSPI_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_CYBORG
        16,                                                                   // doomednum
        StateEnum::S_CYBER_STND,                                              // spawnstate
        4000,                                                                 // spawnhealth
        StateEnum::S_CYBER_RUN1,                                              // seestate
        Sfx::sfx_cybsit,                                                      // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_CYBER_PAIN,                                              // painstate
        20,                                                                   // painchance
        Sfx::sfx_dmpain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_CYBER_ATK1,                                              // missilestate
        StateEnum::S_CYBER_DIE1,                                              // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_cybdth,                                                      // deathsound
        16,                                                                   // speed
        40 * fixed::FRACUNIT,                                                 // radius
        110 * fixed::FRACUNIT,                                                // height
        1000,                                                                 // mass
        0,                                                                    // damage
        Sfx::sfx_dmact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_NULL                                                     // raisestate
    },

    MobjInfo{
        // MT_PAIN
        71,                     // doomednum
        StateEnum::S_PAIN_STND, // spawnstate
        400,                    // spawnhealth
        StateEnum::S_PAIN_RUN1, // seestate
        Sfx::sfx_pesit,         // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_PAIN_PAIN, // painstate
        128,                    // painchance
        Sfx::sfx_pepain,        // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_PAIN_ATK1, // missilestate
        StateEnum::S_PAIN_DIE1, // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_pedth,         // deathsound
        8,                      // speed
        31 * fixed::FRACUNIT,   // radius
        56 * fixed::FRACUNIT,   // height
        400,                    // mass
        0,                      // damage
        Sfx::sfx_dmact,         // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_FLOAT | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_PAIN_RAISE1    // raisestate
    },

    MobjInfo{
        // MT_WOLFSS
        84,                                                                   // doomednum
        StateEnum::S_SSWV_STND,                                               // spawnstate
        50,                                                                   // spawnhealth
        StateEnum::S_SSWV_RUN1,                                               // seestate
        Sfx::sfx_sssit,                                                       // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_None,                                                        // attacksound
        StateEnum::S_SSWV_PAIN,                                               // painstate
        170,                                                                  // painchance
        Sfx::sfx_popain,                                                      // painsound
        StateEnum::S_NULL,                                                    // meleestate
        StateEnum::S_SSWV_ATK1,                                               // missilestate
        StateEnum::S_SSWV_DIE1,                                               // deathstate
        StateEnum::S_SSWV_XDIE1,                                              // xdeathstate
        Sfx::sfx_ssdth,                                                       // deathsound
        8,                                                                    // speed
        20 * fixed::FRACUNIT,                                                 // radius
        56 * fixed::FRACUNIT,                                                 // height
        100,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_posact,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_SSWV_RAISE1                                              // raisestate
    },

    MobjInfo{
        // MT_KEEN
        72,                    // doomednum
        StateEnum::S_KEENSTND, // spawnstate
        100,                   // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_None,         // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_KEENPAIN, // painstate
        256,                   // painchance
        Sfx::sfx_keenpn,       // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_COMMKEEN, // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_keendt,       // deathsound
        0,                     // speed
        16 * fixed::FRACUNIT,  // radius
        72 * fixed::FRACUNIT,  // height
        10000000,              // mass
        0,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_SHOOTABLE |
            MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_NULL           // raisestate
    },

    MobjInfo{
        // MT_BOSSBRAIN
        88,                                          // doomednum
        StateEnum::S_BRAIN,                          // spawnstate
        250,                                         // spawnhealth
        StateEnum::S_NULL,                           // seestate
        Sfx::sfx_None,                               // seesound
        8,                                           // reactiontime
        Sfx::sfx_None,                               // attacksound
        StateEnum::S_BRAIN_PAIN,                     // painstate
        255,                                         // painchance
        Sfx::sfx_bospn,                              // painsound
        StateEnum::S_NULL,                           // meleestate
        StateEnum::S_NULL,                           // missilestate
        StateEnum::S_BRAIN_DIE1,                     // deathstate
        StateEnum::S_NULL,                           // xdeathstate
        Sfx::sfx_bosdth,                             // deathsound
        0,                                           // speed
        16 * fixed::FRACUNIT,                        // radius
        16 * fixed::FRACUNIT,                        // height
        10000000,                                    // mass
        0,                                           // damage
        Sfx::sfx_None,                               // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE, // flags
        StateEnum::S_NULL                            // raisestate
    },

    MobjInfo{
        // MT_BOSSSPIT
        89,                                              // doomednum
        StateEnum::S_BRAINEYE,                           // spawnstate
        1000,                                            // spawnhealth
        StateEnum::S_BRAINEYESEE,                        // seestate
        Sfx::sfx_None,                                   // seesound
        8,                                               // reactiontime
        Sfx::sfx_None,                                   // attacksound
        StateEnum::S_NULL,                               // painstate
        0,                                               // painchance
        Sfx::sfx_None,                                   // painsound
        StateEnum::S_NULL,                               // meleestate
        StateEnum::S_NULL,                               // missilestate
        StateEnum::S_NULL,                               // deathstate
        StateEnum::S_NULL,                               // xdeathstate
        Sfx::sfx_None,                                   // deathsound
        0,                                               // speed
        20 * fixed::FRACUNIT,                            // radius
        32 * fixed::FRACUNIT,                            // height
        100,                                             // mass
        0,                                               // damage
        Sfx::sfx_None,                                   // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOSECTOR, // flags
        StateEnum::S_NULL                                // raisestate
    },

    MobjInfo{
        // MT_BOSSTARGET
        87,                                              // doomednum
        StateEnum::S_NULL,                               // spawnstate
        1000,                                            // spawnhealth
        StateEnum::S_NULL,                               // seestate
        Sfx::sfx_None,                                   // seesound
        8,                                               // reactiontime
        Sfx::sfx_None,                                   // attacksound
        StateEnum::S_NULL,                               // painstate
        0,                                               // painchance
        Sfx::sfx_None,                                   // painsound
        StateEnum::S_NULL,                               // meleestate
        StateEnum::S_NULL,                               // missilestate
        StateEnum::S_NULL,                               // deathstate
        StateEnum::S_NULL,                               // xdeathstate
        Sfx::sfx_None,                                   // deathsound
        0,                                               // speed
        20 * fixed::FRACUNIT,                            // radius
        32 * fixed::FRACUNIT,                            // height
        100,                                             // mass
        0,                                               // damage
        Sfx::sfx_None,                                   // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOSECTOR, // flags
        StateEnum::S_NULL                                // raisestate
    },

    MobjInfo{
        // MT_SPAWNSHOT
        -1,                   // doomednum
        StateEnum::S_SPAWN1,  // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_bospit,      // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_firxpl,      // deathsound
        10 * fixed::FRACUNIT, // speed
        6 * fixed::FRACUNIT,  // radius
        32 * fixed::FRACUNIT, // height
        100,                  // mass
        3,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_NOCLIP, // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_SPAWNFIRE
        -1,                                                                          // doomednum
        StateEnum::S_SPAWNFIRE1,                                                     // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags             // phares
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_BARREL
        2035,                                                               // doomednum
        StateEnum::S_BAR1,                                                  // spawnstate
        20,                                                                 // spawnhealth
        StateEnum::S_NULL,                                                  // seestate
        Sfx::sfx_None,                                                      // seesound
        8,                                                                  // reactiontime
        Sfx::sfx_None,                                                      // attacksound
        StateEnum::S_NULL,                                                  // painstate
        0,                                                                  // painchance
        Sfx::sfx_None,                                                      // painsound
        StateEnum::S_NULL,                                                  // meleestate
        StateEnum::S_NULL,                                                  // missilestate
        StateEnum::S_BEXP,                                                  // deathstate
        StateEnum::S_NULL,                                                  // xdeathstate
        Sfx::sfx_barexp,                                                    // deathsound
        0,                                                                  // speed
        10 * fixed::FRACUNIT,                                               // radius
        42 * fixed::FRACUNIT,                                               // height
        100,                                                                // mass
        0,                                                                  // damage
        Sfx::sfx_None,                                                      // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_NOBLOOD, // flags
        StateEnum::S_NULL                                                   // raisestate
    },

    MobjInfo{
        // MT_TROOPSHOT
        -1,                   // doomednum
        StateEnum::S_TBALL1,  // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_firsht,      // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_TBALLX1, // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_firxpl,      // deathsound
        10 * fixed::FRACUNIT, // speed
        6 * fixed::FRACUNIT,  // radius
        8 * fixed::FRACUNIT,  // height
        100,                  // mass
        3,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_HEADSHOT
        -1,                   // doomednum
        StateEnum::S_RBALL1,  // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_firsht,      // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_RBALLX1, // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_firxpl,      // deathsound
        10 * fixed::FRACUNIT, // speed
        6 * fixed::FRACUNIT,  // radius
        8 * fixed::FRACUNIT,  // height
        100,                  // mass
        5,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags // phares,   // flags
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_ROCKET
        -1,                                                                                             // doomednum
        StateEnum::S_ROCKET,                                                                            // spawnstate
        1000,                                                                                           // spawnhealth
        StateEnum::S_NULL,                                                                              // seestate
        Sfx::sfx_rlaunc,                                                                                // seesound
        8,                                                                                              // reactiontime
        Sfx::sfx_None,                                                                                  // attacksound
        StateEnum::S_NULL,                                                                              // painstate
        0,                                                                                              // painchance
        Sfx::sfx_None,                                                                                  // painsound
        StateEnum::S_NULL,                                                                              // meleestate
        StateEnum::S_NULL,                                                                              // missilestate
        StateEnum::S_EXPLODE1,                                                                          // deathstate
        StateEnum::S_NULL,                                                                              // xdeathstate
        Sfx::sfx_barexp,                                                                                // deathsound
        20 * fixed::FRACUNIT,                                                                           // speed
        11 * fixed::FRACUNIT,                                                                           // radius
        8 * fixed::FRACUNIT,                                                                            // height
        100,                                                                                            // mass
        20,                                                                                             // damage
        Sfx::sfx_None,                                                                                  // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                                               // raisestate
    },

    MobjInfo{
        // MT_PLASMA
        -1,                    // doomednum
        StateEnum::S_PLASBALL, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_plasma,       // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_PLASEXP,  // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_firxpl,       // deathsound
        25 * fixed::FRACUNIT,  // speed
        13 * fixed::FRACUNIT,  // radius
        8 * fixed::FRACUNIT,   // height
        100,                   // mass
        5,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_BFG
        -1,                   // doomednum
        StateEnum::S_BFGSHOT, // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_BFGLAND, // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_rxplod,      // deathsound
        25 * fixed::FRACUNIT, // speed
        13 * fixed::FRACUNIT, // radius
        8 * fixed::FRACUNIT,  // height
        100,                  // mass
        100,                  // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_ARACHPLAZ
        -1,                      // doomednum
        StateEnum::S_ARACH_PLAZ, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_plasma,         // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_ARACH_PLEX, // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_firxpl,         // deathsound
        25 * fixed::FRACUNIT,    // speed
        13 * fixed::FRACUNIT,    // radius
        8 * fixed::FRACUNIT,     // height
        100,                     // mass
        5,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL             // raisestate
    },

    MobjInfo{
        // MT_PUFF
        -1,                                                                          // doomednum
        StateEnum::S_PUFF1,                                                          // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_BLOOD
        -1,                      // doomednum
        StateEnum::S_BLOOD1,     // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_TFOG
        -1,                                                                          // doomednum
        StateEnum::S_TFOG,                                                           // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_IFOG
        -1,                                                                          // doomednum
        StateEnum::S_IFOG,                                                           // spawnstate
        1000,                                                                        // spawnhealth
        StateEnum::S_NULL,                                                           // seestate
        Sfx::sfx_None,                                                               // seesound
        8,                                                                           // reactiontime
        Sfx::sfx_None,                                                               // attacksound
        StateEnum::S_NULL,                                                           // painstate
        0,                                                                           // painchance
        Sfx::sfx_None,                                                               // painsound
        StateEnum::S_NULL,                                                           // meleestate
        StateEnum::S_NULL,                                                           // missilestate
        StateEnum::S_NULL,                                                           // deathstate
        StateEnum::S_NULL,                                                           // xdeathstate
        Sfx::sfx_None,                                                               // deathsound
        0,                                                                           // speed
        20 * fixed::FRACUNIT,                                                        // radius
        16 * fixed::FRACUNIT,                                                        // height
        100,                                                                         // mass
        0,                                                                           // damage
        Sfx::sfx_None,                                                               // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY | MobjFlag::MF_TRANSLUCENT, // flags // phares
        StateEnum::S_NULL                                                            // raisestate
    },

    MobjInfo{
        // MT_TELEPORTMAN
        14,                                              // doomednum
        StateEnum::S_NULL,                               // spawnstate
        1000,                                            // spawnhealth
        StateEnum::S_NULL,                               // seestate
        Sfx::sfx_None,                                   // seesound
        8,                                               // reactiontime
        Sfx::sfx_None,                                   // attacksound
        StateEnum::S_NULL,                               // painstate
        0,                                               // painchance
        Sfx::sfx_None,                                   // painsound
        StateEnum::S_NULL,                               // meleestate
        StateEnum::S_NULL,                               // missilestate
        StateEnum::S_NULL,                               // deathstate
        StateEnum::S_NULL,                               // xdeathstate
        Sfx::sfx_None,                                   // deathsound
        0,                                               // speed
        20 * fixed::FRACUNIT,                            // radius
        16 * fixed::FRACUNIT,                            // height
        100,                                             // mass
        0,                                               // damage
        Sfx::sfx_None,                                   // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOSECTOR, // flags
        StateEnum::S_NULL                                // raisestate
    },

    MobjInfo{
        // MT_EXTRABFG
        -1,                                               // doomednum
        StateEnum::S_BFGEXP,                              // spawnstate
        1000,                                             // spawnhealth
        StateEnum::S_NULL,                                // seestate
        Sfx::sfx_None,                                    // seesound
        8,                                                // reactiontime
        Sfx::sfx_None,                                    // attacksound
        StateEnum::S_NULL,                                // painstate
        0,                                                // painchance
        Sfx::sfx_None,                                    // painsound
        StateEnum::S_NULL,                                // meleestate
        StateEnum::S_NULL,                                // missilestate
        StateEnum::S_NULL,                                // deathstate
        StateEnum::S_NULL,                                // xdeathstate
        Sfx::sfx_None,                                    // deathsound
        0,                                                // speed
        20 * fixed::FRACUNIT,                             // radius
        16 * fixed::FRACUNIT,                             // height
        100,                                              // mass
        0,                                                // damage
        Sfx::sfx_None,                                    // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                 // raisestate
    },

    MobjInfo{
        // MT_MISC0
        2018,                 // doomednum
        StateEnum::S_ARM1,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC1
        2019,                 // doomednum
        StateEnum::S_ARM2,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC2
        2014,                                          // doomednum
        StateEnum::S_BON1,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC3
        2015,                                          // doomednum
        StateEnum::S_BON2,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC4
        5,                                             // doomednum
        StateEnum::S_BKEY,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC5
        13,                                            // doomednum
        StateEnum::S_RKEY,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC6
        6,                                             // doomednum
        StateEnum::S_YKEY,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC7
        39,                                            // doomednum
        StateEnum::S_YSKULL,                           // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC8
        38,                                            // doomednum
        StateEnum::S_RSKULL,                           // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC9
        40,                                            // doomednum
        StateEnum::S_BSKULL,                           // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_NOTDMATCH, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC10
        2011,                 // doomednum
        StateEnum::S_STIM,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC11
        2012,                 // doomednum
        StateEnum::S_MEDI,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC12
        2013,                                                                     // doomednum
        StateEnum::S_SOUL,                                                        // spawnstate
        1000,                                                                     // spawnhealth
        StateEnum::S_NULL,                                                        // seestate
        Sfx::sfx_None,                                                            // seesound
        8,                                                                        // reactiontime
        Sfx::sfx_None,                                                            // attacksound
        StateEnum::S_NULL,                                                        // painstate
        0,                                                                        // painchance
        Sfx::sfx_None,                                                            // painsound
        StateEnum::S_NULL,                                                        // meleestate
        StateEnum::S_NULL,                                                        // missilestate
        StateEnum::S_NULL,                                                        // deathstate
        StateEnum::S_NULL,                                                        // xdeathstate
        Sfx::sfx_None,                                                            // deathsound
        0,                                                                        // speed
        20 * fixed::FRACUNIT,                                                     // radius
        16 * fixed::FRACUNIT,                                                     // height
        100,                                                                      // mass
        0,                                                                        // damage
        Sfx::sfx_None,                                                            // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM | MobjFlag::MF_TRANSLUCENT, // flags   // killough 2/21/98
        StateEnum::S_NULL                                                         // raisestate
    },

    MobjInfo{
        // MT_INV
        2022,                                                                     // doomednum
        StateEnum::S_PINV,                                                        // spawnstate
        1000,                                                                     // spawnhealth
        StateEnum::S_NULL,                                                        // seestate
        Sfx::sfx_None,                                                            // seesound
        8,                                                                        // reactiontime
        Sfx::sfx_None,                                                            // attacksound
        StateEnum::S_NULL,                                                        // painstate
        0,                                                                        // painchance
        Sfx::sfx_None,                                                            // painsound
        StateEnum::S_NULL,                                                        // meleestate
        StateEnum::S_NULL,                                                        // missilestate
        StateEnum::S_NULL,                                                        // deathstate
        StateEnum::S_NULL,                                                        // xdeathstate
        Sfx::sfx_None,                                                            // deathsound
        0,                                                                        // speed
        20 * fixed::FRACUNIT,                                                     // radius
        16 * fixed::FRACUNIT,                                                     // height
        100,                                                                      // mass
        0,                                                                        // damage
        Sfx::sfx_None,                                                            // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM | MobjFlag::MF_TRANSLUCENT, // flags // killough 2/21/98
        StateEnum::S_NULL                                                         // raisestate
    },

    MobjInfo{
        // MT_MISC13
        2023,                                          // doomednum
        StateEnum::S_PSTR,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_INS
        2024,                                                                     // doomednum
        StateEnum::S_PINS,                                                        // spawnstate
        1000,                                                                     // spawnhealth
        StateEnum::S_NULL,                                                        // seestate
        Sfx::sfx_None,                                                            // seesound
        8,                                                                        // reactiontime
        Sfx::sfx_None,                                                            // attacksound
        StateEnum::S_NULL,                                                        // painstate
        0,                                                                        // painchance
        Sfx::sfx_None,                                                            // painsound
        StateEnum::S_NULL,                                                        // meleestate
        StateEnum::S_NULL,                                                        // missilestate
        StateEnum::S_NULL,                                                        // deathstate
        StateEnum::S_NULL,                                                        // xdeathstate
        Sfx::sfx_None,                                                            // deathsound
        0,                                                                        // speed
        20 * fixed::FRACUNIT,                                                     // radius
        16 * fixed::FRACUNIT,                                                     // height
        100,                                                                      // mass
        0,                                                                        // damage
        Sfx::sfx_None,                                                            // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM | MobjFlag::MF_TRANSLUCENT, // flags // killough 2/21/98
        StateEnum::S_NULL                                                         // raisestate
    },

    MobjInfo{
        // MT_MISC14
        2025,                 // doomednum
        StateEnum::S_SUIT,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC15
        2026,                                          // doomednum
        StateEnum::S_PMAP,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MISC16
        2045,                                          // doomednum
        StateEnum::S_PVIS,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    MobjInfo{
        // MT_MEGA
        83,                                                                       // doomednum
        StateEnum::S_MEGA,                                                        // spawnstate
        1000,                                                                     // spawnhealth
        StateEnum::S_NULL,                                                        // seestate
        Sfx::sfx_None,                                                            // seesound
        8,                                                                        // reactiontime
        Sfx::sfx_None,                                                            // attacksound
        StateEnum::S_NULL,                                                        // painstate
        0,                                                                        // painchance
        Sfx::sfx_None,                                                            // painsound
        StateEnum::S_NULL,                                                        // meleestate
        StateEnum::S_NULL,                                                        // missilestate
        StateEnum::S_NULL,                                                        // deathstate
        StateEnum::S_NULL,                                                        // xdeathstate
        Sfx::sfx_None,                                                            // deathsound
        0,                                                                        // speed
        20 * fixed::FRACUNIT,                                                     // radius
        16 * fixed::FRACUNIT,                                                     // height
        100,                                                                      // mass
        0,                                                                        // damage
        Sfx::sfx_None,                                                            // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM | MobjFlag::MF_TRANSLUCENT, // flags // killough 2/21/98
        StateEnum::S_NULL                                                         // raisestate
    },

    MobjInfo{
        // MT_CLIP
        2007,                 // doomednum
        StateEnum::S_CLIP,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC17
        2048,                 // doomednum
        StateEnum::S_AMMO,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC18
        2010,                 // doomednum
        StateEnum::S_ROCK,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC19
        2046,                 // doomednum
        StateEnum::S_BROK,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC20
        2047,                 // doomednum
        StateEnum::S_CELL,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC21
        17,                   // doomednum
        StateEnum::S_CELP,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC22
        2008,                 // doomednum
        StateEnum::S_SHEL,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC23
        2049,                 // doomednum
        StateEnum::S_SBOX,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC24
        8,                    // doomednum
        StateEnum::S_BPAK,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC25
        2006,                 // doomednum
        StateEnum::S_BFUG,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_CHAINGUN
        2002,                 // doomednum
        StateEnum::S_MGUN,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC26
        2005,                 // doomednum
        StateEnum::S_CSAW,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC27
        2003,                 // doomednum
        StateEnum::S_LAUN,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC28
        2004,                 // doomednum
        StateEnum::S_PLAS,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_SHOTGUN
        2001,                 // doomednum
        StateEnum::S_SHOT,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_SUPERSHOTGUN
        82,                   // doomednum
        StateEnum::S_SHOT2,   // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SPECIAL, // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC29
        85,                    // doomednum
        StateEnum::S_TECHLAMP, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_None,         // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_NULL,     // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_None,         // deathsound
        0,                     // speed
        16 * fixed::FRACUNIT,  // radius
        16 * fixed::FRACUNIT,  // height
        100,                   // mass
        0,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_SOLID,    // flags
        StateEnum::S_NULL      // raisestate
    },

    MobjInfo{
        // MT_MISC30
        86,                     // doomednum
        StateEnum::S_TECH2LAMP, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        16 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_SOLID,     // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC31
        2028,                 // doomednum
        StateEnum::S_COLU,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        16 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SOLID,   // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC32
        30,                      // doomednum
        StateEnum::S_TALLGRNCOL, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC33
        31,                      // doomednum
        StateEnum::S_SHRTGRNCOL, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC34
        32,                      // doomednum
        StateEnum::S_TALLREDCOL, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC35
        33,                      // doomednum
        StateEnum::S_SHRTREDCOL, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC36
        37,                    // doomednum
        StateEnum::S_SKULLCOL, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_None,         // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_NULL,     // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_None,         // deathsound
        0,                     // speed
        16 * fixed::FRACUNIT,  // radius
        16 * fixed::FRACUNIT,  // height
        100,                   // mass
        0,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_SOLID,    // flags
        StateEnum::S_NULL      // raisestate
    },

    MobjInfo{
        // MT_MISC37
        36,                    // doomednum
        StateEnum::S_HEARTCOL, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_None,         // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_NULL,     // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_None,         // deathsound
        0,                     // speed
        16 * fixed::FRACUNIT,  // radius
        16 * fixed::FRACUNIT,  // height
        100,                   // mass
        0,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_SOLID,    // flags
        StateEnum::S_NULL      // raisestate
    },

    MobjInfo{
        // MT_MISC38
        41,                   // doomednum
        StateEnum::S_EVILEYE, // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        16 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SOLID,   // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC39
        42,                      // doomednum
        StateEnum::S_FLOATSKULL, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC40
        43,                     // doomednum
        StateEnum::S_TORCHTREE, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        16 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_SOLID,     // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC41
        44,                     // doomednum
        StateEnum::S_BLUETORCH, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        16 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_SOLID,     // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC42
        45,                      // doomednum
        StateEnum::S_GREENTORCH, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC43
        46,                    // doomednum
        StateEnum::S_REDTORCH, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_None,         // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_NULL,     // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_None,         // deathsound
        0,                     // speed
        16 * fixed::FRACUNIT,  // radius
        16 * fixed::FRACUNIT,  // height
        100,                   // mass
        0,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_SOLID,    // flags
        StateEnum::S_NULL      // raisestate
    },

    MobjInfo{
        // MT_MISC44
        55,                      // doomednum
        StateEnum::S_BTORCHSHRT, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC45
        56,                      // doomednum
        StateEnum::S_GTORCHSHRT, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC46
        57,                      // doomednum
        StateEnum::S_RTORCHSHRT, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC47
        47,                      // doomednum
        StateEnum::S_STALAGTITE, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC48
        48,                      // doomednum
        StateEnum::S_TECHPILLAR, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC49
        34,                      // doomednum
        StateEnum::S_CANDLESTIK, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NONE,       // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC50
        35,                      // doomednum
        StateEnum::S_CANDELABRA, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_SOLID,      // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC51
        49,                                                                      // doomednum
        StateEnum::S_BLOODYTWITCH,                                               // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        68 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC52
        50,                                                                      // doomednum
        StateEnum::S_MEAT2,                                                      // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        84 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC53
        51,                                                                      // doomednum
        StateEnum::S_MEAT3,                                                      // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        84 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC54
        52,                                                                      // doomednum
        StateEnum::S_MEAT4,                                                      // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        68 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC55
        53,                                                                      // doomednum
        StateEnum::S_MEAT5,                                                      // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        52 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC56
        59,                                                 // doomednum
        StateEnum::S_MEAT2,                                 // spawnstate
        1000,                                               // spawnhealth
        StateEnum::S_NULL,                                  // seestate
        Sfx::sfx_None,                                      // seesound
        8,                                                  // reactiontime
        Sfx::sfx_None,                                      // attacksound
        StateEnum::S_NULL,                                  // painstate
        0,                                                  // painchance
        Sfx::sfx_None,                                      // painsound
        StateEnum::S_NULL,                                  // meleestate
        StateEnum::S_NULL,                                  // missilestate
        StateEnum::S_NULL,                                  // deathstate
        StateEnum::S_NULL,                                  // xdeathstate
        Sfx::sfx_None,                                      // deathsound
        0,                                                  // speed
        20 * fixed::FRACUNIT,                               // radius
        84 * fixed::FRACUNIT,                               // height
        100,                                                // mass
        0,                                                  // damage
        Sfx::sfx_None,                                      // activesound
        MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                   // raisestate
    },

    MobjInfo{
        // MT_MISC57
        60,                                                 // doomednum
        StateEnum::S_MEAT4,                                 // spawnstate
        1000,                                               // spawnhealth
        StateEnum::S_NULL,                                  // seestate
        Sfx::sfx_None,                                      // seesound
        8,                                                  // reactiontime
        Sfx::sfx_None,                                      // attacksound
        StateEnum::S_NULL,                                  // painstate
        0,                                                  // painchance
        Sfx::sfx_None,                                      // painsound
        StateEnum::S_NULL,                                  // meleestate
        StateEnum::S_NULL,                                  // missilestate
        StateEnum::S_NULL,                                  // deathstate
        StateEnum::S_NULL,                                  // xdeathstate
        Sfx::sfx_None,                                      // deathsound
        0,                                                  // speed
        20 * fixed::FRACUNIT,                               // radius
        68 * fixed::FRACUNIT,                               // height
        100,                                                // mass
        0,                                                  // damage
        Sfx::sfx_None,                                      // activesound
        MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                   // raisestate
    },

    MobjInfo{
        // MT_MISC58
        61,                                                 // doomednum
        StateEnum::S_MEAT3,                                 // spawnstate
        1000,                                               // spawnhealth
        StateEnum::S_NULL,                                  // seestate
        Sfx::sfx_None,                                      // seesound
        8,                                                  // reactiontime
        Sfx::sfx_None,                                      // attacksound
        StateEnum::S_NULL,                                  // painstate
        0,                                                  // painchance
        Sfx::sfx_None,                                      // painsound
        StateEnum::S_NULL,                                  // meleestate
        StateEnum::S_NULL,                                  // missilestate
        StateEnum::S_NULL,                                  // deathstate
        StateEnum::S_NULL,                                  // xdeathstate
        Sfx::sfx_None,                                      // deathsound
        0,                                                  // speed
        20 * fixed::FRACUNIT,                               // radius
        52 * fixed::FRACUNIT,                               // height
        100,                                                // mass
        0,                                                  // damage
        Sfx::sfx_None,                                      // activesound
        MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                   // raisestate
    },

    MobjInfo{
        // MT_MISC59
        62,                                                 // doomednum
        StateEnum::S_MEAT5,                                 // spawnstate
        1000,                                               // spawnhealth
        StateEnum::S_NULL,                                  // seestate
        Sfx::sfx_None,                                      // seesound
        8,                                                  // reactiontime
        Sfx::sfx_None,                                      // attacksound
        StateEnum::S_NULL,                                  // painstate
        0,                                                  // painchance
        Sfx::sfx_None,                                      // painsound
        StateEnum::S_NULL,                                  // meleestate
        StateEnum::S_NULL,                                  // missilestate
        StateEnum::S_NULL,                                  // deathstate
        StateEnum::S_NULL,                                  // xdeathstate
        Sfx::sfx_None,                                      // deathsound
        0,                                                  // speed
        20 * fixed::FRACUNIT,                               // radius
        52 * fixed::FRACUNIT,                               // height
        100,                                                // mass
        0,                                                  // damage
        Sfx::sfx_None,                                      // activesound
        MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                   // raisestate
    },

    MobjInfo{
        // MT_MISC60
        63,                                                 // doomednum
        StateEnum::S_BLOODYTWITCH,                          // spawnstate
        1000,                                               // spawnhealth
        StateEnum::S_NULL,                                  // seestate
        Sfx::sfx_None,                                      // seesound
        8,                                                  // reactiontime
        Sfx::sfx_None,                                      // attacksound
        StateEnum::S_NULL,                                  // painstate
        0,                                                  // painchance
        Sfx::sfx_None,                                      // painsound
        StateEnum::S_NULL,                                  // meleestate
        StateEnum::S_NULL,                                  // missilestate
        StateEnum::S_NULL,                                  // deathstate
        StateEnum::S_NULL,                                  // xdeathstate
        Sfx::sfx_None,                                      // deathsound
        0,                                                  // speed
        20 * fixed::FRACUNIT,                               // radius
        68 * fixed::FRACUNIT,                               // height
        100,                                                // mass
        0,                                                  // damage
        Sfx::sfx_None,                                      // activesound
        MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                   // raisestate
    },

    MobjInfo{
        // MT_MISC61
        22,                     // doomednum
        StateEnum::S_HEAD_DIE6, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC62
        15,                     // doomednum
        StateEnum::S_PLAY_DIE7, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC63
        18,                     // doomednum
        StateEnum::S_POSS_DIE5, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC64
        21,                     // doomednum
        StateEnum::S_SARG_DIE6, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC65
        23,                      // doomednum
        StateEnum::S_SKULL_DIE6, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NONE,       // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC66
        20,                     // doomednum
        StateEnum::S_TROO_DIE5, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC67
        19,                     // doomednum
        StateEnum::S_SPOS_DIE5, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        20 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_NONE,      // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC68
        10,                      // doomednum
        StateEnum::S_PLAY_XDIE9, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NONE,       // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC69
        12,                      // doomednum
        StateEnum::S_PLAY_XDIE9, // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NONE,       // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC70
        28,                        // doomednum
        StateEnum::S_HEADSONSTICK, // spawnstate
        1000,                      // spawnhealth
        StateEnum::S_NULL,         // seestate
        Sfx::sfx_None,             // seesound
        8,                         // reactiontime
        Sfx::sfx_None,             // attacksound
        StateEnum::S_NULL,         // painstate
        0,                         // painchance
        Sfx::sfx_None,             // painsound
        StateEnum::S_NULL,         // meleestate
        StateEnum::S_NULL,         // missilestate
        StateEnum::S_NULL,         // deathstate
        StateEnum::S_NULL,         // xdeathstate
        Sfx::sfx_None,             // deathsound
        0,                         // speed
        16 * fixed::FRACUNIT,      // radius
        16 * fixed::FRACUNIT,      // height
        100,                       // mass
        0,                         // damage
        Sfx::sfx_None,             // activesound
        MobjFlag::MF_SOLID,        // flags
        StateEnum::S_NULL          // raisestate
    },

    MobjInfo{
        // MT_MISC71
        24,                   // doomednum
        StateEnum::S_GIBS,    // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        20 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_NONE,    // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC72
        27,                        // doomednum
        StateEnum::S_HEADONASTICK, // spawnstate
        1000,                      // spawnhealth
        StateEnum::S_NULL,         // seestate
        Sfx::sfx_None,             // seesound
        8,                         // reactiontime
        Sfx::sfx_None,             // attacksound
        StateEnum::S_NULL,         // painstate
        0,                         // painchance
        Sfx::sfx_None,             // painsound
        StateEnum::S_NULL,         // meleestate
        StateEnum::S_NULL,         // missilestate
        StateEnum::S_NULL,         // deathstate
        StateEnum::S_NULL,         // xdeathstate
        Sfx::sfx_None,             // deathsound
        0,                         // speed
        16 * fixed::FRACUNIT,      // radius
        16 * fixed::FRACUNIT,      // height
        100,                       // mass
        0,                         // damage
        Sfx::sfx_None,             // activesound
        MobjFlag::MF_SOLID,        // flags
        StateEnum::S_NULL          // raisestate
    },

    MobjInfo{
        // MT_MISC73
        29,                       // doomednum
        StateEnum::S_HEADCANDLES, // spawnstate
        1000,                     // spawnhealth
        StateEnum::S_NULL,        // seestate
        Sfx::sfx_None,            // seesound
        8,                        // reactiontime
        Sfx::sfx_None,            // attacksound
        StateEnum::S_NULL,        // painstate
        0,                        // painchance
        Sfx::sfx_None,            // painsound
        StateEnum::S_NULL,        // meleestate
        StateEnum::S_NULL,        // missilestate
        StateEnum::S_NULL,        // deathstate
        StateEnum::S_NULL,        // xdeathstate
        Sfx::sfx_None,            // deathsound
        0,                        // speed
        16 * fixed::FRACUNIT,     // radius
        16 * fixed::FRACUNIT,     // height
        100,                      // mass
        0,                        // damage
        Sfx::sfx_None,            // activesound
        MobjFlag::MF_SOLID,       // flags
        StateEnum::S_NULL         // raisestate
    },

    MobjInfo{
        // MT_MISC74
        25,                     // doomednum
        StateEnum::S_DEADSTICK, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        16 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_SOLID,     // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC75
        26,                     // doomednum
        StateEnum::S_LIVESTICK, // spawnstate
        1000,                   // spawnhealth
        StateEnum::S_NULL,      // seestate
        Sfx::sfx_None,          // seesound
        8,                      // reactiontime
        Sfx::sfx_None,          // attacksound
        StateEnum::S_NULL,      // painstate
        0,                      // painchance
        Sfx::sfx_None,          // painsound
        StateEnum::S_NULL,      // meleestate
        StateEnum::S_NULL,      // missilestate
        StateEnum::S_NULL,      // deathstate
        StateEnum::S_NULL,      // xdeathstate
        Sfx::sfx_None,          // deathsound
        0,                      // speed
        16 * fixed::FRACUNIT,   // radius
        16 * fixed::FRACUNIT,   // height
        100,                    // mass
        0,                      // damage
        Sfx::sfx_None,          // activesound
        MobjFlag::MF_SOLID,     // flags
        StateEnum::S_NULL       // raisestate
    },

    MobjInfo{
        // MT_MISC76
        54,                   // doomednum
        StateEnum::S_BIGTREE, // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        32 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SOLID,   // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC77
        70,                   // doomednum
        StateEnum::S_BBAR1,   // spawnstate
        1000,                 // spawnhealth
        StateEnum::S_NULL,    // seestate
        Sfx::sfx_None,        // seesound
        8,                    // reactiontime
        Sfx::sfx_None,        // attacksound
        StateEnum::S_NULL,    // painstate
        0,                    // painchance
        Sfx::sfx_None,        // painsound
        StateEnum::S_NULL,    // meleestate
        StateEnum::S_NULL,    // missilestate
        StateEnum::S_NULL,    // deathstate
        StateEnum::S_NULL,    // xdeathstate
        Sfx::sfx_None,        // deathsound
        0,                    // speed
        16 * fixed::FRACUNIT, // radius
        16 * fixed::FRACUNIT, // height
        100,                  // mass
        0,                    // damage
        Sfx::sfx_None,        // activesound
        MobjFlag::MF_SOLID,   // flags
        StateEnum::S_NULL     // raisestate
    },

    MobjInfo{
        // MT_MISC78
        73,                                                                      // doomednum
        StateEnum::S_HANGNOGUTS,                                                 // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        88 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC79
        74,                                                                      // doomednum
        StateEnum::S_HANGBNOBRAIN,                                               // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        88 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC80
        75,                                                                      // doomednum
        StateEnum::S_HANGTLOOKDN,                                                // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        64 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC81
        76,                                                                      // doomednum
        StateEnum::S_HANGTSKULL,                                                 // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        64 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC82
        77,                                                                      // doomednum
        StateEnum::S_HANGTLOOKUP,                                                // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        64 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC83
        78,                                                                      // doomednum
        StateEnum::S_HANGTNOBRAIN,                                               // spawnstate
        1000,                                                                    // spawnhealth
        StateEnum::S_NULL,                                                       // seestate
        Sfx::sfx_None,                                                           // seesound
        8,                                                                       // reactiontime
        Sfx::sfx_None,                                                           // attacksound
        StateEnum::S_NULL,                                                       // painstate
        0,                                                                       // painchance
        Sfx::sfx_None,                                                           // painsound
        StateEnum::S_NULL,                                                       // meleestate
        StateEnum::S_NULL,                                                       // missilestate
        StateEnum::S_NULL,                                                       // deathstate
        StateEnum::S_NULL,                                                       // xdeathstate
        Sfx::sfx_None,                                                           // deathsound
        0,                                                                       // speed
        16 * fixed::FRACUNIT,                                                    // radius
        64 * fixed::FRACUNIT,                                                    // height
        100,                                                                     // mass
        0,                                                                       // damage
        Sfx::sfx_None,                                                           // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SPAWNCEILING | MobjFlag::MF_NOGRAVITY, // flags
        StateEnum::S_NULL                                                        // raisestate
    },

    MobjInfo{
        // MT_MISC84
        79,                      // doomednum
        StateEnum::S_COLONGIBS,  // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC85
        80,                      // doomednum
        StateEnum::S_SMALLPOOL,  // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_MISC86
        81,                      // doomednum
        StateEnum::S_BRAINSTEM,  // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        20 * fixed::FRACUNIT,    // radius
        16 * fixed::FRACUNIT,    // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    // For use with wind and current effects
    MobjInfo{
        // MT_PUSH                       // phares
        5001,                    // doomednum       //   |      //jff 5/11/98 deconflict
        StateEnum::S_TNT1,       // spawnstate      //   V      // with DOSDoom
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        8,                       // radius
        8,                       // height
        10,                      // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    // For use with wind and current effects
    MobjInfo{
        // MT_PULL
        5002,                    // doomednum                   //jff 5/11/98 deconflict
        StateEnum::S_TNT1,       // spawnstate                  // with DOSDoom
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        8,                       // radius
        8,                       // height
        10,                      // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    // Marine's best friend :)      // killough 7/19/98
    MobjInfo{
        // MT_DOGS
        888,                                                                  // doomednum
        StateEnum::S_DOGS_STND,                                               // spawnstate
        500,                                                                  // spawnhealth
        StateEnum::S_DOGS_RUN1,                                               // seestate
        Sfx::sfx_dgsit,                                                       // seesound
        8,                                                                    // reactiontime
        Sfx::sfx_dgatk,                                                       // attacksound
        StateEnum::S_DOGS_PAIN,                                               // painstate
        180,                                                                  // painchance
        Sfx::sfx_dgpain,                                                      // painsound
        StateEnum::S_DOGS_ATK1,                                               // meleestate
        StateEnum::S_NULL,                                                    // missilestate
        StateEnum::S_DOGS_DIE1,                                               // deathstate
        StateEnum::S_NULL,                                                    // xdeathstate
        Sfx::sfx_dgdth,                                                       // deathsound
        10,                                                                   // speed
        12 * fixed::FRACUNIT,                                                 // radius
        28 * fixed::FRACUNIT,                                                 // height
        100,                                                                  // mass
        0,                                                                    // damage
        Sfx::sfx_dgact,                                                       // activesound
        MobjFlag::MF_SOLID | MobjFlag::MF_SHOOTABLE | MobjFlag::MF_COUNTKILL, // flags
        StateEnum::S_DOGS_RAISE1                                              // raisestate
    },

    // killough 7/11/98: this is the first of two plasma fireballs in the beta
    MobjInfo{
        // MT_PLASMA1
        -1,                    // doomednum
        StateEnum::S_PLS1BALL, // spawnstate
        1000,                  // spawnhealth
        StateEnum::S_NULL,     // seestate
        Sfx::sfx_plasma,       // seesound
        8,                     // reactiontime
        Sfx::sfx_None,         // attacksound
        StateEnum::S_NULL,     // painstate
        0,                     // painchance
        Sfx::sfx_None,         // painsound
        StateEnum::S_NULL,     // meleestate
        StateEnum::S_NULL,     // missilestate
        StateEnum::S_PLS1EXP,  // deathstate
        StateEnum::S_NULL,     // xdeathstate
        Sfx::sfx_firxpl,       // deathsound
        25 * fixed::FRACUNIT,  // speed
        13 * fixed::FRACUNIT,  // radius
        8 * fixed::FRACUNIT,   // height
        100,                   // mass
        4,                     // damage
        Sfx::sfx_None,         // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_BOUNCES, // flags
        StateEnum::S_NULL         // raisestate
    },

    // killough 7/11/98: this is the second of two plasma fireballs in the beta
    MobjInfo{
        // MT_PLASMA2
        -1,                      // doomednum
        StateEnum::S_PLS2BALL,   // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_plasma,         // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_PLS2BALLX1, // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_firxpl,         // deathsound
        25 * fixed::FRACUNIT,    // speed
        6 * fixed::FRACUNIT,     // radius
        8 * fixed::FRACUNIT,     // height
        100,                     // mass
        4,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_MISSILE | MobjFlag::MF_DROPOFF | MobjFlag::MF_NOGRAVITY |
            MobjFlag::MF_BOUNCES, // flags
        StateEnum::S_NULL         // raisestate
    },

    // killough 7/11/98: this is the evil sceptre in the beta version
    MobjInfo{
        // MT_SCEPTRE
        2016,                                          // doomednum
        StateEnum::S_BON3,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        10 * fixed::FRACUNIT,                          // radius
        16 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    // killough 7/11/98: this is the unholy bible in the beta version
    MobjInfo{
        // MT_BIBLE
        2017,                                          // doomednum
        StateEnum::S_BON4,                             // spawnstate
        1000,                                          // spawnhealth
        StateEnum::S_NULL,                             // seestate
        Sfx::sfx_None,                                 // seesound
        8,                                             // reactiontime
        Sfx::sfx_None,                                 // attacksound
        StateEnum::S_NULL,                             // painstate
        0,                                             // painchance
        Sfx::sfx_None,                                 // painsound
        StateEnum::S_NULL,                             // meleestate
        StateEnum::S_NULL,                             // missilestate
        StateEnum::S_NULL,                             // deathstate
        StateEnum::S_NULL,                             // xdeathstate
        Sfx::sfx_None,                                 // deathsound
        0,                                             // speed
        20 * fixed::FRACUNIT,                          // radius
        10 * fixed::FRACUNIT,                          // height
        100,                                           // mass
        0,                                             // damage
        Sfx::sfx_None,                                 // activesound
        MobjFlag::MF_SPECIAL | MobjFlag::MF_COUNTITEM, // flags
        StateEnum::S_NULL                              // raisestate
    },

    // MUSINFO lump
    MobjInfo{
        // MT_MUSICSOURCE
        14164,                   // doomednum
        StateEnum::S_TNT1,       // spawnstate
        1000,                    // spawnhealth
        StateEnum::S_NULL,       // seestate
        Sfx::sfx_None,           // seesound
        8,                       // reactiontime
        Sfx::sfx_None,           // attacksound
        StateEnum::S_NULL,       // painstate
        0,                       // painchance
        Sfx::sfx_None,           // painsound
        StateEnum::S_NULL,       // meleestate
        StateEnum::S_NULL,       // missilestate
        StateEnum::S_NULL,       // deathstate
        StateEnum::S_NULL,       // xdeathstate
        Sfx::sfx_None,           // deathsound
        0,                       // speed
        16,                      // radius
        16,                      // height
        100,                     // mass
        0,                       // damage
        Sfx::sfx_None,           // activesound
        MobjFlag::MF_NOBLOCKMAP, // flags
        StateEnum::S_NULL        // raisestate
    },

    MobjInfo{
        // MT_GIBDTH
        -1,                                             // doomednum
        StateEnum::S_TNT1,                              // spawnstate
        1000,                                           // spawnhealth
        StateEnum::S_NULL,                              // seestate
        Sfx::sfx_None,                                  // seesound
        8,                                              // reactiontime
        Sfx::sfx_None,                                  // attacksound
        StateEnum::S_NULL,                              // painstate
        0,                                              // painchance
        Sfx::sfx_None,                                  // painsound
        StateEnum::S_NULL,                              // meleestate
        StateEnum::S_NULL,                              // missilestate
        StateEnum::S_NULL,                              // deathstate
        StateEnum::S_NULL,                              // xdeathstate
        Sfx::sfx_None,                                  // deathsound
        0,                                              // speed
        4 * fixed::FRACUNIT,                            // radius
        4 * fixed::FRACUNIT,                            // height
        100,                                            // mass
        0,                                              // damage
        Sfx::sfx_None,                                  // activesound
        MobjFlag::MF_NOBLOCKMAP | MobjFlag::MF_DROPOFF, // flags
        StateEnum::S_NULL                               // raisestate
    },

};
constinit map::map<info::StateEnum, info::State, to_underlying(info::StateEnum::NUMSTATES)> info::states{{{
    {StateEnum::S_NULL, {SpriteEnum::SPR_TROO, 0, -1, action::doNothing, StateEnum::S_NULL, 0, 0}},
    {StateEnum::S_LIGHTDONE, {SpriteEnum::SPR_SHTG, 4, 0, action::light0, StateEnum::S_NULL, 0, 0}},
    {StateEnum::S_PUNCH, {SpriteEnum::SPR_PUNG, 0, 1, action::weaponReady, StateEnum::S_PUNCH, 0, 0}},
       {StateEnum::S_PUNCHDOWN,
        {SpriteEnum::SPR_PUNG, 0, 1, action::lower, StateEnum::S_PUNCHDOWN,
        0, 0}},
       {StateEnum::S_PUNCHUP,
        {SpriteEnum::SPR_PUNG, 0, 1, action::raise, StateEnum::S_PUNCHUP, 0,
        0}},
       {StateEnum::S_PUNCH1,
        {SpriteEnum::SPR_PUNG, 1, 4, nullptr, StateEnum::S_PUNCH2, 0, 0}},
       {StateEnum::S_PUNCH2,
        {SpriteEnum::SPR_PUNG, 2, 4, action::punch, StateEnum::S_PUNCH3, 0,
        0}},
       {StateEnum::S_PUNCH3,
        {SpriteEnum::SPR_PUNG, 3, 5, nullptr, StateEnum::S_PUNCH4, 0, 0}},
       {StateEnum::S_PUNCH4,
        {SpriteEnum::SPR_PUNG, 2, 4, nullptr, StateEnum::S_PUNCH5, 0, 0}},
       {StateEnum::S_PUNCH5,
        {SpriteEnum::SPR_PUNG, 1, 5, action::reFire, StateEnum::S_PUNCH, 0,
        0}},
       {StateEnum::S_PISTOL,
        {SpriteEnum::SPR_PISG, 0, 1, action::weaponReady,
        StateEnum::S_PISTOL, 0,
         0}},
       {StateEnum::S_PISTOLDOWN,
        {SpriteEnum::SPR_PISG, 0, 1, action::lower, StateEnum::S_PISTOLDOWN,
        0,
         0}},
       {StateEnum::S_PISTOLUP,
        {SpriteEnum::SPR_PISG, 0, 1, action::raise, StateEnum::S_PISTOLUP, 0,
        0}},
       {StateEnum::S_PISTOL1,
        {SpriteEnum::SPR_PISG, 0, 4, nullptr, StateEnum::S_PISTOL2, 0, 0}},
       {StateEnum::S_PISTOL2,
        {SpriteEnum::SPR_PISG, 1, 6, action::firePistol,
        StateEnum::S_PISTOL3, 0,
         0}},
       {StateEnum::S_PISTOL3,
        {SpriteEnum::SPR_PISG, 2, 4, nullptr, StateEnum::S_PISTOL4, 0, 0}},
       {StateEnum::S_PISTOL4,
        {SpriteEnum::SPR_PISG, 1, 5, action::reFire, StateEnum::S_PISTOL, 0,
        0}},
       {StateEnum::S_PISTOLFLASH,
        {SpriteEnum::SPR_PISF, 32768, 7, action::light1,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_SGUN,
        {SpriteEnum::SPR_SHTG, 0, 1, action::weaponReady, StateEnum::S_SGUN,
        0,
         0}},
       {StateEnum::S_SGUNDOWN,
        {SpriteEnum::SPR_SHTG, 0, 1, action::lower, StateEnum::S_SGUNDOWN, 0,
        0}},
       {StateEnum::S_SGUNUP,
        {SpriteEnum::SPR_SHTG, 0, 1, action::raise, StateEnum::S_SGUNUP, 0,
        0}},
       {StateEnum::S_SGUN1,
        {SpriteEnum::SPR_SHTG, 0, 3, nullptr, StateEnum::S_SGUN2, 0, 0}},
       {StateEnum::S_SGUN2,
        {SpriteEnum::SPR_SHTG, 0, 7, action::fireShotgun, StateEnum::S_SGUN3,
        0,
         0}},
       {StateEnum::S_SGUN3,
        {SpriteEnum::SPR_SHTG, 1, 5, nullptr, StateEnum::S_SGUN4, 0, 0}},
       {StateEnum::S_SGUN4,
        {SpriteEnum::SPR_SHTG, 2, 5, nullptr, StateEnum::S_SGUN5, 0, 0}},
       {StateEnum::S_SGUN5,
        {SpriteEnum::SPR_SHTG, 3, 4, nullptr, StateEnum::S_SGUN6, 0, 0}},
       {StateEnum::S_SGUN6,
        {SpriteEnum::SPR_SHTG, 2, 5, nullptr, StateEnum::S_SGUN7, 0, 0}},
       {StateEnum::S_SGUN7,
        {SpriteEnum::SPR_SHTG, 1, 5, nullptr, StateEnum::S_SGUN8, 0, 0}},
       {StateEnum::S_SGUN8,
        {SpriteEnum::SPR_SHTG, 0, 3, nullptr, StateEnum::S_SGUN9, 0, 0}},
       {StateEnum::S_SGUN9,
        {SpriteEnum::SPR_SHTG, 0, 7, action::reFire, StateEnum::S_SGUN, 0,
        0}},
       {StateEnum::S_SGUNFLASH1,
        {SpriteEnum::SPR_SHTF, 32768, 4, action::light1,
        StateEnum::S_SGUNFLASH2,
         0, 0}},
       {StateEnum::S_SGUNFLASH2,
        {SpriteEnum::SPR_SHTF, 32769, 3, action::light2,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_DSGUN,
        {SpriteEnum::SPR_SHT2, 0, 1, action::weaponReady, StateEnum::S_DSGUN,
        0,
         0}},
       {StateEnum::S_DSGUNDOWN,
        {SpriteEnum::SPR_SHT2, 0, 1, action::lower, StateEnum::S_DSGUNDOWN,
        0, 0}},
       {StateEnum::S_DSGUNUP,
        {SpriteEnum::SPR_SHT2, 0, 1, action::raise, StateEnum::S_DSGUNUP, 0,
        0}},
       {StateEnum::S_DSGUN1,
        {SpriteEnum::SPR_SHT2, 0, 3, nullptr, StateEnum::S_DSGUN2, 0, 0}},
       {StateEnum::S_DSGUN2,
        {SpriteEnum::SPR_SHT2, 0, 7, action::fireShotgun2,
        StateEnum::S_DSGUN3, 0,
         0}},
       {StateEnum::S_DSGUN3,
        {SpriteEnum::SPR_SHT2, 1, 7, nullptr, StateEnum::S_DSGUN4, 0, 0}},
       {StateEnum::S_DSGUN4,
        {SpriteEnum::SPR_SHT2, 2, 7, action::checkReload,
        StateEnum::S_DSGUN5, 0,
         0}},
       {StateEnum::S_DSGUN5,
        {SpriteEnum::SPR_SHT2, 3, 7, action::openShotgun2,
        StateEnum::S_DSGUN6, 0,
         0}},
       {StateEnum::S_DSGUN6,
        {SpriteEnum::SPR_SHT2, 4, 7, nullptr, StateEnum::S_DSGUN7, 0, 0}},
       {StateEnum::S_DSGUN7,
        {SpriteEnum::SPR_SHT2, 5, 7, action::loadShotgun2,
        StateEnum::S_DSGUN8, 0,
         0}},
       {StateEnum::S_DSGUN8,
        {SpriteEnum::SPR_SHT2, 6, 6, nullptr, StateEnum::S_DSGUN9, 0, 0}},
       {StateEnum::S_DSGUN9,
        {SpriteEnum::SPR_SHT2, 7, 6, action::closeShotgun2,
        StateEnum::S_DSGUN10,
         0, 0}},
       {StateEnum::S_DSGUN10,
        {SpriteEnum::SPR_SHT2, 0, 5, action::reFire, StateEnum::S_DSGUN, 0,
        0}},
       {StateEnum::S_DSNR1,
        {SpriteEnum::SPR_SHT2, 1, 7, nullptr, StateEnum::S_DSNR2, 0, 0}},
       {StateEnum::S_DSNR2,
        {SpriteEnum::SPR_SHT2, 0, 3, nullptr, StateEnum::S_DSGUNDOWN, 0, 0}},
       {StateEnum::S_DSGUNFLASH1,
        {SpriteEnum::SPR_SHT2, 32776, 5, action::light1,
        StateEnum::S_DSGUNFLASH2,
         0, 0}},
       {StateEnum::S_DSGUNFLASH2,
        {SpriteEnum::SPR_SHT2, 32777, 4, action::light2,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_CHAIN,
        {SpriteEnum::SPR_CHGG, 0, 1, action::weaponReady, StateEnum::S_CHAIN,
        0,
         0}},
       {StateEnum::S_CHAINDOWN,
        {SpriteEnum::SPR_CHGG, 0, 1, action::lower, StateEnum::S_CHAINDOWN,
        0, 0}},
       {StateEnum::S_CHAINUP,
        {SpriteEnum::SPR_CHGG, 0, 1, action::raise, StateEnum::S_CHAINUP, 0,
        0}},
       {StateEnum::S_CHAIN1,
        {SpriteEnum::SPR_CHGG, 0, 4, action::fireCGun, StateEnum::S_CHAIN2,
        0, 0}},
       {StateEnum::S_CHAIN2,
        {SpriteEnum::SPR_CHGG, 1, 4, action::fireCGun, StateEnum::S_CHAIN3,
        0, 0}},
       {StateEnum::S_CHAIN3,
        {SpriteEnum::SPR_CHGG, 1, 0, action::reFire, StateEnum::S_CHAIN, 0,
        0}},
       {StateEnum::S_CHAINFLASH1,
        {SpriteEnum::SPR_CHGF, 32768, 5, action::light1,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_CHAINFLASH2,
        {SpriteEnum::SPR_CHGF, 32769, 5, action::light2,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_MISSILE,
        {SpriteEnum::SPR_MISG, 0, 1, action::weaponReady,
        StateEnum::S_MISSILE, 0,
         0}},
       {StateEnum::S_MISSILEDOWN,
        {SpriteEnum::SPR_MISG, 0, 1, action::lower, StateEnum::S_MISSILEDOWN,
        0,
         0}},
       {StateEnum::S_MISSILEUP,
        {SpriteEnum::SPR_MISG, 0, 1, action::raise, StateEnum::S_MISSILEUP,
        0, 0}},
       {StateEnum::S_MISSILE1,
        {SpriteEnum::SPR_MISG, 1, 8, action::gunFlash, StateEnum::S_MISSILE2,
        0,
         0}},
       {StateEnum::S_MISSILE2,
        {SpriteEnum::SPR_MISG, 1, 12, action::fireMissile,
        StateEnum::S_MISSILE3,
         0, 0}},
       {StateEnum::S_MISSILE3,
        {SpriteEnum::SPR_MISG, 1, 0, action::reFire, StateEnum::S_MISSILE, 0,
        0}},
       {StateEnum::S_MISSILEFLASH1,
        {SpriteEnum::SPR_MISF, 32768, 3, action::light1,
         StateEnum::S_MISSILEFLASH2, 0, 0}},
       {StateEnum::S_MISSILEFLASH2,
        {SpriteEnum::SPR_MISF, 32769, 4, nullptr, StateEnum::S_MISSILEFLASH3,
        0,
         0}},
       {StateEnum::S_MISSILEFLASH3,
        {SpriteEnum::SPR_MISF, 32770, 4, action::light2,
         StateEnum::S_MISSILEFLASH4, 0, 0}},
       {StateEnum::S_MISSILEFLASH4,
        {SpriteEnum::SPR_MISF, 32771, 4, action::light2,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_SAW,
        {SpriteEnum::SPR_SAWG, 2, 4, action::weaponReady, StateEnum::S_SAWB,
        0,
         0}},
       {StateEnum::S_SAWB,
        {SpriteEnum::SPR_SAWG, 3, 4, action::weaponReady, StateEnum::S_SAW,
        0, 0}},
       {StateEnum::S_SAWDOWN,
        {SpriteEnum::SPR_SAWG, 2, 1, action::lower, StateEnum::S_SAWDOWN, 0,
        0}},
       {StateEnum::S_SAWUP,
        {SpriteEnum::SPR_SAWG, 2, 1, action::raise, StateEnum::S_SAWUP, 0,
        0}},
       {StateEnum::S_SAW1,
        {SpriteEnum::SPR_SAWG, 0, 4, action::saw, StateEnum::S_SAW2, 0, 0}},
       {StateEnum::S_SAW2,
        {SpriteEnum::SPR_SAWG, 1, 4, action::saw, StateEnum::S_SAW3, 0, 0}},
       {StateEnum::S_SAW3,
        {SpriteEnum::SPR_SAWG, 1, 0, action::reFire, StateEnum::S_SAW, 0,
        0}},
       {StateEnum::S_PLASMA,
        {SpriteEnum::SPR_PLSG, 0, 1, action::weaponReady,
        StateEnum::S_PLASMA, 0,
         0}},
       {StateEnum::S_PLASMADOWN,
        {SpriteEnum::SPR_PLSG, 0, 1, action::lower, StateEnum::S_PLASMADOWN,
        0,
         0}},
       {StateEnum::S_PLASMAUP,
        {SpriteEnum::SPR_PLSG, 0, 1, action::raise, StateEnum::S_PLASMAUP, 0,
        0}},
       {StateEnum::S_PLASMA1,
        {SpriteEnum::SPR_PLSG, 0, 3, action::firePlasma,
        StateEnum::S_PLASMA2, 0,
         0}},
       {StateEnum::S_PLASMA2,
        {SpriteEnum::SPR_PLSG, 1, 20, action::reFire, StateEnum::S_PLASMA, 0,
        0}},
       {StateEnum::S_PLASMAFLASH1,
        {SpriteEnum::SPR_PLSF, 32768, 4, action::light1,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_PLASMAFLASH2,
        {SpriteEnum::SPR_PLSF, 32769, 4, action::light1,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_BFG,
        {SpriteEnum::SPR_BFGG, 0, 1, action::weaponReady, StateEnum::S_BFG,
        0, 0}},
       {StateEnum::S_BFGDOWN,
        {SpriteEnum::SPR_BFGG, 0, 1, action::lower, StateEnum::S_BFGDOWN, 0,
        0}},
       {StateEnum::S_BFGUP,
        {SpriteEnum::SPR_BFGG, 0, 1, action::raise, StateEnum::S_BFGUP, 0,
        0}},
       {StateEnum::S_BFG1,
        {SpriteEnum::SPR_BFGG, 0, 20, action::bfgSound, StateEnum::S_BFG2, 0,
        0}},
       {StateEnum::S_BFG2,
        {SpriteEnum::SPR_BFGG, 1, 10, action::gunFlash, StateEnum::S_BFG3, 0,
        0}},
       {StateEnum::S_BFG3,
        {SpriteEnum::SPR_BFGG, 1, 10, action::fireBfg, StateEnum::S_BFG4, 0,
        0}},
       {StateEnum::S_BFG4,
        {SpriteEnum::SPR_BFGG, 1, 20, action::reFire, StateEnum::S_BFG, 0,
        0}},
       {StateEnum::S_BFGFLASH1,
        {SpriteEnum::SPR_BFGF, 32768, 11, action::light1,
        StateEnum::S_BFGFLASH2,
         0, 0}},
       {StateEnum::S_BFGFLASH2,
        {SpriteEnum::SPR_BFGF, 32769, 6, action::light2,
        StateEnum::S_LIGHTDONE, 0,
         0}},
       {StateEnum::S_BLOOD1,
        {SpriteEnum::SPR_BLUD, 2, 8, nullptr, StateEnum::S_BLOOD2, 0, 0}},
       {StateEnum::S_BLOOD2,
        {SpriteEnum::SPR_BLUD, 1, 8, nullptr, StateEnum::S_BLOOD3, 0, 0}},
       {StateEnum::S_BLOOD3,
        {SpriteEnum::SPR_BLUD, 0, 8, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PUFF1,
        {SpriteEnum::SPR_PUFF, 32768, 4, nullptr, StateEnum::S_PUFF2, 0, 0}},
       {StateEnum::S_PUFF2,
        {SpriteEnum::SPR_PUFF, 1, 4, nullptr, StateEnum::S_PUFF3, 0, 0}},
       {StateEnum::S_PUFF3,
        {SpriteEnum::SPR_PUFF, 2, 4, nullptr, StateEnum::S_PUFF4, 0, 0}},
       {StateEnum::S_PUFF4,
        {SpriteEnum::SPR_PUFF, 3, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TBALL1,
        {SpriteEnum::SPR_BAL1, 32768, 4, nullptr, StateEnum::S_TBALL2, 0,
        0}},
       {StateEnum::S_TBALL2,
        {SpriteEnum::SPR_BAL1, 32769, 4, nullptr, StateEnum::S_TBALL1, 0,
        0}},
       {StateEnum::S_TBALLX1,
        {SpriteEnum::SPR_BAL1, 32770, 6, nullptr, StateEnum::S_TBALLX2, 0,
        0}},
       {StateEnum::S_TBALLX2,
        {SpriteEnum::SPR_BAL1, 32771, 6, nullptr, StateEnum::S_TBALLX3, 0,
        0}},
       {StateEnum::S_TBALLX3,
        {SpriteEnum::SPR_BAL1, 32772, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_RBALL1,
        {SpriteEnum::SPR_BAL2, 32768, 4, nullptr, StateEnum::S_RBALL2, 0,
        0}},
       {StateEnum::S_RBALL2,
        {SpriteEnum::SPR_BAL2, 32769, 4, nullptr, StateEnum::S_RBALL1, 0,
        0}},
       {StateEnum::S_RBALLX1,
        {SpriteEnum::SPR_BAL2, 32770, 6, nullptr, StateEnum::S_RBALLX2, 0,
        0}},
       {StateEnum::S_RBALLX2,
        {SpriteEnum::SPR_BAL2, 32771, 6, nullptr, StateEnum::S_RBALLX3, 0,
        0}},
       {StateEnum::S_RBALLX3,
        {SpriteEnum::SPR_BAL2, 32772, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PLASBALL,
        {SpriteEnum::SPR_PLSS, 32768, 6, nullptr, StateEnum::S_PLASBALL2, 0,
        0}},
       {StateEnum::S_PLASBALL2,
        {SpriteEnum::SPR_PLSS, 32769, 6, nullptr, StateEnum::S_PLASBALL, 0,
        0}},
       {StateEnum::S_PLASEXP,
        {SpriteEnum::SPR_PLSE, 32768, 4, nullptr, StateEnum::S_PLASEXP2, 0,
        0}},
       {StateEnum::S_PLASEXP2,
        {SpriteEnum::SPR_PLSE, 32769, 4, nullptr, StateEnum::S_PLASEXP3, 0,
        0}},
       {StateEnum::S_PLASEXP3,
        {SpriteEnum::SPR_PLSE, 32770, 4, nullptr, StateEnum::S_PLASEXP4, 0,
        0}},
       {StateEnum::S_PLASEXP4,
        {SpriteEnum::SPR_PLSE, 32771, 4, nullptr, StateEnum::S_PLASEXP5, 0,
        0}},
       {StateEnum::S_PLASEXP5,
        {SpriteEnum::SPR_PLSE, 32772, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_ROCKET,
        {SpriteEnum::SPR_MISL, 32768, 1, nullptr, StateEnum::S_ROCKET, 0,
        0}},
       {StateEnum::S_BFGSHOT,
        {SpriteEnum::SPR_BFS1, 32768, 4, nullptr, StateEnum::S_BFGSHOT2, 0,
        0}},
       {StateEnum::S_BFGSHOT2,
        {SpriteEnum::SPR_BFS1, 32769, 4, nullptr, StateEnum::S_BFGSHOT, 0,
        0}},
       {StateEnum::S_BFGLAND,
        {SpriteEnum::SPR_BFE1, 32768, 8, nullptr, StateEnum::S_BFGLAND2, 0,
        0}},
       {StateEnum::S_BFGLAND2,
        {SpriteEnum::SPR_BFE1, 32769, 8, nullptr, StateEnum::S_BFGLAND3, 0,
        0}},
       {StateEnum::S_BFGLAND3,
        {SpriteEnum::SPR_BFE1, 32770, 8, action::bfgSpray,
        StateEnum::S_BFGLAND4,
         0, 0}},
       {StateEnum::S_BFGLAND4,
        {SpriteEnum::SPR_BFE1, 32771, 8, nullptr, StateEnum::S_BFGLAND5, 0,
        0}},
       {StateEnum::S_BFGLAND5,
        {SpriteEnum::SPR_BFE1, 32772, 8, nullptr, StateEnum::S_BFGLAND6, 0,
        0}},
       {StateEnum::S_BFGLAND6,
        {SpriteEnum::SPR_BFE1, 32773, 8, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BFGEXP,
        {SpriteEnum::SPR_BFE2, 32768, 8, nullptr, StateEnum::S_BFGEXP2, 0,
        0}},
       {StateEnum::S_BFGEXP2,
        {SpriteEnum::SPR_BFE2, 32769, 8, nullptr, StateEnum::S_BFGEXP3, 0,
        0}},
       {StateEnum::S_BFGEXP3,
        {SpriteEnum::SPR_BFE2, 32770, 8, nullptr, StateEnum::S_BFGEXP4, 0,
        0}},
       {StateEnum::S_BFGEXP4,
        {SpriteEnum::SPR_BFE2, 32771, 8, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_EXPLODE1,
        {SpriteEnum::SPR_MISL, 32769, 8, action::explode,
        StateEnum::S_EXPLODE2, 0,
         0}},
       {StateEnum::S_EXPLODE2,
        {SpriteEnum::SPR_MISL, 32770, 6, nullptr, StateEnum::S_EXPLODE3, 0,
        0}},
       {StateEnum::S_EXPLODE3,
        {SpriteEnum::SPR_MISL, 32771, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TFOG,
        {SpriteEnum::SPR_TFOG, 32768, 6, nullptr, StateEnum::S_TFOG01, 0,
        0}},
       {StateEnum::S_TFOG01,
        {SpriteEnum::SPR_TFOG, 32769, 6, nullptr, StateEnum::S_TFOG02, 0,
        0}},
       {StateEnum::S_TFOG02,
        {SpriteEnum::SPR_TFOG, 32768, 6, nullptr, StateEnum::S_TFOG2, 0, 0}},
       {StateEnum::S_TFOG2,
        {SpriteEnum::SPR_TFOG, 32769, 6, nullptr, StateEnum::S_TFOG3, 0, 0}},
       {StateEnum::S_TFOG3,
        {SpriteEnum::SPR_TFOG, 32770, 6, nullptr, StateEnum::S_TFOG4, 0, 0}},
       {StateEnum::S_TFOG4,
        {SpriteEnum::SPR_TFOG, 32771, 6, nullptr, StateEnum::S_TFOG5, 0, 0}},
       {StateEnum::S_TFOG5,
        {SpriteEnum::SPR_TFOG, 32772, 6, nullptr, StateEnum::S_TFOG6, 0, 0}},
       {StateEnum::S_TFOG6,
        {SpriteEnum::SPR_TFOG, 32773, 6, nullptr, StateEnum::S_TFOG7, 0, 0}},
       {StateEnum::S_TFOG7,
        {SpriteEnum::SPR_TFOG, 32774, 6, nullptr, StateEnum::S_TFOG8, 0, 0}},
       {StateEnum::S_TFOG8,
        {SpriteEnum::SPR_TFOG, 32775, 6, nullptr, StateEnum::S_TFOG9, 0, 0}},
       {StateEnum::S_TFOG9,
        {SpriteEnum::SPR_TFOG, 32776, 6, nullptr, StateEnum::S_TFOG10, 0,
        0}},
       {StateEnum::S_TFOG10,
        {SpriteEnum::SPR_TFOG, 32777, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_IFOG,
        {SpriteEnum::SPR_IFOG, 32768, 6, nullptr, StateEnum::S_IFOG01, 0,
        0}},
       {StateEnum::S_IFOG01,
        {SpriteEnum::SPR_IFOG, 32769, 6, nullptr, StateEnum::S_IFOG02, 0,
        0}},
       {StateEnum::S_IFOG02,
        {SpriteEnum::SPR_IFOG, 32768, 6, nullptr, StateEnum::S_IFOG2, 0, 0}},
       {StateEnum::S_IFOG2,
        {SpriteEnum::SPR_IFOG, 32769, 6, nullptr, StateEnum::S_IFOG3, 0, 0}},
       {StateEnum::S_IFOG3,
        {SpriteEnum::SPR_IFOG, 32770, 6, nullptr, StateEnum::S_IFOG4, 0, 0}},
       {StateEnum::S_IFOG4,
        {SpriteEnum::SPR_IFOG, 32771, 6, nullptr, StateEnum::S_IFOG5, 0, 0}},
       {StateEnum::S_IFOG5,
        {SpriteEnum::SPR_IFOG, 32772, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PLAY,
        {SpriteEnum::SPR_PLAY, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PLAY_RUN1,
        {SpriteEnum::SPR_PLAY, 0, 4, nullptr, StateEnum::S_PLAY_RUN2, 0, 0}},
       {StateEnum::S_PLAY_RUN2,
        {SpriteEnum::SPR_PLAY, 1, 4, nullptr, StateEnum::S_PLAY_RUN3, 0, 0}},
       {StateEnum::S_PLAY_RUN3,
        {SpriteEnum::SPR_PLAY, 2, 4, nullptr, StateEnum::S_PLAY_RUN4, 0, 0}},
       {StateEnum::S_PLAY_RUN4,
        {SpriteEnum::SPR_PLAY, 3, 4, nullptr, StateEnum::S_PLAY_RUN1, 0, 0}},
       {StateEnum::S_PLAY_ATK1,
        {SpriteEnum::SPR_PLAY, 4, 12, nullptr, StateEnum::S_PLAY, 0, 0}},
       {StateEnum::S_PLAY_ATK2,
        {SpriteEnum::SPR_PLAY, 32773, 6, nullptr, StateEnum::S_PLAY_ATK1, 0,
        0}},
       {StateEnum::S_PLAY_PAIN,
        {SpriteEnum::SPR_PLAY, 6, 4, nullptr, StateEnum::S_PLAY_PAIN2, 0,
        0}},
       {StateEnum::S_PLAY_PAIN2,
        {SpriteEnum::SPR_PLAY, 6, 4, action::pain, StateEnum::S_PLAY, 0, 0}},
       {StateEnum::S_PLAY_DIE1,
        {SpriteEnum::SPR_PLAY, 7, 10, nullptr, StateEnum::S_PLAY_DIE2, 0,
        0}},
       {StateEnum::S_PLAY_DIE2,
        {SpriteEnum::SPR_PLAY, 8, 10, action::playerScream,
        StateEnum::S_PLAY_DIE3,
         0, 0}},
       {StateEnum::S_PLAY_DIE3,
        {SpriteEnum::SPR_PLAY, 9, 10, action::fall, StateEnum::S_PLAY_DIE4,
        0, 0}},
       {StateEnum::S_PLAY_DIE4,
        {SpriteEnum::SPR_PLAY, 10, 10, nullptr, StateEnum::S_PLAY_DIE5, 0,
        0}},
       {StateEnum::S_PLAY_DIE5,
        {SpriteEnum::SPR_PLAY, 11, 10, nullptr, StateEnum::S_PLAY_DIE6, 0,
        0}},
       {StateEnum::S_PLAY_DIE6,
        {SpriteEnum::SPR_PLAY, 12, 10, nullptr, StateEnum::S_PLAY_DIE7, 0,
        0}},
       {StateEnum::S_PLAY_DIE7,
        {SpriteEnum::SPR_PLAY, 13, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PLAY_XDIE1,
        {SpriteEnum::SPR_PLAY, 14, 5, nullptr, StateEnum::S_PLAY_XDIE2, 0,
        0}},
       {StateEnum::S_PLAY_XDIE2,
        {SpriteEnum::SPR_PLAY, 15, 5, action::xScream,
        StateEnum::S_PLAY_XDIE3, 0,
         0}},
       {StateEnum::S_PLAY_XDIE3,
        {SpriteEnum::SPR_PLAY, 16, 5, action::fall, StateEnum::S_PLAY_XDIE4,
        0,
         0}},
       {StateEnum::S_PLAY_XDIE4,
        {SpriteEnum::SPR_PLAY, 17, 5, nullptr, StateEnum::S_PLAY_XDIE5, 0,
        0}},
       {StateEnum::S_PLAY_XDIE5,
        {SpriteEnum::SPR_PLAY, 18, 5, nullptr, StateEnum::S_PLAY_XDIE6, 0,
        0}},
       {StateEnum::S_PLAY_XDIE6,
        {SpriteEnum::SPR_PLAY, 19, 5, nullptr, StateEnum::S_PLAY_XDIE7, 0,
        0}},
       {StateEnum::S_PLAY_XDIE7,
        {SpriteEnum::SPR_PLAY, 20, 5, nullptr, StateEnum::S_PLAY_XDIE8, 0,
        0}},
       {StateEnum::S_PLAY_XDIE8,
        {SpriteEnum::SPR_PLAY, 21, 5, nullptr, StateEnum::S_PLAY_XDIE9, 0,
        0}},
       {StateEnum::S_PLAY_XDIE9,
        {SpriteEnum::SPR_PLAY, 22, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_POSS_STND,
        {SpriteEnum::SPR_POSS, 0, 10, action::look, StateEnum::S_POSS_STND2,
        0,
         0}},
       {StateEnum::S_POSS_STND2,
        {SpriteEnum::SPR_POSS, 1, 10, action::look, StateEnum::S_POSS_STND,
        0, 0}},
       {StateEnum::S_POSS_RUN1,
        {SpriteEnum::SPR_POSS, 0, 4, action::chase, StateEnum::S_POSS_RUN2,
        0, 0}},
       {StateEnum::S_POSS_RUN2,
        {SpriteEnum::SPR_POSS, 0, 4, action::chase, StateEnum::S_POSS_RUN3,
        0, 0}},
       {StateEnum::S_POSS_RUN3,
        {SpriteEnum::SPR_POSS, 1, 4, action::chase, StateEnum::S_POSS_RUN4,
        0, 0}},
       {StateEnum::S_POSS_RUN4,
        {SpriteEnum::SPR_POSS, 1, 4, action::chase, StateEnum::S_POSS_RUN5,
        0, 0}},
       {StateEnum::S_POSS_RUN5,
        {SpriteEnum::SPR_POSS, 2, 4, action::chase, StateEnum::S_POSS_RUN6,
        0, 0}},
       {StateEnum::S_POSS_RUN6,
        {SpriteEnum::SPR_POSS, 2, 4, action::chase, StateEnum::S_POSS_RUN7,
        0, 0}},
       {StateEnum::S_POSS_RUN7,
        {SpriteEnum::SPR_POSS, 3, 4, action::chase, StateEnum::S_POSS_RUN8,
        0, 0}},
       {StateEnum::S_POSS_RUN8,
        {SpriteEnum::SPR_POSS, 3, 4, action::chase, StateEnum::S_POSS_RUN1,
        0, 0}},
       {StateEnum::S_POSS_ATK1,
        {SpriteEnum::SPR_POSS, 4, 10, action::faceTarget,
        StateEnum::S_POSS_ATK2,
         0, 0}},
       {StateEnum::S_POSS_ATK2,
        {SpriteEnum::SPR_POSS, 5, 8, action::posAttack,
        StateEnum::S_POSS_ATK3, 0,
         0}},
       {StateEnum::S_POSS_ATK3,
        {SpriteEnum::SPR_POSS, 4, 8, nullptr, StateEnum::S_POSS_RUN1, 0, 0}},
       {StateEnum::S_POSS_PAIN,
        {SpriteEnum::SPR_POSS, 6, 3, nullptr, StateEnum::S_POSS_PAIN2, 0,
        0}},
       {StateEnum::S_POSS_PAIN2,
        {SpriteEnum::SPR_POSS, 6, 3, action::pain, StateEnum::S_POSS_RUN1, 0,
        0}},
       {StateEnum::S_POSS_DIE1,
        {SpriteEnum::SPR_POSS, 7, 5, nullptr, StateEnum::S_POSS_DIE2, 0, 0}},
       {StateEnum::S_POSS_DIE2,
        {SpriteEnum::SPR_POSS, 8, 5, action::scream, StateEnum::S_POSS_DIE3,
        0,
         0}},
       {StateEnum::S_POSS_DIE3,
        {SpriteEnum::SPR_POSS, 9, 5, action::fall, StateEnum::S_POSS_DIE4, 0,
        0}},
       {StateEnum::S_POSS_DIE4,
        {SpriteEnum::SPR_POSS, 10, 5, nullptr, StateEnum::S_POSS_DIE5, 0,
        0}},
       {StateEnum::S_POSS_DIE5,
        {SpriteEnum::SPR_POSS, 11, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_POSS_XDIE1,
        {SpriteEnum::SPR_POSS, 12, 5, nullptr, StateEnum::S_POSS_XDIE2, 0,
        0}},
       {StateEnum::S_POSS_XDIE2,
        {SpriteEnum::SPR_POSS, 13, 5, action::xScream,
        StateEnum::S_POSS_XDIE3, 0,
         0}},
       {StateEnum::S_POSS_XDIE3,
        {SpriteEnum::SPR_POSS, 14, 5, action::fall, StateEnum::S_POSS_XDIE4,
        0,
         0}},
       {StateEnum::S_POSS_XDIE4,
        {SpriteEnum::SPR_POSS, 15, 5, nullptr, StateEnum::S_POSS_XDIE5, 0,
        0}},
       {StateEnum::S_POSS_XDIE5,
        {SpriteEnum::SPR_POSS, 16, 5, nullptr, StateEnum::S_POSS_XDIE6, 0,
        0}},
       {StateEnum::S_POSS_XDIE6,
        {SpriteEnum::SPR_POSS, 17, 5, nullptr, StateEnum::S_POSS_XDIE7, 0,
        0}},
       {StateEnum::S_POSS_XDIE7,
        {SpriteEnum::SPR_POSS, 18, 5, nullptr, StateEnum::S_POSS_XDIE8, 0,
        0}},
       {StateEnum::S_POSS_XDIE8,
        {SpriteEnum::SPR_POSS, 19, 5, nullptr, StateEnum::S_POSS_XDIE9, 0,
        0}},
       {StateEnum::S_POSS_XDIE9,
        {SpriteEnum::SPR_POSS, 20, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_POSS_RAISE1,
        {SpriteEnum::SPR_POSS, 10, 5, nullptr, StateEnum::S_POSS_RAISE2, 0,
        0}},
       {StateEnum::S_POSS_RAISE2,
        {SpriteEnum::SPR_POSS, 9, 5, nullptr, StateEnum::S_POSS_RAISE3, 0,
        0}},
       {StateEnum::S_POSS_RAISE3,
        {SpriteEnum::SPR_POSS, 8, 5, nullptr, StateEnum::S_POSS_RAISE4, 0,
        0}},
       {StateEnum::S_POSS_RAISE4,
        {SpriteEnum::SPR_POSS, 7, 5, nullptr, StateEnum::S_POSS_RUN1, 0, 0}},
       {StateEnum::S_SPOS_STND,
        {SpriteEnum::SPR_SPOS, 0, 10, action::look, StateEnum::S_SPOS_STND2,
        0,
         0}},
       {StateEnum::S_SPOS_STND2,
        {SpriteEnum::SPR_SPOS, 1, 10, action::look, StateEnum::S_SPOS_STND,
        0, 0}},
       {StateEnum::S_SPOS_RUN1,
        {SpriteEnum::SPR_SPOS, 0, 3, action::chase, StateEnum::S_SPOS_RUN2,
        0, 0}},
       {StateEnum::S_SPOS_RUN2,
        {SpriteEnum::SPR_SPOS, 0, 3, action::chase, StateEnum::S_SPOS_RUN3,
        0, 0}},
       {StateEnum::S_SPOS_RUN3,
        {SpriteEnum::SPR_SPOS, 1, 3, action::chase, StateEnum::S_SPOS_RUN4,
        0, 0}},
       {StateEnum::S_SPOS_RUN4,
        {SpriteEnum::SPR_SPOS, 1, 3, action::chase, StateEnum::S_SPOS_RUN5,
        0, 0}},
       {StateEnum::S_SPOS_RUN5,
        {SpriteEnum::SPR_SPOS, 2, 3, action::chase, StateEnum::S_SPOS_RUN6,
        0, 0}},
       {StateEnum::S_SPOS_RUN6,
        {SpriteEnum::SPR_SPOS, 2, 3, action::chase, StateEnum::S_SPOS_RUN7,
        0, 0}},
       {StateEnum::S_SPOS_RUN7,
        {SpriteEnum::SPR_SPOS, 3, 3, action::chase, StateEnum::S_SPOS_RUN8,
        0, 0}},
       {StateEnum::S_SPOS_RUN8,
        {SpriteEnum::SPR_SPOS, 3, 3, action::chase, StateEnum::S_SPOS_RUN1,
        0, 0}},
       {StateEnum::S_SPOS_ATK1,
        {SpriteEnum::SPR_SPOS, 4, 10, action::faceTarget,
        StateEnum::S_SPOS_ATK2,
         0, 0}},
       {StateEnum::S_SPOS_ATK2,
        {SpriteEnum::SPR_SPOS, 32773, 10, action::sPosAttack,
         StateEnum::S_SPOS_ATK3, 0, 0}},
       {StateEnum::S_SPOS_ATK3,
        {SpriteEnum::SPR_SPOS, 4, 10, nullptr, StateEnum::S_SPOS_RUN1, 0,
        0}},
       {StateEnum::S_SPOS_PAIN,
        {SpriteEnum::SPR_SPOS, 6, 3, nullptr, StateEnum::S_SPOS_PAIN2, 0,
        0}},
       {StateEnum::S_SPOS_PAIN2,
        {SpriteEnum::SPR_SPOS, 6, 3, action::pain, StateEnum::S_SPOS_RUN1, 0,
        0}},
       {StateEnum::S_SPOS_DIE1,
        {SpriteEnum::SPR_SPOS, 7, 5, nullptr, StateEnum::S_SPOS_DIE2, 0, 0}},
       {StateEnum::S_SPOS_DIE2,
        {SpriteEnum::SPR_SPOS, 8, 5, action::scream, StateEnum::S_SPOS_DIE3,
        0,
         0}},
       {StateEnum::S_SPOS_DIE3,
        {SpriteEnum::SPR_SPOS, 9, 5, action::fall, StateEnum::S_SPOS_DIE4, 0,
        0}},
       {StateEnum::S_SPOS_DIE4,
        {SpriteEnum::SPR_SPOS, 10, 5, nullptr, StateEnum::S_SPOS_DIE5, 0,
        0}},
       {StateEnum::S_SPOS_DIE5,
        {SpriteEnum::SPR_SPOS, 11, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SPOS_XDIE1,
        {SpriteEnum::SPR_SPOS, 12, 5, nullptr, StateEnum::S_SPOS_XDIE2, 0,
        0}},
       {StateEnum::S_SPOS_XDIE2,
        {SpriteEnum::SPR_SPOS, 13, 5, action::xScream,
        StateEnum::S_SPOS_XDIE3, 0,
         0}},
       {StateEnum::S_SPOS_XDIE3,
        {SpriteEnum::SPR_SPOS, 14, 5, action::fall, StateEnum::S_SPOS_XDIE4,
        0,
         0}},
       {StateEnum::S_SPOS_XDIE4,
        {SpriteEnum::SPR_SPOS, 15, 5, nullptr, StateEnum::S_SPOS_XDIE5, 0,
        0}},
       {StateEnum::S_SPOS_XDIE5,
        {SpriteEnum::SPR_SPOS, 16, 5, nullptr, StateEnum::S_SPOS_XDIE6, 0,
        0}},
       {StateEnum::S_SPOS_XDIE6,
        {SpriteEnum::SPR_SPOS, 17, 5, nullptr, StateEnum::S_SPOS_XDIE7, 0,
        0}},
       {StateEnum::S_SPOS_XDIE7,
        {SpriteEnum::SPR_SPOS, 18, 5, nullptr, StateEnum::S_SPOS_XDIE8, 0,
        0}},
       {StateEnum::S_SPOS_XDIE8,
        {SpriteEnum::SPR_SPOS, 19, 5, nullptr, StateEnum::S_SPOS_XDIE9, 0,
        0}},
       {StateEnum::S_SPOS_XDIE9,
        {SpriteEnum::SPR_SPOS, 20, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SPOS_RAISE1,
        {SpriteEnum::SPR_SPOS, 11, 5, nullptr, StateEnum::S_SPOS_RAISE2, 0,
        0}},
       {StateEnum::S_SPOS_RAISE2,
        {SpriteEnum::SPR_SPOS, 10, 5, nullptr, StateEnum::S_SPOS_RAISE3, 0,
        0}},
       {StateEnum::S_SPOS_RAISE3,
        {SpriteEnum::SPR_SPOS, 9, 5, nullptr, StateEnum::S_SPOS_RAISE4, 0,
        0}},
       {StateEnum::S_SPOS_RAISE4,
        {SpriteEnum::SPR_SPOS, 8, 5, nullptr, StateEnum::S_SPOS_RAISE5, 0,
        0}},
       {StateEnum::S_SPOS_RAISE5,
        {SpriteEnum::SPR_SPOS, 7, 5, nullptr, StateEnum::S_SPOS_RUN1, 0, 0}},
       {StateEnum::S_VILE_STND,
        {SpriteEnum::SPR_VILE, 0, 10, action::look, StateEnum::S_VILE_STND2,
        0,
         0}},
       {StateEnum::S_VILE_STND2,
        {SpriteEnum::SPR_VILE, 1, 10, action::look, StateEnum::S_VILE_STND,
        0, 0}},
       {StateEnum::S_VILE_RUN1,
        {SpriteEnum::SPR_VILE, 0, 2, action::vileChase,
        StateEnum::S_VILE_RUN2, 0,
         0}},
       {StateEnum::S_VILE_RUN2,
        {SpriteEnum::SPR_VILE, 0, 2, action::vileChase,
        StateEnum::S_VILE_RUN3, 0,
         0}},
       {StateEnum::S_VILE_RUN3,
        {SpriteEnum::SPR_VILE, 1, 2, action::vileChase,
        StateEnum::S_VILE_RUN4, 0,
         0}},
       {StateEnum::S_VILE_RUN4,
        {SpriteEnum::SPR_VILE, 1, 2, action::vileChase,
        StateEnum::S_VILE_RUN5, 0,
         0}},
       {StateEnum::S_VILE_RUN5,
        {SpriteEnum::SPR_VILE, 2, 2, action::vileChase,
        StateEnum::S_VILE_RUN6, 0,
         0}},
       {StateEnum::S_VILE_RUN6,
        {SpriteEnum::SPR_VILE, 2, 2, action::vileChase,
        StateEnum::S_VILE_RUN7, 0,
         0}},
       {StateEnum::S_VILE_RUN7,
        {SpriteEnum::SPR_VILE, 3, 2, action::vileChase,
        StateEnum::S_VILE_RUN8, 0,
         0}},
       {StateEnum::S_VILE_RUN8,
        {SpriteEnum::SPR_VILE, 3, 2, action::vileChase,
        StateEnum::S_VILE_RUN9, 0,
         0}},
       {StateEnum::S_VILE_RUN9,
        {SpriteEnum::SPR_VILE, 4, 2, action::vileChase,
        StateEnum::S_VILE_RUN10, 0,
         0}},
       {StateEnum::S_VILE_RUN10,
        {SpriteEnum::SPR_VILE, 4, 2, action::vileChase,
        StateEnum::S_VILE_RUN11, 0,
         0}},
       {StateEnum::S_VILE_RUN11,
        {SpriteEnum::SPR_VILE, 5, 2, action::vileChase,
        StateEnum::S_VILE_RUN12, 0,
         0}},
       {StateEnum::S_VILE_RUN12,
        {SpriteEnum::SPR_VILE, 5, 2, action::vileChase,
        StateEnum::S_VILE_RUN1, 0,
         0}},
       {StateEnum::S_VILE_ATK1,
        {SpriteEnum::SPR_VILE, 32774, 0, action::vileStart,
        StateEnum::S_VILE_ATK2,
         0, 0}},
       {StateEnum::S_VILE_ATK2,
        {SpriteEnum::SPR_VILE, 32774, 10, action::faceTarget,
         StateEnum::S_VILE_ATK3, 0, 0}},
       {StateEnum::S_VILE_ATK3,
        {SpriteEnum::SPR_VILE, 32775, 8, action::vileTarget,
         StateEnum::S_VILE_ATK4, 0, 0}},
       {StateEnum::S_VILE_ATK4,
        {SpriteEnum::SPR_VILE, 32776, 8, action::faceTarget,
         StateEnum::S_VILE_ATK5, 0, 0}},
       {StateEnum::S_VILE_ATK5,
        {SpriteEnum::SPR_VILE, 32777, 8, action::faceTarget,
         StateEnum::S_VILE_ATK6, 0, 0}},
       {StateEnum::S_VILE_ATK6,
        {SpriteEnum::SPR_VILE, 32778, 8, action::faceTarget,
         StateEnum::S_VILE_ATK7, 0, 0}},
       {StateEnum::S_VILE_ATK7,
        {SpriteEnum::SPR_VILE, 32779, 8, action::faceTarget,
         StateEnum::S_VILE_ATK8, 0, 0}},
       {StateEnum::S_VILE_ATK8,
        {SpriteEnum::SPR_VILE, 32780, 8, action::faceTarget,
         StateEnum::S_VILE_ATK9, 0, 0}},
       {StateEnum::S_VILE_ATK9,
        {SpriteEnum::SPR_VILE, 32781, 8, action::faceTarget,
         StateEnum::S_VILE_ATK10, 0, 0}},
       {StateEnum::S_VILE_ATK10,
        {SpriteEnum::SPR_VILE, 32782, 8, action::vileAttack,
         StateEnum::S_VILE_ATK11, 0, 0}},
       {StateEnum::S_VILE_ATK11,
        {SpriteEnum::SPR_VILE, 32783, 20, nullptr, StateEnum::S_VILE_RUN1, 0,
        0}},
       {StateEnum::S_VILE_HEAL1,
        {SpriteEnum::SPR_VILE, 32794, 10, nullptr, StateEnum::S_VILE_HEAL2,
        0, 0}},
       {StateEnum::S_VILE_HEAL2,
        {SpriteEnum::SPR_VILE, 32795, 10, nullptr, StateEnum::S_VILE_HEAL3,
        0, 0}},
       {StateEnum::S_VILE_HEAL3,
        {SpriteEnum::SPR_VILE, 32796, 10, nullptr, StateEnum::S_VILE_RUN1, 0,
        0}},
       {StateEnum::S_VILE_PAIN,
        {SpriteEnum::SPR_VILE, 16, 5, nullptr, StateEnum::S_VILE_PAIN2, 0,
        0}},
       {StateEnum::S_VILE_PAIN2,
        {SpriteEnum::SPR_VILE, 16, 5, action::pain, StateEnum::S_VILE_RUN1,
        0, 0}},
       {StateEnum::S_VILE_DIE1,
        {SpriteEnum::SPR_VILE, 16, 7, nullptr, StateEnum::S_VILE_DIE2, 0,
        0}},
       {StateEnum::S_VILE_DIE2,
        {SpriteEnum::SPR_VILE, 17, 7, action::scream, StateEnum::S_VILE_DIE3,
        0,
         0}},
       {StateEnum::S_VILE_DIE3,
        {SpriteEnum::SPR_VILE, 18, 7, action::fall, StateEnum::S_VILE_DIE4,
        0, 0}},
       {StateEnum::S_VILE_DIE4,
        {SpriteEnum::SPR_VILE, 19, 7, nullptr, StateEnum::S_VILE_DIE5, 0,
        0}},
       {StateEnum::S_VILE_DIE5,
        {SpriteEnum::SPR_VILE, 20, 7, nullptr, StateEnum::S_VILE_DIE6, 0,
        0}},
       {StateEnum::S_VILE_DIE6,
        {SpriteEnum::SPR_VILE, 21, 7, nullptr, StateEnum::S_VILE_DIE7, 0,
        0}},
       {StateEnum::S_VILE_DIE7,
        {SpriteEnum::SPR_VILE, 22, 7, nullptr, StateEnum::S_VILE_DIE8, 0,
        0}},
       {StateEnum::S_VILE_DIE8,
        {SpriteEnum::SPR_VILE, 23, 5, nullptr, StateEnum::S_VILE_DIE9, 0,
        0}},
       {StateEnum::S_VILE_DIE9,
        {SpriteEnum::SPR_VILE, 24, 5, nullptr, StateEnum::S_VILE_DIE10, 0,
        0}},
       {StateEnum::S_VILE_DIE10,
        {SpriteEnum::SPR_VILE, 25, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_FIRE1,
        {SpriteEnum::SPR_FIRE, 32768, 2, action::startFire,
        StateEnum::S_FIRE2, 0,
         0}},
       {StateEnum::S_FIRE2,
        {SpriteEnum::SPR_FIRE, 32769, 2, action::fire, StateEnum::S_FIRE3, 0,
        0}},
       {StateEnum::S_FIRE3,
        {SpriteEnum::SPR_FIRE, 32768, 2, action::fire, StateEnum::S_FIRE4, 0,
        0}},
       {StateEnum::S_FIRE4,
        {SpriteEnum::SPR_FIRE, 32769, 2, action::fire, StateEnum::S_FIRE5, 0,
        0}},
       {StateEnum::S_FIRE5,
        {SpriteEnum::SPR_FIRE, 32770, 2, action::fireCrackle,
        StateEnum::S_FIRE6,
         0, 0}},
       {StateEnum::S_FIRE6,
        {SpriteEnum::SPR_FIRE, 32769, 2, action::fire, StateEnum::S_FIRE7, 0,
        0}},
       {StateEnum::S_FIRE7,
        {SpriteEnum::SPR_FIRE, 32770, 2, action::fire, StateEnum::S_FIRE8, 0,
        0}},
       {StateEnum::S_FIRE8,
        {SpriteEnum::SPR_FIRE, 32769, 2, action::fire, StateEnum::S_FIRE9, 0,
        0}},
       {StateEnum::S_FIRE9,
        {SpriteEnum::SPR_FIRE, 32770, 2, action::fire, StateEnum::S_FIRE10,
        0, 0}},
       {StateEnum::S_FIRE10,
        {SpriteEnum::SPR_FIRE, 32771, 2, action::fire, StateEnum::S_FIRE11,
        0, 0}},
       {StateEnum::S_FIRE11,
        {SpriteEnum::SPR_FIRE, 32770, 2, action::fire, StateEnum::S_FIRE12,
        0, 0}},
       {StateEnum::S_FIRE12,
        {SpriteEnum::SPR_FIRE, 32771, 2, action::fire, StateEnum::S_FIRE13,
        0, 0}},
       {StateEnum::S_FIRE13,
        {SpriteEnum::SPR_FIRE, 32770, 2, action::fire, StateEnum::S_FIRE14,
        0, 0}},
       {StateEnum::S_FIRE14,
        {SpriteEnum::SPR_FIRE, 32771, 2, action::fire, StateEnum::S_FIRE15,
        0, 0}},
       {StateEnum::S_FIRE15,
        {SpriteEnum::SPR_FIRE, 32772, 2, action::fire, StateEnum::S_FIRE16,
        0, 0}},
       {StateEnum::S_FIRE16,
        {SpriteEnum::SPR_FIRE, 32771, 2, action::fire, StateEnum::S_FIRE17,
        0, 0}},
       {StateEnum::S_FIRE17,
        {SpriteEnum::SPR_FIRE, 32772, 2, action::fire, StateEnum::S_FIRE18,
        0, 0}},
       {StateEnum::S_FIRE18,
        {SpriteEnum::SPR_FIRE, 32771, 2, action::fire, StateEnum::S_FIRE19,
        0, 0}},
       {StateEnum::S_FIRE19,
        {SpriteEnum::SPR_FIRE, 32772, 2, action::fireCrackle,
        StateEnum::S_FIRE20,
         0, 0}},
       {StateEnum::S_FIRE20,
        {SpriteEnum::SPR_FIRE, 32773, 2, action::fire, StateEnum::S_FIRE21,
        0, 0}},
       {StateEnum::S_FIRE21,
        {SpriteEnum::SPR_FIRE, 32772, 2, action::fire, StateEnum::S_FIRE22,
        0, 0}},
       {StateEnum::S_FIRE22,
        {SpriteEnum::SPR_FIRE, 32773, 2, action::fire, StateEnum::S_FIRE23,
        0, 0}},
       {StateEnum::S_FIRE23,
        {SpriteEnum::SPR_FIRE, 32772, 2, action::fire, StateEnum::S_FIRE24,
        0, 0}},
       {StateEnum::S_FIRE24,
        {SpriteEnum::SPR_FIRE, 32773, 2, action::fire, StateEnum::S_FIRE25,
        0, 0}},
       {StateEnum::S_FIRE25,
        {SpriteEnum::SPR_FIRE, 32774, 2, action::fire, StateEnum::S_FIRE26,
        0, 0}},
       {StateEnum::S_FIRE26,
        {SpriteEnum::SPR_FIRE, 32775, 2, action::fire, StateEnum::S_FIRE27,
        0, 0}},
       {StateEnum::S_FIRE27,
        {SpriteEnum::SPR_FIRE, 32774, 2, action::fire, StateEnum::S_FIRE28,
        0, 0}},
       {StateEnum::S_FIRE28,
        {SpriteEnum::SPR_FIRE, 32775, 2, action::fire, StateEnum::S_FIRE29,
        0, 0}},
       {StateEnum::S_FIRE29,
        {SpriteEnum::SPR_FIRE, 32774, 2, action::fire, StateEnum::S_FIRE30,
        0, 0}},
       {StateEnum::S_FIRE30,
        {SpriteEnum::SPR_FIRE, 32775, 2, action::fire, StateEnum::S_NULL, 0,
        0}},
       {StateEnum::S_SMOKE1,
        {SpriteEnum::SPR_PUFF, 1, 4, nullptr, StateEnum::S_SMOKE2, 0, 0}},
       {StateEnum::S_SMOKE2,
        {SpriteEnum::SPR_PUFF, 2, 4, nullptr, StateEnum::S_SMOKE3, 0, 0}},
       {StateEnum::S_SMOKE3,
        {SpriteEnum::SPR_PUFF, 1, 4, nullptr, StateEnum::S_SMOKE4, 0, 0}},
       {StateEnum::S_SMOKE4,
        {SpriteEnum::SPR_PUFF, 2, 4, nullptr, StateEnum::S_SMOKE5, 0, 0}},
       {StateEnum::S_SMOKE5,
        {SpriteEnum::SPR_PUFF, 3, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TRACER,
        {SpriteEnum::SPR_FATB, 32768, 2, action::tracer,
        StateEnum::S_TRACER2, 0,
         0}},
       {StateEnum::S_TRACER2,
        {SpriteEnum::SPR_FATB, 32769, 2, action::tracer, StateEnum::S_TRACER,
        0,
         0}},
       {StateEnum::S_TRACEEXP1,
        {SpriteEnum::SPR_FBXP, 32768, 8, nullptr, StateEnum::S_TRACEEXP2, 0,
        0}},
       {StateEnum::S_TRACEEXP2,
        {SpriteEnum::SPR_FBXP, 32769, 6, nullptr, StateEnum::S_TRACEEXP3, 0,
        0}},
       {StateEnum::S_TRACEEXP3,
        {SpriteEnum::SPR_FBXP, 32770, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SKEL_STND,
        {SpriteEnum::SPR_SKEL, 0, 10, action::look, StateEnum::S_SKEL_STND2,
        0,
         0}},
       {StateEnum::S_SKEL_STND2,
        {SpriteEnum::SPR_SKEL, 1, 10, action::look, StateEnum::S_SKEL_STND,
        0, 0}},
       {StateEnum::S_SKEL_RUN1,
        {SpriteEnum::SPR_SKEL, 0, 2, action::chase, StateEnum::S_SKEL_RUN2,
        0, 0}},
       {StateEnum::S_SKEL_RUN2,
        {SpriteEnum::SPR_SKEL, 0, 2, action::chase, StateEnum::S_SKEL_RUN3,
        0, 0}},
       {StateEnum::S_SKEL_RUN3,
        {SpriteEnum::SPR_SKEL, 1, 2, action::chase, StateEnum::S_SKEL_RUN4,
        0, 0}},
       {StateEnum::S_SKEL_RUN4,
        {SpriteEnum::SPR_SKEL, 1, 2, action::chase, StateEnum::S_SKEL_RUN5,
        0, 0}},
       {StateEnum::S_SKEL_RUN5,
        {SpriteEnum::SPR_SKEL, 2, 2, action::chase, StateEnum::S_SKEL_RUN6,
        0, 0}},
       {StateEnum::S_SKEL_RUN6,
        {SpriteEnum::SPR_SKEL, 2, 2, action::chase, StateEnum::S_SKEL_RUN7,
        0, 0}},
       {StateEnum::S_SKEL_RUN7,
        {SpriteEnum::SPR_SKEL, 3, 2, action::chase, StateEnum::S_SKEL_RUN8,
        0, 0}},
       {StateEnum::S_SKEL_RUN8,
        {SpriteEnum::SPR_SKEL, 3, 2, action::chase, StateEnum::S_SKEL_RUN9,
        0, 0}},
       {StateEnum::S_SKEL_RUN9,
        {SpriteEnum::SPR_SKEL, 4, 2, action::chase, StateEnum::S_SKEL_RUN10,
        0,
         0}},
       {StateEnum::S_SKEL_RUN10,
        {SpriteEnum::SPR_SKEL, 4, 2, action::chase, StateEnum::S_SKEL_RUN11,
        0,
         0}},
       {StateEnum::S_SKEL_RUN11,
        {SpriteEnum::SPR_SKEL, 5, 2, action::chase, StateEnum::S_SKEL_RUN12,
        0,
         0}},
       {StateEnum::S_SKEL_RUN12,
        {SpriteEnum::SPR_SKEL, 5, 2, action::chase, StateEnum::S_SKEL_RUN1,
        0, 0}},
       {StateEnum::S_SKEL_FIST1,
        {SpriteEnum::SPR_SKEL, 6, 0, action::faceTarget,
        StateEnum::S_SKEL_FIST2,
         0, 0}},
       {StateEnum::S_SKEL_FIST2,
        {SpriteEnum::SPR_SKEL, 6, 6, action::skelWhoosh,
        StateEnum::S_SKEL_FIST3,
         0, 0}},
       {StateEnum::S_SKEL_FIST3,
        {SpriteEnum::SPR_SKEL, 7, 6, action::faceTarget,
        StateEnum::S_SKEL_FIST4,
         0, 0}},
       {StateEnum::S_SKEL_FIST4,
        {SpriteEnum::SPR_SKEL, 8, 6, action::skelFist,
        StateEnum::S_SKEL_RUN1, 0,
         0}},
       {StateEnum::S_SKEL_MISS1,
        {SpriteEnum::SPR_SKEL, 32777, 0, action::faceTarget,
         StateEnum::S_SKEL_MISS2, 0, 0}},
       {StateEnum::S_SKEL_MISS2,
        {SpriteEnum::SPR_SKEL, 32777, 10, action::faceTarget,
         StateEnum::S_SKEL_MISS3, 0, 0}},
       {StateEnum::S_SKEL_MISS3,
        {SpriteEnum::SPR_SKEL, 10, 10, action::skelMissile,
         StateEnum::S_SKEL_MISS4, 0, 0}},
       {StateEnum::S_SKEL_MISS4,
        {SpriteEnum::SPR_SKEL, 10, 10, action::faceTarget,
        StateEnum::S_SKEL_RUN1,
         0, 0}},
       {StateEnum::S_SKEL_PAIN,
        {SpriteEnum::SPR_SKEL, 11, 5, nullptr, StateEnum::S_SKEL_PAIN2, 0,
        0}},
       {StateEnum::S_SKEL_PAIN2,
        {SpriteEnum::SPR_SKEL, 11, 5, action::pain, StateEnum::S_SKEL_RUN1,
        0, 0}},
       {StateEnum::S_SKEL_DIE1,
        {SpriteEnum::SPR_SKEL, 11, 7, nullptr, StateEnum::S_SKEL_DIE2, 0,
        0}},
       {StateEnum::S_SKEL_DIE2,
        {SpriteEnum::SPR_SKEL, 12, 7, nullptr, StateEnum::S_SKEL_DIE3, 0,
        0}},
       {StateEnum::S_SKEL_DIE3,
        {SpriteEnum::SPR_SKEL, 13, 7, action::scream, StateEnum::S_SKEL_DIE4,
        0,
         0}},
       {StateEnum::S_SKEL_DIE4,
        {SpriteEnum::SPR_SKEL, 14, 7, action::fall, StateEnum::S_SKEL_DIE5,
        0, 0}},
       {StateEnum::S_SKEL_DIE5,
        {SpriteEnum::SPR_SKEL, 15, 7, nullptr, StateEnum::S_SKEL_DIE6, 0,
        0}},
       {StateEnum::S_SKEL_DIE6,
        {SpriteEnum::SPR_SKEL, 16, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SKEL_RAISE1,
        {SpriteEnum::SPR_SKEL, 16, 5, nullptr, StateEnum::S_SKEL_RAISE2, 0,
        0}},
       {StateEnum::S_SKEL_RAISE2,
        {SpriteEnum::SPR_SKEL, 15, 5, nullptr, StateEnum::S_SKEL_RAISE3, 0,
        0}},
       {StateEnum::S_SKEL_RAISE3,
        {SpriteEnum::SPR_SKEL, 14, 5, nullptr, StateEnum::S_SKEL_RAISE4, 0,
        0}},
       {StateEnum::S_SKEL_RAISE4,
        {SpriteEnum::SPR_SKEL, 13, 5, nullptr, StateEnum::S_SKEL_RAISE5, 0,
        0}},
       {StateEnum::S_SKEL_RAISE5,
        {SpriteEnum::SPR_SKEL, 12, 5, nullptr, StateEnum::S_SKEL_RAISE6, 0,
        0}},
       {StateEnum::S_SKEL_RAISE6,
        {SpriteEnum::SPR_SKEL, 11, 5, nullptr, StateEnum::S_SKEL_RUN1, 0,
        0}},
       {StateEnum::S_FATSHOT1,
        {SpriteEnum::SPR_MANF, 32768, 4, nullptr, StateEnum::S_FATSHOT2, 0,
        0}},
       {StateEnum::S_FATSHOT2,
        {SpriteEnum::SPR_MANF, 32769, 4, nullptr, StateEnum::S_FATSHOT1, 0,
        0}},
       {StateEnum::S_FATSHOTX1,
        {SpriteEnum::SPR_MISL, 32769, 8, nullptr, StateEnum::S_FATSHOTX2, 0,
        0}},
       {StateEnum::S_FATSHOTX2,
        {SpriteEnum::SPR_MISL, 32770, 6, nullptr, StateEnum::S_FATSHOTX3, 0,
        0}},
       {StateEnum::S_FATSHOTX3,
        {SpriteEnum::SPR_MISL, 32771, 4, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_FATT_STND,
        {SpriteEnum::SPR_FATT, 0, 15, action::look, StateEnum::S_FATT_STND2,
        0,
         0}},
       {StateEnum::S_FATT_STND2,
        {SpriteEnum::SPR_FATT, 1, 15, action::look, StateEnum::S_FATT_STND,
        0, 0}},
       {StateEnum::S_FATT_RUN1,
        {SpriteEnum::SPR_FATT, 0, 4, action::chase, StateEnum::S_FATT_RUN2,
        0, 0}},
       {StateEnum::S_FATT_RUN2,
        {SpriteEnum::SPR_FATT, 0, 4, action::chase, StateEnum::S_FATT_RUN3,
        0, 0}},
       {StateEnum::S_FATT_RUN3,
        {SpriteEnum::SPR_FATT, 1, 4, action::chase, StateEnum::S_FATT_RUN4,
        0, 0}},
       {StateEnum::S_FATT_RUN4,
        {SpriteEnum::SPR_FATT, 1, 4, action::chase, StateEnum::S_FATT_RUN5,
        0, 0}},
       {StateEnum::S_FATT_RUN5,
        {SpriteEnum::SPR_FATT, 2, 4, action::chase, StateEnum::S_FATT_RUN6,
        0, 0}},
       {StateEnum::S_FATT_RUN6,
        {SpriteEnum::SPR_FATT, 2, 4, action::chase, StateEnum::S_FATT_RUN7,
        0, 0}},
       {StateEnum::S_FATT_RUN7,
        {SpriteEnum::SPR_FATT, 3, 4, action::chase, StateEnum::S_FATT_RUN8,
        0, 0}},
       {StateEnum::S_FATT_RUN8,
        {SpriteEnum::SPR_FATT, 3, 4, action::chase, StateEnum::S_FATT_RUN9,
        0, 0}},
       {StateEnum::S_FATT_RUN9,
        {SpriteEnum::SPR_FATT, 4, 4, action::chase, StateEnum::S_FATT_RUN10,
        0,
         0}},
       {StateEnum::S_FATT_RUN10,
        {SpriteEnum::SPR_FATT, 4, 4, action::chase, StateEnum::S_FATT_RUN11,
        0,
         0}},
       {StateEnum::S_FATT_RUN11,
        {SpriteEnum::SPR_FATT, 5, 4, action::chase, StateEnum::S_FATT_RUN12,
        0,
         0}},
       {StateEnum::S_FATT_RUN12,
        {SpriteEnum::SPR_FATT, 5, 4, action::chase, StateEnum::S_FATT_RUN1,
        0, 0}},
       {StateEnum::S_FATT_ATK1,
        {SpriteEnum::SPR_FATT, 6, 20, action::fatRaise,
        StateEnum::S_FATT_ATK2, 0,
         0}},
       {StateEnum::S_FATT_ATK2,
        {SpriteEnum::SPR_FATT, 32775, 10, action::fatAttack1,
         StateEnum::S_FATT_ATK3, 0, 0}},
       {StateEnum::S_FATT_ATK3,
        {SpriteEnum::SPR_FATT, 8, 5, action::faceTarget,
        StateEnum::S_FATT_ATK4, 0,
         0}},
       {StateEnum::S_FATT_ATK4,
        {SpriteEnum::SPR_FATT, 6, 5, action::faceTarget,
        StateEnum::S_FATT_ATK5, 0,
         0}},
       {StateEnum::S_FATT_ATK5,
        {SpriteEnum::SPR_FATT, 32775, 10, action::fatAttack2,
         StateEnum::S_FATT_ATK6, 0, 0}},
       {StateEnum::S_FATT_ATK6,
        {SpriteEnum::SPR_FATT, 8, 5, action::faceTarget,
        StateEnum::S_FATT_ATK7, 0,
         0}},
       {StateEnum::S_FATT_ATK7,
        {SpriteEnum::SPR_FATT, 6, 5, action::faceTarget,
        StateEnum::S_FATT_ATK8, 0,
         0}},
       {StateEnum::S_FATT_ATK8,
        {SpriteEnum::SPR_FATT, 32775, 10, action::fatAttack3,
         StateEnum::S_FATT_ATK9, 0, 0}},
       {StateEnum::S_FATT_ATK9,
        {SpriteEnum::SPR_FATT, 8, 5, action::faceTarget,
        StateEnum::S_FATT_ATK10,
         0, 0}},
       {StateEnum::S_FATT_ATK10,
        {SpriteEnum::SPR_FATT, 6, 5, action::faceTarget,
        StateEnum::S_FATT_RUN1, 0,
         0}},
       {StateEnum::S_FATT_PAIN,
        {SpriteEnum::SPR_FATT, 9, 3, nullptr, StateEnum::S_FATT_PAIN2, 0,
        0}},
       {StateEnum::S_FATT_PAIN2,
        {SpriteEnum::SPR_FATT, 9, 3, action::pain, StateEnum::S_FATT_RUN1, 0,
        0}},
       {StateEnum::S_FATT_DIE1,
        {SpriteEnum::SPR_FATT, 10, 6, nullptr, StateEnum::S_FATT_DIE2, 0,
        0}},
       {StateEnum::S_FATT_DIE2,
        {SpriteEnum::SPR_FATT, 11, 6, action::scream, StateEnum::S_FATT_DIE3,
        0,
         0}},
       {StateEnum::S_FATT_DIE3,
        {SpriteEnum::SPR_FATT, 12, 6, action::fall, StateEnum::S_FATT_DIE4,
        0, 0}},
       {StateEnum::S_FATT_DIE4,
        {SpriteEnum::SPR_FATT, 13, 6, nullptr, StateEnum::S_FATT_DIE5, 0,
        0}},
       {StateEnum::S_FATT_DIE5,
        {SpriteEnum::SPR_FATT, 14, 6, nullptr, StateEnum::S_FATT_DIE6, 0,
        0}},
       {StateEnum::S_FATT_DIE6,
        {SpriteEnum::SPR_FATT, 15, 6, nullptr, StateEnum::S_FATT_DIE7, 0,
        0}},
       {StateEnum::S_FATT_DIE7,
        {SpriteEnum::SPR_FATT, 16, 6, nullptr, StateEnum::S_FATT_DIE8, 0,
        0}},
       {StateEnum::S_FATT_DIE8,
        {SpriteEnum::SPR_FATT, 17, 6, nullptr, StateEnum::S_FATT_DIE9, 0,
        0}},
       {StateEnum::S_FATT_DIE9,
        {SpriteEnum::SPR_FATT, 18, 6, nullptr, StateEnum::S_FATT_DIE10, 0,
        0}},
       {StateEnum::S_FATT_DIE10,
        {SpriteEnum::SPR_FATT, 19, -1, action::bossDeath, StateEnum::S_NULL,
        0,
         0}},
       {StateEnum::S_FATT_RAISE1,
        {SpriteEnum::SPR_FATT, 17, 5, nullptr, StateEnum::S_FATT_RAISE2, 0,
        0}},
       {StateEnum::S_FATT_RAISE2,
        {SpriteEnum::SPR_FATT, 16, 5, nullptr, StateEnum::S_FATT_RAISE3, 0,
        0}},
       {StateEnum::S_FATT_RAISE3,
        {SpriteEnum::SPR_FATT, 15, 5, nullptr, StateEnum::S_FATT_RAISE4, 0,
        0}},
       {StateEnum::S_FATT_RAISE4,
        {SpriteEnum::SPR_FATT, 14, 5, nullptr, StateEnum::S_FATT_RAISE5, 0,
        0}},
       {StateEnum::S_FATT_RAISE5,
        {SpriteEnum::SPR_FATT, 13, 5, nullptr, StateEnum::S_FATT_RAISE6, 0,
        0}},
       {StateEnum::S_FATT_RAISE6,
        {SpriteEnum::SPR_FATT, 12, 5, nullptr, StateEnum::S_FATT_RAISE7, 0,
        0}},
       {StateEnum::S_FATT_RAISE7,
        {SpriteEnum::SPR_FATT, 11, 5, nullptr, StateEnum::S_FATT_RAISE8, 0,
        0}},
       {StateEnum::S_FATT_RAISE8,
        {SpriteEnum::SPR_FATT, 10, 5, nullptr, StateEnum::S_FATT_RUN1, 0,
        0}},
       {StateEnum::S_CPOS_STND,
        {SpriteEnum::SPR_CPOS, 0, 10, action::look, StateEnum::S_CPOS_STND2,
        0,
         0}},
       {StateEnum::S_CPOS_STND2,
        {SpriteEnum::SPR_CPOS, 1, 10, action::look, StateEnum::S_CPOS_STND,
        0, 0}},
       {StateEnum::S_CPOS_RUN1,
        {SpriteEnum::SPR_CPOS, 0, 3, action::chase, StateEnum::S_CPOS_RUN2,
        0, 0}},
       {StateEnum::S_CPOS_RUN2,
        {SpriteEnum::SPR_CPOS, 0, 3, action::chase, StateEnum::S_CPOS_RUN3,
        0, 0}},
       {StateEnum::S_CPOS_RUN3,
        {SpriteEnum::SPR_CPOS, 1, 3, action::chase, StateEnum::S_CPOS_RUN4,
        0, 0}},
       {StateEnum::S_CPOS_RUN4,
        {SpriteEnum::SPR_CPOS, 1, 3, action::chase, StateEnum::S_CPOS_RUN5,
        0, 0}},
       {StateEnum::S_CPOS_RUN5,
        {SpriteEnum::SPR_CPOS, 2, 3, action::chase, StateEnum::S_CPOS_RUN6,
        0, 0}},
       {StateEnum::S_CPOS_RUN6,
        {SpriteEnum::SPR_CPOS, 2, 3, action::chase, StateEnum::S_CPOS_RUN7,
        0, 0}},
       {StateEnum::S_CPOS_RUN7,
        {SpriteEnum::SPR_CPOS, 3, 3, action::chase, StateEnum::S_CPOS_RUN8,
        0, 0}},
       {StateEnum::S_CPOS_RUN8,
        {SpriteEnum::SPR_CPOS, 3, 3, action::chase, StateEnum::S_CPOS_RUN1,
        0, 0}},
       {StateEnum::S_CPOS_ATK1,
        {SpriteEnum::SPR_CPOS, 4, 10, action::faceTarget,
        StateEnum::S_CPOS_ATK2,
         0, 0}},
       {StateEnum::S_CPOS_ATK2,
        {SpriteEnum::SPR_CPOS, 32773, 4, action::cPosAttack,
         StateEnum::S_CPOS_ATK3, 0, 0}},
       {StateEnum::S_CPOS_ATK3,
        {SpriteEnum::SPR_CPOS, 32772, 4, action::cPosAttack,
         StateEnum::S_CPOS_ATK4, 0, 0}},
       {StateEnum::S_CPOS_ATK4,
        {SpriteEnum::SPR_CPOS, 5, 1, action::cPosRefire,
        StateEnum::S_CPOS_ATK2, 0,
         0}},
       {StateEnum::S_CPOS_PAIN,
        {SpriteEnum::SPR_CPOS, 6, 3, nullptr, StateEnum::S_CPOS_PAIN2, 0,
        0}},
       {StateEnum::S_CPOS_PAIN2,
        {SpriteEnum::SPR_CPOS, 6, 3, action::pain, StateEnum::S_CPOS_RUN1, 0,
        0}},
       {StateEnum::S_CPOS_DIE1,
        {SpriteEnum::SPR_CPOS, 7, 5, nullptr, StateEnum::S_CPOS_DIE2, 0, 0}},
       {StateEnum::S_CPOS_DIE2,
        {SpriteEnum::SPR_CPOS, 8, 5, action::scream, StateEnum::S_CPOS_DIE3,
        0,
         0}},
       {StateEnum::S_CPOS_DIE3,
        {SpriteEnum::SPR_CPOS, 9, 5, action::fall, StateEnum::S_CPOS_DIE4, 0,
        0}},
       {StateEnum::S_CPOS_DIE4,
        {SpriteEnum::SPR_CPOS, 10, 5, nullptr, StateEnum::S_CPOS_DIE5, 0,
        0}},
       {StateEnum::S_CPOS_DIE5,
        {SpriteEnum::SPR_CPOS, 11, 5, nullptr, StateEnum::S_CPOS_DIE6, 0,
        0}},
       {StateEnum::S_CPOS_DIE6,
        {SpriteEnum::SPR_CPOS, 12, 5, nullptr, StateEnum::S_CPOS_DIE7, 0,
        0}},
       {StateEnum::S_CPOS_DIE7,
        {SpriteEnum::SPR_CPOS, 13, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CPOS_XDIE1,
        {SpriteEnum::SPR_CPOS, 14, 5, nullptr, StateEnum::S_CPOS_XDIE2, 0,
        0}},
       {StateEnum::S_CPOS_XDIE2,
        {SpriteEnum::SPR_CPOS, 15, 5, action::xScream,
        StateEnum::S_CPOS_XDIE3, 0,
         0}},
       {StateEnum::S_CPOS_XDIE3,
        {SpriteEnum::SPR_CPOS, 16, 5, action::fall, StateEnum::S_CPOS_XDIE4,
        0,
         0}},
       {StateEnum::S_CPOS_XDIE4,
        {SpriteEnum::SPR_CPOS, 17, 5, nullptr, StateEnum::S_CPOS_XDIE5, 0,
        0}},
       {StateEnum::S_CPOS_XDIE5,
        {SpriteEnum::SPR_CPOS, 18, 5, nullptr, StateEnum::S_CPOS_XDIE6, 0,
        0}},
       {StateEnum::S_CPOS_XDIE6,
        {SpriteEnum::SPR_CPOS, 19, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CPOS_RAISE1,
        {SpriteEnum::SPR_CPOS, 13, 5, nullptr, StateEnum::S_CPOS_RAISE2, 0,
        0}},
       {StateEnum::S_CPOS_RAISE2,
        {SpriteEnum::SPR_CPOS, 12, 5, nullptr, StateEnum::S_CPOS_RAISE3, 0,
        0}},
       {StateEnum::S_CPOS_RAISE3,
        {SpriteEnum::SPR_CPOS, 11, 5, nullptr, StateEnum::S_CPOS_RAISE4, 0,
        0}},
       {StateEnum::S_CPOS_RAISE4,
        {SpriteEnum::SPR_CPOS, 10, 5, nullptr, StateEnum::S_CPOS_RAISE5, 0,
        0}},
       {StateEnum::S_CPOS_RAISE5,
        {SpriteEnum::SPR_CPOS, 9, 5, nullptr, StateEnum::S_CPOS_RAISE6, 0,
        0}},
       {StateEnum::S_CPOS_RAISE6,
        {SpriteEnum::SPR_CPOS, 8, 5, nullptr, StateEnum::S_CPOS_RAISE7, 0,
        0}},
       {StateEnum::S_CPOS_RAISE7,
        {SpriteEnum::SPR_CPOS, 7, 5, nullptr, StateEnum::S_CPOS_RUN1, 0, 0}},
       {StateEnum::S_TROO_STND,
        {SpriteEnum::SPR_TROO, 0, 10, action::look, StateEnum::S_TROO_STND2,
        0,
         0}},
       {StateEnum::S_TROO_STND2,
        {SpriteEnum::SPR_TROO, 1, 10, action::look, StateEnum::S_TROO_STND,
        0, 0}},
       {StateEnum::S_TROO_RUN1,
        {SpriteEnum::SPR_TROO, 0, 3, action::chase, StateEnum::S_TROO_RUN2,
        0, 0}},
       {StateEnum::S_TROO_RUN2,
        {SpriteEnum::SPR_TROO, 0, 3, action::chase, StateEnum::S_TROO_RUN3,
        0, 0}},
       {StateEnum::S_TROO_RUN3,
        {SpriteEnum::SPR_TROO, 1, 3, action::chase, StateEnum::S_TROO_RUN4,
        0, 0}},
       {StateEnum::S_TROO_RUN4,
        {SpriteEnum::SPR_TROO, 1, 3, action::chase, StateEnum::S_TROO_RUN5,
        0, 0}},
       {StateEnum::S_TROO_RUN5,
        {SpriteEnum::SPR_TROO, 2, 3, action::chase, StateEnum::S_TROO_RUN6,
        0, 0}},
       {StateEnum::S_TROO_RUN6,
        {SpriteEnum::SPR_TROO, 2, 3, action::chase, StateEnum::S_TROO_RUN7,
        0, 0}},
       {StateEnum::S_TROO_RUN7,
        {SpriteEnum::SPR_TROO, 3, 3, action::chase, StateEnum::S_TROO_RUN8,
        0, 0}},
       {StateEnum::S_TROO_RUN8,
        {SpriteEnum::SPR_TROO, 3, 3, action::chase, StateEnum::S_TROO_RUN1,
        0, 0}},
       {StateEnum::S_TROO_ATK1,
        {SpriteEnum::SPR_TROO, 4, 8, action::faceTarget,
        StateEnum::S_TROO_ATK2, 0,
         0}},
       {StateEnum::S_TROO_ATK2,
        {SpriteEnum::SPR_TROO, 5, 8, action::faceTarget,
        StateEnum::S_TROO_ATK3, 0,
         0}},
       {StateEnum::S_TROO_ATK3,
        {SpriteEnum::SPR_TROO, 6, 6, action::troopAttack,
        StateEnum::S_TROO_RUN1,
         0, 0}},
       {StateEnum::S_TROO_PAIN,
        {SpriteEnum::SPR_TROO, 7, 2, nullptr, StateEnum::S_TROO_PAIN2, 0,
        0}},
       {StateEnum::S_TROO_PAIN2,
        {SpriteEnum::SPR_TROO, 7, 2, action::pain, StateEnum::S_TROO_RUN1, 0,
        0}},
       {StateEnum::S_TROO_DIE1,
        {SpriteEnum::SPR_TROO, 8, 8, nullptr, StateEnum::S_TROO_DIE2, 0, 0}},
       {StateEnum::S_TROO_DIE2,
        {SpriteEnum::SPR_TROO, 9, 8, action::scream, StateEnum::S_TROO_DIE3,
        0,
         0}},
       {StateEnum::S_TROO_DIE3,
        {SpriteEnum::SPR_TROO, 10, 6, nullptr, StateEnum::S_TROO_DIE4, 0,
        0}},
       {StateEnum::S_TROO_DIE4,
        {SpriteEnum::SPR_TROO, 11, 6, action::fall, StateEnum::S_TROO_DIE5,
        0, 0}},
       {StateEnum::S_TROO_DIE5,
        {SpriteEnum::SPR_TROO, 12, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TROO_XDIE1,
        {SpriteEnum::SPR_TROO, 13, 5, nullptr, StateEnum::S_TROO_XDIE2, 0,
        0}},
       {StateEnum::S_TROO_XDIE2,
        {SpriteEnum::SPR_TROO, 14, 5, action::xScream,
        StateEnum::S_TROO_XDIE3, 0,
         0}},
       {StateEnum::S_TROO_XDIE3,
        {SpriteEnum::SPR_TROO, 15, 5, nullptr, StateEnum::S_TROO_XDIE4, 0,
        0}},
       {StateEnum::S_TROO_XDIE4,
        {SpriteEnum::SPR_TROO, 16, 5, action::fall, StateEnum::S_TROO_XDIE5,
        0,
         0}},
       {StateEnum::S_TROO_XDIE5,
        {SpriteEnum::SPR_TROO, 17, 5, nullptr, StateEnum::S_TROO_XDIE6, 0,
        0}},
       {StateEnum::S_TROO_XDIE6,
        {SpriteEnum::SPR_TROO, 18, 5, nullptr, StateEnum::S_TROO_XDIE7, 0,
        0}},
       {StateEnum::S_TROO_XDIE7,
        {SpriteEnum::SPR_TROO, 19, 5, nullptr, StateEnum::S_TROO_XDIE8, 0,
        0}},
       {StateEnum::S_TROO_XDIE8,
        {SpriteEnum::SPR_TROO, 20, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TROO_RAISE1,
        {SpriteEnum::SPR_TROO, 12, 8, nullptr, StateEnum::S_TROO_RAISE2, 0,
        0}},
       {StateEnum::S_TROO_RAISE2,
        {SpriteEnum::SPR_TROO, 11, 8, nullptr, StateEnum::S_TROO_RAISE3, 0,
        0}},
       {StateEnum::S_TROO_RAISE3,
        {SpriteEnum::SPR_TROO, 10, 6, nullptr, StateEnum::S_TROO_RAISE4, 0,
        0}},
       {StateEnum::S_TROO_RAISE4,
        {SpriteEnum::SPR_TROO, 9, 6, nullptr, StateEnum::S_TROO_RAISE5, 0,
        0}},
       {StateEnum::S_TROO_RAISE5,
        {SpriteEnum::SPR_TROO, 8, 6, nullptr, StateEnum::S_TROO_RUN1, 0, 0}},
       {StateEnum::S_SARG_STND,
        {SpriteEnum::SPR_SARG, 0, 10, action::look, StateEnum::S_SARG_STND2,
        0,
         0}},
       {StateEnum::S_SARG_STND2,
        {SpriteEnum::SPR_SARG, 1, 10, action::look, StateEnum::S_SARG_STND,
        0, 0}},
       {StateEnum::S_SARG_RUN1,
        {SpriteEnum::SPR_SARG, 0, 2, action::chase, StateEnum::S_SARG_RUN2,
        0, 0}},
       {StateEnum::S_SARG_RUN2,
        {SpriteEnum::SPR_SARG, 0, 2, action::chase, StateEnum::S_SARG_RUN3,
        0, 0}},
       {StateEnum::S_SARG_RUN3,
        {SpriteEnum::SPR_SARG, 1, 2, action::chase, StateEnum::S_SARG_RUN4,
        0, 0}},
       {StateEnum::S_SARG_RUN4,
        {SpriteEnum::SPR_SARG, 1, 2, action::chase, StateEnum::S_SARG_RUN5,
        0, 0}},
       {StateEnum::S_SARG_RUN5,
        {SpriteEnum::SPR_SARG, 2, 2, action::chase, StateEnum::S_SARG_RUN6,
        0, 0}},
       {StateEnum::S_SARG_RUN6,
        {SpriteEnum::SPR_SARG, 2, 2, action::chase, StateEnum::S_SARG_RUN7,
        0, 0}},
       {StateEnum::S_SARG_RUN7,
        {SpriteEnum::SPR_SARG, 3, 2, action::chase, StateEnum::S_SARG_RUN8,
        0, 0}},
       {StateEnum::S_SARG_RUN8,
        {SpriteEnum::SPR_SARG, 3, 2, action::chase, StateEnum::S_SARG_RUN1,
        0, 0}},
       {StateEnum::S_SARG_ATK1,
        {SpriteEnum::SPR_SARG, 4, 8, action::faceTarget,
        StateEnum::S_SARG_ATK2, 0,
         0}},
       {StateEnum::S_SARG_ATK2,
        {SpriteEnum::SPR_SARG, 5, 8, action::faceTarget,
        StateEnum::S_SARG_ATK3, 0,
         0}},
       {StateEnum::S_SARG_ATK3,
        {SpriteEnum::SPR_SARG, 6, 8, action::sargAttack,
        StateEnum::S_SARG_RUN1, 0,
         0}},
       {StateEnum::S_SARG_PAIN,
        {SpriteEnum::SPR_SARG, 7, 2, nullptr, StateEnum::S_SARG_PAIN2, 0,
        0}},
       {StateEnum::S_SARG_PAIN2,
        {SpriteEnum::SPR_SARG, 7, 2, action::pain, StateEnum::S_SARG_RUN1, 0,
        0}},
       {StateEnum::S_SARG_DIE1,
        {SpriteEnum::SPR_SARG, 8, 8, nullptr, StateEnum::S_SARG_DIE2, 0, 0}},
       {StateEnum::S_SARG_DIE2,
        {SpriteEnum::SPR_SARG, 9, 8, action::scream, StateEnum::S_SARG_DIE3,
        0,
         0}},
       {StateEnum::S_SARG_DIE3,
        {SpriteEnum::SPR_SARG, 10, 4, nullptr, StateEnum::S_SARG_DIE4, 0,
        0}},
       {StateEnum::S_SARG_DIE4,
        {SpriteEnum::SPR_SARG, 11, 4, action::fall, StateEnum::S_SARG_DIE5,
        0, 0}},
       {StateEnum::S_SARG_DIE5,
        {SpriteEnum::SPR_SARG, 12, 4, nullptr, StateEnum::S_SARG_DIE6, 0,
        0}},
       {StateEnum::S_SARG_DIE6,
        {SpriteEnum::SPR_SARG, 13, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SARG_RAISE1,
        {SpriteEnum::SPR_SARG, 13, 5, nullptr, StateEnum::S_SARG_RAISE2, 0,
        0}},
       {StateEnum::S_SARG_RAISE2,
        {SpriteEnum::SPR_SARG, 12, 5, nullptr, StateEnum::S_SARG_RAISE3, 0,
        0}},
       {StateEnum::S_SARG_RAISE3,
        {SpriteEnum::SPR_SARG, 11, 5, nullptr, StateEnum::S_SARG_RAISE4, 0,
        0}},
       {StateEnum::S_SARG_RAISE4,
        {SpriteEnum::SPR_SARG, 10, 5, nullptr, StateEnum::S_SARG_RAISE5, 0,
        0}},
       {StateEnum::S_SARG_RAISE5,
        {SpriteEnum::SPR_SARG, 9, 5, nullptr, StateEnum::S_SARG_RAISE6, 0,
        0}},
       {StateEnum::S_SARG_RAISE6,
        {SpriteEnum::SPR_SARG, 8, 5, nullptr, StateEnum::S_SARG_RUN1, 0, 0}},
       {StateEnum::S_HEAD_STND,
        {SpriteEnum::SPR_HEAD, 0, 10, action::look, StateEnum::S_HEAD_STND,
        0, 0}},
       {StateEnum::S_HEAD_RUN1,
        {SpriteEnum::SPR_HEAD, 0, 3, action::chase, StateEnum::S_HEAD_RUN1,
        0, 0}},
       {StateEnum::S_HEAD_ATK1,
        {SpriteEnum::SPR_HEAD, 1, 5, action::faceTarget,
        StateEnum::S_HEAD_ATK2, 0,
         0}},
       {StateEnum::S_HEAD_ATK2,
        {SpriteEnum::SPR_HEAD, 2, 5, action::faceTarget,
        StateEnum::S_HEAD_ATK3, 0,
         0}},
       {StateEnum::S_HEAD_ATK3,
        {SpriteEnum::SPR_HEAD, 32771, 5, action::headAttack,
         StateEnum::S_HEAD_RUN1, 0, 0}},
       {StateEnum::S_HEAD_PAIN,
        {SpriteEnum::SPR_HEAD, 4, 3, nullptr, StateEnum::S_HEAD_PAIN2, 0,
        0}},
       {StateEnum::S_HEAD_PAIN2,
        {SpriteEnum::SPR_HEAD, 4, 3, action::pain, StateEnum::S_HEAD_PAIN3,
        0, 0}},
       {StateEnum::S_HEAD_PAIN3,
        {SpriteEnum::SPR_HEAD, 5, 6, nullptr, StateEnum::S_HEAD_RUN1, 0, 0}},
       {StateEnum::S_HEAD_DIE1,
        {SpriteEnum::SPR_HEAD, 6, 8, nullptr, StateEnum::S_HEAD_DIE2, 0, 0}},
       {StateEnum::S_HEAD_DIE2,
        {SpriteEnum::SPR_HEAD, 7, 8, action::scream, StateEnum::S_HEAD_DIE3,
        0,
         0}},
       {StateEnum::S_HEAD_DIE3,
        {SpriteEnum::SPR_HEAD, 8, 8, nullptr, StateEnum::S_HEAD_DIE4, 0, 0}},
       {StateEnum::S_HEAD_DIE4,
        {SpriteEnum::SPR_HEAD, 9, 8, nullptr, StateEnum::S_HEAD_DIE5, 0, 0}},
       {StateEnum::S_HEAD_DIE5,
        {SpriteEnum::SPR_HEAD, 10, 8, action::fall, StateEnum::S_HEAD_DIE6,
        0, 0}},
       {StateEnum::S_HEAD_DIE6,
        {SpriteEnum::SPR_HEAD, 11, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HEAD_RAISE1,
        {SpriteEnum::SPR_HEAD, 11, 8, nullptr, StateEnum::S_HEAD_RAISE2, 0,
        0}},
       {StateEnum::S_HEAD_RAISE2,
        {SpriteEnum::SPR_HEAD, 10, 8, nullptr, StateEnum::S_HEAD_RAISE3, 0,
        0}},
       {StateEnum::S_HEAD_RAISE3,
        {SpriteEnum::SPR_HEAD, 9, 8, nullptr, StateEnum::S_HEAD_RAISE4, 0,
        0}},
       {StateEnum::S_HEAD_RAISE4,
        {SpriteEnum::SPR_HEAD, 8, 8, nullptr, StateEnum::S_HEAD_RAISE5, 0,
        0}},
       {StateEnum::S_HEAD_RAISE5,
        {SpriteEnum::SPR_HEAD, 7, 8, nullptr, StateEnum::S_HEAD_RAISE6, 0,
        0}},
       {StateEnum::S_HEAD_RAISE6,
        {SpriteEnum::SPR_HEAD, 6, 8, nullptr, StateEnum::S_HEAD_RUN1, 0, 0}},
       {StateEnum::S_BRBALL1,
        {SpriteEnum::SPR_BAL7, 32768, 4, nullptr, StateEnum::S_BRBALL2, 0,
        0}},
       {StateEnum::S_BRBALL2,
        {SpriteEnum::SPR_BAL7, 32769, 4, nullptr, StateEnum::S_BRBALL1, 0,
        0}},
       {StateEnum::S_BRBALLX1,
        {SpriteEnum::SPR_BAL7, 32770, 6, nullptr, StateEnum::S_BRBALLX2, 0,
        0}},
       {StateEnum::S_BRBALLX2,
        {SpriteEnum::SPR_BAL7, 32771, 6, nullptr, StateEnum::S_BRBALLX3, 0,
        0}},
       {StateEnum::S_BRBALLX3,
        {SpriteEnum::SPR_BAL7, 32772, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BOSS_STND,
        {SpriteEnum::SPR_BOSS, 0, 10, action::look, StateEnum::S_BOSS_STND2,
        0,
         0}},
       {StateEnum::S_BOSS_STND2,
        {SpriteEnum::SPR_BOSS, 1, 10, action::look, StateEnum::S_BOSS_STND,
        0, 0}},
       {StateEnum::S_BOSS_RUN1,
        {SpriteEnum::SPR_BOSS, 0, 3, action::chase, StateEnum::S_BOSS_RUN2,
        0, 0}},
       {StateEnum::S_BOSS_RUN2,
        {SpriteEnum::SPR_BOSS, 0, 3, action::chase, StateEnum::S_BOSS_RUN3,
        0, 0}},
       {StateEnum::S_BOSS_RUN3,
        {SpriteEnum::SPR_BOSS, 1, 3, action::chase, StateEnum::S_BOSS_RUN4,
        0, 0}},
       {StateEnum::S_BOSS_RUN4,
        {SpriteEnum::SPR_BOSS, 1, 3, action::chase, StateEnum::S_BOSS_RUN5,
        0, 0}},
       {StateEnum::S_BOSS_RUN5,
        {SpriteEnum::SPR_BOSS, 2, 3, action::chase, StateEnum::S_BOSS_RUN6,
        0, 0}},
       {StateEnum::S_BOSS_RUN6,
        {SpriteEnum::SPR_BOSS, 2, 3, action::chase, StateEnum::S_BOSS_RUN7,
        0, 0}},
       {StateEnum::S_BOSS_RUN7,
        {SpriteEnum::SPR_BOSS, 3, 3, action::chase, StateEnum::S_BOSS_RUN8,
        0, 0}},
       {StateEnum::S_BOSS_RUN8,
        {SpriteEnum::SPR_BOSS, 3, 3, action::chase, StateEnum::S_BOSS_RUN1,
        0, 0}},
       {StateEnum::S_BOSS_ATK1,
        {SpriteEnum::SPR_BOSS, 4, 8, action::faceTarget,
        StateEnum::S_BOSS_ATK2, 0,
         0}},
       {StateEnum::S_BOSS_ATK2,
        {SpriteEnum::SPR_BOSS, 5, 8, action::faceTarget,
        StateEnum::S_BOSS_ATK3, 0,
         0}},
       {StateEnum::S_BOSS_ATK3,
        {SpriteEnum::SPR_BOSS, 6, 8, action::bruisAttack,
        StateEnum::S_BOSS_RUN1,
         0, 0}},
       {StateEnum::S_BOSS_PAIN,
        {SpriteEnum::SPR_BOSS, 7, 2, nullptr, StateEnum::S_BOSS_PAIN2, 0,
        0}},
       {StateEnum::S_BOSS_PAIN2,
        {SpriteEnum::SPR_BOSS, 7, 2, action::pain, StateEnum::S_BOSS_RUN1, 0,
        0}},
       {StateEnum::S_BOSS_DIE1,
        {SpriteEnum::SPR_BOSS, 8, 8, nullptr, StateEnum::S_BOSS_DIE2, 0, 0}},
       {StateEnum::S_BOSS_DIE2,
        {SpriteEnum::SPR_BOSS, 9, 8, action::scream, StateEnum::S_BOSS_DIE3,
        0,
         0}},
       {StateEnum::S_BOSS_DIE3,
        {SpriteEnum::SPR_BOSS, 10, 8, nullptr, StateEnum::S_BOSS_DIE4, 0,
        0}},
       {StateEnum::S_BOSS_DIE4,
        {SpriteEnum::SPR_BOSS, 11, 8, action::fall, StateEnum::S_BOSS_DIE5,
        0, 0}},
       {StateEnum::S_BOSS_DIE5,
        {SpriteEnum::SPR_BOSS, 12, 8, nullptr, StateEnum::S_BOSS_DIE6, 0,
        0}},
       {StateEnum::S_BOSS_DIE6,
        {SpriteEnum::SPR_BOSS, 13, 8, nullptr, StateEnum::S_BOSS_DIE7, 0,
        0}},
       {StateEnum::S_BOSS_DIE7,
        {SpriteEnum::SPR_BOSS, 14, -1, action::bossDeath, StateEnum::S_NULL,
        0,
         0}},
       {StateEnum::S_BOSS_RAISE1,
        {SpriteEnum::SPR_BOSS, 14, 8, nullptr, StateEnum::S_BOSS_RAISE2, 0,
        0}},
       {StateEnum::S_BOSS_RAISE2,
        {SpriteEnum::SPR_BOSS, 13, 8, nullptr, StateEnum::S_BOSS_RAISE3, 0,
        0}},
       {StateEnum::S_BOSS_RAISE3,
        {SpriteEnum::SPR_BOSS, 12, 8, nullptr, StateEnum::S_BOSS_RAISE4, 0,
        0}},
       {StateEnum::S_BOSS_RAISE4,
        {SpriteEnum::SPR_BOSS, 11, 8, nullptr, StateEnum::S_BOSS_RAISE5, 0,
        0}},
       {StateEnum::S_BOSS_RAISE5,
        {SpriteEnum::SPR_BOSS, 10, 8, nullptr, StateEnum::S_BOSS_RAISE6, 0,
        0}},
       {StateEnum::S_BOSS_RAISE6,
        {SpriteEnum::SPR_BOSS, 9, 8, nullptr, StateEnum::S_BOSS_RAISE7, 0,
        0}},
       {StateEnum::S_BOSS_RAISE7,
        {SpriteEnum::SPR_BOSS, 8, 8, nullptr, StateEnum::S_BOSS_RUN1, 0, 0}},
       {StateEnum::S_BOS2_STND,
        {SpriteEnum::SPR_BOS2, 0, 10, action::look, StateEnum::S_BOS2_STND2,
        0,
         0}},
       {StateEnum::S_BOS2_STND2,
        {SpriteEnum::SPR_BOS2, 1, 10, action::look, StateEnum::S_BOS2_STND,
        0, 0}},
       {StateEnum::S_BOS2_RUN1,
        {SpriteEnum::SPR_BOS2, 0, 3, action::chase, StateEnum::S_BOS2_RUN2,
        0, 0}},
       {StateEnum::S_BOS2_RUN2,
        {SpriteEnum::SPR_BOS2, 0, 3, action::chase, StateEnum::S_BOS2_RUN3,
        0, 0}},
       {StateEnum::S_BOS2_RUN3,
        {SpriteEnum::SPR_BOS2, 1, 3, action::chase, StateEnum::S_BOS2_RUN4,
        0, 0}},
       {StateEnum::S_BOS2_RUN4,
        {SpriteEnum::SPR_BOS2, 1, 3, action::chase, StateEnum::S_BOS2_RUN5,
        0, 0}},
       {StateEnum::S_BOS2_RUN5,
        {SpriteEnum::SPR_BOS2, 2, 3, action::chase, StateEnum::S_BOS2_RUN6,
        0, 0}},
       {StateEnum::S_BOS2_RUN6,
        {SpriteEnum::SPR_BOS2, 2, 3, action::chase, StateEnum::S_BOS2_RUN7,
        0, 0}},
       {StateEnum::S_BOS2_RUN7,
        {SpriteEnum::SPR_BOS2, 3, 3, action::chase, StateEnum::S_BOS2_RUN8,
        0, 0}},
       {StateEnum::S_BOS2_RUN8,
        {SpriteEnum::SPR_BOS2, 3, 3, action::chase, StateEnum::S_BOS2_RUN1,
        0, 0}},
       {StateEnum::S_BOS2_ATK1,
        {SpriteEnum::SPR_BOS2, 4, 8, action::faceTarget,
        StateEnum::S_BOS2_ATK2, 0,
         0}},
       {StateEnum::S_BOS2_ATK2,
        {SpriteEnum::SPR_BOS2, 5, 8, action::faceTarget,
        StateEnum::S_BOS2_ATK3, 0,
         0}},
       {StateEnum::S_BOS2_ATK3,
        {SpriteEnum::SPR_BOS2, 6, 8, action::bruisAttack,
        StateEnum::S_BOS2_RUN1,
         0, 0}},
       {StateEnum::S_BOS2_PAIN,
        {SpriteEnum::SPR_BOS2, 7, 2, nullptr, StateEnum::S_BOS2_PAIN2, 0,
        0}},
       {StateEnum::S_BOS2_PAIN2,
        {SpriteEnum::SPR_BOS2, 7, 2, action::pain, StateEnum::S_BOS2_RUN1, 0,
        0}},
       {StateEnum::S_BOS2_DIE1,
        {SpriteEnum::SPR_BOS2, 8, 8, nullptr, StateEnum::S_BOS2_DIE2, 0, 0}},
       {StateEnum::S_BOS2_DIE2,
        {SpriteEnum::SPR_BOS2, 9, 8, action::scream, StateEnum::S_BOS2_DIE3,
        0,
         0}},
       {StateEnum::S_BOS2_DIE3,
        {SpriteEnum::SPR_BOS2, 10, 8, nullptr, StateEnum::S_BOS2_DIE4, 0,
        0}},
       {StateEnum::S_BOS2_DIE4,
        {SpriteEnum::SPR_BOS2, 11, 8, action::fall, StateEnum::S_BOS2_DIE5,
        0, 0}},
       {StateEnum::S_BOS2_DIE5,
        {SpriteEnum::SPR_BOS2, 12, 8, nullptr, StateEnum::S_BOS2_DIE6, 0,
        0}},
       {StateEnum::S_BOS2_DIE6,
        {SpriteEnum::SPR_BOS2, 13, 8, nullptr, StateEnum::S_BOS2_DIE7, 0,
        0}},
       {StateEnum::S_BOS2_DIE7,
        {SpriteEnum::SPR_BOS2, 14, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BOS2_RAISE1,
        {SpriteEnum::SPR_BOS2, 14, 8, nullptr, StateEnum::S_BOS2_RAISE2, 0,
        0}},
       {StateEnum::S_BOS2_RAISE2,
        {SpriteEnum::SPR_BOS2, 13, 8, nullptr, StateEnum::S_BOS2_RAISE3, 0,
        0}},
       {StateEnum::S_BOS2_RAISE3,
        {SpriteEnum::SPR_BOS2, 12, 8, nullptr, StateEnum::S_BOS2_RAISE4, 0,
        0}},
       {StateEnum::S_BOS2_RAISE4,
        {SpriteEnum::SPR_BOS2, 11, 8, nullptr, StateEnum::S_BOS2_RAISE5, 0,
        0}},
       {StateEnum::S_BOS2_RAISE5,
        {SpriteEnum::SPR_BOS2, 10, 8, nullptr, StateEnum::S_BOS2_RAISE6, 0,
        0}},
       {StateEnum::S_BOS2_RAISE6,
        {SpriteEnum::SPR_BOS2, 9, 8, nullptr, StateEnum::S_BOS2_RAISE7, 0,
        0}},
       {StateEnum::S_BOS2_RAISE7,
        {SpriteEnum::SPR_BOS2, 8, 8, nullptr, StateEnum::S_BOS2_RUN1, 0, 0}},
       {StateEnum::S_SKULL_STND,
        {SpriteEnum::SPR_SKUL, 32768, 10, action::look,
        StateEnum::S_SKULL_STND2,
         0, 0}},
       {StateEnum::S_SKULL_STND2,
        {SpriteEnum::SPR_SKUL, 32769, 10, action::look,
        StateEnum::S_SKULL_STND, 0,
         0}},
       {StateEnum::S_SKULL_RUN1,
        {SpriteEnum::SPR_SKUL, 32768, 6, action::chase,
        StateEnum::S_SKULL_RUN2, 0,
         0}},
       {StateEnum::S_SKULL_RUN2,
        {SpriteEnum::SPR_SKUL, 32769, 6, action::chase,
        StateEnum::S_SKULL_RUN1, 0,
         0}},
       {StateEnum::S_SKULL_ATK1,
        {SpriteEnum::SPR_SKUL, 32770, 10, action::faceTarget,
         StateEnum::S_SKULL_ATK2, 0, 0}},
       {StateEnum::S_SKULL_ATK2,
        {SpriteEnum::SPR_SKUL, 32771, 4, action::skullAttack,
         StateEnum::S_SKULL_ATK3, 0, 0}},
       {StateEnum::S_SKULL_ATK3,
        {SpriteEnum::SPR_SKUL, 32770, 4, nullptr, StateEnum::S_SKULL_ATK4, 0,
        0}},
       {StateEnum::S_SKULL_ATK4,
        {SpriteEnum::SPR_SKUL, 32771, 4, nullptr, StateEnum::S_SKULL_ATK3, 0,
        0}},
       {StateEnum::S_SKULL_PAIN,
        {SpriteEnum::SPR_SKUL, 32772, 3, nullptr, StateEnum::S_SKULL_PAIN2,
        0, 0}},
       {StateEnum::S_SKULL_PAIN2,
        {SpriteEnum::SPR_SKUL, 32772, 3, action::pain,
        StateEnum::S_SKULL_RUN1, 0,
         0}},
       {StateEnum::S_SKULL_DIE1,
        {SpriteEnum::SPR_SKUL, 32773, 6, nullptr, StateEnum::S_SKULL_DIE2, 0,
        0}},
       {StateEnum::S_SKULL_DIE2,
        {SpriteEnum::SPR_SKUL, 32774, 6, action::scream,
        StateEnum::S_SKULL_DIE3,
         0, 0}},
       {StateEnum::S_SKULL_DIE3,
        {SpriteEnum::SPR_SKUL, 32775, 6, nullptr, StateEnum::S_SKULL_DIE4, 0,
        0}},
       {StateEnum::S_SKULL_DIE4,
        {SpriteEnum::SPR_SKUL, 32776, 6, action::fall,
        StateEnum::S_SKULL_DIE5, 0,
         0}},
       {StateEnum::S_SKULL_DIE5,
        {SpriteEnum::SPR_SKUL, 9, 6, nullptr, StateEnum::S_SKULL_DIE6, 0,
        0}},
       {StateEnum::S_SKULL_DIE6,
        {SpriteEnum::SPR_SKUL, 10, 6, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SPID_STND,
        {SpriteEnum::SPR_SPID, 0, 10, action::look, StateEnum::S_SPID_STND2,
        0,
         0}},
       {StateEnum::S_SPID_STND2,
        {SpriteEnum::SPR_SPID, 1, 10, action::look, StateEnum::S_SPID_STND,
        0, 0}},
       {StateEnum::S_SPID_RUN1,
        {SpriteEnum::SPR_SPID, 0, 3, action::metal, StateEnum::S_SPID_RUN2,
        0, 0}},
       {StateEnum::S_SPID_RUN2,
        {SpriteEnum::SPR_SPID, 0, 3, action::chase, StateEnum::S_SPID_RUN3,
        0, 0}},
       {StateEnum::S_SPID_RUN3,
        {SpriteEnum::SPR_SPID, 1, 3, action::chase, StateEnum::S_SPID_RUN4,
        0, 0}},
       {StateEnum::S_SPID_RUN4,
        {SpriteEnum::SPR_SPID, 1, 3, action::chase, StateEnum::S_SPID_RUN5,
        0, 0}},
       {StateEnum::S_SPID_RUN5,
        {SpriteEnum::SPR_SPID, 2, 3, action::metal, StateEnum::S_SPID_RUN6,
        0, 0}},
       {StateEnum::S_SPID_RUN6,
        {SpriteEnum::SPR_SPID, 2, 3, action::chase, StateEnum::S_SPID_RUN7,
        0, 0}},
       {StateEnum::S_SPID_RUN7,
        {SpriteEnum::SPR_SPID, 3, 3, action::chase, StateEnum::S_SPID_RUN8,
        0, 0}},
       {StateEnum::S_SPID_RUN8,
        {SpriteEnum::SPR_SPID, 3, 3, action::chase, StateEnum::S_SPID_RUN9,
        0, 0}},
       {StateEnum::S_SPID_RUN9,
        {SpriteEnum::SPR_SPID, 4, 3, action::metal, StateEnum::S_SPID_RUN10,
        0,
         0}},
       {StateEnum::S_SPID_RUN10,
        {SpriteEnum::SPR_SPID, 4, 3, action::chase, StateEnum::S_SPID_RUN11,
        0,
         0}},
       {StateEnum::S_SPID_RUN11,
        {SpriteEnum::SPR_SPID, 5, 3, action::chase, StateEnum::S_SPID_RUN12,
        0,
         0}},
       {StateEnum::S_SPID_RUN12,
        {SpriteEnum::SPR_SPID, 5, 3, action::chase, StateEnum::S_SPID_RUN1,
        0, 0}},
       {StateEnum::S_SPID_ATK1,
        {SpriteEnum::SPR_SPID, 32768, 20, action::faceTarget,
         StateEnum::S_SPID_ATK2, 0, 0}},
       {StateEnum::S_SPID_ATK2,
        {SpriteEnum::SPR_SPID, 32774, 4, action::sPosAttack,
         StateEnum::S_SPID_ATK3, 0, 0}},
       {StateEnum::S_SPID_ATK3,
        {SpriteEnum::SPR_SPID, 32775, 4, action::sPosAttack,
         StateEnum::S_SPID_ATK4, 0, 0}},
       {StateEnum::S_SPID_ATK4,
        {SpriteEnum::SPR_SPID, 32775, 1, action::spidRefire,
         StateEnum::S_SPID_ATK2, 0, 0}},
       {StateEnum::S_SPID_PAIN,
        {SpriteEnum::SPR_SPID, 8, 3, nullptr, StateEnum::S_SPID_PAIN2, 0,
        0}},
       {StateEnum::S_SPID_PAIN2,
        {SpriteEnum::SPR_SPID, 8, 3, action::pain, StateEnum::S_SPID_RUN1, 0,
        0}},
       {StateEnum::S_SPID_DIE1,
        {SpriteEnum::SPR_SPID, 9, 20, action::scream, StateEnum::S_SPID_DIE2,
        0,
         0}},
       {StateEnum::S_SPID_DIE2,
        {SpriteEnum::SPR_SPID, 10, 10, action::fall, StateEnum::S_SPID_DIE3,
        0,
         0}},
       {StateEnum::S_SPID_DIE3,
        {SpriteEnum::SPR_SPID, 11, 10, nullptr, StateEnum::S_SPID_DIE4, 0,
        0}},
       {StateEnum::S_SPID_DIE4,
        {SpriteEnum::SPR_SPID, 12, 10, nullptr, StateEnum::S_SPID_DIE5, 0,
        0}},
       {StateEnum::S_SPID_DIE5,
        {SpriteEnum::SPR_SPID, 13, 10, nullptr, StateEnum::S_SPID_DIE6, 0,
        0}},
       {StateEnum::S_SPID_DIE6,
        {SpriteEnum::SPR_SPID, 14, 10, nullptr, StateEnum::S_SPID_DIE7, 0,
        0}},
       {StateEnum::S_SPID_DIE7,
        {SpriteEnum::SPR_SPID, 15, 10, nullptr, StateEnum::S_SPID_DIE8, 0,
        0}},
       {StateEnum::S_SPID_DIE8,
        {SpriteEnum::SPR_SPID, 16, 10, nullptr, StateEnum::S_SPID_DIE9, 0,
        0}},
       {StateEnum::S_SPID_DIE9,
        {SpriteEnum::SPR_SPID, 17, 10, nullptr, StateEnum::S_SPID_DIE10, 0,
        0}},
       {StateEnum::S_SPID_DIE10,
        {SpriteEnum::SPR_SPID, 18, 30, nullptr, StateEnum::S_SPID_DIE11, 0,
        0}},
       {StateEnum::S_SPID_DIE11,
        {SpriteEnum::SPR_SPID, 18, -1, action::bossDeath, StateEnum::S_NULL,
        0,
         0}},
       {StateEnum::S_BSPI_STND,
        {SpriteEnum::SPR_BSPI, 0, 10, action::look, StateEnum::S_BSPI_STND2,
        0,
         0}},
       {StateEnum::S_BSPI_STND2,
        {SpriteEnum::SPR_BSPI, 1, 10, action::look, StateEnum::S_BSPI_STND,
        0, 0}},
       {StateEnum::S_BSPI_SIGHT,
        {SpriteEnum::SPR_BSPI, 0, 20, nullptr, StateEnum::S_BSPI_RUN1, 0,
        0}},
       {StateEnum::S_BSPI_RUN1,
        {SpriteEnum::SPR_BSPI, 0, 3, action::babyMetal,
        StateEnum::S_BSPI_RUN2, 0,
         0}},
       {StateEnum::S_BSPI_RUN2,
        {SpriteEnum::SPR_BSPI, 0, 3, action::chase, StateEnum::S_BSPI_RUN3,
        0, 0}},
       {StateEnum::S_BSPI_RUN3,
        {SpriteEnum::SPR_BSPI, 1, 3, action::chase, StateEnum::S_BSPI_RUN4,
        0, 0}},
       {StateEnum::S_BSPI_RUN4,
        {SpriteEnum::SPR_BSPI, 1, 3, action::chase, StateEnum::S_BSPI_RUN5,
        0, 0}},
       {StateEnum::S_BSPI_RUN5,
        {SpriteEnum::SPR_BSPI, 2, 3, action::chase, StateEnum::S_BSPI_RUN6,
        0, 0}},
       {StateEnum::S_BSPI_RUN6,
        {SpriteEnum::SPR_BSPI, 2, 3, action::chase, StateEnum::S_BSPI_RUN7,
        0, 0}},
       {StateEnum::S_BSPI_RUN7,
        {SpriteEnum::SPR_BSPI, 3, 3, action::babyMetal,
        StateEnum::S_BSPI_RUN8, 0,
         0}},
       {StateEnum::S_BSPI_RUN8,
        {SpriteEnum::SPR_BSPI, 3, 3, action::chase, StateEnum::S_BSPI_RUN9,
        0, 0}},
       {StateEnum::S_BSPI_RUN9,
        {SpriteEnum::SPR_BSPI, 4, 3, action::chase, StateEnum::S_BSPI_RUN10,
        0,
         0}},
       {StateEnum::S_BSPI_RUN10,
        {SpriteEnum::SPR_BSPI, 4, 3, action::chase, StateEnum::S_BSPI_RUN11,
        0,
         0}},
       {StateEnum::S_BSPI_RUN11,
        {SpriteEnum::SPR_BSPI, 5, 3, action::chase, StateEnum::S_BSPI_RUN12,
        0,
         0}},
       {StateEnum::S_BSPI_RUN12,
        {SpriteEnum::SPR_BSPI, 5, 3, action::chase, StateEnum::S_BSPI_RUN1,
        0, 0}},
       {StateEnum::S_BSPI_ATK1,
        {SpriteEnum::SPR_BSPI, 32768, 20, action::faceTarget,
         StateEnum::S_BSPI_ATK2, 0, 0}},
       {StateEnum::S_BSPI_ATK2,
        {SpriteEnum::SPR_BSPI, 32774, 4, action::bspiAttack,
         StateEnum::S_BSPI_ATK3, 0, 0}},
       {StateEnum::S_BSPI_ATK3,
        {SpriteEnum::SPR_BSPI, 32775, 4, nullptr, StateEnum::S_BSPI_ATK4, 0,
        0}},
       {StateEnum::S_BSPI_ATK4,
        {SpriteEnum::SPR_BSPI, 32775, 1, action::spidRefire,
         StateEnum::S_BSPI_ATK2, 0, 0}},
       {StateEnum::S_BSPI_PAIN,
        {SpriteEnum::SPR_BSPI, 8, 3, nullptr, StateEnum::S_BSPI_PAIN2, 0,
        0}},
       {StateEnum::S_BSPI_PAIN2,
        {SpriteEnum::SPR_BSPI, 8, 3, action::pain, StateEnum::S_BSPI_RUN1, 0,
        0}},
       {StateEnum::S_BSPI_DIE1,
        {SpriteEnum::SPR_BSPI, 9, 20, action::scream, StateEnum::S_BSPI_DIE2,
        0,
         0}},
       {StateEnum::S_BSPI_DIE2,
        {SpriteEnum::SPR_BSPI, 10, 7, action::fall, StateEnum::S_BSPI_DIE3,
        0, 0}},
       {StateEnum::S_BSPI_DIE3,
        {SpriteEnum::SPR_BSPI, 11, 7, nullptr, StateEnum::S_BSPI_DIE4, 0,
        0}},
       {StateEnum::S_BSPI_DIE4,
        {SpriteEnum::SPR_BSPI, 12, 7, nullptr, StateEnum::S_BSPI_DIE5, 0,
        0}},
       {StateEnum::S_BSPI_DIE5,
        {SpriteEnum::SPR_BSPI, 13, 7, nullptr, StateEnum::S_BSPI_DIE6, 0,
        0}},
       {StateEnum::S_BSPI_DIE6,
        {SpriteEnum::SPR_BSPI, 14, 7, nullptr, StateEnum::S_BSPI_DIE7, 0,
        0}},
       {StateEnum::S_BSPI_DIE7,
        {SpriteEnum::SPR_BSPI, 15, -1, action::bossDeath, StateEnum::S_NULL,
        0,
         0}},
       {StateEnum::S_BSPI_RAISE1,
        {SpriteEnum::SPR_BSPI, 15, 5, nullptr, StateEnum::S_BSPI_RAISE2, 0,
        0}},
       {StateEnum::S_BSPI_RAISE2,
        {SpriteEnum::SPR_BSPI, 14, 5, nullptr, StateEnum::S_BSPI_RAISE3, 0,
        0}},
       {StateEnum::S_BSPI_RAISE3,
        {SpriteEnum::SPR_BSPI, 13, 5, nullptr, StateEnum::S_BSPI_RAISE4, 0,
        0}},
       {StateEnum::S_BSPI_RAISE4,
        {SpriteEnum::SPR_BSPI, 12, 5, nullptr, StateEnum::S_BSPI_RAISE5, 0,
        0}},
       {StateEnum::S_BSPI_RAISE5,
        {SpriteEnum::SPR_BSPI, 11, 5, nullptr, StateEnum::S_BSPI_RAISE6, 0,
        0}},
       {StateEnum::S_BSPI_RAISE6,
        {SpriteEnum::SPR_BSPI, 10, 5, nullptr, StateEnum::S_BSPI_RAISE7, 0,
        0}},
       {StateEnum::S_BSPI_RAISE7,
        {SpriteEnum::SPR_BSPI, 9, 5, nullptr, StateEnum::S_BSPI_RUN1, 0, 0}},
       {StateEnum::S_ARACH_PLAZ,
        {SpriteEnum::SPR_APLS, 32768, 5, nullptr, StateEnum::S_ARACH_PLAZ2,
        0, 0}},
       {StateEnum::S_ARACH_PLAZ2,
        {SpriteEnum::SPR_APLS, 32769, 5, nullptr, StateEnum::S_ARACH_PLAZ, 0,
        0}},
       {StateEnum::S_ARACH_PLEX,
        {SpriteEnum::SPR_APBX, 32768, 5, nullptr, StateEnum::S_ARACH_PLEX2,
        0, 0}},
       {StateEnum::S_ARACH_PLEX2,
        {SpriteEnum::SPR_APBX, 32769, 5, nullptr, StateEnum::S_ARACH_PLEX3,
        0, 0}},
       {StateEnum::S_ARACH_PLEX3,
        {SpriteEnum::SPR_APBX, 32770, 5, nullptr, StateEnum::S_ARACH_PLEX4,
        0, 0}},
       {StateEnum::S_ARACH_PLEX4,
        {SpriteEnum::SPR_APBX, 32771, 5, nullptr, StateEnum::S_ARACH_PLEX5,
        0, 0}},
       {StateEnum::S_ARACH_PLEX5,
        {SpriteEnum::SPR_APBX, 32772, 5, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CYBER_STND,
        {SpriteEnum::SPR_CYBR, 0, 10, action::look, StateEnum::S_CYBER_STND2,
        0,
         0}},
       {StateEnum::S_CYBER_STND2,
        {SpriteEnum::SPR_CYBR, 1, 10, action::look, StateEnum::S_CYBER_STND,
        0,
         0}},
       {StateEnum::S_CYBER_RUN1,
        {SpriteEnum::SPR_CYBR, 0, 3, action::hoof, StateEnum::S_CYBER_RUN2,
        0, 0}},
       {StateEnum::S_CYBER_RUN2,
        {SpriteEnum::SPR_CYBR, 0, 3, action::chase, StateEnum::S_CYBER_RUN3,
        0,
         0}},
       {StateEnum::S_CYBER_RUN3,
        {SpriteEnum::SPR_CYBR, 1, 3, action::chase, StateEnum::S_CYBER_RUN4,
        0,
         0}},
       {StateEnum::S_CYBER_RUN4,
        {SpriteEnum::SPR_CYBR, 1, 3, action::chase, StateEnum::S_CYBER_RUN5,
        0,
         0}},
       {StateEnum::S_CYBER_RUN5,
        {SpriteEnum::SPR_CYBR, 2, 3, action::chase, StateEnum::S_CYBER_RUN6,
        0,
         0}},
       {StateEnum::S_CYBER_RUN6,
        {SpriteEnum::SPR_CYBR, 2, 3, action::chase, StateEnum::S_CYBER_RUN7,
        0,
         0}},
       {StateEnum::S_CYBER_RUN7,
        {SpriteEnum::SPR_CYBR, 3, 3, action::metal, StateEnum::S_CYBER_RUN8,
        0,
         0}},
       {StateEnum::S_CYBER_RUN8,
        {SpriteEnum::SPR_CYBR, 3, 3, action::chase, StateEnum::S_CYBER_RUN1,
        0,
         0}},
       {StateEnum::S_CYBER_ATK1,
        {SpriteEnum::SPR_CYBR, 4, 6, action::faceTarget,
        StateEnum::S_CYBER_ATK2,
         0, 0}},
       {StateEnum::S_CYBER_ATK2,
        {SpriteEnum::SPR_CYBR, 5, 12, action::cyberAttack,
        StateEnum::S_CYBER_ATK3,
         0, 0}},
       {StateEnum::S_CYBER_ATK3,
        {SpriteEnum::SPR_CYBR, 4, 12, action::faceTarget,
        StateEnum::S_CYBER_ATK4,
         0, 0}},
       {StateEnum::S_CYBER_ATK4,
        {SpriteEnum::SPR_CYBR, 5, 12, action::cyberAttack,
        StateEnum::S_CYBER_ATK5,
         0, 0}},
       {StateEnum::S_CYBER_ATK5,
        {SpriteEnum::SPR_CYBR, 4, 12, action::faceTarget,
        StateEnum::S_CYBER_ATK6,
         0, 0}},
       {StateEnum::S_CYBER_ATK6,
        {SpriteEnum::SPR_CYBR, 5, 12, action::cyberAttack,
        StateEnum::S_CYBER_RUN1,
         0, 0}},
       {StateEnum::S_CYBER_PAIN,
        {SpriteEnum::SPR_CYBR, 6, 10, action::pain, StateEnum::S_CYBER_RUN1,
        0,
         0}},
       {StateEnum::S_CYBER_DIE1,
        {SpriteEnum::SPR_CYBR, 7, 10, nullptr, StateEnum::S_CYBER_DIE2, 0,
        0}},
       {StateEnum::S_CYBER_DIE2,
        {SpriteEnum::SPR_CYBR, 8, 10, action::scream,
        StateEnum::S_CYBER_DIE3, 0,
         0}},
       {StateEnum::S_CYBER_DIE3,
        {SpriteEnum::SPR_CYBR, 9, 10, nullptr, StateEnum::S_CYBER_DIE4, 0,
        0}},
       {StateEnum::S_CYBER_DIE4,
        {SpriteEnum::SPR_CYBR, 10, 10, nullptr, StateEnum::S_CYBER_DIE5, 0,
        0}},
       {StateEnum::S_CYBER_DIE5,
        {SpriteEnum::SPR_CYBR, 11, 10, nullptr, StateEnum::S_CYBER_DIE6, 0,
        0}},
       {StateEnum::S_CYBER_DIE6,
        {SpriteEnum::SPR_CYBR, 12, 10, action::fall, StateEnum::S_CYBER_DIE7,
        0,
         0}},
       {StateEnum::S_CYBER_DIE7,
        {SpriteEnum::SPR_CYBR, 13, 10, nullptr, StateEnum::S_CYBER_DIE8, 0,
        0}},
       {StateEnum::S_CYBER_DIE8,
        {SpriteEnum::SPR_CYBR, 14, 10, nullptr, StateEnum::S_CYBER_DIE9, 0,
        0}},
       {StateEnum::S_CYBER_DIE9,
        {SpriteEnum::SPR_CYBR, 15, 30, nullptr, StateEnum::S_CYBER_DIE10, 0,
        0}},
       {StateEnum::S_CYBER_DIE10,
        {SpriteEnum::SPR_CYBR, 15, -1, action::bossDeath, StateEnum::S_NULL,
        0,
         0}},
       {StateEnum::S_PAIN_STND,
        {SpriteEnum::SPR_PAIN, 0, 10, action::look, StateEnum::S_PAIN_STND,
        0, 0}},
       {StateEnum::S_PAIN_RUN1,
        {SpriteEnum::SPR_PAIN, 0, 3, action::chase, StateEnum::S_PAIN_RUN2,
        0, 0}},
       {StateEnum::S_PAIN_RUN2,
        {SpriteEnum::SPR_PAIN, 0, 3, action::chase, StateEnum::S_PAIN_RUN3,
        0, 0}},
       {StateEnum::S_PAIN_RUN3,
        {SpriteEnum::SPR_PAIN, 1, 3, action::chase, StateEnum::S_PAIN_RUN4,
        0, 0}},
       {StateEnum::S_PAIN_RUN4,
        {SpriteEnum::SPR_PAIN, 1, 3, action::chase, StateEnum::S_PAIN_RUN5,
        0, 0}},
       {StateEnum::S_PAIN_RUN5,
        {SpriteEnum::SPR_PAIN, 2, 3, action::chase, StateEnum::S_PAIN_RUN6,
        0, 0}},
       {StateEnum::S_PAIN_RUN6,
        {SpriteEnum::SPR_PAIN, 2, 3, action::chase, StateEnum::S_PAIN_RUN1,
        0, 0}},
       {StateEnum::S_PAIN_ATK1,
        {SpriteEnum::SPR_PAIN, 3, 5, action::faceTarget,
        StateEnum::S_PAIN_ATK2, 0,
         0}},
       {StateEnum::S_PAIN_ATK2,
        {SpriteEnum::SPR_PAIN, 4, 5, action::faceTarget,
        StateEnum::S_PAIN_ATK3, 0,
         0}},
       {StateEnum::S_PAIN_ATK3,
        {SpriteEnum::SPR_PAIN, 32773, 5, action::faceTarget,
         StateEnum::S_PAIN_ATK4, 0, 0}},
       {StateEnum::S_PAIN_ATK4,
        {SpriteEnum::SPR_PAIN, 32773, 0, action::painAttack,
         StateEnum::S_PAIN_RUN1, 0, 0}},
       {StateEnum::S_PAIN_PAIN,
        {SpriteEnum::SPR_PAIN, 6, 6, nullptr, StateEnum::S_PAIN_PAIN2, 0,
        0}},
       {StateEnum::S_PAIN_PAIN2,
        {SpriteEnum::SPR_PAIN, 6, 6, action::pain, StateEnum::S_PAIN_RUN1, 0,
        0}},
       {StateEnum::S_PAIN_DIE1,
        {SpriteEnum::SPR_PAIN, 32775, 8, nullptr, StateEnum::S_PAIN_DIE2, 0,
        0}},
       {StateEnum::S_PAIN_DIE2,
        {SpriteEnum::SPR_PAIN, 32776, 8, action::scream,
        StateEnum::S_PAIN_DIE3, 0,
         0}},
       {StateEnum::S_PAIN_DIE3,
        {SpriteEnum::SPR_PAIN, 32777, 8, nullptr, StateEnum::S_PAIN_DIE4, 0,
        0}},
       {StateEnum::S_PAIN_DIE4,
        {SpriteEnum::SPR_PAIN, 32778, 8, nullptr, StateEnum::S_PAIN_DIE5, 0,
        0}},
       {StateEnum::S_PAIN_DIE5,
        {SpriteEnum::SPR_PAIN, 32779, 8, action::painDie,
        StateEnum::S_PAIN_DIE6,
         0, 0}},
       {StateEnum::S_PAIN_DIE6,
        {SpriteEnum::SPR_PAIN, 32780, 8, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PAIN_RAISE1,
        {SpriteEnum::SPR_PAIN, 12, 8, nullptr, StateEnum::S_PAIN_RAISE2, 0,
        0}},
       {StateEnum::S_PAIN_RAISE2,
        {SpriteEnum::SPR_PAIN, 11, 8, nullptr, StateEnum::S_PAIN_RAISE3, 0,
        0}},
       {StateEnum::S_PAIN_RAISE3,
        {SpriteEnum::SPR_PAIN, 10, 8, nullptr, StateEnum::S_PAIN_RAISE4, 0,
        0}},
       {StateEnum::S_PAIN_RAISE4,
        {SpriteEnum::SPR_PAIN, 9, 8, nullptr, StateEnum::S_PAIN_RAISE5, 0,
        0}},
       {StateEnum::S_PAIN_RAISE5,
        {SpriteEnum::SPR_PAIN, 8, 8, nullptr, StateEnum::S_PAIN_RAISE6, 0,
        0}},
       {StateEnum::S_PAIN_RAISE6,
        {SpriteEnum::SPR_PAIN, 7, 8, nullptr, StateEnum::S_PAIN_RUN1, 0, 0}},
       {StateEnum::S_SSWV_STND,
        {SpriteEnum::SPR_SSWV, 0, 10, action::look, StateEnum::S_SSWV_STND2,
        0,
         0}},
       {StateEnum::S_SSWV_STND2,
        {SpriteEnum::SPR_SSWV, 1, 10, action::look, StateEnum::S_SSWV_STND,
        0, 0}},
       {StateEnum::S_SSWV_RUN1,
        {SpriteEnum::SPR_SSWV, 0, 3, action::chase, StateEnum::S_SSWV_RUN2,
        0, 0}},
       {StateEnum::S_SSWV_RUN2,
        {SpriteEnum::SPR_SSWV, 0, 3, action::chase, StateEnum::S_SSWV_RUN3,
        0, 0}},
       {StateEnum::S_SSWV_RUN3,
        {SpriteEnum::SPR_SSWV, 1, 3, action::chase, StateEnum::S_SSWV_RUN4,
        0, 0}},
       {StateEnum::S_SSWV_RUN4,
        {SpriteEnum::SPR_SSWV, 1, 3, action::chase, StateEnum::S_SSWV_RUN5,
        0, 0}},
       {StateEnum::S_SSWV_RUN5,
        {SpriteEnum::SPR_SSWV, 2, 3, action::chase, StateEnum::S_SSWV_RUN6,
        0, 0}},
       {StateEnum::S_SSWV_RUN6,
        {SpriteEnum::SPR_SSWV, 2, 3, action::chase, StateEnum::S_SSWV_RUN7,
        0, 0}},
       {StateEnum::S_SSWV_RUN7,
        {SpriteEnum::SPR_SSWV, 3, 3, action::chase, StateEnum::S_SSWV_RUN8,
        0, 0}},
       {StateEnum::S_SSWV_RUN8,
        {SpriteEnum::SPR_SSWV, 3, 3, action::chase, StateEnum::S_SSWV_RUN1,
        0, 0}},
       {StateEnum::S_SSWV_ATK1,
        {SpriteEnum::SPR_SSWV, 4, 10, action::faceTarget,
        StateEnum::S_SSWV_ATK2,
         0, 0}},
       {StateEnum::S_SSWV_ATK2,
        {SpriteEnum::SPR_SSWV, 5, 10, action::faceTarget,
        StateEnum::S_SSWV_ATK3,
         0, 0}},
       {StateEnum::S_SSWV_ATK3,
        {SpriteEnum::SPR_SSWV, 32774, 4, action::cPosAttack,
         StateEnum::S_SSWV_ATK4, 0, 0}},
       {StateEnum::S_SSWV_ATK4,
        {SpriteEnum::SPR_SSWV, 5, 6, action::faceTarget,
        StateEnum::S_SSWV_ATK5, 0,
         0}},
       {StateEnum::S_SSWV_ATK5,
        {SpriteEnum::SPR_SSWV, 32774, 4, action::cPosAttack,
         StateEnum::S_SSWV_ATK6, 0, 0}},
       {StateEnum::S_SSWV_ATK6,
        {SpriteEnum::SPR_SSWV, 5, 1, action::cPosRefire,
        StateEnum::S_SSWV_ATK2, 0,
         0}},
       {StateEnum::S_SSWV_PAIN,
        {SpriteEnum::SPR_SSWV, 7, 3, nullptr, StateEnum::S_SSWV_PAIN2, 0,
        0}},
       {StateEnum::S_SSWV_PAIN2,
        {SpriteEnum::SPR_SSWV, 7, 3, action::pain, StateEnum::S_SSWV_RUN1, 0,
        0}},
       {StateEnum::S_SSWV_DIE1,
        {SpriteEnum::SPR_SSWV, 8, 5, nullptr, StateEnum::S_SSWV_DIE2, 0, 0}},
       {StateEnum::S_SSWV_DIE2,
        {SpriteEnum::SPR_SSWV, 9, 5, action::scream, StateEnum::S_SSWV_DIE3,
        0,
         0}},
       {StateEnum::S_SSWV_DIE3,
        {SpriteEnum::SPR_SSWV, 10, 5, action::fall, StateEnum::S_SSWV_DIE4,
        0, 0}},
       {StateEnum::S_SSWV_DIE4,
        {SpriteEnum::SPR_SSWV, 11, 5, nullptr, StateEnum::S_SSWV_DIE5, 0,
        0}},
       {StateEnum::S_SSWV_DIE5,
        {SpriteEnum::SPR_SSWV, 12, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SSWV_XDIE1,
        {SpriteEnum::SPR_SSWV, 13, 5, nullptr, StateEnum::S_SSWV_XDIE2, 0,
        0}},
       {StateEnum::S_SSWV_XDIE2,
        {SpriteEnum::SPR_SSWV, 14, 5, action::xScream,
        StateEnum::S_SSWV_XDIE3, 0,
         0}},
       {StateEnum::S_SSWV_XDIE3,
        {SpriteEnum::SPR_SSWV, 15, 5, action::fall, StateEnum::S_SSWV_XDIE4,
        0,
         0}},
       {StateEnum::S_SSWV_XDIE4,
        {SpriteEnum::SPR_SSWV, 16, 5, nullptr, StateEnum::S_SSWV_XDIE5, 0,
        0}},
       {StateEnum::S_SSWV_XDIE5,
        {SpriteEnum::SPR_SSWV, 17, 5, nullptr, StateEnum::S_SSWV_XDIE6, 0,
        0}},
       {StateEnum::S_SSWV_XDIE6,
        {SpriteEnum::SPR_SSWV, 18, 5, nullptr, StateEnum::S_SSWV_XDIE7, 0,
        0}},
       {StateEnum::S_SSWV_XDIE7,
        {SpriteEnum::SPR_SSWV, 19, 5, nullptr, StateEnum::S_SSWV_XDIE8, 0,
        0}},
       {StateEnum::S_SSWV_XDIE8,
        {SpriteEnum::SPR_SSWV, 20, 5, nullptr, StateEnum::S_SSWV_XDIE9, 0,
        0}},
       {StateEnum::S_SSWV_XDIE9,
        {SpriteEnum::SPR_SSWV, 21, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SSWV_RAISE1,
        {SpriteEnum::SPR_SSWV, 12, 5, nullptr, StateEnum::S_SSWV_RAISE2, 0,
        0}},
       {StateEnum::S_SSWV_RAISE2,
        {SpriteEnum::SPR_SSWV, 11, 5, nullptr, StateEnum::S_SSWV_RAISE3, 0,
        0}},
       {StateEnum::S_SSWV_RAISE3,
        {SpriteEnum::SPR_SSWV, 10, 5, nullptr, StateEnum::S_SSWV_RAISE4, 0,
        0}},
       {StateEnum::S_SSWV_RAISE4,
        {SpriteEnum::SPR_SSWV, 9, 5, nullptr, StateEnum::S_SSWV_RAISE5, 0,
        0}},
       {StateEnum::S_SSWV_RAISE5,
        {SpriteEnum::SPR_SSWV, 8, 5, nullptr, StateEnum::S_SSWV_RUN1, 0, 0}},
       {StateEnum::S_KEENSTND,
        {SpriteEnum::SPR_KEEN, 0, -1, nullptr, StateEnum::S_KEENSTND, 0, 0}},
       {StateEnum::S_COMMKEEN,
        {SpriteEnum::SPR_KEEN, 0, 6, nullptr, StateEnum::S_COMMKEEN2, 0, 0}},
       {StateEnum::S_COMMKEEN2,
        {SpriteEnum::SPR_KEEN, 1, 6, nullptr, StateEnum::S_COMMKEEN3, 0, 0}},
       {StateEnum::S_COMMKEEN3,
        {SpriteEnum::SPR_KEEN, 2, 6, action::scream, StateEnum::S_COMMKEEN4,
        0,
         0}},
       {StateEnum::S_COMMKEEN4,
        {SpriteEnum::SPR_KEEN, 3, 6, nullptr, StateEnum::S_COMMKEEN5, 0, 0}},
       {StateEnum::S_COMMKEEN5,
        {SpriteEnum::SPR_KEEN, 4, 6, nullptr, StateEnum::S_COMMKEEN6, 0, 0}},
       {StateEnum::S_COMMKEEN6,
        {SpriteEnum::SPR_KEEN, 5, 6, nullptr, StateEnum::S_COMMKEEN7, 0, 0}},
       {StateEnum::S_COMMKEEN7,
        {SpriteEnum::SPR_KEEN, 6, 6, nullptr, StateEnum::S_COMMKEEN8, 0, 0}},
       {StateEnum::S_COMMKEEN8,
        {SpriteEnum::SPR_KEEN, 7, 6, nullptr, StateEnum::S_COMMKEEN9, 0, 0}},
       {StateEnum::S_COMMKEEN9,
        {SpriteEnum::SPR_KEEN, 8, 6, nullptr, StateEnum::S_COMMKEEN10, 0,
        0}},
       {StateEnum::S_COMMKEEN10,
        {SpriteEnum::SPR_KEEN, 9, 6, nullptr, StateEnum::S_COMMKEEN11, 0,
        0}},
       {StateEnum::S_COMMKEEN11,
        {SpriteEnum::SPR_KEEN, 10, 6, action::keenDie,
        StateEnum::S_COMMKEEN12, 0,
         0}},
       {StateEnum::S_COMMKEEN12,
        {SpriteEnum::SPR_KEEN, 11, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_KEENPAIN,
        {SpriteEnum::SPR_KEEN, 12, 4, nullptr, StateEnum::S_KEENPAIN2, 0,
        0}},
       {StateEnum::S_KEENPAIN2,
        {SpriteEnum::SPR_KEEN, 12, 8, action::pain, StateEnum::S_KEENSTND, 0,
        0}},
       {StateEnum::S_BRAIN,
        {SpriteEnum::SPR_BBRN, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BRAIN_PAIN,
        {SpriteEnum::SPR_BBRN, 1, 36, action::brainPain, StateEnum::S_BRAIN,
        0,
         0}},
       {StateEnum::S_BRAIN_DIE1,
        {SpriteEnum::SPR_BBRN, 0, 100, action::brainScream,
         StateEnum::S_BRAIN_DIE2, 0, 0}},
       {StateEnum::S_BRAIN_DIE2,
        {SpriteEnum::SPR_BBRN, 0, 10, nullptr, StateEnum::S_BRAIN_DIE3, 0,
        0}},
       {StateEnum::S_BRAIN_DIE3,
        {SpriteEnum::SPR_BBRN, 0, 10, nullptr, StateEnum::S_BRAIN_DIE4, 0,
        0}},
       {StateEnum::S_BRAIN_DIE4,
        {SpriteEnum::SPR_BBRN, 0, -1, action::brainDie, StateEnum::S_NULL, 0,
        0}},
       {StateEnum::S_BRAINEYE,
        {SpriteEnum::SPR_SSWV, 0, 10, action::look, StateEnum::S_BRAINEYE, 0,
        0}},
       {StateEnum::S_BRAINEYESEE,
        {SpriteEnum::SPR_SSWV, 0, 181, action::brainAwake,
        StateEnum::S_BRAINEYE1,
         0, 0}},
       {StateEnum::S_BRAINEYE1,
        {SpriteEnum::SPR_SSWV, 0, 150, action::brainSpit,
        StateEnum::S_BRAINEYE1,
         0, 0}},
       {StateEnum::S_SPAWN1,
        {SpriteEnum::SPR_BOSF, 32768, 3, action::spawnSound,
        StateEnum::S_SPAWN2,
         0, 0}},
       {StateEnum::S_SPAWN2,
        {SpriteEnum::SPR_BOSF, 32769, 3, action::spawnFly,
        StateEnum::S_SPAWN3, 0,
         0}},
       {StateEnum::S_SPAWN3,
        {SpriteEnum::SPR_BOSF, 32770, 3, action::spawnFly,
        StateEnum::S_SPAWN4, 0,
         0}},
       {StateEnum::S_SPAWN4,
        {SpriteEnum::SPR_BOSF, 32771, 3, action::spawnFly,
        StateEnum::S_SPAWN1, 0,
         0}},
       {StateEnum::S_SPAWNFIRE1,
        {SpriteEnum::SPR_FIRE, 32768, 4, action::fire,
        StateEnum::S_SPAWNFIRE2, 0,
         0}},
       {StateEnum::S_SPAWNFIRE2,
        {SpriteEnum::SPR_FIRE, 32769, 4, action::fire,
        StateEnum::S_SPAWNFIRE3, 0,
         0}},
       {StateEnum::S_SPAWNFIRE3,
        {SpriteEnum::SPR_FIRE, 32770, 4, action::fire,
        StateEnum::S_SPAWNFIRE4, 0,
         0}},
       {StateEnum::S_SPAWNFIRE4,
        {SpriteEnum::SPR_FIRE, 32771, 4, action::fire,
        StateEnum::S_SPAWNFIRE5, 0,
         0}},
       {StateEnum::S_SPAWNFIRE5,
        {SpriteEnum::SPR_FIRE, 32772, 4, action::fire,
        StateEnum::S_SPAWNFIRE6, 0,
         0}},
       {StateEnum::S_SPAWNFIRE6,
        {SpriteEnum::SPR_FIRE, 32773, 4, action::fire,
        StateEnum::S_SPAWNFIRE7, 0,
         0}},
       {StateEnum::S_SPAWNFIRE7,
        {SpriteEnum::SPR_FIRE, 32774, 4, action::fire,
        StateEnum::S_SPAWNFIRE8, 0,
         0}},
       {StateEnum::S_SPAWNFIRE8,
        {SpriteEnum::SPR_FIRE, 32775, 4, action::fire, StateEnum::S_NULL, 0,
        0}},
       {StateEnum::S_BRAINEXPLODE1,
        {SpriteEnum::SPR_MISL, 32769, 10, nullptr,
        StateEnum::S_BRAINEXPLODE2, 0,
         0}},
       {StateEnum::S_BRAINEXPLODE2,
        {SpriteEnum::SPR_MISL, 32770, 10, nullptr,
        StateEnum::S_BRAINEXPLODE3, 0,
         0}},
       {StateEnum::S_BRAINEXPLODE3,
        {SpriteEnum::SPR_MISL, 32771, 10, action::brainExplode,
        StateEnum::S_NULL,
         0, 0}},
       {StateEnum::S_ARM1,
        {SpriteEnum::SPR_ARM1, 0, 6, nullptr, StateEnum::S_ARM1A, 0, 0}},
       {StateEnum::S_ARM1A,
        {SpriteEnum::SPR_ARM1, 32769, 7, nullptr, StateEnum::S_ARM1, 0, 0}},
       {StateEnum::S_ARM2,
        {SpriteEnum::SPR_ARM2, 0, 6, nullptr, StateEnum::S_ARM2A, 0, 0}},
       {StateEnum::S_ARM2A,
        {SpriteEnum::SPR_ARM2, 32769, 6, nullptr, StateEnum::S_ARM2, 0, 0}},
       {StateEnum::S_BAR1,
        {SpriteEnum::SPR_BAR1, 0, 6, nullptr, StateEnum::S_BAR2, 0, 0}},
       {StateEnum::S_BAR2,
        {SpriteEnum::SPR_BAR1, 1, 6, nullptr, StateEnum::S_BAR1, 0, 0}},
       {StateEnum::S_BEXP,
        {SpriteEnum::SPR_BEXP, 32768, 5, nullptr, StateEnum::S_BEXP2, 0, 0}},
       {StateEnum::S_BEXP2,
        {SpriteEnum::SPR_BEXP, 32769, 5, action::scream, StateEnum::S_BEXP3,
        0,
         0}},
       {StateEnum::S_BEXP3,
        {SpriteEnum::SPR_BEXP, 32770, 5, nullptr, StateEnum::S_BEXP4, 0, 0}},
       {StateEnum::S_BEXP4,
        {SpriteEnum::SPR_BEXP, 32771, 10, action::explode,
        StateEnum::S_BEXP5, 0,
         0}},
       {StateEnum::S_BEXP5,
        {SpriteEnum::SPR_BEXP, 32772, 10, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BBAR1,
        {SpriteEnum::SPR_FCAN, 32768, 4, nullptr, StateEnum::S_BBAR2, 0, 0}},
       {StateEnum::S_BBAR2,
        {SpriteEnum::SPR_FCAN, 32769, 4, nullptr, StateEnum::S_BBAR3, 0, 0}},
       {StateEnum::S_BBAR3,
        {SpriteEnum::SPR_FCAN, 32770, 4, nullptr, StateEnum::S_BBAR1, 0, 0}},
       {StateEnum::S_BON1,
        {SpriteEnum::SPR_BON1, 0, 6, nullptr, StateEnum::S_BON1A, 0, 0}},
       {StateEnum::S_BON1A,
        {SpriteEnum::SPR_BON1, 1, 6, nullptr, StateEnum::S_BON1B, 0, 0}},
       {StateEnum::S_BON1B,
        {SpriteEnum::SPR_BON1, 2, 6, nullptr, StateEnum::S_BON1C, 0, 0}},
       {StateEnum::S_BON1C,
        {SpriteEnum::SPR_BON1, 3, 6, nullptr, StateEnum::S_BON1D, 0, 0}},
       {StateEnum::S_BON1D,
        {SpriteEnum::SPR_BON1, 2, 6, nullptr, StateEnum::S_BON1E, 0, 0}},
       {StateEnum::S_BON1E,
        {SpriteEnum::SPR_BON1, 1, 6, nullptr, StateEnum::S_BON1, 0, 0}},
       {StateEnum::S_BON2,
        {SpriteEnum::SPR_BON2, 0, 6, nullptr, StateEnum::S_BON2A, 0, 0}},
       {StateEnum::S_BON2A,
        {SpriteEnum::SPR_BON2, 1, 6, nullptr, StateEnum::S_BON2B, 0, 0}},
       {StateEnum::S_BON2B,
        {SpriteEnum::SPR_BON2, 2, 6, nullptr, StateEnum::S_BON2C, 0, 0}},
       {StateEnum::S_BON2C,
        {SpriteEnum::SPR_BON2, 3, 6, nullptr, StateEnum::S_BON2D, 0, 0}},
       {StateEnum::S_BON2D,
        {SpriteEnum::SPR_BON2, 2, 6, nullptr, StateEnum::S_BON2E, 0, 0}},
       {StateEnum::S_BON2E,
        {SpriteEnum::SPR_BON2, 1, 6, nullptr, StateEnum::S_BON2, 0, 0}},
       {StateEnum::S_BKEY,
        {SpriteEnum::SPR_BKEY, 0, 10, nullptr, StateEnum::S_BKEY2, 0, 0}},
       {StateEnum::S_BKEY2,
        {SpriteEnum::SPR_BKEY, 32769, 10, nullptr, StateEnum::S_BKEY, 0, 0}},
       {StateEnum::S_RKEY,
        {SpriteEnum::SPR_RKEY, 0, 10, nullptr, StateEnum::S_RKEY2, 0, 0}},
       {StateEnum::S_RKEY2,
        {SpriteEnum::SPR_RKEY, 32769, 10, nullptr, StateEnum::S_RKEY, 0, 0}},
       {StateEnum::S_YKEY,
        {SpriteEnum::SPR_YKEY, 0, 10, nullptr, StateEnum::S_YKEY2, 0, 0}},
       {StateEnum::S_YKEY2,
        {SpriteEnum::SPR_YKEY, 32769, 10, nullptr, StateEnum::S_YKEY, 0, 0}},
       {StateEnum::S_BSKULL,
        {SpriteEnum::SPR_BSKU, 0, 10, nullptr, StateEnum::S_BSKULL2, 0, 0}},
       {StateEnum::S_BSKULL2,
        {SpriteEnum::SPR_BSKU, 32769, 10, nullptr, StateEnum::S_BSKULL, 0,
        0}},
       {StateEnum::S_RSKULL,
        {SpriteEnum::SPR_RSKU, 0, 10, nullptr, StateEnum::S_RSKULL2, 0, 0}},
       {StateEnum::S_RSKULL2,
        {SpriteEnum::SPR_RSKU, 32769, 10, nullptr, StateEnum::S_RSKULL, 0,
        0}},
       {StateEnum::S_YSKULL,
        {SpriteEnum::SPR_YSKU, 0, 10, nullptr, StateEnum::S_YSKULL2, 0, 0}},
       {StateEnum::S_YSKULL2,
        {SpriteEnum::SPR_YSKU, 32769, 10, nullptr, StateEnum::S_YSKULL, 0,
        0}},
       {StateEnum::S_STIM,
        {SpriteEnum::SPR_STIM, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_MEDI,
        {SpriteEnum::SPR_MEDI, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SOUL,
        {SpriteEnum::SPR_SOUL, 32768, 6, nullptr, StateEnum::S_SOUL2, 0, 0}},
       {StateEnum::S_SOUL2,
        {SpriteEnum::SPR_SOUL, 32769, 6, nullptr, StateEnum::S_SOUL3, 0, 0}},
       {StateEnum::S_SOUL3,
        {SpriteEnum::SPR_SOUL, 32770, 6, nullptr, StateEnum::S_SOUL4, 0, 0}},
       {StateEnum::S_SOUL4,
        {SpriteEnum::SPR_SOUL, 32771, 6, nullptr, StateEnum::S_SOUL5, 0, 0}},
       {StateEnum::S_SOUL5,
        {SpriteEnum::SPR_SOUL, 32770, 6, nullptr, StateEnum::S_SOUL6, 0, 0}},
       {StateEnum::S_SOUL6,
        {SpriteEnum::SPR_SOUL, 32769, 6, nullptr, StateEnum::S_SOUL, 0, 0}},
       {StateEnum::S_PINV,
        {SpriteEnum::SPR_PINV, 32768, 6, nullptr, StateEnum::S_PINV2, 0, 0}},
       {StateEnum::S_PINV2,
        {SpriteEnum::SPR_PINV, 32769, 6, nullptr, StateEnum::S_PINV3, 0, 0}},
       {StateEnum::S_PINV3,
        {SpriteEnum::SPR_PINV, 32770, 6, nullptr, StateEnum::S_PINV4, 0, 0}},
       {StateEnum::S_PINV4,
        {SpriteEnum::SPR_PINV, 32771, 6, nullptr, StateEnum::S_PINV, 0, 0}},
       {StateEnum::S_PSTR,
        {SpriteEnum::SPR_PSTR, 32768, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PINS,
        {SpriteEnum::SPR_PINS, 32768, 6, nullptr, StateEnum::S_PINS2, 0, 0}},
       {StateEnum::S_PINS2,
        {SpriteEnum::SPR_PINS, 32769, 6, nullptr, StateEnum::S_PINS3, 0, 0}},
       {StateEnum::S_PINS3,
        {SpriteEnum::SPR_PINS, 32770, 6, nullptr, StateEnum::S_PINS4, 0, 0}},
       {StateEnum::S_PINS4,
        {SpriteEnum::SPR_PINS, 32771, 6, nullptr, StateEnum::S_PINS, 0, 0}},
       {StateEnum::S_MEGA,
        {SpriteEnum::SPR_MEGA, 32768, 6, nullptr, StateEnum::S_MEGA2, 0, 0}},
       {StateEnum::S_MEGA2,
        {SpriteEnum::SPR_MEGA, 32769, 6, nullptr, StateEnum::S_MEGA3, 0, 0}},
       {StateEnum::S_MEGA3,
        {SpriteEnum::SPR_MEGA, 32770, 6, nullptr, StateEnum::S_MEGA4, 0, 0}},
       {StateEnum::S_MEGA4,
        {SpriteEnum::SPR_MEGA, 32771, 6, nullptr, StateEnum::S_MEGA, 0, 0}},
       {StateEnum::S_SUIT,
        {SpriteEnum::SPR_SUIT, 32768, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PMAP,
        {SpriteEnum::SPR_PMAP, 32768, 6, nullptr, StateEnum::S_PMAP2, 0, 0}},
       {StateEnum::S_PMAP2,
        {SpriteEnum::SPR_PMAP, 32769, 6, nullptr, StateEnum::S_PMAP3, 0, 0}},
       {StateEnum::S_PMAP3,
        {SpriteEnum::SPR_PMAP, 32770, 6, nullptr, StateEnum::S_PMAP4, 0, 0}},
       {StateEnum::S_PMAP4,
        {SpriteEnum::SPR_PMAP, 32771, 6, nullptr, StateEnum::S_PMAP5, 0, 0}},
       {StateEnum::S_PMAP5,
        {SpriteEnum::SPR_PMAP, 32770, 6, nullptr, StateEnum::S_PMAP6, 0, 0}},
       {StateEnum::S_PMAP6,
        {SpriteEnum::SPR_PMAP, 32769, 6, nullptr, StateEnum::S_PMAP, 0, 0}},
       {StateEnum::S_PVIS,
        {SpriteEnum::SPR_PVIS, 32768, 6, nullptr, StateEnum::S_PVIS2, 0, 0}},
       {StateEnum::S_PVIS2,
        {SpriteEnum::SPR_PVIS, 1, 6, nullptr, StateEnum::S_PVIS, 0, 0}},
       {StateEnum::S_CLIP,
        {SpriteEnum::SPR_CLIP, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_AMMO,
        {SpriteEnum::SPR_AMMO, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_ROCK,
        {SpriteEnum::SPR_ROCK, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BROK,
        {SpriteEnum::SPR_BROK, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CELL,
        {SpriteEnum::SPR_CELL, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CELP,
        {SpriteEnum::SPR_CELP, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SHEL,
        {SpriteEnum::SPR_SHEL, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SBOX,
        {SpriteEnum::SPR_SBOX, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BPAK,
        {SpriteEnum::SPR_BPAK, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BFUG,
        {SpriteEnum::SPR_BFUG, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_MGUN,
        {SpriteEnum::SPR_MGUN, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CSAW,
        {SpriteEnum::SPR_CSAW, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_LAUN,
        {SpriteEnum::SPR_LAUN, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_PLAS,
        {SpriteEnum::SPR_PLAS, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SHOT,
        {SpriteEnum::SPR_SHOT, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SHOT2,
        {SpriteEnum::SPR_SGN2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_COLU,
        {SpriteEnum::SPR_COLU, 32768, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_STALAG,
        {SpriteEnum::SPR_SMT2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BLOODYTWITCH,
        {SpriteEnum::SPR_GOR1, 0, 10, nullptr, StateEnum::S_BLOODYTWITCH2, 0,
        0}},
       {StateEnum::S_BLOODYTWITCH2,
        {SpriteEnum::SPR_GOR1, 1, 15, nullptr, StateEnum::S_BLOODYTWITCH3, 0,
        0}},
       {StateEnum::S_BLOODYTWITCH3,
        {SpriteEnum::SPR_GOR1, 2, 8, nullptr, StateEnum::S_BLOODYTWITCH4, 0,
        0}},
       {StateEnum::S_BLOODYTWITCH4,
        {SpriteEnum::SPR_GOR1, 1, 6, nullptr, StateEnum::S_BLOODYTWITCH, 0,
        0}},
       {StateEnum::S_DEADTORSO,
        {SpriteEnum::SPR_PLAY, 13, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_DEADBOTTOM,
        {SpriteEnum::SPR_PLAY, 18, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HEADSONSTICK,
        {SpriteEnum::SPR_POL2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_GIBS,
        {SpriteEnum::SPR_POL5, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HEADONASTICK,
        {SpriteEnum::SPR_POL4, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HEADCANDLES,
        {SpriteEnum::SPR_POL3, 32768, 6, nullptr, StateEnum::S_HEADCANDLES2,
        0,
         0}},
       {StateEnum::S_HEADCANDLES2,
        {SpriteEnum::SPR_POL3, 32769, 6, nullptr, StateEnum::S_HEADCANDLES,
        0, 0}},
       {StateEnum::S_DEADSTICK,
        {SpriteEnum::SPR_POL1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_LIVESTICK,
        {SpriteEnum::SPR_POL6, 0, 6, nullptr, StateEnum::S_LIVESTICK2, 0,
        0}},
       {StateEnum::S_LIVESTICK2,
        {SpriteEnum::SPR_POL6, 1, 8, nullptr, StateEnum::S_LIVESTICK, 0, 0}},
       {StateEnum::S_MEAT2,
        {SpriteEnum::SPR_GOR2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_MEAT3,
        {SpriteEnum::SPR_GOR3, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_MEAT4,
        {SpriteEnum::SPR_GOR4, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_MEAT5,
        {SpriteEnum::SPR_GOR5, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_STALAGTITE,
        {SpriteEnum::SPR_SMIT, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TALLGRNCOL,
        {SpriteEnum::SPR_COL1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SHRTGRNCOL,
        {SpriteEnum::SPR_COL2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TALLREDCOL,
        {SpriteEnum::SPR_COL3, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SHRTREDCOL,
        {SpriteEnum::SPR_COL4, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CANDLESTIK,
        {SpriteEnum::SPR_CAND, 32768, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_CANDELABRA,
        {SpriteEnum::SPR_CBRA, 32768, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SKULLCOL,
        {SpriteEnum::SPR_COL6, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TORCHTREE,
        {SpriteEnum::SPR_TRE1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BIGTREE,
        {SpriteEnum::SPR_TRE2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TECHPILLAR,
        {SpriteEnum::SPR_ELEC, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_EVILEYE,
        {SpriteEnum::SPR_CEYE, 32768, 6, nullptr, StateEnum::S_EVILEYE2, 0,
        0}},
       {StateEnum::S_EVILEYE2,
        {SpriteEnum::SPR_CEYE, 32769, 6, nullptr, StateEnum::S_EVILEYE3, 0,
        0}},
       {StateEnum::S_EVILEYE3,
        {SpriteEnum::SPR_CEYE, 32770, 6, nullptr, StateEnum::S_EVILEYE4, 0,
        0}},
       {StateEnum::S_EVILEYE4,
        {SpriteEnum::SPR_CEYE, 32769, 6, nullptr, StateEnum::S_EVILEYE, 0,
        0}},
       {StateEnum::S_FLOATSKULL,
        {SpriteEnum::SPR_FSKU, 32768, 6, nullptr, StateEnum::S_FLOATSKULL2,
        0, 0}},
       {StateEnum::S_FLOATSKULL2,
        {SpriteEnum::SPR_FSKU, 32769, 6, nullptr, StateEnum::S_FLOATSKULL3,
        0, 0}},
       {StateEnum::S_FLOATSKULL3,
        {SpriteEnum::SPR_FSKU, 32770, 6, nullptr, StateEnum::S_FLOATSKULL, 0,
        0}},
       {StateEnum::S_HEARTCOL,
        {SpriteEnum::SPR_COL5, 0, 14, nullptr, StateEnum::S_HEARTCOL2, 0,
        0}},
       {StateEnum::S_HEARTCOL2,
        {SpriteEnum::SPR_COL5, 1, 14, nullptr, StateEnum::S_HEARTCOL, 0, 0}},
       {StateEnum::S_BLUETORCH,
        {SpriteEnum::SPR_TBLU, 32768, 4, nullptr, StateEnum::S_BLUETORCH2, 0,
        0}},
       {StateEnum::S_BLUETORCH2,
        {SpriteEnum::SPR_TBLU, 32769, 4, nullptr, StateEnum::S_BLUETORCH3, 0,
        0}},
       {StateEnum::S_BLUETORCH3,
        {SpriteEnum::SPR_TBLU, 32770, 4, nullptr, StateEnum::S_BLUETORCH4, 0,
        0}},
       {StateEnum::S_BLUETORCH4,
        {SpriteEnum::SPR_TBLU, 32771, 4, nullptr, StateEnum::S_BLUETORCH, 0,
        0}},
       {StateEnum::S_GREENTORCH,
        {SpriteEnum::SPR_TGRN, 32768, 4, nullptr, StateEnum::S_GREENTORCH2,
        0, 0}},
       {StateEnum::S_GREENTORCH2,
        {SpriteEnum::SPR_TGRN, 32769, 4, nullptr, StateEnum::S_GREENTORCH3,
        0, 0}},
       {StateEnum::S_GREENTORCH3,
        {SpriteEnum::SPR_TGRN, 32770, 4, nullptr, StateEnum::S_GREENTORCH4,
        0, 0}},
       {StateEnum::S_GREENTORCH4,
        {SpriteEnum::SPR_TGRN, 32771, 4, nullptr, StateEnum::S_GREENTORCH, 0,
        0}},
       {StateEnum::S_REDTORCH,
        {SpriteEnum::SPR_TRED, 32768, 4, nullptr, StateEnum::S_REDTORCH2, 0,
        0}},
       {StateEnum::S_REDTORCH2,
        {SpriteEnum::SPR_TRED, 32769, 4, nullptr, StateEnum::S_REDTORCH3, 0,
        0}},
       {StateEnum::S_REDTORCH3,
        {SpriteEnum::SPR_TRED, 32770, 4, nullptr, StateEnum::S_REDTORCH4, 0,
        0}},
       {StateEnum::S_REDTORCH4,
        {SpriteEnum::SPR_TRED, 32771, 4, nullptr, StateEnum::S_REDTORCH, 0,
        0}},
       {StateEnum::S_BTORCHSHRT,
        {SpriteEnum::SPR_SMBT, 32768, 4, nullptr, StateEnum::S_BTORCHSHRT2,
        0, 0}},
       {StateEnum::S_BTORCHSHRT2,
        {SpriteEnum::SPR_SMBT, 32769, 4, nullptr, StateEnum::S_BTORCHSHRT3,
        0, 0}},
       {StateEnum::S_BTORCHSHRT3,
        {SpriteEnum::SPR_SMBT, 32770, 4, nullptr, StateEnum::S_BTORCHSHRT4,
        0, 0}},
       {StateEnum::S_BTORCHSHRT4,
        {SpriteEnum::SPR_SMBT, 32771, 4, nullptr, StateEnum::S_BTORCHSHRT, 0,
        0}},
       {StateEnum::S_GTORCHSHRT,
        {SpriteEnum::SPR_SMGT, 32768, 4, nullptr, StateEnum::S_GTORCHSHRT2,
        0, 0}},
       {StateEnum::S_GTORCHSHRT2,
        {SpriteEnum::SPR_SMGT, 32769, 4, nullptr, StateEnum::S_GTORCHSHRT3,
        0, 0}},
       {StateEnum::S_GTORCHSHRT3,
        {SpriteEnum::SPR_SMGT, 32770, 4, nullptr, StateEnum::S_GTORCHSHRT4,
        0, 0}},
       {StateEnum::S_GTORCHSHRT4,
        {SpriteEnum::SPR_SMGT, 32771, 4, nullptr, StateEnum::S_GTORCHSHRT, 0,
        0}},
       {StateEnum::S_RTORCHSHRT,
        {SpriteEnum::SPR_SMRT, 32768, 4, nullptr, StateEnum::S_RTORCHSHRT2,
        0, 0}},
       {StateEnum::S_RTORCHSHRT2,
        {SpriteEnum::SPR_SMRT, 32769, 4, nullptr, StateEnum::S_RTORCHSHRT3,
        0, 0}},
       {StateEnum::S_RTORCHSHRT3,
        {SpriteEnum::SPR_SMRT, 32770, 4, nullptr, StateEnum::S_RTORCHSHRT4,
        0, 0}},
       {StateEnum::S_RTORCHSHRT4,
        {SpriteEnum::SPR_SMRT, 32771, 4, nullptr, StateEnum::S_RTORCHSHRT, 0,
        0}},
       {StateEnum::S_HANGNOGUTS,
        {SpriteEnum::SPR_HDB1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HANGBNOBRAIN,
        {SpriteEnum::SPR_HDB2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HANGTLOOKDN,
        {SpriteEnum::SPR_HDB3, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HANGTSKULL,
        {SpriteEnum::SPR_HDB4, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HANGTLOOKUP,
        {SpriteEnum::SPR_HDB5, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_HANGTNOBRAIN,
        {SpriteEnum::SPR_HDB6, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_COLONGIBS,
        {SpriteEnum::SPR_POB1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_SMALLPOOL,
        {SpriteEnum::SPR_POB2, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_BRAINSTEM,
        {SpriteEnum::SPR_BRS1, 0, -1, nullptr, StateEnum::S_NULL, 0, 0}},
       {StateEnum::S_TECHLAMP,
        {SpriteEnum::SPR_TLMP, 32768, 4, nullptr, StateEnum::S_TECHLAMP2, 0,
        0}},
       {StateEnum::S_TECHLAMP2,
        {SpriteEnum::SPR_TLMP, 32769, 4, nullptr, StateEnum::S_TECHLAMP3, 0,
        0}},
       {StateEnum::S_TECHLAMP3,
        {SpriteEnum::SPR_TLMP, 32770, 4, nullptr, StateEnum::S_TECHLAMP4, 0,
        0}},
       {StateEnum::S_TECHLAMP4,
        {SpriteEnum::SPR_TLMP, 32771, 4, nullptr, StateEnum::S_TECHLAMP, 0,
        0}},
       {StateEnum::S_TECH2LAMP,
        {SpriteEnum::SPR_TLP2, 32768, 4, nullptr, StateEnum::S_TECH2LAMP2, 0,
        0}},
       {StateEnum::S_TECH2LAMP2,
        {SpriteEnum::SPR_TLP2, 32769, 4, nullptr, StateEnum::S_TECH2LAMP3, 0,
        0}},
       {StateEnum::S_TECH2LAMP3,
        {SpriteEnum::SPR_TLP2, 32770, 4, nullptr, StateEnum::S_TECH2LAMP4, 0,
        0}},
       {StateEnum::S_TECH2LAMP4,
        {SpriteEnum::SPR_TLP2, 32771, 4, nullptr, StateEnum::S_TECH2LAMP, 0,
        0}},
       {StateEnum::S_TNT1,
        {SpriteEnum::SPR_TNT1, 0, -1, nullptr, StateEnum::S_TNT1, 0,
         0}}, // phares 3/8/98
    
       // killough 8/9/98: grenade
       {StateEnum::S_GRENADE,
        {SpriteEnum::SPR_MISL, 32768, 1000, action::die,
        StateEnum::S_GRENADE}},
    
       // killough 8/10/98: variable damage explosion
       {StateEnum::S_DETONATE,
        {SpriteEnum::SPR_MISL, 32769, 4, action::scream,
        StateEnum::S_DETONATE2}},
       {StateEnum::S_DETONATE2,
        {SpriteEnum::SPR_MISL, 32770, 6, action::detonate,
         StateEnum::S_DETONATE3}},
       {StateEnum::S_DETONATE3,
        {SpriteEnum::SPR_MISL, 32771, 10, nullptr, StateEnum::S_NULL}},
    
       // killough 7/19/98: Marine's best friend :)
       {StateEnum::S_DOGS_STND,
        {SpriteEnum::SPR_DOGS, 0, 10, action::look,
        StateEnum::S_DOGS_STND2}},
       {StateEnum::S_DOGS_STND2,
        {SpriteEnum::SPR_DOGS, 1, 10, action::look, StateEnum::S_DOGS_STND}},
       {StateEnum::S_DOGS_RUN1,
        {SpriteEnum::SPR_DOGS, 0, 2, action::chase, StateEnum::S_DOGS_RUN2}},
       {StateEnum::S_DOGS_RUN2,
        {SpriteEnum::SPR_DOGS, 0, 2, action::chase, StateEnum::S_DOGS_RUN3}},
       {StateEnum::S_DOGS_RUN3,
        {SpriteEnum::SPR_DOGS, 1, 2, action::chase, StateEnum::S_DOGS_RUN4}},
       {StateEnum::S_DOGS_RUN4,
        {SpriteEnum::SPR_DOGS, 1, 2, action::chase, StateEnum::S_DOGS_RUN5}},
       {StateEnum::S_DOGS_RUN5,
        {SpriteEnum::SPR_DOGS, 2, 2, action::chase, StateEnum::S_DOGS_RUN6}},
       {StateEnum::S_DOGS_RUN6,
        {SpriteEnum::SPR_DOGS, 2, 2, action::chase, StateEnum::S_DOGS_RUN7}},
       {StateEnum::S_DOGS_RUN7,
        {SpriteEnum::SPR_DOGS, 3, 2, action::chase, StateEnum::S_DOGS_RUN8}},
       {StateEnum::S_DOGS_RUN8,
        {SpriteEnum::SPR_DOGS, 3, 2, action::chase, StateEnum::S_DOGS_RUN1}},
       {StateEnum::S_DOGS_ATK1,
        {SpriteEnum::SPR_DOGS, 4, 8, action::faceTarget,
        StateEnum::S_DOGS_ATK2}},
       {StateEnum::S_DOGS_ATK2,
        {SpriteEnum::SPR_DOGS, 5, 8, action::faceTarget,
        StateEnum::S_DOGS_ATK3}},
       {StateEnum::S_DOGS_ATK3,
        {SpriteEnum::SPR_DOGS, 6, 8, action::sargAttack,
        StateEnum::S_DOGS_RUN1}},
       {StateEnum::S_DOGS_PAIN,
        {SpriteEnum::SPR_DOGS, 7, 2, nullptr, StateEnum::S_DOGS_PAIN2}},
       {StateEnum::S_DOGS_PAIN2,
        {SpriteEnum::SPR_DOGS, 7, 2, action::pain, StateEnum::S_DOGS_RUN1}},
       {StateEnum::S_DOGS_DIE1,
        {SpriteEnum::SPR_DOGS, 8, 8, nullptr, StateEnum::S_DOGS_DIE2}},
       {StateEnum::S_DOGS_DIE2,
        {SpriteEnum::SPR_DOGS, 9, 8, action::scream,
        StateEnum::S_DOGS_DIE3}},
       {StateEnum::S_DOGS_DIE3,
        {SpriteEnum::SPR_DOGS, 10, 4, nullptr, StateEnum::S_DOGS_DIE4}},
       {StateEnum::S_DOGS_DIE4,
        {SpriteEnum::SPR_DOGS, 11, 4, action::fall, StateEnum::S_DOGS_DIE5}},
       {StateEnum::S_DOGS_DIE5,
        {SpriteEnum::SPR_DOGS, 12, 4, nullptr, StateEnum::S_DOGS_DIE6}},
       {StateEnum::S_DOGS_DIE6,
        {SpriteEnum::SPR_DOGS, 13, -1, nullptr, StateEnum::S_NULL}},
       {StateEnum::S_DOGS_RAISE1,
        {SpriteEnum::SPR_DOGS, 13, 5, nullptr, StateEnum::S_DOGS_RAISE2}},
       {StateEnum::S_DOGS_RAISE2,
        {SpriteEnum::SPR_DOGS, 12, 5, nullptr, StateEnum::S_DOGS_RAISE3}},
       {StateEnum::S_DOGS_RAISE3,
        {SpriteEnum::SPR_DOGS, 11, 5, nullptr, StateEnum::S_DOGS_RAISE4}},
       {StateEnum::S_DOGS_RAISE4,
        {SpriteEnum::SPR_DOGS, 10, 5, nullptr, StateEnum::S_DOGS_RAISE5}},
       {StateEnum::S_DOGS_RAISE5,
        {SpriteEnum::SPR_DOGS, 9, 5, nullptr, StateEnum::S_DOGS_RAISE6}},
       {StateEnum::S_DOGS_RAISE6,
        {SpriteEnum::SPR_DOGS, 8, 5, nullptr, StateEnum::S_DOGS_RUN1}},
    
       //{StateEnum::S_OLDBFG42,{SpriteEnum::SPR_DOGS,7,2,action::pain,StateEnum::S_DOGS_RUN1},
       {SpriteEnum::SPR_BFGG, {1, 0, action::light0, StateEnum::S_OLDBFG43}},
       {StateEnum::S_OLDBFG43,
        {SpriteEnum::SPR_BFGG, 1, 20, action::reFire, StateEnum::S_BFG}},
    
       // killough 7/11/98: end of beta BFG
    
       // killough 7/19/98: First plasma fireball in the beta:
       {StateEnum::S_PLS1BALL,
        {SpriteEnum::SPR_PLS1, 32768, 6, nullptr, StateEnum::S_PLS1BALL2}},
       {StateEnum::S_PLS1BALL2,
        {SpriteEnum::SPR_PLS1, 32769, 6, nullptr, StateEnum::S_PLS1BALL}},
       {StateEnum::S_PLS1EXP,
        {SpriteEnum::SPR_PLS1, 32770, 4, nullptr, StateEnum::S_PLS1EXP2}},
       {StateEnum::S_PLS1EXP2,
        {SpriteEnum::SPR_PLS1, 32771, 4, nullptr, StateEnum::S_PLS1EXP3}},
       {StateEnum::S_PLS1EXP3,
        {SpriteEnum::SPR_PLS1, 32772, 4, nullptr, StateEnum::S_PLS1EXP4}},
       {StateEnum::S_PLS1EXP4,
        {SpriteEnum::SPR_PLS1, 32773, 4, nullptr, StateEnum::S_PLS1EXP5}},
       {StateEnum::S_PLS1EXP5,
        {SpriteEnum::SPR_PLS1, 32774, 4, nullptr, StateEnum::S_NULL}},
    
       // killough 7/19/98: Second plasma fireball in the beta:
       {StateEnum::S_PLS2BALL,
        {SpriteEnum::SPR_PLS2, 32768, 4, nullptr, StateEnum::S_PLS2BALL2}},
       {StateEnum::S_PLS2BALL2,
        {SpriteEnum::SPR_PLS2, 32769, 4, nullptr, StateEnum::S_PLS2BALL}},
       {StateEnum::S_PLS2BALLX1,
        {SpriteEnum::SPR_PLS2, 32770, 6, nullptr, StateEnum::S_PLS2BALLX2}},
       {StateEnum::S_PLS2BALLX2,
        {SpriteEnum::SPR_PLS2, 32771, 6, nullptr, StateEnum::S_PLS2BALLX3}},
       {StateEnum::S_PLS2BALLX3,
        {SpriteEnum::SPR_PLS2, 32772, 6, nullptr, StateEnum::S_NULL}},
    
       {StateEnum::S_BON3,
        {SpriteEnum::SPR_BON3, 0, 6, nullptr,
         StateEnum::S_BON3}}, // killough 7/11/98:
       {StateEnum::S_BON4,
        {SpriteEnum::SPR_BON4, 0, 6, nullptr,
         StateEnum::S_BON4}}, // beta bonus items
    
       // killough 10/98: beta lost souls attacked from a distance,
       // animated with colors, and stayed in the air when killed.
       // This is an approximation, but I'm sure it can be improved.
    
       // spawnstate
       {StateEnum::S_BSKUL_STND,
        {SpriteEnum::SPR_SKUL, 0, 10, action::look,
        StateEnum::S_BSKUL_STND}},
    
       // chasestate
       {StateEnum::S_BSKUL_RUN1,
        {SpriteEnum::SPR_SKUL, 1, 5, action::chase,
        StateEnum::S_BSKUL_RUN2}},
       {StateEnum::S_BSKUL_RUN2,
        {SpriteEnum::SPR_SKUL, 2, 5, action::chase,
        StateEnum::S_BSKUL_RUN3}},
       {StateEnum::S_BSKUL_RUN3,
        {SpriteEnum::SPR_SKUL, 3, 5, action::chase,
        StateEnum::S_BSKUL_RUN4}},
       {StateEnum::S_BSKUL_RUN4,
        {SpriteEnum::SPR_SKUL, 0, 5, action::chase,
        StateEnum::S_BSKUL_RUN1}},
    
       // missilestate
       {StateEnum::S_BSKUL_ATK1,
        {SpriteEnum::SPR_SKUL, 4, 4, action::faceTarget,
        StateEnum::S_BSKUL_ATK2}},
       {StateEnum::S_BSKUL_ATK2,
        {SpriteEnum::SPR_SKUL, 5, 5, action::betaSkullAttack,
         StateEnum::S_BSKUL_ATK3}},
       {StateEnum::S_BSKUL_ATK3,
        {SpriteEnum::SPR_SKUL, 5, 4, nullptr, StateEnum::S_BSKUL_RUN1}},
    
       // painstate
       {StateEnum::S_BSKUL_PAIN1,
        {SpriteEnum::SPR_SKUL, 6, 4, nullptr, StateEnum::S_BSKUL_PAIN2}},
       {StateEnum::S_BSKUL_PAIN2,
        {SpriteEnum::SPR_SKUL, 7, 2, action::pain, StateEnum::S_BSKUL_RUN1}},
       {StateEnum::S_BSKUL_PAIN3,
        {SpriteEnum::SPR_SKUL, 8, 4, nullptr, StateEnum::S_BSKUL_RUN1}},
    
       // deathstate
       {StateEnum::S_BSKUL_DIE1,
        {SpriteEnum::SPR_SKUL, 9, 5, nullptr, StateEnum::S_BSKUL_DIE2}},
       {StateEnum::S_BSKUL_DIE2,
        {SpriteEnum::SPR_SKUL, 10, 5, nullptr, StateEnum::S_BSKUL_DIE3}},
       {StateEnum::S_BSKUL_DIE3,
        {SpriteEnum::SPR_SKUL, 11, 5, nullptr, StateEnum::S_BSKUL_DIE4}},
       {StateEnum::S_BSKUL_DIE4,
        {SpriteEnum::SPR_SKUL, 12, 5, nullptr, StateEnum::S_BSKUL_DIE5}},
       {StateEnum::S_BSKUL_DIE5,
        {SpriteEnum::SPR_SKUL, 13, 5, action::scream,
        StateEnum::S_BSKUL_DIE6}},
       {StateEnum::S_BSKUL_DIE6,
        {SpriteEnum::SPR_SKUL, 14, 5, nullptr, StateEnum::S_BSKUL_DIE7}},
       {StateEnum::S_BSKUL_DIE7,
        {SpriteEnum::SPR_SKUL, 15, 5, action::fall,
        StateEnum::S_BSKUL_DIE8}},
       {StateEnum::S_BSKUL_DIE8,
        {SpriteEnum::SPR_SKUL, 16, 5, action::stop,
        StateEnum::S_BSKUL_DIE8}},
    
       // killough 10/98: mushroom effect
       {StateEnum::S_MUSHROOM,
        {SpriteEnum::SPR_MISL, 32769, 8, action::mushroom,
        StateEnum::S_EXPLODE2}},
    
       {StateEnum::S_PLAY_GDIE1,
        {SpriteEnum::SPR_PLAY, 14, 5, nullptr, StateEnum::S_PLAY_GDIE2, 0,
        0}},
       {StateEnum::S_PLAY_GDIE2,
        {SpriteEnum::SPR_PLAY, 15, 5, action::skullPop,
        StateEnum::S_PLAY_GDIE3, 0,
         0}},
       {StateEnum::S_PLAY_GDIE3,
        {SpriteEnum::SPR_PLAY, 16, 5, action::fall, StateEnum::S_PLAY_GDIE4,
        0,
         0}},
       {StateEnum::S_PLAY_GDIE4,
        {SpriteEnum::SPR_PLAY, 17, 5, nullptr, StateEnum::S_PLAY_GDIE5, 0,
        0}},
       {StateEnum::S_PLAY_GDIE5,
        {SpriteEnum::SPR_PLAY, 18, 5, nullptr, StateEnum::S_PLAY_GDIE6, 0,
        0}},
       {StateEnum::S_PLAY_GDIE6,
        {SpriteEnum::SPR_PLAY, 19, 5, nullptr, StateEnum::S_PLAY_GDIE7, 0,
        0}},
       {StateEnum::S_PLAY_GDIE7,
        {SpriteEnum::SPR_PLAY, 20, 5, nullptr, StateEnum::S_PLAY_GDIE8, 0,
        0}},
       {StateEnum::S_PLAY_GDIE8,
        {SpriteEnum::SPR_PLAY, 21, 5, nullptr, StateEnum::S_PLAY_GDIE9, 0,
        0}},
       {StateEnum::S_PLAY_GDIE9,
        {SpriteEnum::SPR_PLAY, 22, -1, nullptr, StateEnum::S_NULL, 0, 0}},
}}};
