//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_ACTION_HH
#define DOOM_ACTION_HH

#include "think.hh"
#include <gsl/gsl>

namespace action
{

void light0(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void weaponReady(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void lower(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void raise(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void punch(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void reFire(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void firePistol(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void light1(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void fireShotgun(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void light2(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void fireShotgun2(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context);
void checkReload(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void openShotgun2(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context);
void loadShotgun2(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context);
void closeShotgun2(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context);
void fireCGun(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void gunFlash(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void fireMissile(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void saw(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void firePlasma(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void bfgSound(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void fireBfg(gsl::not_null<mobj::MapObject *> obj,
             const think::Context &context);
void bfgSpray(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void explode(gsl::not_null<mobj::MapObject *> obj,
             const think::Context &context);
void pain(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void playerScream(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context);
void fall(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void xScream(gsl::not_null<mobj::MapObject *> obj,
             const think::Context &context);
void look(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void chase(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void faceTarget(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void posAttack(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void scream(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void sPosAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void vileChase(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void vileStart(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void vileTarget(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void vileAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void startFire(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void fire(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void fireCrackle(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void tracer(gsl::not_null<mobj::MapObject *> obj,
            const think::Context &context);
void skelWhoosh(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void skelFist(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void skelMissile(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void fatRaise(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void fatAttack1(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void fatAttack2(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void fatAttack3(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void bossDeath(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void cPosAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void cPosRefire(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void troopAttack(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void sargAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void headAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void bruisAttack(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void skullAttack(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void metal(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void spidRefire(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void babyMetal(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void bspiAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void hoof(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void cyberAttack(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void painAttack(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void painDie(gsl::not_null<mobj::MapObject *> obj,
             const think::Context &context);
void keenDie(gsl::not_null<mobj::MapObject *> obj,
             const think::Context &context);
void brainPain(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void brainScream(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context);
void brainDie(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void brainAwake(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void brainSpit(gsl::not_null<mobj::MapObject *> obj,
               const think::Context &context);
void spawnSound(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void spawnFly(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void brainExplode(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context);
void die(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void detonate(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void betaSkullAttack(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context);
void fireOldBfg(gsl::not_null<mobj::MapObject *> obj,
                const think::Context &context);
void stop(gsl::not_null<mobj::MapObject *> obj, const think::Context &context);
void mushroom(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);
void skullPop(gsl::not_null<mobj::MapObject *> obj,
              const think::Context &context);

} // namespace action

#endif // DOOM_ACTION_HH
