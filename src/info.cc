//
// Created by kyle on 9/20/20.
//

#include "info.hh"

#include <cstddef>

#include "action.hh"

info::State info::states[static_cast<size_t>(info::StateNum::NUMSTATES)]{
    {SpriteNum::SPR_TROO, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_NULL
    {SpriteNum::SPR_SHTG, 4, 0, action::light0, StateNum::S_NULL, 0,
     0}, // S_LIGHTDONE
    {SpriteNum::SPR_PUNG, 0, 1, action::weaponReady, StateNum::S_PUNCH, 0,
     0}, // S_PUNCH
    {SpriteNum::SPR_PUNG, 0, 1, action::lower, StateNum::S_PUNCHDOWN, 0,
     0}, // S_PUNCHDOWN
    {SpriteNum::SPR_PUNG, 0, 1, action::raise, StateNum::S_PUNCHUP, 0,
     0},                                                            // S_PUNCHUP
    {SpriteNum::SPR_PUNG, 1, 4, nullptr, StateNum::S_PUNCH2, 0, 0}, // S_PUNCH1
    {SpriteNum::SPR_PUNG, 2, 4, action::punch, StateNum::S_PUNCH3, 0,
     0},                                                            // S_PUNCH2
    {SpriteNum::SPR_PUNG, 3, 5, nullptr, StateNum::S_PUNCH4, 0, 0}, // S_PUNCH3
    {SpriteNum::SPR_PUNG, 2, 4, nullptr, StateNum::S_PUNCH5, 0, 0}, // S_PUNCH4
    {SpriteNum::SPR_PUNG, 1, 5, action::reFire, StateNum::S_PUNCH, 0,
     0}, // S_PUNCH5
    {SpriteNum::SPR_PISG, 0, 1, action::weaponReady, StateNum::S_PISTOL, 0,
     0}, // S_PISTOL
    {SpriteNum::SPR_PISG, 0, 1, action::lower, StateNum::S_PISTOLDOWN, 0,
     0}, // S_PISTOLDOWN
    {SpriteNum::SPR_PISG, 0, 1, action::raise, StateNum::S_PISTOLUP, 0,
     0}, // S_PISTOLUP
    {SpriteNum::SPR_PISG, 0, 4, nullptr, StateNum::S_PISTOL2, 0,
     0}, // S_PISTOL1
    {SpriteNum::SPR_PISG, 1, 6, action::firePistol, StateNum::S_PISTOL3, 0,
     0}, // S_PISTOL2
    {SpriteNum::SPR_PISG, 2, 4, nullptr, StateNum::S_PISTOL4, 0,
     0}, // S_PISTOL3
    {SpriteNum::SPR_PISG, 1, 5, action::reFire, StateNum::S_PISTOL, 0,
     0}, // S_PISTOL4
    {SpriteNum::SPR_PISF, 32768, 7, action::light1, StateNum::S_LIGHTDONE, 0,
     0}, // S_PISTOLFLASH
    {SpriteNum::SPR_SHTG, 0, 1, action::weaponReady, StateNum::S_SGUN, 0,
     0}, // S_SGUN
    {SpriteNum::SPR_SHTG, 0, 1, action::lower, StateNum::S_SGUNDOWN, 0,
     0}, // S_SGUNDOWN
    {SpriteNum::SPR_SHTG, 0, 1, action::raise, StateNum::S_SGUNUP, 0,
     0},                                                           // S_SGUNUP
    {SpriteNum::SPR_SHTG, 0, 3, nullptr, StateNum::S_SGUN2, 0, 0}, // S_SGUN1
    {SpriteNum::SPR_SHTG, 0, 7, action::fireShotgun, StateNum::S_SGUN3, 0,
     0},                                                           // S_SGUN2
    {SpriteNum::SPR_SHTG, 1, 5, nullptr, StateNum::S_SGUN4, 0, 0}, // S_SGUN3
    {SpriteNum::SPR_SHTG, 2, 5, nullptr, StateNum::S_SGUN5, 0, 0}, // S_SGUN4
    {SpriteNum::SPR_SHTG, 3, 4, nullptr, StateNum::S_SGUN6, 0, 0}, // S_SGUN5
    {SpriteNum::SPR_SHTG, 2, 5, nullptr, StateNum::S_SGUN7, 0, 0}, // S_SGUN6
    {SpriteNum::SPR_SHTG, 1, 5, nullptr, StateNum::S_SGUN8, 0, 0}, // S_SGUN7
    {SpriteNum::SPR_SHTG, 0, 3, nullptr, StateNum::S_SGUN9, 0, 0}, // S_SGUN8
    {SpriteNum::SPR_SHTG, 0, 7, action::reFire, StateNum::S_SGUN, 0,
     0}, // S_SGUN9
    {SpriteNum::SPR_SHTF, 32768, 4, action::light1, StateNum::S_SGUNFLASH2, 0,
     0}, // S_SGUNFLASH1
    {SpriteNum::SPR_SHTF, 32769, 3, action::light2, StateNum::S_LIGHTDONE, 0,
     0}, // S_SGUNFLASH2
    {SpriteNum::SPR_SHT2, 0, 1, action::weaponReady, StateNum::S_DSGUN, 0,
     0}, // S_DSGUN
    {SpriteNum::SPR_SHT2, 0, 1, action::lower, StateNum::S_DSGUNDOWN, 0,
     0}, // S_DSGUNDOWN
    {SpriteNum::SPR_SHT2, 0, 1, action::raise, StateNum::S_DSGUNUP, 0,
     0},                                                            // S_DSGUNUP
    {SpriteNum::SPR_SHT2, 0, 3, nullptr, StateNum::S_DSGUN2, 0, 0}, // S_DSGUN1
    {SpriteNum::SPR_SHT2, 0, 7, action::fireShotgun2, StateNum::S_DSGUN3, 0,
     0},                                                            // S_DSGUN2
    {SpriteNum::SPR_SHT2, 1, 7, nullptr, StateNum::S_DSGUN4, 0, 0}, // S_DSGUN3
    {SpriteNum::SPR_SHT2, 2, 7, action::checkReload, StateNum::S_DSGUN5, 0,
     0}, // S_DSGUN4
    {SpriteNum::SPR_SHT2, 3, 7, action::openShotgun2, StateNum::S_DSGUN6, 0,
     0},                                                            // S_DSGUN5
    {SpriteNum::SPR_SHT2, 4, 7, nullptr, StateNum::S_DSGUN7, 0, 0}, // S_DSGUN6
    {SpriteNum::SPR_SHT2, 5, 7, action::loadShotgun2, StateNum::S_DSGUN8, 0,
     0},                                                            // S_DSGUN7
    {SpriteNum::SPR_SHT2, 6, 6, nullptr, StateNum::S_DSGUN9, 0, 0}, // S_DSGUN8
    {SpriteNum::SPR_SHT2, 7, 6, action::closeShotgun2, StateNum::S_DSGUN10, 0,
     0}, // S_DSGUN9
    {SpriteNum::SPR_SHT2, 0, 5, action::reFire, StateNum::S_DSGUN, 0,
     0},                                                           // S_DSGUN10
    {SpriteNum::SPR_SHT2, 1, 7, nullptr, StateNum::S_DSNR2, 0, 0}, // S_DSNR1
    {SpriteNum::SPR_SHT2, 0, 3, nullptr, StateNum::S_DSGUNDOWN, 0,
     0}, // S_DSNR2
    {SpriteNum::SPR_SHT2, 32776, 5, action::light1, StateNum::S_DSGUNFLASH2, 0,
     0}, // S_DSGUNFLASH1
    {SpriteNum::SPR_SHT2, 32777, 4, action::light2, StateNum::S_LIGHTDONE, 0,
     0}, // S_DSGUNFLASH2
    {SpriteNum::SPR_CHGG, 0, 1, action::weaponReady, StateNum::S_CHAIN, 0,
     0}, // S_CHAIN
    {SpriteNum::SPR_CHGG, 0, 1, action::lower, StateNum::S_CHAINDOWN, 0,
     0}, // S_CHAINDOWN
    {SpriteNum::SPR_CHGG, 0, 1, action::raise, StateNum::S_CHAINUP, 0,
     0}, // S_CHAINUP
    {SpriteNum::SPR_CHGG, 0, 4, action::fireCGun, StateNum::S_CHAIN2, 0,
     0}, // S_CHAIN1
    {SpriteNum::SPR_CHGG, 1, 4, action::fireCGun, StateNum::S_CHAIN3, 0,
     0}, // S_CHAIN2
    {SpriteNum::SPR_CHGG, 1, 0, action::reFire, StateNum::S_CHAIN, 0,
     0}, // S_CHAIN3
    {SpriteNum::SPR_CHGF, 32768, 5, action::light1, StateNum::S_LIGHTDONE, 0,
     0}, // S_CHAINFLASH1
    {SpriteNum::SPR_CHGF, 32769, 5, action::light2, StateNum::S_LIGHTDONE, 0,
     0}, // S_CHAINFLASH2
    {SpriteNum::SPR_MISG, 0, 1, action::weaponReady, StateNum::S_MISSILE, 0,
     0}, // S_MISSILE
    {SpriteNum::SPR_MISG, 0, 1, action::lower, StateNum::S_MISSILEDOWN, 0,
     0}, // S_MISSILEDOWN
    {SpriteNum::SPR_MISG, 0, 1, action::raise, StateNum::S_MISSILEUP, 0,
     0}, // S_MISSILEUP
    {SpriteNum::SPR_MISG, 1, 8, action::gunFlash, StateNum::S_MISSILE2, 0,
     0}, // S_MISSILE1
    {SpriteNum::SPR_MISG, 1, 12, action::fireMissile, StateNum::S_MISSILE3, 0,
     0}, // S_MISSILE2
    {SpriteNum::SPR_MISG, 1, 0, action::reFire, StateNum::S_MISSILE, 0,
     0}, // S_MISSILE3
    {SpriteNum::SPR_MISF, 32768, 3, action::light1, StateNum::S_MISSILEFLASH2,
     0, 0}, // S_MISSILEFLASH1
    {SpriteNum::SPR_MISF, 32769, 4, nullptr, StateNum::S_MISSILEFLASH3, 0,
     0}, // S_MISSILEFLASH2
    {SpriteNum::SPR_MISF, 32770, 4, action::light2, StateNum::S_MISSILEFLASH4,
     0, 0}, // S_MISSILEFLASH3
    {SpriteNum::SPR_MISF, 32771, 4, action::light2, StateNum::S_LIGHTDONE, 0,
     0}, // S_MISSILEFLASH4
    {SpriteNum::SPR_SAWG, 2, 4, action::weaponReady, StateNum::S_SAWB, 0,
     0}, // S_SAW
    {SpriteNum::SPR_SAWG, 3, 4, action::weaponReady, StateNum::S_SAW, 0,
     0}, // S_SAWB
    {SpriteNum::SPR_SAWG, 2, 1, action::lower, StateNum::S_SAWDOWN, 0,
     0}, // S_SAWDOWN
    {SpriteNum::SPR_SAWG, 2, 1, action::raise, StateNum::S_SAWUP, 0,
     0},                                                              // S_SAWUP
    {SpriteNum::SPR_SAWG, 0, 4, action::saw, StateNum::S_SAW2, 0, 0}, // S_SAW1
    {SpriteNum::SPR_SAWG, 1, 4, action::saw, StateNum::S_SAW3, 0, 0}, // S_SAW2
    {SpriteNum::SPR_SAWG, 1, 0, action::reFire, StateNum::S_SAW, 0,
     0}, // S_SAW3
    {SpriteNum::SPR_PLSG, 0, 1, action::weaponReady, StateNum::S_PLASMA, 0,
     0}, // S_PLASMA
    {SpriteNum::SPR_PLSG, 0, 1, action::lower, StateNum::S_PLASMADOWN, 0,
     0}, // S_PLASMADOWN
    {SpriteNum::SPR_PLSG, 0, 1, action::raise, StateNum::S_PLASMAUP, 0,
     0}, // S_PLASMAUP
    {SpriteNum::SPR_PLSG, 0, 3, action::firePlasma, StateNum::S_PLASMA2, 0,
     0}, // S_PLASMA1
    {SpriteNum::SPR_PLSG, 1, 20, action::reFire, StateNum::S_PLASMA, 0,
     0}, // S_PLASMA2
    {SpriteNum::SPR_PLSF, 32768, 4, action::light1, StateNum::S_LIGHTDONE, 0,
     0}, // S_PLASMAFLASH1
    {SpriteNum::SPR_PLSF, 32769, 4, action::light1, StateNum::S_LIGHTDONE, 0,
     0}, // S_PLASMAFLASH2
    {SpriteNum::SPR_BFGG, 0, 1, action::weaponReady, StateNum::S_BFG, 0,
     0}, // S_BFG
    {SpriteNum::SPR_BFGG, 0, 1, action::lower, StateNum::S_BFGDOWN, 0,
     0}, // S_BFGDOWN
    {SpriteNum::SPR_BFGG, 0, 1, action::raise, StateNum::S_BFGUP, 0,
     0}, // S_BFGUP
    {SpriteNum::SPR_BFGG, 0, 20, action::bfgSound, StateNum::S_BFG2, 0,
     0}, // S_BFG1
    {SpriteNum::SPR_BFGG, 1, 10, action::gunFlash, StateNum::S_BFG3, 0,
     0}, // S_BFG2
    {SpriteNum::SPR_BFGG, 1, 10, action::fireBfg, StateNum::S_BFG4, 0,
     0}, // S_BFG3
    {SpriteNum::SPR_BFGG, 1, 20, action::reFire, StateNum::S_BFG, 0,
     0}, // S_BFG4
    {SpriteNum::SPR_BFGF, 32768, 11, action::light1, StateNum::S_BFGFLASH2, 0,
     0}, // S_BFGFLASH1
    {SpriteNum::SPR_BFGF, 32769, 6, action::light2, StateNum::S_LIGHTDONE, 0,
     0}, // S_BFGFLASH2
    {SpriteNum::SPR_BLUD, 2, 8, nullptr, StateNum::S_BLOOD2, 0, 0}, // S_BLOOD1
    {SpriteNum::SPR_BLUD, 1, 8, nullptr, StateNum::S_BLOOD3, 0, 0}, // S_BLOOD2
    {SpriteNum::SPR_BLUD, 0, 8, nullptr, StateNum::S_NULL, 0, 0},   // S_BLOOD3
    {SpriteNum::SPR_PUFF, 32768, 4, nullptr, StateNum::S_PUFF2, 0,
     0},                                                           // S_PUFF1
    {SpriteNum::SPR_PUFF, 1, 4, nullptr, StateNum::S_PUFF3, 0, 0}, // S_PUFF2
    {SpriteNum::SPR_PUFF, 2, 4, nullptr, StateNum::S_PUFF4, 0, 0}, // S_PUFF3
    {SpriteNum::SPR_PUFF, 3, 4, nullptr, StateNum::S_NULL, 0, 0},  // S_PUFF4
    {SpriteNum::SPR_BAL1, 32768, 4, nullptr, StateNum::S_TBALL2, 0,
     0}, // S_TBALL1
    {SpriteNum::SPR_BAL1, 32769, 4, nullptr, StateNum::S_TBALL1, 0,
     0}, // S_TBALL2
    {SpriteNum::SPR_BAL1, 32770, 6, nullptr, StateNum::S_TBALLX2, 0,
     0}, // S_TBALLX1
    {SpriteNum::SPR_BAL1, 32771, 6, nullptr, StateNum::S_TBALLX3, 0,
     0}, // S_TBALLX2
    {SpriteNum::SPR_BAL1, 32772, 6, nullptr, StateNum::S_NULL, 0,
     0}, // S_TBALLX3
    {SpriteNum::SPR_BAL2, 32768, 4, nullptr, StateNum::S_RBALL2, 0,
     0}, // S_RBALL1
    {SpriteNum::SPR_BAL2, 32769, 4, nullptr, StateNum::S_RBALL1, 0,
     0}, // S_RBALL2
    {SpriteNum::SPR_BAL2, 32770, 6, nullptr, StateNum::S_RBALLX2, 0,
     0}, // S_RBALLX1
    {SpriteNum::SPR_BAL2, 32771, 6, nullptr, StateNum::S_RBALLX3, 0,
     0}, // S_RBALLX2
    {SpriteNum::SPR_BAL2, 32772, 6, nullptr, StateNum::S_NULL, 0,
     0}, // S_RBALLX3
    {SpriteNum::SPR_PLSS, 32768, 6, nullptr, StateNum::S_PLASBALL2, 0,
     0}, // S_PLASBALL
    {SpriteNum::SPR_PLSS, 32769, 6, nullptr, StateNum::S_PLASBALL, 0,
     0}, // S_PLASBALL2
    {SpriteNum::SPR_PLSE, 32768, 4, nullptr, StateNum::S_PLASEXP2, 0,
     0}, // S_PLASEXP
    {SpriteNum::SPR_PLSE, 32769, 4, nullptr, StateNum::S_PLASEXP3, 0,
     0}, // S_PLASEXP2
    {SpriteNum::SPR_PLSE, 32770, 4, nullptr, StateNum::S_PLASEXP4, 0,
     0}, // S_PLASEXP3
    {SpriteNum::SPR_PLSE, 32771, 4, nullptr, StateNum::S_PLASEXP5, 0,
     0}, // S_PLASEXP4
    {SpriteNum::SPR_PLSE, 32772, 4, nullptr, StateNum::S_NULL, 0,
     0}, // S_PLASEXP5
    {SpriteNum::SPR_MISL, 32768, 1, nullptr, StateNum::S_ROCKET, 0,
     0}, // S_ROCKET
    {SpriteNum::SPR_BFS1, 32768, 4, nullptr, StateNum::S_BFGSHOT2, 0,
     0}, // S_BFGSHOT
    {SpriteNum::SPR_BFS1, 32769, 4, nullptr, StateNum::S_BFGSHOT, 0,
     0}, // S_BFGSHOT2
    {SpriteNum::SPR_BFE1, 32768, 8, nullptr, StateNum::S_BFGLAND2, 0,
     0}, // S_BFGLAND
    {SpriteNum::SPR_BFE1, 32769, 8, nullptr, StateNum::S_BFGLAND3, 0,
     0}, // S_BFGLAND2
    {SpriteNum::SPR_BFE1, 32770, 8, action::bfgSpray, StateNum::S_BFGLAND4, 0,
     0}, // S_BFGLAND3
    {SpriteNum::SPR_BFE1, 32771, 8, nullptr, StateNum::S_BFGLAND5, 0,
     0}, // S_BFGLAND4
    {SpriteNum::SPR_BFE1, 32772, 8, nullptr, StateNum::S_BFGLAND6, 0,
     0}, // S_BFGLAND5
    {SpriteNum::SPR_BFE1, 32773, 8, nullptr, StateNum::S_NULL, 0,
     0}, // S_BFGLAND6
    {SpriteNum::SPR_BFE2, 32768, 8, nullptr, StateNum::S_BFGEXP2, 0,
     0}, // S_BFGEXP
    {SpriteNum::SPR_BFE2, 32769, 8, nullptr, StateNum::S_BFGEXP3, 0,
     0}, // S_BFGEXP2
    {SpriteNum::SPR_BFE2, 32770, 8, nullptr, StateNum::S_BFGEXP4, 0,
     0}, // S_BFGEXP3
    {SpriteNum::SPR_BFE2, 32771, 8, nullptr, StateNum::S_NULL, 0,
     0}, // S_BFGEXP4
    {SpriteNum::SPR_MISL, 32769, 8, action::explode, StateNum::S_EXPLODE2, 0,
     0}, // S_EXPLODE1
    {SpriteNum::SPR_MISL, 32770, 6, nullptr, StateNum::S_EXPLODE3, 0,
     0}, // S_EXPLODE2
    {SpriteNum::SPR_MISL, 32771, 4, nullptr, StateNum::S_NULL, 0,
     0}, // S_EXPLODE3
    {SpriteNum::SPR_TFOG, 32768, 6, nullptr, StateNum::S_TFOG01, 0,
     0}, // S_TFOG
    {SpriteNum::SPR_TFOG, 32769, 6, nullptr, StateNum::S_TFOG02, 0,
     0}, // S_TFOG01
    {SpriteNum::SPR_TFOG, 32768, 6, nullptr, StateNum::S_TFOG2, 0,
     0}, // S_TFOG02
    {SpriteNum::SPR_TFOG, 32769, 6, nullptr, StateNum::S_TFOG3, 0,
     0}, // S_TFOG2
    {SpriteNum::SPR_TFOG, 32770, 6, nullptr, StateNum::S_TFOG4, 0,
     0}, // S_TFOG3
    {SpriteNum::SPR_TFOG, 32771, 6, nullptr, StateNum::S_TFOG5, 0,
     0}, // S_TFOG4
    {SpriteNum::SPR_TFOG, 32772, 6, nullptr, StateNum::S_TFOG6, 0,
     0}, // S_TFOG5
    {SpriteNum::SPR_TFOG, 32773, 6, nullptr, StateNum::S_TFOG7, 0,
     0}, // S_TFOG6
    {SpriteNum::SPR_TFOG, 32774, 6, nullptr, StateNum::S_TFOG8, 0,
     0}, // S_TFOG7
    {SpriteNum::SPR_TFOG, 32775, 6, nullptr, StateNum::S_TFOG9, 0,
     0}, // S_TFOG8
    {SpriteNum::SPR_TFOG, 32776, 6, nullptr, StateNum::S_TFOG10, 0,
     0}, // S_TFOG9
    {SpriteNum::SPR_TFOG, 32777, 6, nullptr, StateNum::S_NULL, 0,
     0}, // S_TFOG10
    {SpriteNum::SPR_IFOG, 32768, 6, nullptr, StateNum::S_IFOG01, 0,
     0}, // S_IFOG
    {SpriteNum::SPR_IFOG, 32769, 6, nullptr, StateNum::S_IFOG02, 0,
     0}, // S_IFOG01
    {SpriteNum::SPR_IFOG, 32768, 6, nullptr, StateNum::S_IFOG2, 0,
     0}, // S_IFOG02
    {SpriteNum::SPR_IFOG, 32769, 6, nullptr, StateNum::S_IFOG3, 0,
     0}, // S_IFOG2
    {SpriteNum::SPR_IFOG, 32770, 6, nullptr, StateNum::S_IFOG4, 0,
     0}, // S_IFOG3
    {SpriteNum::SPR_IFOG, 32771, 6, nullptr, StateNum::S_IFOG5, 0,
     0},                                                              // S_IFOG4
    {SpriteNum::SPR_IFOG, 32772, 6, nullptr, StateNum::S_NULL, 0, 0}, // S_IFOG5
    {SpriteNum::SPR_PLAY, 0, -1, nullptr, StateNum::S_NULL, 0, 0},    // S_PLAY
    {SpriteNum::SPR_PLAY, 0, 4, nullptr, StateNum::S_PLAY_RUN2, 0,
     0}, // S_PLAY_RUN1
    {SpriteNum::SPR_PLAY, 1, 4, nullptr, StateNum::S_PLAY_RUN3, 0,
     0}, // S_PLAY_RUN2
    {SpriteNum::SPR_PLAY, 2, 4, nullptr, StateNum::S_PLAY_RUN4, 0,
     0}, // S_PLAY_RUN3
    {SpriteNum::SPR_PLAY, 3, 4, nullptr, StateNum::S_PLAY_RUN1, 0,
     0}, // S_PLAY_RUN4
    {SpriteNum::SPR_PLAY, 4, 12, nullptr, StateNum::S_PLAY, 0,
     0}, // S_PLAY_ATK1
    {SpriteNum::SPR_PLAY, 32773, 6, nullptr, StateNum::S_PLAY_ATK1, 0,
     0}, // S_PLAY_ATK2
    {SpriteNum::SPR_PLAY, 6, 4, nullptr, StateNum::S_PLAY_PAIN2, 0,
     0}, // S_PLAY_PAIN
    {SpriteNum::SPR_PLAY, 6, 4, action::pain, StateNum::S_PLAY, 0,
     0}, // S_PLAY_PAIN2
    {SpriteNum::SPR_PLAY, 7, 10, nullptr, StateNum::S_PLAY_DIE2, 0,
     0}, // S_PLAY_DIE1
    {SpriteNum::SPR_PLAY, 8, 10, action::playerScream, StateNum::S_PLAY_DIE3, 0,
     0}, // S_PLAY_DIE2
    {SpriteNum::SPR_PLAY, 9, 10, action::fall, StateNum::S_PLAY_DIE4, 0,
     0}, // S_PLAY_DIE3
    {SpriteNum::SPR_PLAY, 10, 10, nullptr, StateNum::S_PLAY_DIE5, 0,
     0}, // S_PLAY_DIE4
    {SpriteNum::SPR_PLAY, 11, 10, nullptr, StateNum::S_PLAY_DIE6, 0,
     0}, // S_PLAY_DIE5
    {SpriteNum::SPR_PLAY, 12, 10, nullptr, StateNum::S_PLAY_DIE7, 0,
     0}, // S_PLAY_DIE6
    {SpriteNum::SPR_PLAY, 13, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_PLAY_DIE7
    {SpriteNum::SPR_PLAY, 14, 5, nullptr, StateNum::S_PLAY_XDIE2, 0,
     0}, // S_PLAY_XDIE1
    {SpriteNum::SPR_PLAY, 15, 5, action::xScream, StateNum::S_PLAY_XDIE3, 0,
     0}, // S_PLAY_XDIE2
    {SpriteNum::SPR_PLAY, 16, 5, action::fall, StateNum::S_PLAY_XDIE4, 0,
     0}, // S_PLAY_XDIE3
    {SpriteNum::SPR_PLAY, 17, 5, nullptr, StateNum::S_PLAY_XDIE5, 0,
     0}, // S_PLAY_XDIE4
    {SpriteNum::SPR_PLAY, 18, 5, nullptr, StateNum::S_PLAY_XDIE6, 0,
     0}, // S_PLAY_XDIE5
    {SpriteNum::SPR_PLAY, 19, 5, nullptr, StateNum::S_PLAY_XDIE7, 0,
     0}, // S_PLAY_XDIE6
    {SpriteNum::SPR_PLAY, 20, 5, nullptr, StateNum::S_PLAY_XDIE8, 0,
     0}, // S_PLAY_XDIE7
    {SpriteNum::SPR_PLAY, 21, 5, nullptr, StateNum::S_PLAY_XDIE9, 0,
     0}, // S_PLAY_XDIE8
    {SpriteNum::SPR_PLAY, 22, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_PLAY_XDIE9
    {SpriteNum::SPR_POSS, 0, 10, action::look, StateNum::S_POSS_STND2, 0,
     0}, // S_POSS_STND
    {SpriteNum::SPR_POSS, 1, 10, action::look, StateNum::S_POSS_STND, 0,
     0}, // S_POSS_STND2
    {SpriteNum::SPR_POSS, 0, 4, action::chase, StateNum::S_POSS_RUN2, 0,
     0}, // S_POSS_RUN1
    {SpriteNum::SPR_POSS, 0, 4, action::chase, StateNum::S_POSS_RUN3, 0,
     0}, // S_POSS_RUN2
    {SpriteNum::SPR_POSS, 1, 4, action::chase, StateNum::S_POSS_RUN4, 0,
     0}, // S_POSS_RUN3
    {SpriteNum::SPR_POSS, 1, 4, action::chase, StateNum::S_POSS_RUN5, 0,
     0}, // S_POSS_RUN4
    {SpriteNum::SPR_POSS, 2, 4, action::chase, StateNum::S_POSS_RUN6, 0,
     0}, // S_POSS_RUN5
    {SpriteNum::SPR_POSS, 2, 4, action::chase, StateNum::S_POSS_RUN7, 0,
     0}, // S_POSS_RUN6
    {SpriteNum::SPR_POSS, 3, 4, action::chase, StateNum::S_POSS_RUN8, 0,
     0}, // S_POSS_RUN7
    {SpriteNum::SPR_POSS, 3, 4, action::chase, StateNum::S_POSS_RUN1, 0,
     0}, // S_POSS_RUN8
    {SpriteNum::SPR_POSS, 4, 10, action::faceTarget, StateNum::S_POSS_ATK2, 0,
     0}, // S_POSS_ATK1
    {SpriteNum::SPR_POSS, 5, 8, action::posAttack, StateNum::S_POSS_ATK3, 0,
     0}, // S_POSS_ATK2
    {SpriteNum::SPR_POSS, 4, 8, nullptr, StateNum::S_POSS_RUN1, 0,
     0}, // S_POSS_ATK3
    {SpriteNum::SPR_POSS, 6, 3, nullptr, StateNum::S_POSS_PAIN2, 0,
     0}, // S_POSS_PAIN
    {SpriteNum::SPR_POSS, 6, 3, action::pain, StateNum::S_POSS_RUN1, 0,
     0}, // S_POSS_PAIN2
    {SpriteNum::SPR_POSS, 7, 5, nullptr, StateNum::S_POSS_DIE2, 0,
     0}, // S_POSS_DIE1
    {SpriteNum::SPR_POSS, 8, 5, action::scream, StateNum::S_POSS_DIE3, 0,
     0}, // S_POSS_DIE2
    {SpriteNum::SPR_POSS, 9, 5, action::fall, StateNum::S_POSS_DIE4, 0,
     0}, // S_POSS_DIE3
    {SpriteNum::SPR_POSS, 10, 5, nullptr, StateNum::S_POSS_DIE5, 0,
     0}, // S_POSS_DIE4
    {SpriteNum::SPR_POSS, 11, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_POSS_DIE5
    {SpriteNum::SPR_POSS, 12, 5, nullptr, StateNum::S_POSS_XDIE2, 0,
     0}, // S_POSS_XDIE1
    {SpriteNum::SPR_POSS, 13, 5, action::xScream, StateNum::S_POSS_XDIE3, 0,
     0}, // S_POSS_XDIE2
    {SpriteNum::SPR_POSS, 14, 5, action::fall, StateNum::S_POSS_XDIE4, 0,
     0}, // S_POSS_XDIE3
    {SpriteNum::SPR_POSS, 15, 5, nullptr, StateNum::S_POSS_XDIE5, 0,
     0}, // S_POSS_XDIE4
    {SpriteNum::SPR_POSS, 16, 5, nullptr, StateNum::S_POSS_XDIE6, 0,
     0}, // S_POSS_XDIE5
    {SpriteNum::SPR_POSS, 17, 5, nullptr, StateNum::S_POSS_XDIE7, 0,
     0}, // S_POSS_XDIE6
    {SpriteNum::SPR_POSS, 18, 5, nullptr, StateNum::S_POSS_XDIE8, 0,
     0}, // S_POSS_XDIE7
    {SpriteNum::SPR_POSS, 19, 5, nullptr, StateNum::S_POSS_XDIE9, 0,
     0}, // S_POSS_XDIE8
    {SpriteNum::SPR_POSS, 20, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_POSS_XDIE9
    {SpriteNum::SPR_POSS, 10, 5, nullptr, StateNum::S_POSS_RAISE2, 0,
     0}, // S_POSS_RAISE1
    {SpriteNum::SPR_POSS, 9, 5, nullptr, StateNum::S_POSS_RAISE3, 0,
     0}, // S_POSS_RAISE2
    {SpriteNum::SPR_POSS, 8, 5, nullptr, StateNum::S_POSS_RAISE4, 0,
     0}, // S_POSS_RAISE3
    {SpriteNum::SPR_POSS, 7, 5, nullptr, StateNum::S_POSS_RUN1, 0,
     0}, // S_POSS_RAISE4
    {SpriteNum::SPR_SPOS, 0, 10, action::look, StateNum::S_SPOS_STND2, 0,
     0}, // S_SPOS_STND
    {SpriteNum::SPR_SPOS, 1, 10, action::look, StateNum::S_SPOS_STND, 0,
     0}, // S_SPOS_STND2
    {SpriteNum::SPR_SPOS, 0, 3, action::chase, StateNum::S_SPOS_RUN2, 0,
     0}, // S_SPOS_RUN1
    {SpriteNum::SPR_SPOS, 0, 3, action::chase, StateNum::S_SPOS_RUN3, 0,
     0}, // S_SPOS_RUN2
    {SpriteNum::SPR_SPOS, 1, 3, action::chase, StateNum::S_SPOS_RUN4, 0,
     0}, // S_SPOS_RUN3
    {SpriteNum::SPR_SPOS, 1, 3, action::chase, StateNum::S_SPOS_RUN5, 0,
     0}, // S_SPOS_RUN4
    {SpriteNum::SPR_SPOS, 2, 3, action::chase, StateNum::S_SPOS_RUN6, 0,
     0}, // S_SPOS_RUN5
    {SpriteNum::SPR_SPOS, 2, 3, action::chase, StateNum::S_SPOS_RUN7, 0,
     0}, // S_SPOS_RUN6
    {SpriteNum::SPR_SPOS, 3, 3, action::chase, StateNum::S_SPOS_RUN8, 0,
     0}, // S_SPOS_RUN7
    {SpriteNum::SPR_SPOS, 3, 3, action::chase, StateNum::S_SPOS_RUN1, 0,
     0}, // S_SPOS_RUN8
    {SpriteNum::SPR_SPOS, 4, 10, action::faceTarget, StateNum::S_SPOS_ATK2, 0,
     0}, // S_SPOS_ATK1
    {SpriteNum::SPR_SPOS, 32773, 10, action::sPosAttack, StateNum::S_SPOS_ATK3,
     0, 0}, // S_SPOS_ATK2
    {SpriteNum::SPR_SPOS, 4, 10, nullptr, StateNum::S_SPOS_RUN1, 0,
     0}, // S_SPOS_ATK3
    {SpriteNum::SPR_SPOS, 6, 3, nullptr, StateNum::S_SPOS_PAIN2, 0,
     0}, // S_SPOS_PAIN
    {SpriteNum::SPR_SPOS, 6, 3, action::pain, StateNum::S_SPOS_RUN1, 0,
     0}, // S_SPOS_PAIN2
    {SpriteNum::SPR_SPOS, 7, 5, nullptr, StateNum::S_SPOS_DIE2, 0,
     0}, // S_SPOS_DIE1
    {SpriteNum::SPR_SPOS, 8, 5, action::scream, StateNum::S_SPOS_DIE3, 0,
     0}, // S_SPOS_DIE2
    {SpriteNum::SPR_SPOS, 9, 5, action::fall, StateNum::S_SPOS_DIE4, 0,
     0}, // S_SPOS_DIE3
    {SpriteNum::SPR_SPOS, 10, 5, nullptr, StateNum::S_SPOS_DIE5, 0,
     0}, // S_SPOS_DIE4
    {SpriteNum::SPR_SPOS, 11, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SPOS_DIE5
    {SpriteNum::SPR_SPOS, 12, 5, nullptr, StateNum::S_SPOS_XDIE2, 0,
     0}, // S_SPOS_XDIE1
    {SpriteNum::SPR_SPOS, 13, 5, action::xScream, StateNum::S_SPOS_XDIE3, 0,
     0}, // S_SPOS_XDIE2
    {SpriteNum::SPR_SPOS, 14, 5, action::fall, StateNum::S_SPOS_XDIE4, 0,
     0}, // S_SPOS_XDIE3
    {SpriteNum::SPR_SPOS, 15, 5, nullptr, StateNum::S_SPOS_XDIE5, 0,
     0}, // S_SPOS_XDIE4
    {SpriteNum::SPR_SPOS, 16, 5, nullptr, StateNum::S_SPOS_XDIE6, 0,
     0}, // S_SPOS_XDIE5
    {SpriteNum::SPR_SPOS, 17, 5, nullptr, StateNum::S_SPOS_XDIE7, 0,
     0}, // S_SPOS_XDIE6
    {SpriteNum::SPR_SPOS, 18, 5, nullptr, StateNum::S_SPOS_XDIE8, 0,
     0}, // S_SPOS_XDIE7
    {SpriteNum::SPR_SPOS, 19, 5, nullptr, StateNum::S_SPOS_XDIE9, 0,
     0}, // S_SPOS_XDIE8
    {SpriteNum::SPR_SPOS, 20, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SPOS_XDIE9
    {SpriteNum::SPR_SPOS, 11, 5, nullptr, StateNum::S_SPOS_RAISE2, 0,
     0}, // S_SPOS_RAISE1
    {SpriteNum::SPR_SPOS, 10, 5, nullptr, StateNum::S_SPOS_RAISE3, 0,
     0}, // S_SPOS_RAISE2
    {SpriteNum::SPR_SPOS, 9, 5, nullptr, StateNum::S_SPOS_RAISE4, 0,
     0}, // S_SPOS_RAISE3
    {SpriteNum::SPR_SPOS, 8, 5, nullptr, StateNum::S_SPOS_RAISE5, 0,
     0}, // S_SPOS_RAISE4
    {SpriteNum::SPR_SPOS, 7, 5, nullptr, StateNum::S_SPOS_RUN1, 0,
     0}, // S_SPOS_RAISE5
    {SpriteNum::SPR_VILE, 0, 10, action::look, StateNum::S_VILE_STND2, 0,
     0}, // S_VILE_STND
    {SpriteNum::SPR_VILE, 1, 10, action::look, StateNum::S_VILE_STND, 0,
     0}, // S_VILE_STND2
    {SpriteNum::SPR_VILE, 0, 2, action::vileChase, StateNum::S_VILE_RUN2, 0,
     0}, // S_VILE_RUN1
    {SpriteNum::SPR_VILE, 0, 2, action::vileChase, StateNum::S_VILE_RUN3, 0,
     0}, // S_VILE_RUN2
    {SpriteNum::SPR_VILE, 1, 2, action::vileChase, StateNum::S_VILE_RUN4, 0,
     0}, // S_VILE_RUN3
    {SpriteNum::SPR_VILE, 1, 2, action::vileChase, StateNum::S_VILE_RUN5, 0,
     0}, // S_VILE_RUN4
    {SpriteNum::SPR_VILE, 2, 2, action::vileChase, StateNum::S_VILE_RUN6, 0,
     0}, // S_VILE_RUN5
    {SpriteNum::SPR_VILE, 2, 2, action::vileChase, StateNum::S_VILE_RUN7, 0,
     0}, // S_VILE_RUN6
    {SpriteNum::SPR_VILE, 3, 2, action::vileChase, StateNum::S_VILE_RUN8, 0,
     0}, // S_VILE_RUN7
    {SpriteNum::SPR_VILE, 3, 2, action::vileChase, StateNum::S_VILE_RUN9, 0,
     0}, // S_VILE_RUN8
    {SpriteNum::SPR_VILE, 4, 2, action::vileChase, StateNum::S_VILE_RUN10, 0,
     0}, // S_VILE_RUN9
    {SpriteNum::SPR_VILE, 4, 2, action::vileChase, StateNum::S_VILE_RUN11, 0,
     0}, // S_VILE_RUN10
    {SpriteNum::SPR_VILE, 5, 2, action::vileChase, StateNum::S_VILE_RUN12, 0,
     0}, // S_VILE_RUN11
    {SpriteNum::SPR_VILE, 5, 2, action::vileChase, StateNum::S_VILE_RUN1, 0,
     0}, // S_VILE_RUN12
    {SpriteNum::SPR_VILE, 32774, 0, action::vileStart, StateNum::S_VILE_ATK2, 0,
     0}, // S_VILE_ATK1
    {SpriteNum::SPR_VILE, 32774, 10, action::faceTarget, StateNum::S_VILE_ATK3,
     0, 0}, // S_VILE_ATK2
    {SpriteNum::SPR_VILE, 32775, 8, action::vileTarget, StateNum::S_VILE_ATK4,
     0, 0}, // S_VILE_ATK3
    {SpriteNum::SPR_VILE, 32776, 8, action::faceTarget, StateNum::S_VILE_ATK5,
     0, 0}, // S_VILE_ATK4
    {SpriteNum::SPR_VILE, 32777, 8, action::faceTarget, StateNum::S_VILE_ATK6,
     0, 0}, // S_VILE_ATK5
    {SpriteNum::SPR_VILE, 32778, 8, action::faceTarget, StateNum::S_VILE_ATK7,
     0, 0}, // S_VILE_ATK6
    {SpriteNum::SPR_VILE, 32779, 8, action::faceTarget, StateNum::S_VILE_ATK8,
     0, 0}, // S_VILE_ATK7
    {SpriteNum::SPR_VILE, 32780, 8, action::faceTarget, StateNum::S_VILE_ATK9,
     0, 0}, // S_VILE_ATK8
    {SpriteNum::SPR_VILE, 32781, 8, action::faceTarget, StateNum::S_VILE_ATK10,
     0, 0}, // S_VILE_ATK9
    {SpriteNum::SPR_VILE, 32782, 8, action::vileAttack, StateNum::S_VILE_ATK11,
     0, 0}, // S_VILE_ATK10
    {SpriteNum::SPR_VILE, 32783, 20, nullptr, StateNum::S_VILE_RUN1, 0,
     0}, // S_VILE_ATK11
    {SpriteNum::SPR_VILE, 32794, 10, nullptr, StateNum::S_VILE_HEAL2, 0,
     0}, // S_VILE_HEAL1
    {SpriteNum::SPR_VILE, 32795, 10, nullptr, StateNum::S_VILE_HEAL3, 0,
     0}, // S_VILE_HEAL2
    {SpriteNum::SPR_VILE, 32796, 10, nullptr, StateNum::S_VILE_RUN1, 0,
     0}, // S_VILE_HEAL3
    {SpriteNum::SPR_VILE, 16, 5, nullptr, StateNum::S_VILE_PAIN2, 0,
     0}, // S_VILE_PAIN
    {SpriteNum::SPR_VILE, 16, 5, action::pain, StateNum::S_VILE_RUN1, 0,
     0}, // S_VILE_PAIN2
    {SpriteNum::SPR_VILE, 16, 7, nullptr, StateNum::S_VILE_DIE2, 0,
     0}, // S_VILE_DIE1
    {SpriteNum::SPR_VILE, 17, 7, action::scream, StateNum::S_VILE_DIE3, 0,
     0}, // S_VILE_DIE2
    {SpriteNum::SPR_VILE, 18, 7, action::fall, StateNum::S_VILE_DIE4, 0,
     0}, // S_VILE_DIE3
    {SpriteNum::SPR_VILE, 19, 7, nullptr, StateNum::S_VILE_DIE5, 0,
     0}, // S_VILE_DIE4
    {SpriteNum::SPR_VILE, 20, 7, nullptr, StateNum::S_VILE_DIE6, 0,
     0}, // S_VILE_DIE5
    {SpriteNum::SPR_VILE, 21, 7, nullptr, StateNum::S_VILE_DIE7, 0,
     0}, // S_VILE_DIE6
    {SpriteNum::SPR_VILE, 22, 7, nullptr, StateNum::S_VILE_DIE8, 0,
     0}, // S_VILE_DIE7
    {SpriteNum::SPR_VILE, 23, 5, nullptr, StateNum::S_VILE_DIE9, 0,
     0}, // S_VILE_DIE8
    {SpriteNum::SPR_VILE, 24, 5, nullptr, StateNum::S_VILE_DIE10, 0,
     0}, // S_VILE_DIE9
    {SpriteNum::SPR_VILE, 25, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_VILE_DIE10
    {SpriteNum::SPR_FIRE, 32768, 2, action::startFire, StateNum::S_FIRE2, 0,
     0}, // S_FIRE1
    {SpriteNum::SPR_FIRE, 32769, 2, action::fire, StateNum::S_FIRE3, 0,
     0}, // S_FIRE2
    {SpriteNum::SPR_FIRE, 32768, 2, action::fire, StateNum::S_FIRE4, 0,
     0}, // S_FIRE3
    {SpriteNum::SPR_FIRE, 32769, 2, action::fire, StateNum::S_FIRE5, 0,
     0}, // S_FIRE4
    {SpriteNum::SPR_FIRE, 32770, 2, action::fireCrackle, StateNum::S_FIRE6, 0,
     0}, // S_FIRE5
    {SpriteNum::SPR_FIRE, 32769, 2, action::fire, StateNum::S_FIRE7, 0,
     0}, // S_FIRE6
    {SpriteNum::SPR_FIRE, 32770, 2, action::fire, StateNum::S_FIRE8, 0,
     0}, // S_FIRE7
    {SpriteNum::SPR_FIRE, 32769, 2, action::fire, StateNum::S_FIRE9, 0,
     0}, // S_FIRE8
    {SpriteNum::SPR_FIRE, 32770, 2, action::fire, StateNum::S_FIRE10, 0,
     0}, // S_FIRE9
    {SpriteNum::SPR_FIRE, 32771, 2, action::fire, StateNum::S_FIRE11, 0,
     0}, // S_FIRE10
    {SpriteNum::SPR_FIRE, 32770, 2, action::fire, StateNum::S_FIRE12, 0,
     0}, // S_FIRE11
    {SpriteNum::SPR_FIRE, 32771, 2, action::fire, StateNum::S_FIRE13, 0,
     0}, // S_FIRE12
    {SpriteNum::SPR_FIRE, 32770, 2, action::fire, StateNum::S_FIRE14, 0,
     0}, // S_FIRE13
    {SpriteNum::SPR_FIRE, 32771, 2, action::fire, StateNum::S_FIRE15, 0,
     0}, // S_FIRE14
    {SpriteNum::SPR_FIRE, 32772, 2, action::fire, StateNum::S_FIRE16, 0,
     0}, // S_FIRE15
    {SpriteNum::SPR_FIRE, 32771, 2, action::fire, StateNum::S_FIRE17, 0,
     0}, // S_FIRE16
    {SpriteNum::SPR_FIRE, 32772, 2, action::fire, StateNum::S_FIRE18, 0,
     0}, // S_FIRE17
    {SpriteNum::SPR_FIRE, 32771, 2, action::fire, StateNum::S_FIRE19, 0,
     0}, // S_FIRE18
    {SpriteNum::SPR_FIRE, 32772, 2, action::fireCrackle, StateNum::S_FIRE20, 0,
     0}, // S_FIRE19
    {SpriteNum::SPR_FIRE, 32773, 2, action::fire, StateNum::S_FIRE21, 0,
     0}, // S_FIRE20
    {SpriteNum::SPR_FIRE, 32772, 2, action::fire, StateNum::S_FIRE22, 0,
     0}, // S_FIRE21
    {SpriteNum::SPR_FIRE, 32773, 2, action::fire, StateNum::S_FIRE23, 0,
     0}, // S_FIRE22
    {SpriteNum::SPR_FIRE, 32772, 2, action::fire, StateNum::S_FIRE24, 0,
     0}, // S_FIRE23
    {SpriteNum::SPR_FIRE, 32773, 2, action::fire, StateNum::S_FIRE25, 0,
     0}, // S_FIRE24
    {SpriteNum::SPR_FIRE, 32774, 2, action::fire, StateNum::S_FIRE26, 0,
     0}, // S_FIRE25
    {SpriteNum::SPR_FIRE, 32775, 2, action::fire, StateNum::S_FIRE27, 0,
     0}, // S_FIRE26
    {SpriteNum::SPR_FIRE, 32774, 2, action::fire, StateNum::S_FIRE28, 0,
     0}, // S_FIRE27
    {SpriteNum::SPR_FIRE, 32775, 2, action::fire, StateNum::S_FIRE29, 0,
     0}, // S_FIRE28
    {SpriteNum::SPR_FIRE, 32774, 2, action::fire, StateNum::S_FIRE30, 0,
     0}, // S_FIRE29
    {SpriteNum::SPR_FIRE, 32775, 2, action::fire, StateNum::S_NULL, 0,
     0},                                                            // S_FIRE30
    {SpriteNum::SPR_PUFF, 1, 4, nullptr, StateNum::S_SMOKE2, 0, 0}, // S_SMOKE1
    {SpriteNum::SPR_PUFF, 2, 4, nullptr, StateNum::S_SMOKE3, 0, 0}, // S_SMOKE2
    {SpriteNum::SPR_PUFF, 1, 4, nullptr, StateNum::S_SMOKE4, 0, 0}, // S_SMOKE3
    {SpriteNum::SPR_PUFF, 2, 4, nullptr, StateNum::S_SMOKE5, 0, 0}, // S_SMOKE4
    {SpriteNum::SPR_PUFF, 3, 4, nullptr, StateNum::S_NULL, 0, 0},   // S_SMOKE5
    {SpriteNum::SPR_FATB, 32768, 2, action::tracer, StateNum::S_TRACER2, 0,
     0}, // S_TRACER
    {SpriteNum::SPR_FATB, 32769, 2, action::tracer, StateNum::S_TRACER, 0,
     0}, // S_TRACER2
    {SpriteNum::SPR_FBXP, 32768, 8, nullptr, StateNum::S_TRACEEXP2, 0,
     0}, // S_TRACEEXP1
    {SpriteNum::SPR_FBXP, 32769, 6, nullptr, StateNum::S_TRACEEXP3, 0,
     0}, // S_TRACEEXP2
    {SpriteNum::SPR_FBXP, 32770, 4, nullptr, StateNum::S_NULL, 0,
     0}, // S_TRACEEXP3
    {SpriteNum::SPR_SKEL, 0, 10, action::look, StateNum::S_SKEL_STND2, 0,
     0}, // S_SKEL_STND
    {SpriteNum::SPR_SKEL, 1, 10, action::look, StateNum::S_SKEL_STND, 0,
     0}, // S_SKEL_STND2
    {SpriteNum::SPR_SKEL, 0, 2, action::chase, StateNum::S_SKEL_RUN2, 0,
     0}, // S_SKEL_RUN1
    {SpriteNum::SPR_SKEL, 0, 2, action::chase, StateNum::S_SKEL_RUN3, 0,
     0}, // S_SKEL_RUN2
    {SpriteNum::SPR_SKEL, 1, 2, action::chase, StateNum::S_SKEL_RUN4, 0,
     0}, // S_SKEL_RUN3
    {SpriteNum::SPR_SKEL, 1, 2, action::chase, StateNum::S_SKEL_RUN5, 0,
     0}, // S_SKEL_RUN4
    {SpriteNum::SPR_SKEL, 2, 2, action::chase, StateNum::S_SKEL_RUN6, 0,
     0}, // S_SKEL_RUN5
    {SpriteNum::SPR_SKEL, 2, 2, action::chase, StateNum::S_SKEL_RUN7, 0,
     0}, // S_SKEL_RUN6
    {SpriteNum::SPR_SKEL, 3, 2, action::chase, StateNum::S_SKEL_RUN8, 0,
     0}, // S_SKEL_RUN7
    {SpriteNum::SPR_SKEL, 3, 2, action::chase, StateNum::S_SKEL_RUN9, 0,
     0}, // S_SKEL_RUN8
    {SpriteNum::SPR_SKEL, 4, 2, action::chase, StateNum::S_SKEL_RUN10, 0,
     0}, // S_SKEL_RUN9
    {SpriteNum::SPR_SKEL, 4, 2, action::chase, StateNum::S_SKEL_RUN11, 0,
     0}, // S_SKEL_RUN10
    {SpriteNum::SPR_SKEL, 5, 2, action::chase, StateNum::S_SKEL_RUN12, 0,
     0}, // S_SKEL_RUN11
    {SpriteNum::SPR_SKEL, 5, 2, action::chase, StateNum::S_SKEL_RUN1, 0,
     0}, // S_SKEL_RUN12
    {SpriteNum::SPR_SKEL, 6, 0, action::faceTarget, StateNum::S_SKEL_FIST2, 0,
     0}, // S_SKEL_FIST1
    {SpriteNum::SPR_SKEL, 6, 6, action::skelWhoosh, StateNum::S_SKEL_FIST3, 0,
     0}, // S_SKEL_FIST2
    {SpriteNum::SPR_SKEL, 7, 6, action::faceTarget, StateNum::S_SKEL_FIST4, 0,
     0}, // S_SKEL_FIST3
    {SpriteNum::SPR_SKEL, 8, 6, action::skelFist, StateNum::S_SKEL_RUN1, 0,
     0}, // S_SKEL_FIST4
    {SpriteNum::SPR_SKEL, 32777, 0, action::faceTarget, StateNum::S_SKEL_MISS2,
     0, 0}, // S_SKEL_MISS1
    {SpriteNum::SPR_SKEL, 32777, 10, action::faceTarget, StateNum::S_SKEL_MISS3,
     0, 0}, // S_SKEL_MISS2
    {SpriteNum::SPR_SKEL, 10, 10, action::skelMissile, StateNum::S_SKEL_MISS4,
     0, 0}, // S_SKEL_MISS3
    {SpriteNum::SPR_SKEL, 10, 10, action::faceTarget, StateNum::S_SKEL_RUN1, 0,
     0}, // S_SKEL_MISS4
    {SpriteNum::SPR_SKEL, 11, 5, nullptr, StateNum::S_SKEL_PAIN2, 0,
     0}, // S_SKEL_PAIN
    {SpriteNum::SPR_SKEL, 11, 5, action::pain, StateNum::S_SKEL_RUN1, 0,
     0}, // S_SKEL_PAIN2
    {SpriteNum::SPR_SKEL, 11, 7, nullptr, StateNum::S_SKEL_DIE2, 0,
     0}, // S_SKEL_DIE1
    {SpriteNum::SPR_SKEL, 12, 7, nullptr, StateNum::S_SKEL_DIE3, 0,
     0}, // S_SKEL_DIE2
    {SpriteNum::SPR_SKEL, 13, 7, action::scream, StateNum::S_SKEL_DIE4, 0,
     0}, // S_SKEL_DIE3
    {SpriteNum::SPR_SKEL, 14, 7, action::fall, StateNum::S_SKEL_DIE5, 0,
     0}, // S_SKEL_DIE4
    {SpriteNum::SPR_SKEL, 15, 7, nullptr, StateNum::S_SKEL_DIE6, 0,
     0}, // S_SKEL_DIE5
    {SpriteNum::SPR_SKEL, 16, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SKEL_DIE6
    {SpriteNum::SPR_SKEL, 16, 5, nullptr, StateNum::S_SKEL_RAISE2, 0,
     0}, // S_SKEL_RAISE1
    {SpriteNum::SPR_SKEL, 15, 5, nullptr, StateNum::S_SKEL_RAISE3, 0,
     0}, // S_SKEL_RAISE2
    {SpriteNum::SPR_SKEL, 14, 5, nullptr, StateNum::S_SKEL_RAISE4, 0,
     0}, // S_SKEL_RAISE3
    {SpriteNum::SPR_SKEL, 13, 5, nullptr, StateNum::S_SKEL_RAISE5, 0,
     0}, // S_SKEL_RAISE4
    {SpriteNum::SPR_SKEL, 12, 5, nullptr, StateNum::S_SKEL_RAISE6, 0,
     0}, // S_SKEL_RAISE5
    {SpriteNum::SPR_SKEL, 11, 5, nullptr, StateNum::S_SKEL_RUN1, 0,
     0}, // S_SKEL_RAISE6
    {SpriteNum::SPR_MANF, 32768, 4, nullptr, StateNum::S_FATSHOT2, 0,
     0}, // S_FATSHOT1
    {SpriteNum::SPR_MANF, 32769, 4, nullptr, StateNum::S_FATSHOT1, 0,
     0}, // S_FATSHOT2
    {SpriteNum::SPR_MISL, 32769, 8, nullptr, StateNum::S_FATSHOTX2, 0,
     0}, // S_FATSHOTX1
    {SpriteNum::SPR_MISL, 32770, 6, nullptr, StateNum::S_FATSHOTX3, 0,
     0}, // S_FATSHOTX2
    {SpriteNum::SPR_MISL, 32771, 4, nullptr, StateNum::S_NULL, 0,
     0}, // S_FATSHOTX3
    {SpriteNum::SPR_FATT, 0, 15, action::look, StateNum::S_FATT_STND2, 0,
     0}, // S_FATT_STND
    {SpriteNum::SPR_FATT, 1, 15, action::look, StateNum::S_FATT_STND, 0,
     0}, // S_FATT_STND2
    {SpriteNum::SPR_FATT, 0, 4, action::chase, StateNum::S_FATT_RUN2, 0,
     0}, // S_FATT_RUN1
    {SpriteNum::SPR_FATT, 0, 4, action::chase, StateNum::S_FATT_RUN3, 0,
     0}, // S_FATT_RUN2
    {SpriteNum::SPR_FATT, 1, 4, action::chase, StateNum::S_FATT_RUN4, 0,
     0}, // S_FATT_RUN3
    {SpriteNum::SPR_FATT, 1, 4, action::chase, StateNum::S_FATT_RUN5, 0,
     0}, // S_FATT_RUN4
    {SpriteNum::SPR_FATT, 2, 4, action::chase, StateNum::S_FATT_RUN6, 0,
     0}, // S_FATT_RUN5
    {SpriteNum::SPR_FATT, 2, 4, action::chase, StateNum::S_FATT_RUN7, 0,
     0}, // S_FATT_RUN6
    {SpriteNum::SPR_FATT, 3, 4, action::chase, StateNum::S_FATT_RUN8, 0,
     0}, // S_FATT_RUN7
    {SpriteNum::SPR_FATT, 3, 4, action::chase, StateNum::S_FATT_RUN9, 0,
     0}, // S_FATT_RUN8
    {SpriteNum::SPR_FATT, 4, 4, action::chase, StateNum::S_FATT_RUN10, 0,
     0}, // S_FATT_RUN9
    {SpriteNum::SPR_FATT, 4, 4, action::chase, StateNum::S_FATT_RUN11, 0,
     0}, // S_FATT_RUN10
    {SpriteNum::SPR_FATT, 5, 4, action::chase, StateNum::S_FATT_RUN12, 0,
     0}, // S_FATT_RUN11
    {SpriteNum::SPR_FATT, 5, 4, action::chase, StateNum::S_FATT_RUN1, 0,
     0}, // S_FATT_RUN12
    {SpriteNum::SPR_FATT, 6, 20, action::fatRaise, StateNum::S_FATT_ATK2, 0,
     0}, // S_FATT_ATK1
    {SpriteNum::SPR_FATT, 32775, 10, action::fatAttack1, StateNum::S_FATT_ATK3,
     0, 0}, // S_FATT_ATK2
    {SpriteNum::SPR_FATT, 8, 5, action::faceTarget, StateNum::S_FATT_ATK4, 0,
     0}, // S_FATT_ATK3
    {SpriteNum::SPR_FATT, 6, 5, action::faceTarget, StateNum::S_FATT_ATK5, 0,
     0}, // S_FATT_ATK4
    {SpriteNum::SPR_FATT, 32775, 10, action::fatAttack2, StateNum::S_FATT_ATK6,
     0, 0}, // S_FATT_ATK5
    {SpriteNum::SPR_FATT, 8, 5, action::faceTarget, StateNum::S_FATT_ATK7, 0,
     0}, // S_FATT_ATK6
    {SpriteNum::SPR_FATT, 6, 5, action::faceTarget, StateNum::S_FATT_ATK8, 0,
     0}, // S_FATT_ATK7
    {SpriteNum::SPR_FATT, 32775, 10, action::fatAttack3, StateNum::S_FATT_ATK9,
     0, 0}, // S_FATT_ATK8
    {SpriteNum::SPR_FATT, 8, 5, action::faceTarget, StateNum::S_FATT_ATK10, 0,
     0}, // S_FATT_ATK9
    {SpriteNum::SPR_FATT, 6, 5, action::faceTarget, StateNum::S_FATT_RUN1, 0,
     0}, // S_FATT_ATK10
    {SpriteNum::SPR_FATT, 9, 3, nullptr, StateNum::S_FATT_PAIN2, 0,
     0}, // S_FATT_PAIN
    {SpriteNum::SPR_FATT, 9, 3, action::pain, StateNum::S_FATT_RUN1, 0,
     0}, // S_FATT_PAIN2
    {SpriteNum::SPR_FATT, 10, 6, nullptr, StateNum::S_FATT_DIE2, 0,
     0}, // S_FATT_DIE1
    {SpriteNum::SPR_FATT, 11, 6, action::scream, StateNum::S_FATT_DIE3, 0,
     0}, // S_FATT_DIE2
    {SpriteNum::SPR_FATT, 12, 6, action::fall, StateNum::S_FATT_DIE4, 0,
     0}, // S_FATT_DIE3
    {SpriteNum::SPR_FATT, 13, 6, nullptr, StateNum::S_FATT_DIE5, 0,
     0}, // S_FATT_DIE4
    {SpriteNum::SPR_FATT, 14, 6, nullptr, StateNum::S_FATT_DIE6, 0,
     0}, // S_FATT_DIE5
    {SpriteNum::SPR_FATT, 15, 6, nullptr, StateNum::S_FATT_DIE7, 0,
     0}, // S_FATT_DIE6
    {SpriteNum::SPR_FATT, 16, 6, nullptr, StateNum::S_FATT_DIE8, 0,
     0}, // S_FATT_DIE7
    {SpriteNum::SPR_FATT, 17, 6, nullptr, StateNum::S_FATT_DIE9, 0,
     0}, // S_FATT_DIE8
    {SpriteNum::SPR_FATT, 18, 6, nullptr, StateNum::S_FATT_DIE10, 0,
     0}, // S_FATT_DIE9
    {SpriteNum::SPR_FATT, 19, -1, action::bossDeath, StateNum::S_NULL, 0,
     0}, // S_FATT_DIE10
    {SpriteNum::SPR_FATT, 17, 5, nullptr, StateNum::S_FATT_RAISE2, 0,
     0}, // S_FATT_RAISE1
    {SpriteNum::SPR_FATT, 16, 5, nullptr, StateNum::S_FATT_RAISE3, 0,
     0}, // S_FATT_RAISE2
    {SpriteNum::SPR_FATT, 15, 5, nullptr, StateNum::S_FATT_RAISE4, 0,
     0}, // S_FATT_RAISE3
    {SpriteNum::SPR_FATT, 14, 5, nullptr, StateNum::S_FATT_RAISE5, 0,
     0}, // S_FATT_RAISE4
    {SpriteNum::SPR_FATT, 13, 5, nullptr, StateNum::S_FATT_RAISE6, 0,
     0}, // S_FATT_RAISE5
    {SpriteNum::SPR_FATT, 12, 5, nullptr, StateNum::S_FATT_RAISE7, 0,
     0}, // S_FATT_RAISE6
    {SpriteNum::SPR_FATT, 11, 5, nullptr, StateNum::S_FATT_RAISE8, 0,
     0}, // S_FATT_RAISE7
    {SpriteNum::SPR_FATT, 10, 5, nullptr, StateNum::S_FATT_RUN1, 0,
     0}, // S_FATT_RAISE8
    {SpriteNum::SPR_CPOS, 0, 10, action::look, StateNum::S_CPOS_STND2, 0,
     0}, // S_CPOS_STND
    {SpriteNum::SPR_CPOS, 1, 10, action::look, StateNum::S_CPOS_STND, 0,
     0}, // S_CPOS_STND2
    {SpriteNum::SPR_CPOS, 0, 3, action::chase, StateNum::S_CPOS_RUN2, 0,
     0}, // S_CPOS_RUN1
    {SpriteNum::SPR_CPOS, 0, 3, action::chase, StateNum::S_CPOS_RUN3, 0,
     0}, // S_CPOS_RUN2
    {SpriteNum::SPR_CPOS, 1, 3, action::chase, StateNum::S_CPOS_RUN4, 0,
     0}, // S_CPOS_RUN3
    {SpriteNum::SPR_CPOS, 1, 3, action::chase, StateNum::S_CPOS_RUN5, 0,
     0}, // S_CPOS_RUN4
    {SpriteNum::SPR_CPOS, 2, 3, action::chase, StateNum::S_CPOS_RUN6, 0,
     0}, // S_CPOS_RUN5
    {SpriteNum::SPR_CPOS, 2, 3, action::chase, StateNum::S_CPOS_RUN7, 0,
     0}, // S_CPOS_RUN6
    {SpriteNum::SPR_CPOS, 3, 3, action::chase, StateNum::S_CPOS_RUN8, 0,
     0}, // S_CPOS_RUN7
    {SpriteNum::SPR_CPOS, 3, 3, action::chase, StateNum::S_CPOS_RUN1, 0,
     0}, // S_CPOS_RUN8
    {SpriteNum::SPR_CPOS, 4, 10, action::faceTarget, StateNum::S_CPOS_ATK2, 0,
     0}, // S_CPOS_ATK1
    {SpriteNum::SPR_CPOS, 32773, 4, action::cPosAttack, StateNum::S_CPOS_ATK3,
     0, 0}, // S_CPOS_ATK2
    {SpriteNum::SPR_CPOS, 32772, 4, action::cPosAttack, StateNum::S_CPOS_ATK4,
     0, 0}, // S_CPOS_ATK3
    {SpriteNum::SPR_CPOS, 5, 1, action::cPosRefire, StateNum::S_CPOS_ATK2, 0,
     0}, // S_CPOS_ATK4
    {SpriteNum::SPR_CPOS, 6, 3, nullptr, StateNum::S_CPOS_PAIN2, 0,
     0}, // S_CPOS_PAIN
    {SpriteNum::SPR_CPOS, 6, 3, action::pain, StateNum::S_CPOS_RUN1, 0,
     0}, // S_CPOS_PAIN2
    {SpriteNum::SPR_CPOS, 7, 5, nullptr, StateNum::S_CPOS_DIE2, 0,
     0}, // S_CPOS_DIE1
    {SpriteNum::SPR_CPOS, 8, 5, action::scream, StateNum::S_CPOS_DIE3, 0,
     0}, // S_CPOS_DIE2
    {SpriteNum::SPR_CPOS, 9, 5, action::fall, StateNum::S_CPOS_DIE4, 0,
     0}, // S_CPOS_DIE3
    {SpriteNum::SPR_CPOS, 10, 5, nullptr, StateNum::S_CPOS_DIE5, 0,
     0}, // S_CPOS_DIE4
    {SpriteNum::SPR_CPOS, 11, 5, nullptr, StateNum::S_CPOS_DIE6, 0,
     0}, // S_CPOS_DIE5
    {SpriteNum::SPR_CPOS, 12, 5, nullptr, StateNum::S_CPOS_DIE7, 0,
     0}, // S_CPOS_DIE6
    {SpriteNum::SPR_CPOS, 13, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_CPOS_DIE7
    {SpriteNum::SPR_CPOS, 14, 5, nullptr, StateNum::S_CPOS_XDIE2, 0,
     0}, // S_CPOS_XDIE1
    {SpriteNum::SPR_CPOS, 15, 5, action::xScream, StateNum::S_CPOS_XDIE3, 0,
     0}, // S_CPOS_XDIE2
    {SpriteNum::SPR_CPOS, 16, 5, action::fall, StateNum::S_CPOS_XDIE4, 0,
     0}, // S_CPOS_XDIE3
    {SpriteNum::SPR_CPOS, 17, 5, nullptr, StateNum::S_CPOS_XDIE5, 0,
     0}, // S_CPOS_XDIE4
    {SpriteNum::SPR_CPOS, 18, 5, nullptr, StateNum::S_CPOS_XDIE6, 0,
     0}, // S_CPOS_XDIE5
    {SpriteNum::SPR_CPOS, 19, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_CPOS_XDIE6
    {SpriteNum::SPR_CPOS, 13, 5, nullptr, StateNum::S_CPOS_RAISE2, 0,
     0}, // S_CPOS_RAISE1
    {SpriteNum::SPR_CPOS, 12, 5, nullptr, StateNum::S_CPOS_RAISE3, 0,
     0}, // S_CPOS_RAISE2
    {SpriteNum::SPR_CPOS, 11, 5, nullptr, StateNum::S_CPOS_RAISE4, 0,
     0}, // S_CPOS_RAISE3
    {SpriteNum::SPR_CPOS, 10, 5, nullptr, StateNum::S_CPOS_RAISE5, 0,
     0}, // S_CPOS_RAISE4
    {SpriteNum::SPR_CPOS, 9, 5, nullptr, StateNum::S_CPOS_RAISE6, 0,
     0}, // S_CPOS_RAISE5
    {SpriteNum::SPR_CPOS, 8, 5, nullptr, StateNum::S_CPOS_RAISE7, 0,
     0}, // S_CPOS_RAISE6
    {SpriteNum::SPR_CPOS, 7, 5, nullptr, StateNum::S_CPOS_RUN1, 0,
     0}, // S_CPOS_RAISE7
    {SpriteNum::SPR_TROO, 0, 10, action::look, StateNum::S_TROO_STND2, 0,
     0}, // S_TROO_STND
    {SpriteNum::SPR_TROO, 1, 10, action::look, StateNum::S_TROO_STND, 0,
     0}, // S_TROO_STND2
    {SpriteNum::SPR_TROO, 0, 3, action::chase, StateNum::S_TROO_RUN2, 0,
     0}, // S_TROO_RUN1
    {SpriteNum::SPR_TROO, 0, 3, action::chase, StateNum::S_TROO_RUN3, 0,
     0}, // S_TROO_RUN2
    {SpriteNum::SPR_TROO, 1, 3, action::chase, StateNum::S_TROO_RUN4, 0,
     0}, // S_TROO_RUN3
    {SpriteNum::SPR_TROO, 1, 3, action::chase, StateNum::S_TROO_RUN5, 0,
     0}, // S_TROO_RUN4
    {SpriteNum::SPR_TROO, 2, 3, action::chase, StateNum::S_TROO_RUN6, 0,
     0}, // S_TROO_RUN5
    {SpriteNum::SPR_TROO, 2, 3, action::chase, StateNum::S_TROO_RUN7, 0,
     0}, // S_TROO_RUN6
    {SpriteNum::SPR_TROO, 3, 3, action::chase, StateNum::S_TROO_RUN8, 0,
     0}, // S_TROO_RUN7
    {SpriteNum::SPR_TROO, 3, 3, action::chase, StateNum::S_TROO_RUN1, 0,
     0}, // S_TROO_RUN8
    {SpriteNum::SPR_TROO, 4, 8, action::faceTarget, StateNum::S_TROO_ATK2, 0,
     0}, // S_TROO_ATK1
    {SpriteNum::SPR_TROO, 5, 8, action::faceTarget, StateNum::S_TROO_ATK3, 0,
     0}, // S_TROO_ATK2
    {SpriteNum::SPR_TROO, 6, 6, action::troopAttack, StateNum::S_TROO_RUN1, 0,
     0}, // S_TROO_ATK3
    {SpriteNum::SPR_TROO, 7, 2, nullptr, StateNum::S_TROO_PAIN2, 0,
     0}, // S_TROO_PAIN
    {SpriteNum::SPR_TROO, 7, 2, action::pain, StateNum::S_TROO_RUN1, 0,
     0}, // S_TROO_PAIN2
    {SpriteNum::SPR_TROO, 8, 8, nullptr, StateNum::S_TROO_DIE2, 0,
     0}, // S_TROO_DIE1
    {SpriteNum::SPR_TROO, 9, 8, action::scream, StateNum::S_TROO_DIE3, 0,
     0}, // S_TROO_DIE2
    {SpriteNum::SPR_TROO, 10, 6, nullptr, StateNum::S_TROO_DIE4, 0,
     0}, // S_TROO_DIE3
    {SpriteNum::SPR_TROO, 11, 6, action::fall, StateNum::S_TROO_DIE5, 0,
     0}, // S_TROO_DIE4
    {SpriteNum::SPR_TROO, 12, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TROO_DIE5
    {SpriteNum::SPR_TROO, 13, 5, nullptr, StateNum::S_TROO_XDIE2, 0,
     0}, // S_TROO_XDIE1
    {SpriteNum::SPR_TROO, 14, 5, action::xScream, StateNum::S_TROO_XDIE3, 0,
     0}, // S_TROO_XDIE2
    {SpriteNum::SPR_TROO, 15, 5, nullptr, StateNum::S_TROO_XDIE4, 0,
     0}, // S_TROO_XDIE3
    {SpriteNum::SPR_TROO, 16, 5, action::fall, StateNum::S_TROO_XDIE5, 0,
     0}, // S_TROO_XDIE4
    {SpriteNum::SPR_TROO, 17, 5, nullptr, StateNum::S_TROO_XDIE6, 0,
     0}, // S_TROO_XDIE5
    {SpriteNum::SPR_TROO, 18, 5, nullptr, StateNum::S_TROO_XDIE7, 0,
     0}, // S_TROO_XDIE6
    {SpriteNum::SPR_TROO, 19, 5, nullptr, StateNum::S_TROO_XDIE8, 0,
     0}, // S_TROO_XDIE7
    {SpriteNum::SPR_TROO, 20, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TROO_XDIE8
    {SpriteNum::SPR_TROO, 12, 8, nullptr, StateNum::S_TROO_RAISE2, 0,
     0}, // S_TROO_RAISE1
    {SpriteNum::SPR_TROO, 11, 8, nullptr, StateNum::S_TROO_RAISE3, 0,
     0}, // S_TROO_RAISE2
    {SpriteNum::SPR_TROO, 10, 6, nullptr, StateNum::S_TROO_RAISE4, 0,
     0}, // S_TROO_RAISE3
    {SpriteNum::SPR_TROO, 9, 6, nullptr, StateNum::S_TROO_RAISE5, 0,
     0}, // S_TROO_RAISE4
    {SpriteNum::SPR_TROO, 8, 6, nullptr, StateNum::S_TROO_RUN1, 0,
     0}, // S_TROO_RAISE5
    {SpriteNum::SPR_SARG, 0, 10, action::look, StateNum::S_SARG_STND2, 0,
     0}, // S_SARG_STND
    {SpriteNum::SPR_SARG, 1, 10, action::look, StateNum::S_SARG_STND, 0,
     0}, // S_SARG_STND2
    {SpriteNum::SPR_SARG, 0, 2, action::chase, StateNum::S_SARG_RUN2, 0,
     0}, // S_SARG_RUN1
    {SpriteNum::SPR_SARG, 0, 2, action::chase, StateNum::S_SARG_RUN3, 0,
     0}, // S_SARG_RUN2
    {SpriteNum::SPR_SARG, 1, 2, action::chase, StateNum::S_SARG_RUN4, 0,
     0}, // S_SARG_RUN3
    {SpriteNum::SPR_SARG, 1, 2, action::chase, StateNum::S_SARG_RUN5, 0,
     0}, // S_SARG_RUN4
    {SpriteNum::SPR_SARG, 2, 2, action::chase, StateNum::S_SARG_RUN6, 0,
     0}, // S_SARG_RUN5
    {SpriteNum::SPR_SARG, 2, 2, action::chase, StateNum::S_SARG_RUN7, 0,
     0}, // S_SARG_RUN6
    {SpriteNum::SPR_SARG, 3, 2, action::chase, StateNum::S_SARG_RUN8, 0,
     0}, // S_SARG_RUN7
    {SpriteNum::SPR_SARG, 3, 2, action::chase, StateNum::S_SARG_RUN1, 0,
     0}, // S_SARG_RUN8
    {SpriteNum::SPR_SARG, 4, 8, action::faceTarget, StateNum::S_SARG_ATK2, 0,
     0}, // S_SARG_ATK1
    {SpriteNum::SPR_SARG, 5, 8, action::faceTarget, StateNum::S_SARG_ATK3, 0,
     0}, // S_SARG_ATK2
    {SpriteNum::SPR_SARG, 6, 8, action::sargAttack, StateNum::S_SARG_RUN1, 0,
     0}, // S_SARG_ATK3
    {SpriteNum::SPR_SARG, 7, 2, nullptr, StateNum::S_SARG_PAIN2, 0,
     0}, // S_SARG_PAIN
    {SpriteNum::SPR_SARG, 7, 2, action::pain, StateNum::S_SARG_RUN1, 0,
     0}, // S_SARG_PAIN2
    {SpriteNum::SPR_SARG, 8, 8, nullptr, StateNum::S_SARG_DIE2, 0,
     0}, // S_SARG_DIE1
    {SpriteNum::SPR_SARG, 9, 8, action::scream, StateNum::S_SARG_DIE3, 0,
     0}, // S_SARG_DIE2
    {SpriteNum::SPR_SARG, 10, 4, nullptr, StateNum::S_SARG_DIE4, 0,
     0}, // S_SARG_DIE3
    {SpriteNum::SPR_SARG, 11, 4, action::fall, StateNum::S_SARG_DIE5, 0,
     0}, // S_SARG_DIE4
    {SpriteNum::SPR_SARG, 12, 4, nullptr, StateNum::S_SARG_DIE6, 0,
     0}, // S_SARG_DIE5
    {SpriteNum::SPR_SARG, 13, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SARG_DIE6
    {SpriteNum::SPR_SARG, 13, 5, nullptr, StateNum::S_SARG_RAISE2, 0,
     0}, // S_SARG_RAISE1
    {SpriteNum::SPR_SARG, 12, 5, nullptr, StateNum::S_SARG_RAISE3, 0,
     0}, // S_SARG_RAISE2
    {SpriteNum::SPR_SARG, 11, 5, nullptr, StateNum::S_SARG_RAISE4, 0,
     0}, // S_SARG_RAISE3
    {SpriteNum::SPR_SARG, 10, 5, nullptr, StateNum::S_SARG_RAISE5, 0,
     0}, // S_SARG_RAISE4
    {SpriteNum::SPR_SARG, 9, 5, nullptr, StateNum::S_SARG_RAISE6, 0,
     0}, // S_SARG_RAISE5
    {SpriteNum::SPR_SARG, 8, 5, nullptr, StateNum::S_SARG_RUN1, 0,
     0}, // S_SARG_RAISE6
    {SpriteNum::SPR_HEAD, 0, 10, action::look, StateNum::S_HEAD_STND, 0,
     0}, // S_HEAD_STND
    {SpriteNum::SPR_HEAD, 0, 3, action::chase, StateNum::S_HEAD_RUN1, 0,
     0}, // S_HEAD_RUN1
    {SpriteNum::SPR_HEAD, 1, 5, action::faceTarget, StateNum::S_HEAD_ATK2, 0,
     0}, // S_HEAD_ATK1
    {SpriteNum::SPR_HEAD, 2, 5, action::faceTarget, StateNum::S_HEAD_ATK3, 0,
     0}, // S_HEAD_ATK2
    {SpriteNum::SPR_HEAD, 32771, 5, action::headAttack, StateNum::S_HEAD_RUN1,
     0, 0}, // S_HEAD_ATK3
    {SpriteNum::SPR_HEAD, 4, 3, nullptr, StateNum::S_HEAD_PAIN2, 0,
     0}, // S_HEAD_PAIN
    {SpriteNum::SPR_HEAD, 4, 3, action::pain, StateNum::S_HEAD_PAIN3, 0,
     0}, // S_HEAD_PAIN2
    {SpriteNum::SPR_HEAD, 5, 6, nullptr, StateNum::S_HEAD_RUN1, 0,
     0}, // S_HEAD_PAIN3
    {SpriteNum::SPR_HEAD, 6, 8, nullptr, StateNum::S_HEAD_DIE2, 0,
     0}, // S_HEAD_DIE1
    {SpriteNum::SPR_HEAD, 7, 8, action::scream, StateNum::S_HEAD_DIE3, 0,
     0}, // S_HEAD_DIE2
    {SpriteNum::SPR_HEAD, 8, 8, nullptr, StateNum::S_HEAD_DIE4, 0,
     0}, // S_HEAD_DIE3
    {SpriteNum::SPR_HEAD, 9, 8, nullptr, StateNum::S_HEAD_DIE5, 0,
     0}, // S_HEAD_DIE4
    {SpriteNum::SPR_HEAD, 10, 8, action::fall, StateNum::S_HEAD_DIE6, 0,
     0}, // S_HEAD_DIE5
    {SpriteNum::SPR_HEAD, 11, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HEAD_DIE6
    {SpriteNum::SPR_HEAD, 11, 8, nullptr, StateNum::S_HEAD_RAISE2, 0,
     0}, // S_HEAD_RAISE1
    {SpriteNum::SPR_HEAD, 10, 8, nullptr, StateNum::S_HEAD_RAISE3, 0,
     0}, // S_HEAD_RAISE2
    {SpriteNum::SPR_HEAD, 9, 8, nullptr, StateNum::S_HEAD_RAISE4, 0,
     0}, // S_HEAD_RAISE3
    {SpriteNum::SPR_HEAD, 8, 8, nullptr, StateNum::S_HEAD_RAISE5, 0,
     0}, // S_HEAD_RAISE4
    {SpriteNum::SPR_HEAD, 7, 8, nullptr, StateNum::S_HEAD_RAISE6, 0,
     0}, // S_HEAD_RAISE5
    {SpriteNum::SPR_HEAD, 6, 8, nullptr, StateNum::S_HEAD_RUN1, 0,
     0}, // S_HEAD_RAISE6
    {SpriteNum::SPR_BAL7, 32768, 4, nullptr, StateNum::S_BRBALL2, 0,
     0}, // S_BRBALL1
    {SpriteNum::SPR_BAL7, 32769, 4, nullptr, StateNum::S_BRBALL1, 0,
     0}, // S_BRBALL2
    {SpriteNum::SPR_BAL7, 32770, 6, nullptr, StateNum::S_BRBALLX2, 0,
     0}, // S_BRBALLX1
    {SpriteNum::SPR_BAL7, 32771, 6, nullptr, StateNum::S_BRBALLX3, 0,
     0}, // S_BRBALLX2
    {SpriteNum::SPR_BAL7, 32772, 6, nullptr, StateNum::S_NULL, 0,
     0}, // S_BRBALLX3
    {SpriteNum::SPR_BOSS, 0, 10, action::look, StateNum::S_BOSS_STND2, 0,
     0}, // S_BOSS_STND
    {SpriteNum::SPR_BOSS, 1, 10, action::look, StateNum::S_BOSS_STND, 0,
     0}, // S_BOSS_STND2
    {SpriteNum::SPR_BOSS, 0, 3, action::chase, StateNum::S_BOSS_RUN2, 0,
     0}, // S_BOSS_RUN1
    {SpriteNum::SPR_BOSS, 0, 3, action::chase, StateNum::S_BOSS_RUN3, 0,
     0}, // S_BOSS_RUN2
    {SpriteNum::SPR_BOSS, 1, 3, action::chase, StateNum::S_BOSS_RUN4, 0,
     0}, // S_BOSS_RUN3
    {SpriteNum::SPR_BOSS, 1, 3, action::chase, StateNum::S_BOSS_RUN5, 0,
     0}, // S_BOSS_RUN4
    {SpriteNum::SPR_BOSS, 2, 3, action::chase, StateNum::S_BOSS_RUN6, 0,
     0}, // S_BOSS_RUN5
    {SpriteNum::SPR_BOSS, 2, 3, action::chase, StateNum::S_BOSS_RUN7, 0,
     0}, // S_BOSS_RUN6
    {SpriteNum::SPR_BOSS, 3, 3, action::chase, StateNum::S_BOSS_RUN8, 0,
     0}, // S_BOSS_RUN7
    {SpriteNum::SPR_BOSS, 3, 3, action::chase, StateNum::S_BOSS_RUN1, 0,
     0}, // S_BOSS_RUN8
    {SpriteNum::SPR_BOSS, 4, 8, action::faceTarget, StateNum::S_BOSS_ATK2, 0,
     0}, // S_BOSS_ATK1
    {SpriteNum::SPR_BOSS, 5, 8, action::faceTarget, StateNum::S_BOSS_ATK3, 0,
     0}, // S_BOSS_ATK2
    {SpriteNum::SPR_BOSS, 6, 8, action::bruisAttack, StateNum::S_BOSS_RUN1, 0,
     0}, // S_BOSS_ATK3
    {SpriteNum::SPR_BOSS, 7, 2, nullptr, StateNum::S_BOSS_PAIN2, 0,
     0}, // S_BOSS_PAIN
    {SpriteNum::SPR_BOSS, 7, 2, action::pain, StateNum::S_BOSS_RUN1, 0,
     0}, // S_BOSS_PAIN2
    {SpriteNum::SPR_BOSS, 8, 8, nullptr, StateNum::S_BOSS_DIE2, 0,
     0}, // S_BOSS_DIE1
    {SpriteNum::SPR_BOSS, 9, 8, action::scream, StateNum::S_BOSS_DIE3, 0,
     0}, // S_BOSS_DIE2
    {SpriteNum::SPR_BOSS, 10, 8, nullptr, StateNum::S_BOSS_DIE4, 0,
     0}, // S_BOSS_DIE3
    {SpriteNum::SPR_BOSS, 11, 8, action::fall, StateNum::S_BOSS_DIE5, 0,
     0}, // S_BOSS_DIE4
    {SpriteNum::SPR_BOSS, 12, 8, nullptr, StateNum::S_BOSS_DIE6, 0,
     0}, // S_BOSS_DIE5
    {SpriteNum::SPR_BOSS, 13, 8, nullptr, StateNum::S_BOSS_DIE7, 0,
     0}, // S_BOSS_DIE6
    {SpriteNum::SPR_BOSS, 14, -1, action::bossDeath, StateNum::S_NULL, 0,
     0}, // S_BOSS_DIE7
    {SpriteNum::SPR_BOSS, 14, 8, nullptr, StateNum::S_BOSS_RAISE2, 0,
     0}, // S_BOSS_RAISE1
    {SpriteNum::SPR_BOSS, 13, 8, nullptr, StateNum::S_BOSS_RAISE3, 0,
     0}, // S_BOSS_RAISE2
    {SpriteNum::SPR_BOSS, 12, 8, nullptr, StateNum::S_BOSS_RAISE4, 0,
     0}, // S_BOSS_RAISE3
    {SpriteNum::SPR_BOSS, 11, 8, nullptr, StateNum::S_BOSS_RAISE5, 0,
     0}, // S_BOSS_RAISE4
    {SpriteNum::SPR_BOSS, 10, 8, nullptr, StateNum::S_BOSS_RAISE6, 0,
     0}, // S_BOSS_RAISE5
    {SpriteNum::SPR_BOSS, 9, 8, nullptr, StateNum::S_BOSS_RAISE7, 0,
     0}, // S_BOSS_RAISE6
    {SpriteNum::SPR_BOSS, 8, 8, nullptr, StateNum::S_BOSS_RUN1, 0,
     0}, // S_BOSS_RAISE7
    {SpriteNum::SPR_BOS2, 0, 10, action::look, StateNum::S_BOS2_STND2, 0,
     0}, // S_BOS2_STND
    {SpriteNum::SPR_BOS2, 1, 10, action::look, StateNum::S_BOS2_STND, 0,
     0}, // S_BOS2_STND2
    {SpriteNum::SPR_BOS2, 0, 3, action::chase, StateNum::S_BOS2_RUN2, 0,
     0}, // S_BOS2_RUN1
    {SpriteNum::SPR_BOS2, 0, 3, action::chase, StateNum::S_BOS2_RUN3, 0,
     0}, // S_BOS2_RUN2
    {SpriteNum::SPR_BOS2, 1, 3, action::chase, StateNum::S_BOS2_RUN4, 0,
     0}, // S_BOS2_RUN3
    {SpriteNum::SPR_BOS2, 1, 3, action::chase, StateNum::S_BOS2_RUN5, 0,
     0}, // S_BOS2_RUN4
    {SpriteNum::SPR_BOS2, 2, 3, action::chase, StateNum::S_BOS2_RUN6, 0,
     0}, // S_BOS2_RUN5
    {SpriteNum::SPR_BOS2, 2, 3, action::chase, StateNum::S_BOS2_RUN7, 0,
     0}, // S_BOS2_RUN6
    {SpriteNum::SPR_BOS2, 3, 3, action::chase, StateNum::S_BOS2_RUN8, 0,
     0}, // S_BOS2_RUN7
    {SpriteNum::SPR_BOS2, 3, 3, action::chase, StateNum::S_BOS2_RUN1, 0,
     0}, // S_BOS2_RUN8
    {SpriteNum::SPR_BOS2, 4, 8, action::faceTarget, StateNum::S_BOS2_ATK2, 0,
     0}, // S_BOS2_ATK1
    {SpriteNum::SPR_BOS2, 5, 8, action::faceTarget, StateNum::S_BOS2_ATK3, 0,
     0}, // S_BOS2_ATK2
    {SpriteNum::SPR_BOS2, 6, 8, action::bruisAttack, StateNum::S_BOS2_RUN1, 0,
     0}, // S_BOS2_ATK3
    {SpriteNum::SPR_BOS2, 7, 2, nullptr, StateNum::S_BOS2_PAIN2, 0,
     0}, // S_BOS2_PAIN
    {SpriteNum::SPR_BOS2, 7, 2, action::pain, StateNum::S_BOS2_RUN1, 0,
     0}, // S_BOS2_PAIN2
    {SpriteNum::SPR_BOS2, 8, 8, nullptr, StateNum::S_BOS2_DIE2, 0,
     0}, // S_BOS2_DIE1
    {SpriteNum::SPR_BOS2, 9, 8, action::scream, StateNum::S_BOS2_DIE3, 0,
     0}, // S_BOS2_DIE2
    {SpriteNum::SPR_BOS2, 10, 8, nullptr, StateNum::S_BOS2_DIE4, 0,
     0}, // S_BOS2_DIE3
    {SpriteNum::SPR_BOS2, 11, 8, action::fall, StateNum::S_BOS2_DIE5, 0,
     0}, // S_BOS2_DIE4
    {SpriteNum::SPR_BOS2, 12, 8, nullptr, StateNum::S_BOS2_DIE6, 0,
     0}, // S_BOS2_DIE5
    {SpriteNum::SPR_BOS2, 13, 8, nullptr, StateNum::S_BOS2_DIE7, 0,
     0}, // S_BOS2_DIE6
    {SpriteNum::SPR_BOS2, 14, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_BOS2_DIE7
    {SpriteNum::SPR_BOS2, 14, 8, nullptr, StateNum::S_BOS2_RAISE2, 0,
     0}, // S_BOS2_RAISE1
    {SpriteNum::SPR_BOS2, 13, 8, nullptr, StateNum::S_BOS2_RAISE3, 0,
     0}, // S_BOS2_RAISE2
    {SpriteNum::SPR_BOS2, 12, 8, nullptr, StateNum::S_BOS2_RAISE4, 0,
     0}, // S_BOS2_RAISE3
    {SpriteNum::SPR_BOS2, 11, 8, nullptr, StateNum::S_BOS2_RAISE5, 0,
     0}, // S_BOS2_RAISE4
    {SpriteNum::SPR_BOS2, 10, 8, nullptr, StateNum::S_BOS2_RAISE6, 0,
     0}, // S_BOS2_RAISE5
    {SpriteNum::SPR_BOS2, 9, 8, nullptr, StateNum::S_BOS2_RAISE7, 0,
     0}, // S_BOS2_RAISE6
    {SpriteNum::SPR_BOS2, 8, 8, nullptr, StateNum::S_BOS2_RUN1, 0,
     0}, // S_BOS2_RAISE7
    {SpriteNum::SPR_SKUL, 32768, 10, action::look, StateNum::S_SKULL_STND2, 0,
     0}, // S_SKULL_STND
    {SpriteNum::SPR_SKUL, 32769, 10, action::look, StateNum::S_SKULL_STND, 0,
     0}, // S_SKULL_STND2
    {SpriteNum::SPR_SKUL, 32768, 6, action::chase, StateNum::S_SKULL_RUN2, 0,
     0}, // S_SKULL_RUN1
    {SpriteNum::SPR_SKUL, 32769, 6, action::chase, StateNum::S_SKULL_RUN1, 0,
     0}, // S_SKULL_RUN2
    {SpriteNum::SPR_SKUL, 32770, 10, action::faceTarget, StateNum::S_SKULL_ATK2,
     0, 0}, // S_SKULL_ATK1
    {SpriteNum::SPR_SKUL, 32771, 4, action::skullAttack, StateNum::S_SKULL_ATK3,
     0, 0}, // S_SKULL_ATK2
    {SpriteNum::SPR_SKUL, 32770, 4, nullptr, StateNum::S_SKULL_ATK4, 0,
     0}, // S_SKULL_ATK3
    {SpriteNum::SPR_SKUL, 32771, 4, nullptr, StateNum::S_SKULL_ATK3, 0,
     0}, // S_SKULL_ATK4
    {SpriteNum::SPR_SKUL, 32772, 3, nullptr, StateNum::S_SKULL_PAIN2, 0,
     0}, // S_SKULL_PAIN
    {SpriteNum::SPR_SKUL, 32772, 3, action::pain, StateNum::S_SKULL_RUN1, 0,
     0}, // S_SKULL_PAIN2
    {SpriteNum::SPR_SKUL, 32773, 6, nullptr, StateNum::S_SKULL_DIE2, 0,
     0}, // S_SKULL_DIE1
    {SpriteNum::SPR_SKUL, 32774, 6, action::scream, StateNum::S_SKULL_DIE3, 0,
     0}, // S_SKULL_DIE2
    {SpriteNum::SPR_SKUL, 32775, 6, nullptr, StateNum::S_SKULL_DIE4, 0,
     0}, // S_SKULL_DIE3
    {SpriteNum::SPR_SKUL, 32776, 6, action::fall, StateNum::S_SKULL_DIE5, 0,
     0}, // S_SKULL_DIE4
    {SpriteNum::SPR_SKUL, 9, 6, nullptr, StateNum::S_SKULL_DIE6, 0,
     0}, // S_SKULL_DIE5
    {SpriteNum::SPR_SKUL, 10, 6, nullptr, StateNum::S_NULL, 0,
     0}, // S_SKULL_DIE6
    {SpriteNum::SPR_SPID, 0, 10, action::look, StateNum::S_SPID_STND2, 0,
     0}, // S_SPID_STND
    {SpriteNum::SPR_SPID, 1, 10, action::look, StateNum::S_SPID_STND, 0,
     0}, // S_SPID_STND2
    {SpriteNum::SPR_SPID, 0, 3, action::metal, StateNum::S_SPID_RUN2, 0,
     0}, // S_SPID_RUN1
    {SpriteNum::SPR_SPID, 0, 3, action::chase, StateNum::S_SPID_RUN3, 0,
     0}, // S_SPID_RUN2
    {SpriteNum::SPR_SPID, 1, 3, action::chase, StateNum::S_SPID_RUN4, 0,
     0}, // S_SPID_RUN3
    {SpriteNum::SPR_SPID, 1, 3, action::chase, StateNum::S_SPID_RUN5, 0,
     0}, // S_SPID_RUN4
    {SpriteNum::SPR_SPID, 2, 3, action::metal, StateNum::S_SPID_RUN6, 0,
     0}, // S_SPID_RUN5
    {SpriteNum::SPR_SPID, 2, 3, action::chase, StateNum::S_SPID_RUN7, 0,
     0}, // S_SPID_RUN6
    {SpriteNum::SPR_SPID, 3, 3, action::chase, StateNum::S_SPID_RUN8, 0,
     0}, // S_SPID_RUN7
    {SpriteNum::SPR_SPID, 3, 3, action::chase, StateNum::S_SPID_RUN9, 0,
     0}, // S_SPID_RUN8
    {SpriteNum::SPR_SPID, 4, 3, action::metal, StateNum::S_SPID_RUN10, 0,
     0}, // S_SPID_RUN9
    {SpriteNum::SPR_SPID, 4, 3, action::chase, StateNum::S_SPID_RUN11, 0,
     0}, // S_SPID_RUN10
    {SpriteNum::SPR_SPID, 5, 3, action::chase, StateNum::S_SPID_RUN12, 0,
     0}, // S_SPID_RUN11
    {SpriteNum::SPR_SPID, 5, 3, action::chase, StateNum::S_SPID_RUN1, 0,
     0}, // S_SPID_RUN12
    {SpriteNum::SPR_SPID, 32768, 20, action::faceTarget, StateNum::S_SPID_ATK2,
     0, 0}, // S_SPID_ATK1
    {SpriteNum::SPR_SPID, 32774, 4, action::sPosAttack, StateNum::S_SPID_ATK3,
     0, 0}, // S_SPID_ATK2
    {SpriteNum::SPR_SPID, 32775, 4, action::sPosAttack, StateNum::S_SPID_ATK4,
     0, 0}, // S_SPID_ATK3
    {SpriteNum::SPR_SPID, 32775, 1, action::spidRefire, StateNum::S_SPID_ATK2,
     0, 0}, // S_SPID_ATK4
    {SpriteNum::SPR_SPID, 8, 3, nullptr, StateNum::S_SPID_PAIN2, 0,
     0}, // S_SPID_PAIN
    {SpriteNum::SPR_SPID, 8, 3, action::pain, StateNum::S_SPID_RUN1, 0,
     0}, // S_SPID_PAIN2
    {SpriteNum::SPR_SPID, 9, 20, action::scream, StateNum::S_SPID_DIE2, 0,
     0}, // S_SPID_DIE1
    {SpriteNum::SPR_SPID, 10, 10, action::fall, StateNum::S_SPID_DIE3, 0,
     0}, // S_SPID_DIE2
    {SpriteNum::SPR_SPID, 11, 10, nullptr, StateNum::S_SPID_DIE4, 0,
     0}, // S_SPID_DIE3
    {SpriteNum::SPR_SPID, 12, 10, nullptr, StateNum::S_SPID_DIE5, 0,
     0}, // S_SPID_DIE4
    {SpriteNum::SPR_SPID, 13, 10, nullptr, StateNum::S_SPID_DIE6, 0,
     0}, // S_SPID_DIE5
    {SpriteNum::SPR_SPID, 14, 10, nullptr, StateNum::S_SPID_DIE7, 0,
     0}, // S_SPID_DIE6
    {SpriteNum::SPR_SPID, 15, 10, nullptr, StateNum::S_SPID_DIE8, 0,
     0}, // S_SPID_DIE7
    {SpriteNum::SPR_SPID, 16, 10, nullptr, StateNum::S_SPID_DIE9, 0,
     0}, // S_SPID_DIE8
    {SpriteNum::SPR_SPID, 17, 10, nullptr, StateNum::S_SPID_DIE10, 0,
     0}, // S_SPID_DIE9
    {SpriteNum::SPR_SPID, 18, 30, nullptr, StateNum::S_SPID_DIE11, 0,
     0}, // S_SPID_DIE10
    {SpriteNum::SPR_SPID, 18, -1, action::bossDeath, StateNum::S_NULL, 0,
     0}, // S_SPID_DIE11
    {SpriteNum::SPR_BSPI, 0, 10, action::look, StateNum::S_BSPI_STND2, 0,
     0}, // S_BSPI_STND
    {SpriteNum::SPR_BSPI, 1, 10, action::look, StateNum::S_BSPI_STND, 0,
     0}, // S_BSPI_STND2
    {SpriteNum::SPR_BSPI, 0, 20, nullptr, StateNum::S_BSPI_RUN1, 0,
     0}, // S_BSPI_SIGHT
    {SpriteNum::SPR_BSPI, 0, 3, action::babyMetal, StateNum::S_BSPI_RUN2, 0,
     0}, // S_BSPI_RUN1
    {SpriteNum::SPR_BSPI, 0, 3, action::chase, StateNum::S_BSPI_RUN3, 0,
     0}, // S_BSPI_RUN2
    {SpriteNum::SPR_BSPI, 1, 3, action::chase, StateNum::S_BSPI_RUN4, 0,
     0}, // S_BSPI_RUN3
    {SpriteNum::SPR_BSPI, 1, 3, action::chase, StateNum::S_BSPI_RUN5, 0,
     0}, // S_BSPI_RUN4
    {SpriteNum::SPR_BSPI, 2, 3, action::chase, StateNum::S_BSPI_RUN6, 0,
     0}, // S_BSPI_RUN5
    {SpriteNum::SPR_BSPI, 2, 3, action::chase, StateNum::S_BSPI_RUN7, 0,
     0}, // S_BSPI_RUN6
    {SpriteNum::SPR_BSPI, 3, 3, action::babyMetal, StateNum::S_BSPI_RUN8, 0,
     0}, // S_BSPI_RUN7
    {SpriteNum::SPR_BSPI, 3, 3, action::chase, StateNum::S_BSPI_RUN9, 0,
     0}, // S_BSPI_RUN8
    {SpriteNum::SPR_BSPI, 4, 3, action::chase, StateNum::S_BSPI_RUN10, 0,
     0}, // S_BSPI_RUN9
    {SpriteNum::SPR_BSPI, 4, 3, action::chase, StateNum::S_BSPI_RUN11, 0,
     0}, // S_BSPI_RUN10
    {SpriteNum::SPR_BSPI, 5, 3, action::chase, StateNum::S_BSPI_RUN12, 0,
     0}, // S_BSPI_RUN11
    {SpriteNum::SPR_BSPI, 5, 3, action::chase, StateNum::S_BSPI_RUN1, 0,
     0}, // S_BSPI_RUN12
    {SpriteNum::SPR_BSPI, 32768, 20, action::faceTarget, StateNum::S_BSPI_ATK2,
     0, 0}, // S_BSPI_ATK1
    {SpriteNum::SPR_BSPI, 32774, 4, action::bspiAttack, StateNum::S_BSPI_ATK3,
     0, 0}, // S_BSPI_ATK2
    {SpriteNum::SPR_BSPI, 32775, 4, nullptr, StateNum::S_BSPI_ATK4, 0,
     0}, // S_BSPI_ATK3
    {SpriteNum::SPR_BSPI, 32775, 1, action::spidRefire, StateNum::S_BSPI_ATK2,
     0, 0}, // S_BSPI_ATK4
    {SpriteNum::SPR_BSPI, 8, 3, nullptr, StateNum::S_BSPI_PAIN2, 0,
     0}, // S_BSPI_PAIN
    {SpriteNum::SPR_BSPI, 8, 3, action::pain, StateNum::S_BSPI_RUN1, 0,
     0}, // S_BSPI_PAIN2
    {SpriteNum::SPR_BSPI, 9, 20, action::scream, StateNum::S_BSPI_DIE2, 0,
     0}, // S_BSPI_DIE1
    {SpriteNum::SPR_BSPI, 10, 7, action::fall, StateNum::S_BSPI_DIE3, 0,
     0}, // S_BSPI_DIE2
    {SpriteNum::SPR_BSPI, 11, 7, nullptr, StateNum::S_BSPI_DIE4, 0,
     0}, // S_BSPI_DIE3
    {SpriteNum::SPR_BSPI, 12, 7, nullptr, StateNum::S_BSPI_DIE5, 0,
     0}, // S_BSPI_DIE4
    {SpriteNum::SPR_BSPI, 13, 7, nullptr, StateNum::S_BSPI_DIE6, 0,
     0}, // S_BSPI_DIE5
    {SpriteNum::SPR_BSPI, 14, 7, nullptr, StateNum::S_BSPI_DIE7, 0,
     0}, // S_BSPI_DIE6
    {SpriteNum::SPR_BSPI, 15, -1, action::bossDeath, StateNum::S_NULL, 0,
     0}, // S_BSPI_DIE7
    {SpriteNum::SPR_BSPI, 15, 5, nullptr, StateNum::S_BSPI_RAISE2, 0,
     0}, // S_BSPI_RAISE1
    {SpriteNum::SPR_BSPI, 14, 5, nullptr, StateNum::S_BSPI_RAISE3, 0,
     0}, // S_BSPI_RAISE2
    {SpriteNum::SPR_BSPI, 13, 5, nullptr, StateNum::S_BSPI_RAISE4, 0,
     0}, // S_BSPI_RAISE3
    {SpriteNum::SPR_BSPI, 12, 5, nullptr, StateNum::S_BSPI_RAISE5, 0,
     0}, // S_BSPI_RAISE4
    {SpriteNum::SPR_BSPI, 11, 5, nullptr, StateNum::S_BSPI_RAISE6, 0,
     0}, // S_BSPI_RAISE5
    {SpriteNum::SPR_BSPI, 10, 5, nullptr, StateNum::S_BSPI_RAISE7, 0,
     0}, // S_BSPI_RAISE6
    {SpriteNum::SPR_BSPI, 9, 5, nullptr, StateNum::S_BSPI_RUN1, 0,
     0}, // S_BSPI_RAISE7
    {SpriteNum::SPR_APLS, 32768, 5, nullptr, StateNum::S_ARACH_PLAZ2, 0,
     0}, // S_ARACH_PLAZ
    {SpriteNum::SPR_APLS, 32769, 5, nullptr, StateNum::S_ARACH_PLAZ, 0,
     0}, // S_ARACH_PLAZ2
    {SpriteNum::SPR_APBX, 32768, 5, nullptr, StateNum::S_ARACH_PLEX2, 0,
     0}, // S_ARACH_PLEX
    {SpriteNum::SPR_APBX, 32769, 5, nullptr, StateNum::S_ARACH_PLEX3, 0,
     0}, // S_ARACH_PLEX2
    {SpriteNum::SPR_APBX, 32770, 5, nullptr, StateNum::S_ARACH_PLEX4, 0,
     0}, // S_ARACH_PLEX3
    {SpriteNum::SPR_APBX, 32771, 5, nullptr, StateNum::S_ARACH_PLEX5, 0,
     0}, // S_ARACH_PLEX4
    {SpriteNum::SPR_APBX, 32772, 5, nullptr, StateNum::S_NULL, 0,
     0}, // S_ARACH_PLEX5
    {SpriteNum::SPR_CYBR, 0, 10, action::look, StateNum::S_CYBER_STND2, 0,
     0}, // S_CYBER_STND
    {SpriteNum::SPR_CYBR, 1, 10, action::look, StateNum::S_CYBER_STND, 0,
     0}, // S_CYBER_STND2
    {SpriteNum::SPR_CYBR, 0, 3, action::hoof, StateNum::S_CYBER_RUN2, 0,
     0}, // S_CYBER_RUN1
    {SpriteNum::SPR_CYBR, 0, 3, action::chase, StateNum::S_CYBER_RUN3, 0,
     0}, // S_CYBER_RUN2
    {SpriteNum::SPR_CYBR, 1, 3, action::chase, StateNum::S_CYBER_RUN4, 0,
     0}, // S_CYBER_RUN3
    {SpriteNum::SPR_CYBR, 1, 3, action::chase, StateNum::S_CYBER_RUN5, 0,
     0}, // S_CYBER_RUN4
    {SpriteNum::SPR_CYBR, 2, 3, action::chase, StateNum::S_CYBER_RUN6, 0,
     0}, // S_CYBER_RUN5
    {SpriteNum::SPR_CYBR, 2, 3, action::chase, StateNum::S_CYBER_RUN7, 0,
     0}, // S_CYBER_RUN6
    {SpriteNum::SPR_CYBR, 3, 3, action::metal, StateNum::S_CYBER_RUN8, 0,
     0}, // S_CYBER_RUN7
    {SpriteNum::SPR_CYBR, 3, 3, action::chase, StateNum::S_CYBER_RUN1, 0,
     0}, // S_CYBER_RUN8
    {SpriteNum::SPR_CYBR, 4, 6, action::faceTarget, StateNum::S_CYBER_ATK2, 0,
     0}, // S_CYBER_ATK1
    {SpriteNum::SPR_CYBR, 5, 12, action::cyberAttack, StateNum::S_CYBER_ATK3, 0,
     0}, // S_CYBER_ATK2
    {SpriteNum::SPR_CYBR, 4, 12, action::faceTarget, StateNum::S_CYBER_ATK4, 0,
     0}, // S_CYBER_ATK3
    {SpriteNum::SPR_CYBR, 5, 12, action::cyberAttack, StateNum::S_CYBER_ATK5, 0,
     0}, // S_CYBER_ATK4
    {SpriteNum::SPR_CYBR, 4, 12, action::faceTarget, StateNum::S_CYBER_ATK6, 0,
     0}, // S_CYBER_ATK5
    {SpriteNum::SPR_CYBR, 5, 12, action::cyberAttack, StateNum::S_CYBER_RUN1, 0,
     0}, // S_CYBER_ATK6
    {SpriteNum::SPR_CYBR, 6, 10, action::pain, StateNum::S_CYBER_RUN1, 0,
     0}, // S_CYBER_PAIN
    {SpriteNum::SPR_CYBR, 7, 10, nullptr, StateNum::S_CYBER_DIE2, 0,
     0}, // S_CYBER_DIE1
    {SpriteNum::SPR_CYBR, 8, 10, action::scream, StateNum::S_CYBER_DIE3, 0,
     0}, // S_CYBER_DIE2
    {SpriteNum::SPR_CYBR, 9, 10, nullptr, StateNum::S_CYBER_DIE4, 0,
     0}, // S_CYBER_DIE3
    {SpriteNum::SPR_CYBR, 10, 10, nullptr, StateNum::S_CYBER_DIE5, 0,
     0}, // S_CYBER_DIE4
    {SpriteNum::SPR_CYBR, 11, 10, nullptr, StateNum::S_CYBER_DIE6, 0,
     0}, // S_CYBER_DIE5
    {SpriteNum::SPR_CYBR, 12, 10, action::fall, StateNum::S_CYBER_DIE7, 0,
     0}, // S_CYBER_DIE6
    {SpriteNum::SPR_CYBR, 13, 10, nullptr, StateNum::S_CYBER_DIE8, 0,
     0}, // S_CYBER_DIE7
    {SpriteNum::SPR_CYBR, 14, 10, nullptr, StateNum::S_CYBER_DIE9, 0,
     0}, // S_CYBER_DIE8
    {SpriteNum::SPR_CYBR, 15, 30, nullptr, StateNum::S_CYBER_DIE10, 0,
     0}, // S_CYBER_DIE9
    {SpriteNum::SPR_CYBR, 15, -1, action::bossDeath, StateNum::S_NULL, 0,
     0}, // S_CYBER_DIE10
    {SpriteNum::SPR_PAIN, 0, 10, action::look, StateNum::S_PAIN_STND, 0,
     0}, // S_PAIN_STND
    {SpriteNum::SPR_PAIN, 0, 3, action::chase, StateNum::S_PAIN_RUN2, 0,
     0}, // S_PAIN_RUN1
    {SpriteNum::SPR_PAIN, 0, 3, action::chase, StateNum::S_PAIN_RUN3, 0,
     0}, // S_PAIN_RUN2
    {SpriteNum::SPR_PAIN, 1, 3, action::chase, StateNum::S_PAIN_RUN4, 0,
     0}, // S_PAIN_RUN3
    {SpriteNum::SPR_PAIN, 1, 3, action::chase, StateNum::S_PAIN_RUN5, 0,
     0}, // S_PAIN_RUN4
    {SpriteNum::SPR_PAIN, 2, 3, action::chase, StateNum::S_PAIN_RUN6, 0,
     0}, // S_PAIN_RUN5
    {SpriteNum::SPR_PAIN, 2, 3, action::chase, StateNum::S_PAIN_RUN1, 0,
     0}, // S_PAIN_RUN6
    {SpriteNum::SPR_PAIN, 3, 5, action::faceTarget, StateNum::S_PAIN_ATK2, 0,
     0}, // S_PAIN_ATK1
    {SpriteNum::SPR_PAIN, 4, 5, action::faceTarget, StateNum::S_PAIN_ATK3, 0,
     0}, // S_PAIN_ATK2
    {SpriteNum::SPR_PAIN, 32773, 5, action::faceTarget, StateNum::S_PAIN_ATK4,
     0, 0}, // S_PAIN_ATK3
    {SpriteNum::SPR_PAIN, 32773, 0, action::painAttack, StateNum::S_PAIN_RUN1,
     0, 0}, // S_PAIN_ATK4
    {SpriteNum::SPR_PAIN, 6, 6, nullptr, StateNum::S_PAIN_PAIN2, 0,
     0}, // S_PAIN_PAIN
    {SpriteNum::SPR_PAIN, 6, 6, action::pain, StateNum::S_PAIN_RUN1, 0,
     0}, // S_PAIN_PAIN2
    {SpriteNum::SPR_PAIN, 32775, 8, nullptr, StateNum::S_PAIN_DIE2, 0,
     0}, // S_PAIN_DIE1
    {SpriteNum::SPR_PAIN, 32776, 8, action::scream, StateNum::S_PAIN_DIE3, 0,
     0}, // S_PAIN_DIE2
    {SpriteNum::SPR_PAIN, 32777, 8, nullptr, StateNum::S_PAIN_DIE4, 0,
     0}, // S_PAIN_DIE3
    {SpriteNum::SPR_PAIN, 32778, 8, nullptr, StateNum::S_PAIN_DIE5, 0,
     0}, // S_PAIN_DIE4
    {SpriteNum::SPR_PAIN, 32779, 8, action::painDie, StateNum::S_PAIN_DIE6, 0,
     0}, // S_PAIN_DIE5
    {SpriteNum::SPR_PAIN, 32780, 8, nullptr, StateNum::S_NULL, 0,
     0}, // S_PAIN_DIE6
    {SpriteNum::SPR_PAIN, 12, 8, nullptr, StateNum::S_PAIN_RAISE2, 0,
     0}, // S_PAIN_RAISE1
    {SpriteNum::SPR_PAIN, 11, 8, nullptr, StateNum::S_PAIN_RAISE3, 0,
     0}, // S_PAIN_RAISE2
    {SpriteNum::SPR_PAIN, 10, 8, nullptr, StateNum::S_PAIN_RAISE4, 0,
     0}, // S_PAIN_RAISE3
    {SpriteNum::SPR_PAIN, 9, 8, nullptr, StateNum::S_PAIN_RAISE5, 0,
     0}, // S_PAIN_RAISE4
    {SpriteNum::SPR_PAIN, 8, 8, nullptr, StateNum::S_PAIN_RAISE6, 0,
     0}, // S_PAIN_RAISE5
    {SpriteNum::SPR_PAIN, 7, 8, nullptr, StateNum::S_PAIN_RUN1, 0,
     0}, // S_PAIN_RAISE6
    {SpriteNum::SPR_SSWV, 0, 10, action::look, StateNum::S_SSWV_STND2, 0,
     0}, // S_SSWV_STND
    {SpriteNum::SPR_SSWV, 1, 10, action::look, StateNum::S_SSWV_STND, 0,
     0}, // S_SSWV_STND2
    {SpriteNum::SPR_SSWV, 0, 3, action::chase, StateNum::S_SSWV_RUN2, 0,
     0}, // S_SSWV_RUN1
    {SpriteNum::SPR_SSWV, 0, 3, action::chase, StateNum::S_SSWV_RUN3, 0,
     0}, // S_SSWV_RUN2
    {SpriteNum::SPR_SSWV, 1, 3, action::chase, StateNum::S_SSWV_RUN4, 0,
     0}, // S_SSWV_RUN3
    {SpriteNum::SPR_SSWV, 1, 3, action::chase, StateNum::S_SSWV_RUN5, 0,
     0}, // S_SSWV_RUN4
    {SpriteNum::SPR_SSWV, 2, 3, action::chase, StateNum::S_SSWV_RUN6, 0,
     0}, // S_SSWV_RUN5
    {SpriteNum::SPR_SSWV, 2, 3, action::chase, StateNum::S_SSWV_RUN7, 0,
     0}, // S_SSWV_RUN6
    {SpriteNum::SPR_SSWV, 3, 3, action::chase, StateNum::S_SSWV_RUN8, 0,
     0}, // S_SSWV_RUN7
    {SpriteNum::SPR_SSWV, 3, 3, action::chase, StateNum::S_SSWV_RUN1, 0,
     0}, // S_SSWV_RUN8
    {SpriteNum::SPR_SSWV, 4, 10, action::faceTarget, StateNum::S_SSWV_ATK2, 0,
     0}, // S_SSWV_ATK1
    {SpriteNum::SPR_SSWV, 5, 10, action::faceTarget, StateNum::S_SSWV_ATK3, 0,
     0}, // S_SSWV_ATK2
    {SpriteNum::SPR_SSWV, 32774, 4, action::cPosAttack, StateNum::S_SSWV_ATK4,
     0, 0}, // S_SSWV_ATK3
    {SpriteNum::SPR_SSWV, 5, 6, action::faceTarget, StateNum::S_SSWV_ATK5, 0,
     0}, // S_SSWV_ATK4
    {SpriteNum::SPR_SSWV, 32774, 4, action::cPosAttack, StateNum::S_SSWV_ATK6,
     0, 0}, // S_SSWV_ATK5
    {SpriteNum::SPR_SSWV, 5, 1, action::cPosRefire, StateNum::S_SSWV_ATK2, 0,
     0}, // S_SSWV_ATK6
    {SpriteNum::SPR_SSWV, 7, 3, nullptr, StateNum::S_SSWV_PAIN2, 0,
     0}, // S_SSWV_PAIN
    {SpriteNum::SPR_SSWV, 7, 3, action::pain, StateNum::S_SSWV_RUN1, 0,
     0}, // S_SSWV_PAIN2
    {SpriteNum::SPR_SSWV, 8, 5, nullptr, StateNum::S_SSWV_DIE2, 0,
     0}, // S_SSWV_DIE1
    {SpriteNum::SPR_SSWV, 9, 5, action::scream, StateNum::S_SSWV_DIE3, 0,
     0}, // S_SSWV_DIE2
    {SpriteNum::SPR_SSWV, 10, 5, action::fall, StateNum::S_SSWV_DIE4, 0,
     0}, // S_SSWV_DIE3
    {SpriteNum::SPR_SSWV, 11, 5, nullptr, StateNum::S_SSWV_DIE5, 0,
     0}, // S_SSWV_DIE4
    {SpriteNum::SPR_SSWV, 12, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SSWV_DIE5
    {SpriteNum::SPR_SSWV, 13, 5, nullptr, StateNum::S_SSWV_XDIE2, 0,
     0}, // S_SSWV_XDIE1
    {SpriteNum::SPR_SSWV, 14, 5, action::xScream, StateNum::S_SSWV_XDIE3, 0,
     0}, // S_SSWV_XDIE2
    {SpriteNum::SPR_SSWV, 15, 5, action::fall, StateNum::S_SSWV_XDIE4, 0,
     0}, // S_SSWV_XDIE3
    {SpriteNum::SPR_SSWV, 16, 5, nullptr, StateNum::S_SSWV_XDIE5, 0,
     0}, // S_SSWV_XDIE4
    {SpriteNum::SPR_SSWV, 17, 5, nullptr, StateNum::S_SSWV_XDIE6, 0,
     0}, // S_SSWV_XDIE5
    {SpriteNum::SPR_SSWV, 18, 5, nullptr, StateNum::S_SSWV_XDIE7, 0,
     0}, // S_SSWV_XDIE6
    {SpriteNum::SPR_SSWV, 19, 5, nullptr, StateNum::S_SSWV_XDIE8, 0,
     0}, // S_SSWV_XDIE7
    {SpriteNum::SPR_SSWV, 20, 5, nullptr, StateNum::S_SSWV_XDIE9, 0,
     0}, // S_SSWV_XDIE8
    {SpriteNum::SPR_SSWV, 21, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SSWV_XDIE9
    {SpriteNum::SPR_SSWV, 12, 5, nullptr, StateNum::S_SSWV_RAISE2, 0,
     0}, // S_SSWV_RAISE1
    {SpriteNum::SPR_SSWV, 11, 5, nullptr, StateNum::S_SSWV_RAISE3, 0,
     0}, // S_SSWV_RAISE2
    {SpriteNum::SPR_SSWV, 10, 5, nullptr, StateNum::S_SSWV_RAISE4, 0,
     0}, // S_SSWV_RAISE3
    {SpriteNum::SPR_SSWV, 9, 5, nullptr, StateNum::S_SSWV_RAISE5, 0,
     0}, // S_SSWV_RAISE4
    {SpriteNum::SPR_SSWV, 8, 5, nullptr, StateNum::S_SSWV_RUN1, 0,
     0}, // S_SSWV_RAISE5
    {SpriteNum::SPR_KEEN, 0, -1, nullptr, StateNum::S_KEENSTND, 0,
     0}, // S_KEENSTND
    {SpriteNum::SPR_KEEN, 0, 6, nullptr, StateNum::S_COMMKEEN2, 0,
     0}, // S_COMMKEEN
    {SpriteNum::SPR_KEEN, 1, 6, nullptr, StateNum::S_COMMKEEN3, 0,
     0}, // S_COMMKEEN2
    {SpriteNum::SPR_KEEN, 2, 6, action::scream, StateNum::S_COMMKEEN4, 0,
     0}, // S_COMMKEEN3
    {SpriteNum::SPR_KEEN, 3, 6, nullptr, StateNum::S_COMMKEEN5, 0,
     0}, // S_COMMKEEN4
    {SpriteNum::SPR_KEEN, 4, 6, nullptr, StateNum::S_COMMKEEN6, 0,
     0}, // S_COMMKEEN5
    {SpriteNum::SPR_KEEN, 5, 6, nullptr, StateNum::S_COMMKEEN7, 0,
     0}, // S_COMMKEEN6
    {SpriteNum::SPR_KEEN, 6, 6, nullptr, StateNum::S_COMMKEEN8, 0,
     0}, // S_COMMKEEN7
    {SpriteNum::SPR_KEEN, 7, 6, nullptr, StateNum::S_COMMKEEN9, 0,
     0}, // S_COMMKEEN8
    {SpriteNum::SPR_KEEN, 8, 6, nullptr, StateNum::S_COMMKEEN10, 0,
     0}, // S_COMMKEEN9
    {SpriteNum::SPR_KEEN, 9, 6, nullptr, StateNum::S_COMMKEEN11, 0,
     0}, // S_COMMKEEN10
    {SpriteNum::SPR_KEEN, 10, 6, action::keenDie, StateNum::S_COMMKEEN12, 0,
     0}, // S_COMMKEEN11
    {SpriteNum::SPR_KEEN, 11, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_COMMKEEN12
    {SpriteNum::SPR_KEEN, 12, 4, nullptr, StateNum::S_KEENPAIN2, 0,
     0}, // S_KEENPAIN
    {SpriteNum::SPR_KEEN, 12, 8, action::pain, StateNum::S_KEENSTND, 0,
     0}, // S_KEENPAIN2
    {SpriteNum::SPR_BBRN, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_BRAIN
    {SpriteNum::SPR_BBRN, 1, 36, action::brainPain, StateNum::S_BRAIN, 0,
     0}, // S_BRAIN_PAIN
    {SpriteNum::SPR_BBRN, 0, 100, action::brainScream, StateNum::S_BRAIN_DIE2,
     0, 0}, // S_BRAIN_DIE1
    {SpriteNum::SPR_BBRN, 0, 10, nullptr, StateNum::S_BRAIN_DIE3, 0,
     0}, // S_BRAIN_DIE2
    {SpriteNum::SPR_BBRN, 0, 10, nullptr, StateNum::S_BRAIN_DIE4, 0,
     0}, // S_BRAIN_DIE3
    {SpriteNum::SPR_BBRN, 0, -1, action::brainDie, StateNum::S_NULL, 0,
     0}, // S_BRAIN_DIE4
    {SpriteNum::SPR_SSWV, 0, 10, action::look, StateNum::S_BRAINEYE, 0,
     0}, // S_BRAINEYE
    {SpriteNum::SPR_SSWV, 0, 181, action::brainAwake, StateNum::S_BRAINEYE1, 0,
     0}, // S_BRAINEYESEE
    {SpriteNum::SPR_SSWV, 0, 150, action::brainSpit, StateNum::S_BRAINEYE1, 0,
     0}, // S_BRAINEYE1
    {SpriteNum::SPR_BOSF, 32768, 3, action::spawnSound, StateNum::S_SPAWN2, 0,
     0}, // S_SPAWN1
    {SpriteNum::SPR_BOSF, 32769, 3, action::spawnFly, StateNum::S_SPAWN3, 0,
     0}, // S_SPAWN2
    {SpriteNum::SPR_BOSF, 32770, 3, action::spawnFly, StateNum::S_SPAWN4, 0,
     0}, // S_SPAWN3
    {SpriteNum::SPR_BOSF, 32771, 3, action::spawnFly, StateNum::S_SPAWN1, 0,
     0}, // S_SPAWN4
    {SpriteNum::SPR_FIRE, 32768, 4, action::fire, StateNum::S_SPAWNFIRE2, 0,
     0}, // S_SPAWNFIRE1
    {SpriteNum::SPR_FIRE, 32769, 4, action::fire, StateNum::S_SPAWNFIRE3, 0,
     0}, // S_SPAWNFIRE2
    {SpriteNum::SPR_FIRE, 32770, 4, action::fire, StateNum::S_SPAWNFIRE4, 0,
     0}, // S_SPAWNFIRE3
    {SpriteNum::SPR_FIRE, 32771, 4, action::fire, StateNum::S_SPAWNFIRE5, 0,
     0}, // S_SPAWNFIRE4
    {SpriteNum::SPR_FIRE, 32772, 4, action::fire, StateNum::S_SPAWNFIRE6, 0,
     0}, // S_SPAWNFIRE5
    {SpriteNum::SPR_FIRE, 32773, 4, action::fire, StateNum::S_SPAWNFIRE7, 0,
     0}, // S_SPAWNFIRE6
    {SpriteNum::SPR_FIRE, 32774, 4, action::fire, StateNum::S_SPAWNFIRE8, 0,
     0}, // S_SPAWNFIRE7
    {SpriteNum::SPR_FIRE, 32775, 4, action::fire, StateNum::S_NULL, 0,
     0}, // S_SPAWNFIRE8
    {SpriteNum::SPR_MISL, 32769, 10, nullptr, StateNum::S_BRAINEXPLODE2, 0,
     0}, // S_BRAINEXPLODE1
    {SpriteNum::SPR_MISL, 32770, 10, nullptr, StateNum::S_BRAINEXPLODE3, 0,
     0}, // S_BRAINEXPLODE2
    {SpriteNum::SPR_MISL, 32771, 10, action::brainExplode, StateNum::S_NULL, 0,
     0}, // S_BRAINEXPLODE3
    {SpriteNum::SPR_ARM1, 0, 6, nullptr, StateNum::S_ARM1A, 0, 0},    // S_ARM1
    {SpriteNum::SPR_ARM1, 32769, 7, nullptr, StateNum::S_ARM1, 0, 0}, // S_ARM1A
    {SpriteNum::SPR_ARM2, 0, 6, nullptr, StateNum::S_ARM2A, 0, 0},    // S_ARM2
    {SpriteNum::SPR_ARM2, 32769, 6, nullptr, StateNum::S_ARM2, 0, 0}, // S_ARM2A
    {SpriteNum::SPR_BAR1, 0, 6, nullptr, StateNum::S_BAR2, 0, 0},     // S_BAR1
    {SpriteNum::SPR_BAR1, 1, 6, nullptr, StateNum::S_BAR1, 0, 0},     // S_BAR2
    {SpriteNum::SPR_BEXP, 32768, 5, nullptr, StateNum::S_BEXP2, 0, 0}, // S_BEXP
    {SpriteNum::SPR_BEXP, 32769, 5, action::scream, StateNum::S_BEXP3, 0,
     0}, // S_BEXP2
    {SpriteNum::SPR_BEXP, 32770, 5, nullptr, StateNum::S_BEXP4, 0,
     0}, // S_BEXP3
    {SpriteNum::SPR_BEXP, 32771, 10, action::explode, StateNum::S_BEXP5, 0,
     0}, // S_BEXP4
    {SpriteNum::SPR_BEXP, 32772, 10, nullptr, StateNum::S_NULL, 0,
     0}, // S_BEXP5
    {SpriteNum::SPR_FCAN, 32768, 4, nullptr, StateNum::S_BBAR2, 0,
     0}, // S_BBAR1
    {SpriteNum::SPR_FCAN, 32769, 4, nullptr, StateNum::S_BBAR3, 0,
     0}, // S_BBAR2
    {SpriteNum::SPR_FCAN, 32770, 4, nullptr, StateNum::S_BBAR1, 0,
     0},                                                            // S_BBAR3
    {SpriteNum::SPR_BON1, 0, 6, nullptr, StateNum::S_BON1A, 0, 0},  // S_BON1
    {SpriteNum::SPR_BON1, 1, 6, nullptr, StateNum::S_BON1B, 0, 0},  // S_BON1A
    {SpriteNum::SPR_BON1, 2, 6, nullptr, StateNum::S_BON1C, 0, 0},  // S_BON1B
    {SpriteNum::SPR_BON1, 3, 6, nullptr, StateNum::S_BON1D, 0, 0},  // S_BON1C
    {SpriteNum::SPR_BON1, 2, 6, nullptr, StateNum::S_BON1E, 0, 0},  // S_BON1D
    {SpriteNum::SPR_BON1, 1, 6, nullptr, StateNum::S_BON1, 0, 0},   // S_BON1E
    {SpriteNum::SPR_BON2, 0, 6, nullptr, StateNum::S_BON2A, 0, 0},  // S_BON2
    {SpriteNum::SPR_BON2, 1, 6, nullptr, StateNum::S_BON2B, 0, 0},  // S_BON2A
    {SpriteNum::SPR_BON2, 2, 6, nullptr, StateNum::S_BON2C, 0, 0},  // S_BON2B
    {SpriteNum::SPR_BON2, 3, 6, nullptr, StateNum::S_BON2D, 0, 0},  // S_BON2C
    {SpriteNum::SPR_BON2, 2, 6, nullptr, StateNum::S_BON2E, 0, 0},  // S_BON2D
    {SpriteNum::SPR_BON2, 1, 6, nullptr, StateNum::S_BON2, 0, 0},   // S_BON2E
    {SpriteNum::SPR_BKEY, 0, 10, nullptr, StateNum::S_BKEY2, 0, 0}, // S_BKEY
    {SpriteNum::SPR_BKEY, 32769, 10, nullptr, StateNum::S_BKEY, 0,
     0},                                                            // S_BKEY2
    {SpriteNum::SPR_RKEY, 0, 10, nullptr, StateNum::S_RKEY2, 0, 0}, // S_RKEY
    {SpriteNum::SPR_RKEY, 32769, 10, nullptr, StateNum::S_RKEY, 0,
     0},                                                            // S_RKEY2
    {SpriteNum::SPR_YKEY, 0, 10, nullptr, StateNum::S_YKEY2, 0, 0}, // S_YKEY
    {SpriteNum::SPR_YKEY, 32769, 10, nullptr, StateNum::S_YKEY, 0,
     0}, // S_YKEY2
    {SpriteNum::SPR_BSKU, 0, 10, nullptr, StateNum::S_BSKULL2, 0,
     0}, // S_BSKULL
    {SpriteNum::SPR_BSKU, 32769, 10, nullptr, StateNum::S_BSKULL, 0,
     0}, // S_BSKULL2
    {SpriteNum::SPR_RSKU, 0, 10, nullptr, StateNum::S_RSKULL2, 0,
     0}, // S_RSKULL
    {SpriteNum::SPR_RSKU, 32769, 10, nullptr, StateNum::S_RSKULL, 0,
     0}, // S_RSKULL2
    {SpriteNum::SPR_YSKU, 0, 10, nullptr, StateNum::S_YSKULL2, 0,
     0}, // S_YSKULL
    {SpriteNum::SPR_YSKU, 32769, 10, nullptr, StateNum::S_YSKULL, 0,
     0},                                                           // S_YSKULL2
    {SpriteNum::SPR_STIM, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_STIM
    {SpriteNum::SPR_MEDI, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MEDI
    {SpriteNum::SPR_SOUL, 32768, 6, nullptr, StateNum::S_SOUL2, 0, 0}, // S_SOUL
    {SpriteNum::SPR_SOUL, 32769, 6, nullptr, StateNum::S_SOUL3, 0,
     0}, // S_SOUL2
    {SpriteNum::SPR_SOUL, 32770, 6, nullptr, StateNum::S_SOUL4, 0,
     0}, // S_SOUL3
    {SpriteNum::SPR_SOUL, 32771, 6, nullptr, StateNum::S_SOUL5, 0,
     0}, // S_SOUL4
    {SpriteNum::SPR_SOUL, 32770, 6, nullptr, StateNum::S_SOUL6, 0,
     0},                                                              // S_SOUL5
    {SpriteNum::SPR_SOUL, 32769, 6, nullptr, StateNum::S_SOUL, 0, 0}, // S_SOUL6
    {SpriteNum::SPR_PINV, 32768, 6, nullptr, StateNum::S_PINV2, 0, 0}, // S_PINV
    {SpriteNum::SPR_PINV, 32769, 6, nullptr, StateNum::S_PINV3, 0,
     0}, // S_PINV2
    {SpriteNum::SPR_PINV, 32770, 6, nullptr, StateNum::S_PINV4, 0,
     0},                                                              // S_PINV3
    {SpriteNum::SPR_PINV, 32771, 6, nullptr, StateNum::S_PINV, 0, 0}, // S_PINV4
    {SpriteNum::SPR_PSTR, 32768, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_PSTR
    {SpriteNum::SPR_PINS, 32768, 6, nullptr, StateNum::S_PINS2, 0, 0}, // S_PINS
    {SpriteNum::SPR_PINS, 32769, 6, nullptr, StateNum::S_PINS3, 0,
     0}, // S_PINS2
    {SpriteNum::SPR_PINS, 32770, 6, nullptr, StateNum::S_PINS4, 0,
     0},                                                              // S_PINS3
    {SpriteNum::SPR_PINS, 32771, 6, nullptr, StateNum::S_PINS, 0, 0}, // S_PINS4
    {SpriteNum::SPR_MEGA, 32768, 6, nullptr, StateNum::S_MEGA2, 0, 0}, // S_MEGA
    {SpriteNum::SPR_MEGA, 32769, 6, nullptr, StateNum::S_MEGA3, 0,
     0}, // S_MEGA2
    {SpriteNum::SPR_MEGA, 32770, 6, nullptr, StateNum::S_MEGA4, 0,
     0},                                                              // S_MEGA3
    {SpriteNum::SPR_MEGA, 32771, 6, nullptr, StateNum::S_MEGA, 0, 0}, // S_MEGA4
    {SpriteNum::SPR_SUIT, 32768, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SUIT
    {SpriteNum::SPR_PMAP, 32768, 6, nullptr, StateNum::S_PMAP2, 0, 0}, // S_PMAP
    {SpriteNum::SPR_PMAP, 32769, 6, nullptr, StateNum::S_PMAP3, 0,
     0}, // S_PMAP2
    {SpriteNum::SPR_PMAP, 32770, 6, nullptr, StateNum::S_PMAP4, 0,
     0}, // S_PMAP3
    {SpriteNum::SPR_PMAP, 32771, 6, nullptr, StateNum::S_PMAP5, 0,
     0}, // S_PMAP4
    {SpriteNum::SPR_PMAP, 32770, 6, nullptr, StateNum::S_PMAP6, 0,
     0},                                                              // S_PMAP5
    {SpriteNum::SPR_PMAP, 32769, 6, nullptr, StateNum::S_PMAP, 0, 0}, // S_PMAP6
    {SpriteNum::SPR_PVIS, 32768, 6, nullptr, StateNum::S_PVIS2, 0, 0}, // S_PVIS
    {SpriteNum::SPR_PVIS, 1, 6, nullptr, StateNum::S_PVIS, 0, 0},  // S_PVIS2
    {SpriteNum::SPR_CLIP, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_CLIP
    {SpriteNum::SPR_AMMO, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_AMMO
    {SpriteNum::SPR_ROCK, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_ROCK
    {SpriteNum::SPR_BROK, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_BROK
    {SpriteNum::SPR_CELL, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_CELL
    {SpriteNum::SPR_CELP, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_CELP
    {SpriteNum::SPR_SHEL, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SHEL
    {SpriteNum::SPR_SBOX, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SBOX
    {SpriteNum::SPR_BPAK, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_BPAK
    {SpriteNum::SPR_BFUG, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_BFUG
    {SpriteNum::SPR_MGUN, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MGUN
    {SpriteNum::SPR_CSAW, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_CSAW
    {SpriteNum::SPR_LAUN, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_LAUN
    {SpriteNum::SPR_PLAS, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_PLAS
    {SpriteNum::SPR_SHOT, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SHOT
    {SpriteNum::SPR_SGN2, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SHOT2
    {SpriteNum::SPR_COLU, 32768, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_COLU
    {SpriteNum::SPR_SMT2, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_STALAG
    {SpriteNum::SPR_GOR1, 0, 10, nullptr, StateNum::S_BLOODYTWITCH2, 0,
     0}, // S_BLOODYTWITCH
    {SpriteNum::SPR_GOR1, 1, 15, nullptr, StateNum::S_BLOODYTWITCH3, 0,
     0}, // S_BLOODYTWITCH2
    {SpriteNum::SPR_GOR1, 2, 8, nullptr, StateNum::S_BLOODYTWITCH4, 0,
     0}, // S_BLOODYTWITCH3
    {SpriteNum::SPR_GOR1, 1, 6, nullptr, StateNum::S_BLOODYTWITCH, 0,
     0}, // S_BLOODYTWITCH4
    {SpriteNum::SPR_PLAY, 13, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_DEADTORSO
    {SpriteNum::SPR_PLAY, 18, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_DEADBOTTOM
    {SpriteNum::SPR_POL2, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HEADSONSTICK
    {SpriteNum::SPR_POL5, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_GIBS
    {SpriteNum::SPR_POL4, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HEADONASTICK
    {SpriteNum::SPR_POL3, 32768, 6, nullptr, StateNum::S_HEADCANDLES2, 0,
     0}, // S_HEADCANDLES
    {SpriteNum::SPR_POL3, 32769, 6, nullptr, StateNum::S_HEADCANDLES, 0,
     0}, // S_HEADCANDLES2
    {SpriteNum::SPR_POL1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_DEADSTICK
    {SpriteNum::SPR_POL6, 0, 6, nullptr, StateNum::S_LIVESTICK2, 0,
     0}, // S_LIVESTICK
    {SpriteNum::SPR_POL6, 1, 8, nullptr, StateNum::S_LIVESTICK, 0,
     0}, // S_LIVESTICK2
    {SpriteNum::SPR_GOR2, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MEAT2
    {SpriteNum::SPR_GOR3, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MEAT3
    {SpriteNum::SPR_GOR4, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MEAT4
    {SpriteNum::SPR_GOR5, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_MEAT5
    {SpriteNum::SPR_SMIT, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_STALAGTITE
    {SpriteNum::SPR_COL1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TALLGRNCOL
    {SpriteNum::SPR_COL2, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SHRTGRNCOL
    {SpriteNum::SPR_COL3, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TALLREDCOL
    {SpriteNum::SPR_COL4, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SHRTREDCOL
    {SpriteNum::SPR_CAND, 32768, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_CANDLESTIK
    {SpriteNum::SPR_CBRA, 32768, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_CANDELABRA
    {SpriteNum::SPR_COL6, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_SKULLCOL
    {SpriteNum::SPR_TRE1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TORCHTREE
    {SpriteNum::SPR_TRE2, 0, -1, nullptr, StateNum::S_NULL, 0, 0}, // S_BIGTREE
    {SpriteNum::SPR_ELEC, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_TECHPILLAR
    {SpriteNum::SPR_CEYE, 32768, 6, nullptr, StateNum::S_EVILEYE2, 0,
     0}, // S_EVILEYE
    {SpriteNum::SPR_CEYE, 32769, 6, nullptr, StateNum::S_EVILEYE3, 0,
     0}, // S_EVILEYE2
    {SpriteNum::SPR_CEYE, 32770, 6, nullptr, StateNum::S_EVILEYE4, 0,
     0}, // S_EVILEYE3
    {SpriteNum::SPR_CEYE, 32769, 6, nullptr, StateNum::S_EVILEYE, 0,
     0}, // S_EVILEYE4
    {SpriteNum::SPR_FSKU, 32768, 6, nullptr, StateNum::S_FLOATSKULL2, 0,
     0}, // S_FLOATSKULL
    {SpriteNum::SPR_FSKU, 32769, 6, nullptr, StateNum::S_FLOATSKULL3, 0,
     0}, // S_FLOATSKULL2
    {SpriteNum::SPR_FSKU, 32770, 6, nullptr, StateNum::S_FLOATSKULL, 0,
     0}, // S_FLOATSKULL3
    {SpriteNum::SPR_COL5, 0, 14, nullptr, StateNum::S_HEARTCOL2, 0,
     0}, // S_HEARTCOL
    {SpriteNum::SPR_COL5, 1, 14, nullptr, StateNum::S_HEARTCOL, 0,
     0}, // S_HEARTCOL2
    {SpriteNum::SPR_TBLU, 32768, 4, nullptr, StateNum::S_BLUETORCH2, 0,
     0}, // S_BLUETORCH
    {SpriteNum::SPR_TBLU, 32769, 4, nullptr, StateNum::S_BLUETORCH3, 0,
     0}, // S_BLUETORCH2
    {SpriteNum::SPR_TBLU, 32770, 4, nullptr, StateNum::S_BLUETORCH4, 0,
     0}, // S_BLUETORCH3
    {SpriteNum::SPR_TBLU, 32771, 4, nullptr, StateNum::S_BLUETORCH, 0,
     0}, // S_BLUETORCH4
    {SpriteNum::SPR_TGRN, 32768, 4, nullptr, StateNum::S_GREENTORCH2, 0,
     0}, // S_GREENTORCH
    {SpriteNum::SPR_TGRN, 32769, 4, nullptr, StateNum::S_GREENTORCH3, 0,
     0}, // S_GREENTORCH2
    {SpriteNum::SPR_TGRN, 32770, 4, nullptr, StateNum::S_GREENTORCH4, 0,
     0}, // S_GREENTORCH3
    {SpriteNum::SPR_TGRN, 32771, 4, nullptr, StateNum::S_GREENTORCH, 0,
     0}, // S_GREENTORCH4
    {SpriteNum::SPR_TRED, 32768, 4, nullptr, StateNum::S_REDTORCH2, 0,
     0}, // S_REDTORCH
    {SpriteNum::SPR_TRED, 32769, 4, nullptr, StateNum::S_REDTORCH3, 0,
     0}, // S_REDTORCH2
    {SpriteNum::SPR_TRED, 32770, 4, nullptr, StateNum::S_REDTORCH4, 0,
     0}, // S_REDTORCH3
    {SpriteNum::SPR_TRED, 32771, 4, nullptr, StateNum::S_REDTORCH, 0,
     0}, // S_REDTORCH4
    {SpriteNum::SPR_SMBT, 32768, 4, nullptr, StateNum::S_BTORCHSHRT2, 0,
     0}, // S_BTORCHSHRT
    {SpriteNum::SPR_SMBT, 32769, 4, nullptr, StateNum::S_BTORCHSHRT3, 0,
     0}, // S_BTORCHSHRT2
    {SpriteNum::SPR_SMBT, 32770, 4, nullptr, StateNum::S_BTORCHSHRT4, 0,
     0}, // S_BTORCHSHRT3
    {SpriteNum::SPR_SMBT, 32771, 4, nullptr, StateNum::S_BTORCHSHRT, 0,
     0}, // S_BTORCHSHRT4
    {SpriteNum::SPR_SMGT, 32768, 4, nullptr, StateNum::S_GTORCHSHRT2, 0,
     0}, // S_GTORCHSHRT
    {SpriteNum::SPR_SMGT, 32769, 4, nullptr, StateNum::S_GTORCHSHRT3, 0,
     0}, // S_GTORCHSHRT2
    {SpriteNum::SPR_SMGT, 32770, 4, nullptr, StateNum::S_GTORCHSHRT4, 0,
     0}, // S_GTORCHSHRT3
    {SpriteNum::SPR_SMGT, 32771, 4, nullptr, StateNum::S_GTORCHSHRT, 0,
     0}, // S_GTORCHSHRT4
    {SpriteNum::SPR_SMRT, 32768, 4, nullptr, StateNum::S_RTORCHSHRT2, 0,
     0}, // S_RTORCHSHRT
    {SpriteNum::SPR_SMRT, 32769, 4, nullptr, StateNum::S_RTORCHSHRT3, 0,
     0}, // S_RTORCHSHRT2
    {SpriteNum::SPR_SMRT, 32770, 4, nullptr, StateNum::S_RTORCHSHRT4, 0,
     0}, // S_RTORCHSHRT3
    {SpriteNum::SPR_SMRT, 32771, 4, nullptr, StateNum::S_RTORCHSHRT, 0,
     0}, // S_RTORCHSHRT4
    {SpriteNum::SPR_HDB1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGNOGUTS
    {SpriteNum::SPR_HDB2, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGBNOBRAIN
    {SpriteNum::SPR_HDB3, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGTLOOKDN
    {SpriteNum::SPR_HDB4, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGTSKULL
    {SpriteNum::SPR_HDB5, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGTLOOKUP
    {SpriteNum::SPR_HDB6, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_HANGTNOBRAIN
    {SpriteNum::SPR_POB1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_COLONGIBS
    {SpriteNum::SPR_POB2, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_SMALLPOOL
    {SpriteNum::SPR_BRS1, 0, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_BRAINSTEM
    {SpriteNum::SPR_TLMP, 32768, 4, nullptr, StateNum::S_TECHLAMP2, 0,
     0}, // S_TECHLAMP
    {SpriteNum::SPR_TLMP, 32769, 4, nullptr, StateNum::S_TECHLAMP3, 0,
     0}, // S_TECHLAMP2
    {SpriteNum::SPR_TLMP, 32770, 4, nullptr, StateNum::S_TECHLAMP4, 0,
     0}, // S_TECHLAMP3
    {SpriteNum::SPR_TLMP, 32771, 4, nullptr, StateNum::S_TECHLAMP, 0,
     0}, // S_TECHLAMP4
    {SpriteNum::SPR_TLP2, 32768, 4, nullptr, StateNum::S_TECH2LAMP2, 0,
     0}, // S_TECH2LAMP
    {SpriteNum::SPR_TLP2, 32769, 4, nullptr, StateNum::S_TECH2LAMP3, 0,
     0}, // S_TECH2LAMP2
    {SpriteNum::SPR_TLP2, 32770, 4, nullptr, StateNum::S_TECH2LAMP4, 0,
     0}, // S_TECH2LAMP3
    {SpriteNum::SPR_TLP2, 32771, 4, nullptr, StateNum::S_TECH2LAMP, 0,
     0}, // S_TECH2LAMP4
    {SpriteNum::SPR_TNT1, 0, -1, nullptr, StateNum::S_TNT1, 0,
     0}, // S_TNT1    // phares 3/8/98

    // killough 8/9/98: grenade
    {SpriteNum::SPR_MISL, 32768, 1000, action::die,
     StateNum::S_GRENADE}, // S_GRENADE

    // killough 8/10/98: variable damage explosion
    {SpriteNum::SPR_MISL, 32769, 4, action::scream,
     StateNum::S_DETONATE2}, // S_DETONATE
    {SpriteNum::SPR_MISL, 32770, 6, action::detonate,
     StateNum::S_DETONATE3},                                     // S_DETONATE2
    {SpriteNum::SPR_MISL, 32771, 10, nullptr, StateNum::S_NULL}, // S_DETONATE3

    // killough 7/19/98: Marine's best friend :)
    {SpriteNum::SPR_DOGS, 0, 10, action::look,
     StateNum::S_DOGS_STND2}, // S_DOGS_STND
    {SpriteNum::SPR_DOGS, 1, 10, action::look,
     StateNum::S_DOGS_STND}, // S_DOGS_STND2
    {SpriteNum::SPR_DOGS, 0, 2, action::chase,
     StateNum::S_DOGS_RUN2}, // S_DOGS_RUN1
    {SpriteNum::SPR_DOGS, 0, 2, action::chase,
     StateNum::S_DOGS_RUN3}, // S_DOGS_RUN2
    {SpriteNum::SPR_DOGS, 1, 2, action::chase,
     StateNum::S_DOGS_RUN4}, // S_DOGS_RUN3
    {SpriteNum::SPR_DOGS, 1, 2, action::chase,
     StateNum::S_DOGS_RUN5}, // S_DOGS_RUN4
    {SpriteNum::SPR_DOGS, 2, 2, action::chase,
     StateNum::S_DOGS_RUN6}, // S_DOGS_RUN5
    {SpriteNum::SPR_DOGS, 2, 2, action::chase,
     StateNum::S_DOGS_RUN7}, // S_DOGS_RUN6
    {SpriteNum::SPR_DOGS, 3, 2, action::chase,
     StateNum::S_DOGS_RUN8}, // S_DOGS_RUN7
    {SpriteNum::SPR_DOGS, 3, 2, action::chase,
     StateNum::S_DOGS_RUN1}, // S_DOGS_RUN8
    {SpriteNum::SPR_DOGS, 4, 8, action::faceTarget,
     StateNum::S_DOGS_ATK2}, // S_DOGS_ATK1
    {SpriteNum::SPR_DOGS, 5, 8, action::faceTarget,
     StateNum::S_DOGS_ATK3}, // S_DOGS_ATK2
    {SpriteNum::SPR_DOGS, 6, 8, action::sargAttack,
     StateNum::S_DOGS_RUN1},                                      // S_DOGS_ATK3
    {SpriteNum::SPR_DOGS, 7, 2, nullptr, StateNum::S_DOGS_PAIN2}, // S_DOGS_PAIN
    {SpriteNum::SPR_DOGS, 7, 2, action::pain,
     StateNum::S_DOGS_RUN1},                                     // S_DOGS_PAIN2
    {SpriteNum::SPR_DOGS, 8, 8, nullptr, StateNum::S_DOGS_DIE2}, // S_DOGS_DIE1
    {SpriteNum::SPR_DOGS, 9, 8, action::scream,
     StateNum::S_DOGS_DIE3},                                      // S_DOGS_DIE2
    {SpriteNum::SPR_DOGS, 10, 4, nullptr, StateNum::S_DOGS_DIE4}, // S_DOGS_DIE3
    {SpriteNum::SPR_DOGS, 11, 4, action::fall,
     StateNum::S_DOGS_DIE5},                                      // S_DOGS_DIE4
    {SpriteNum::SPR_DOGS, 12, 4, nullptr, StateNum::S_DOGS_DIE6}, // S_DOGS_DIE5
    {SpriteNum::SPR_DOGS, 13, -1, nullptr, StateNum::S_NULL},     // S_DOGS_DIE6
    {SpriteNum::SPR_DOGS, 13, 5, nullptr,
     StateNum::S_DOGS_RAISE2}, // S_DOGS_RAISE1
    {SpriteNum::SPR_DOGS, 12, 5, nullptr,
     StateNum::S_DOGS_RAISE3}, // S_DOGS_RAISE2
    {SpriteNum::SPR_DOGS, 11, 5, nullptr,
     StateNum::S_DOGS_RAISE4}, // S_DOGS_RAISE3
    {SpriteNum::SPR_DOGS, 10, 5, nullptr,
     StateNum::S_DOGS_RAISE5}, // S_DOGS_RAISE4
    {SpriteNum::SPR_DOGS, 9, 5, nullptr,
     StateNum::S_DOGS_RAISE6}, // S_DOGS_RAISE5
    {SpriteNum::SPR_DOGS, 8, 5, nullptr,
     StateNum::S_DOGS_RUN1}, // S_DOGS_RAISE6

// add dummy beta bfg / lost soul frames for dehacked compatibility
// fixes bug #1576151 (part 2)

#define BFGDELAY 1
#define OLDBFG_1FRAMES(x)                                                      \
  {SpriteNum::SPR_BFGG, 1, BFGDELAY, action::fireOldBfg,                       \
   static_cast<StateNum>(x + static_cast<int>(StateNum::S_OLDBFG1) + 2)},
#define OLDBFG_2FRAMES(x)                                                      \
  OLDBFG_1FRAMES(x) OLDBFG_1FRAMES(static_cast<int>(x) + 1)
#define OLDBFG_4FRAMES(x)                                                      \
  OLDBFG_2FRAMES(x) OLDBFG_2FRAMES(static_cast<int>(x) + 2)
#define OLDBFG_8FRAMES(x)                                                      \
  OLDBFG_4FRAMES(x) OLDBFG_4FRAMES(static_cast<int>(x) + 4)
    {SpriteNum::SPR_BFGG, 0, 10, action::bfgSound,
     static_cast<StateNum>(static_cast<int>(StateNum::S_OLDBFG1) +
                           1)}, // S_OLDBFG1

    OLDBFG_8FRAMES(0) OLDBFG_8FRAMES(8) OLDBFG_8FRAMES(16) OLDBFG_8FRAMES(24)
        OLDBFG_8FRAMES(32)

    //{SpriteNum::SPR_DOGS,7,2,action::pain,StateNum::S_DOGS_RUN1},
    {SpriteNum::SPR_BFGG, 1, 0, action::light0,
     StateNum::S_OLDBFG43},                                        // S_OLDBFG42
    {SpriteNum::SPR_BFGG, 1, 20, action::reFire, StateNum::S_BFG}, // S_OLDBFG43

    // killough 7/11/98: end of beta BFG

    // killough 7/19/98: First plasma fireball in the beta:
    {SpriteNum::SPR_PLS1, 32768, 6, nullptr,
     StateNum::S_PLS1BALL2}, // S_PLS1BALL
    {SpriteNum::SPR_PLS1, 32769, 6, nullptr,
     StateNum::S_PLS1BALL}, // S_PLS1BALL2
    {SpriteNum::SPR_PLS1, 32770, 4, nullptr, StateNum::S_PLS1EXP2}, // S_PLS1EXP
    {SpriteNum::SPR_PLS1, 32771, 4, nullptr,
     StateNum::S_PLS1EXP3}, // S_PLS1EXP2
    {SpriteNum::SPR_PLS1, 32772, 4, nullptr,
     StateNum::S_PLS1EXP4}, // S_PLS1EXP3
    {SpriteNum::SPR_PLS1, 32773, 4, nullptr,
     StateNum::S_PLS1EXP5},                                     // S_PLS1EXP4
    {SpriteNum::SPR_PLS1, 32774, 4, nullptr, StateNum::S_NULL}, // S_PLS1EXP5

    // killough 7/19/98: Second plasma fireball in the beta:
    {SpriteNum::SPR_PLS2, 32768, 4, nullptr,
     StateNum::S_PLS2BALL2}, // S_PLS2BALL
    {SpriteNum::SPR_PLS2, 32769, 4, nullptr,
     StateNum::S_PLS2BALL}, // S_PLS2BALL2
    {SpriteNum::SPR_PLS2, 32770, 6, nullptr,
     StateNum::S_PLS2BALLX2}, // S_PLS2BALLX1
    {SpriteNum::SPR_PLS2, 32771, 6, nullptr,
     StateNum::S_PLS2BALLX3},                                   // S_PLS2BALLX2
    {SpriteNum::SPR_PLS2, 32772, 6, nullptr, StateNum::S_NULL}, // S_PLS2BALLX3

    {SpriteNum::SPR_BON3, 0, 6, nullptr,
     StateNum::S_BON3}, // S_BON3  // killough 7/11/98:
    {SpriteNum::SPR_BON4, 0, 6, nullptr,
     StateNum::S_BON4}, // S_BON4  // beta bonus items

    // killough 10/98: beta lost souls attacked from a distance,
    // animated with colors, and stayed in the air when killed.
    // This is an approximation, but I'm sure it can be improved.

    // spawnstate
    {SpriteNum::SPR_SKUL, 0, 10, action::look,
     StateNum::S_BSKUL_STND}, // S_BSKUL_STND

    // chasestate
    {SpriteNum::SPR_SKUL, 1, 5, action::chase,
     StateNum::S_BSKUL_RUN2}, // S_BSKUL_RUN1
    {SpriteNum::SPR_SKUL, 2, 5, action::chase,
     StateNum::S_BSKUL_RUN3}, // S_BSKUL_RUN2
    {SpriteNum::SPR_SKUL, 3, 5, action::chase,
     StateNum::S_BSKUL_RUN4}, // S_BSKUL_RUN3
    {SpriteNum::SPR_SKUL, 0, 5, action::chase,
     StateNum::S_BSKUL_RUN1}, // S_BSKUL_RUN4

    // missilestate
    {SpriteNum::SPR_SKUL, 4, 4, action::faceTarget,
     StateNum::S_BSKUL_ATK2}, // S_BSKUL_ATK1
    {SpriteNum::SPR_SKUL, 5, 5, action::betaSkullAttack,
     StateNum::S_BSKUL_ATK3}, // S_BSKUL_ATK2
    {SpriteNum::SPR_SKUL, 5, 4, nullptr,
     StateNum::S_BSKUL_RUN1}, // S_BSKUL_ATK3

    // painstate
    {SpriteNum::SPR_SKUL, 6, 4, nullptr,
     StateNum::S_BSKUL_PAIN2}, // S_BSKUL_PAIN1
    {SpriteNum::SPR_SKUL, 7, 2, action::pain,
     StateNum::S_BSKUL_RUN1}, // S_BSKUL_PAIN2
    {SpriteNum::SPR_SKUL, 8, 4, nullptr,
     StateNum::S_BSKUL_RUN1}, // S_BSKUL_PAIN3

    // deathstate
    {SpriteNum::SPR_SKUL, 9, 5, nullptr,
     StateNum::S_BSKUL_DIE2}, // S_BSKUL_DIE1
    {SpriteNum::SPR_SKUL, 10, 5, nullptr,
     StateNum::S_BSKUL_DIE3}, // S_BSKUL_DIE2
    {SpriteNum::SPR_SKUL, 11, 5, nullptr,
     StateNum::S_BSKUL_DIE4}, // S_BSKUL_DIE3
    {SpriteNum::SPR_SKUL, 12, 5, nullptr,
     StateNum::S_BSKUL_DIE5}, // S_BSKUL_DIE4
    {SpriteNum::SPR_SKUL, 13, 5, action::scream,
     StateNum::S_BSKUL_DIE6}, // S_BSKUL_DIE5
    {SpriteNum::SPR_SKUL, 14, 5, nullptr,
     StateNum::S_BSKUL_DIE7}, // S_BSKUL_DIE6
    {SpriteNum::SPR_SKUL, 15, 5, action::fall,
     StateNum::S_BSKUL_DIE8}, // S_BSKUL_DIE7
    {SpriteNum::SPR_SKUL, 16, 5, action::stop,
     StateNum::S_BSKUL_DIE8}, // S_BSKUL_DIE8

    // killough 10/98: mushroom effect
    {SpriteNum::SPR_MISL, 32769, 8, action::mushroom,
     StateNum::S_EXPLODE2}, // S_MUSHROOM

    {SpriteNum::SPR_PLAY, 14, 5, nullptr, StateNum::S_PLAY_GDIE2, 0,
     0}, // S_PLAY_GDIE1
    {SpriteNum::SPR_PLAY, 15, 5, action::skullPop, StateNum::S_PLAY_GDIE3, 0,
     0}, // S_PLAY_GDIE2
    {SpriteNum::SPR_PLAY, 16, 5, action::fall, StateNum::S_PLAY_GDIE4, 0,
     0}, // S_PLAY_GDIE3
    {SpriteNum::SPR_PLAY, 17, 5, nullptr, StateNum::S_PLAY_GDIE5, 0,
     0}, // S_PLAY_GDIE4
    {SpriteNum::SPR_PLAY, 18, 5, nullptr, StateNum::S_PLAY_GDIE6, 0,
     0}, // S_PLAY_GDIE5
    {SpriteNum::SPR_PLAY, 19, 5, nullptr, StateNum::S_PLAY_GDIE7, 0,
     0}, // S_PLAY_GDIE6
    {SpriteNum::SPR_PLAY, 20, 5, nullptr, StateNum::S_PLAY_GDIE8, 0,
     0}, // S_PLAY_GDIE7
    {SpriteNum::SPR_PLAY, 21, 5, nullptr, StateNum::S_PLAY_GDIE9, 0,
     0}, // S_PLAY_GDIE8
    {SpriteNum::SPR_PLAY, 22, -1, nullptr, StateNum::S_NULL, 0,
     0}, // S_PLAY_GDIE9
};

constexpr const char *info::sprnames[static_cast<size_t>(
                                         SpriteNum::NUMSPRITES) +
                                     1]{
    "TROO", "SHTG", "PUNG", "PISG", "PISF", "SHTF", "SHT2", "CHGG", "CHGF",
    "MISG", "MISF", "SAWG", "PLSG", "PLSF", "BFGG", "BFGF", "BLUD", "PUFF",
    "BAL1", "BAL2", "PLSS", "PLSE", "MISL", "BFS1", "BFE1", "BFE2", "TFOG",
    "IFOG", "PLAY", "POSS", "SPOS", "VILE", "FIRE", "FATB", "FBXP", "SKEL",
    "MANF", "FATT", "CPOS", "SARG", "HEAD", "BAL7", "BOSS", "BOS2", "SKUL",
    "SPID", "BSPI", "APLS", "APBX", "CYBR", "PAIN", "SSWV", "KEEN", "BBRN",
    "BOSF", "ARM1", "ARM2", "BAR1", "BEXP", "FCAN", "BON1", "BON2", "BKEY",
    "RKEY", "YKEY", "BSKU", "RSKU", "YSKU", "STIM", "MEDI", "SOUL", "PINV",
    "PSTR", "PINS", "MEGA", "SUIT", "PMAP", "PVIS", "CLIP", "AMMO", "ROCK",
    "BROK", "CELL", "CELP", "SHEL", "SBOX", "BPAK", "BFUG", "MGUN", "CSAW",
    "LAUN", "PLAS", "SHOT", "SGN2", "COLU", "SMT2", "GOR1", "POL2", "POL5",
    "POL4", "POL3", "POL1", "POL6", "GOR2", "GOR3", "GOR4", "GOR5", "SMIT",
    "COL1", "COL2", "COL3", "COL4", "CAND", "CBRA", "COL6", "TRE1", "TRE2",
    "ELEC", "CEYE", "FSKU", "COL5", "TBLU", "TGRN", "TRED", "SMBT", "SMGT",
    "SMRT", "HDB1", "HDB2", "HDB3", "HDB4", "HDB5", "HDB6", "POB1", "POB2",
    "BRS1", "TLMP", "TLP2",
    "TNT1", // invisible sprite                                 phares 3/9/98
    "DOGS", /* killough 7/19/98: Marine's best friend :) */
    "PLS1", // killough 7/19/98: first  of two plasma fireballs in the beta
    "PLS2", // killough 7/19/98: second of two plasma fireballs in the beta
    "BON3", // killough 7/11/98: evil sceptre in the beta version
    "BON4", // killough 7/11/98: unholy bible in the beta version
    "BLD2", // blood splats from Doom Retro, unsused in PrBoom+

    // 100 extra sprite names to use in dehacked patches
    "SP00", "SP01", "SP02", "SP03", "SP04", "SP05", "SP06", "SP07", "SP08",
    "SP09", "SP10", "SP11", "SP12", "SP13", "SP14", "SP15", "SP16", "SP17",
    "SP18", "SP19", "SP20", "SP21", "SP22", "SP23", "SP24", "SP25", "SP26",
    "SP27", "SP28", "SP29", "SP30", "SP31", "SP32", "SP33", "SP34", "SP35",
    "SP36", "SP37", "SP38", "SP39", "SP40", "SP41", "SP42", "SP43", "SP44",
    "SP45", "SP46", "SP47", "SP48", "SP49", "SP50", "SP51", "SP52", "SP53",
    "SP54", "SP55", "SP56", "SP57", "SP58", "SP59", "SP60", "SP61", "SP62",
    "SP63", "SP64", "SP65", "SP66", "SP67", "SP68", "SP69", "SP70", "SP71",
    "SP72", "SP73", "SP74", "SP75", "SP76", "SP77", "SP78", "SP79", "SP80",
    "SP81", "SP82", "SP83", "SP84", "SP85", "SP86", "SP87", "SP88", "SP89",
    "SP90", "SP91", "SP92", "SP93", "SP94", "SP95", "SP96", "SP97", "SP98",
    "SP99",

    nullptr};
