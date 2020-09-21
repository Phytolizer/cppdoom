//
// Created by kyle on 9/20/20.
//

#include "action.hh"
#include "player.hh"
void action::light0(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
  dynamic_cast<player::Player *>(obj.get())->extraLight = false;
}
void action::weaponReady(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::lower(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context)
{
}
void action::raise(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context)
{
}
void action::punch(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context)
{
}
void action::reFire(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
}
void action::firePistol(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::light1(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
}
void action::fireShotgun(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::light2(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
}
void action::fireShotgun2(gsl::not_null<mobj::MapObject *> obj,
                          const think::Context &context)
{
}
void action::checkReload(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::openShotgun2(gsl::not_null<mobj::MapObject *> obj,
                          const think::Context &context)
{
}
void action::loadShotgun2(gsl::not_null<mobj::MapObject *> obj,
                          const think::Context &context)
{
}
void action::closeShotgun2(gsl::not_null<mobj::MapObject *> obj,
                           const think::Context &context)
{
}
void action::fireCGun(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::gunFlash(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::fireMissile(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::saw(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context)
{
}
void action::firePlasma(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::bfgSound(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::fireBfg(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context)
{
}
void action::bfgSpray(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::explode(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context)
{
}
void action::pain(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::playerScream(gsl::not_null<mobj::MapObject *> obj,
                          const think::Context &context)
{
}
void action::fall(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::xScream(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context)
{
}
void action::look(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::chase(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context)
{
}
void action::faceTarget(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::posAttack(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::scream(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
}
void action::sPosAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::vileChase(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::vileStart(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::vileTarget(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::vileAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::startFire(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::fire(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::fireCrackle(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::tracer(gsl::not_null<mobj::MapObject *> obj,
                    const think::Context &context)
{
}
void action::skelWhoosh(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::skelFist(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::skelMissile(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::fatRaise(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::fatAttack1(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::fatAttack2(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::fatAttack3(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::bossDeath(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::cPosAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::cPosRefire(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::troopAttack(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::sargAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::headAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::bruisAttack(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::skullAttack(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::metal(gsl::not_null<mobj::MapObject *> obj,
                   const think::Context &context)
{
}
void action::spidRefire(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::babyMetal(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::bspiAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::hoof(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::cyberAttack(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::painAttack(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::painDie(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context)
{
}
void action::keenDie(gsl::not_null<mobj::MapObject *> obj,
                     const think::Context &context)
{
}
void action::brainPain(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::brainScream(gsl::not_null<mobj::MapObject *> obj,
                         const think::Context &context)
{
}
void action::brainDie(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::brainAwake(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::brainSpit(gsl::not_null<mobj::MapObject *> obj,
                       const think::Context &context)
{
}
void action::spawnSound(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::spawnFly(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::brainExplode(gsl::not_null<mobj::MapObject *> obj,
                          const think::Context &context)
{
}
void action::die(gsl::not_null<mobj::MapObject *> obj,
                 const think::Context &context)
{
}
void action::detonate(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::betaSkullAttack(gsl::not_null<mobj::MapObject *> obj,
                             const think::Context &context)
{
}
void action::fireOldBfg(gsl::not_null<mobj::MapObject *> obj,
                        const think::Context &context)
{
}
void action::stop(gsl::not_null<mobj::MapObject *> obj,
                  const think::Context &context)
{
}
void action::mushroom(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
void action::skullPop(gsl::not_null<mobj::MapObject *> obj,
                      const think::Context &context)
{
}
