//
// Created by kyle on 9/19/20.
//

#include "pspr.hh"

#include "info.hh"
#include "player.hh"

void pspr::setPsprite(NotNull<player::Player*> player, pspr::PSprEnum position,
                      info::StateEnum stateNum)
{
  PSpDef* psp = &player->psprites[position];

  do
  {
    if (stateNum == info::StateEnum::S_NULL)
    {
      psp->state = nullptr;
      break;
    }
    info::State* state = &info::states.at(stateNum);
    psp->state = state;
    psp->tics = state->durationTics;

    if (state->misc1 != 0)
    {
      psp->sx = state->misc1 << fixed::FRACBITS;
      psp->sy = state->misc2 << fixed::FRACBITS;
    }

    if (!boost::variant2::get_if<action::VoidAction>(state->action))
    {

    }
  } while (psp->tics == 0);
}
void pspr::fireWeapon(NotNull<player::Player*> player)
{
  // TODO(kyle)
}
