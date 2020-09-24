//
// Created by kyle on 9/20/20.
//

#include "action.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "event.hh"
#include "game.hh"
#include "info.hh"
#include "items.hh"
#include "player.hh"
#include "pspr.hh"
#include "sound.hh"

void action::light0(NotNull<player::Player*> player)
{
  player->extraLight = 0;
}
void action::weaponReady(NotNull<player::Player*> player, pspr::PSpDef* psp)
{
  if (player->state == &info::states[static_cast<std::size_t>(
                           info::StateEnum::S_PLAY_ATK1)] ||
      player->state ==
          &info::states[static_cast<std::size_t>(info::StateEnum::S_PLAY_ATK2)])
  {
    mobj::setMobjState(dynamic_cast<mobj::MapObject*>(player.get()),
                       info::StateEnum::S_PLAY);
  }

  if (player->readyWeapon == defs::WeaponType::WP_CHAINSAW &&
      psp->state == &info::states[info::StateEnum::S_SAW])
  {
    sound::startSound(dynamic_cast<mobj::MapObject*>(player.get()),
                      info::Sfx::sfx_sawidl);
  }

  if (player->pendingWeapon != defs::WeaponType::WP_NOCHANGE ||
      player->health == 0)
  {
    info::StateEnum newState =
        items::weaponinfo.at(player->readyWeapon).downState;
    pspr::setPsprite(player, pspr::PSprEnum::PS_WEAPON, newState);
    return;
  }

  if (static_cast<bool>(player->cmd.buttons & event::ButtonCode::BT_ATTACK))
  {
    if (!player->attackDown ||
        player->readyWeapon != defs::WeaponType::WP_MISSILE &&
            player->readyWeapon != defs::WeaponType::WP_BFG)
    {
      player->attackDown = true;
      pspr::fireWeapon(player);
      return;
    }
  }
  else
  {
    player->attackDown = false;
  }

  auto angle = (128 * doomstat::levelTime) & tables::FINE_MASK;
  psp->sx =
      fixed::FRACUNIT + fixed::fixedMul(player->bob, tables::finecosine(angle));
  angle &= tables::FINE_ANGLES / 2 - 1;
  psp->sy =
      pspr::WEAPONTOP + fixed::fixedMul(player->bob, tables::finesine[angle]);

  game::done_autoswitch = false;
}
void action::doNothing()
{
}
