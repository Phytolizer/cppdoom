//
// Created by kyle on 9/19/20.
//

#include "pspr.hh"

#include "info.hh"
#include "player.hh"

int pspr::weapon_attack_alignment;

void pspr::setPsprite(player::Player& player, pspr::PSprEnum position, info::StateEnum stateNum)
{
    PSpDef& psp = player.psprites[position];

    do
    {
        if (stateNum == info::StateEnum::S_NULL)
        {
            psp.state = nullptr;
            break;
        }
        info::State* state = &info::states.at(stateNum);
        psp.state = state;
        psp.tics = state->durationTics;

        if (state->misc1 != 0)
        {
            psp.sx = state->misc1 << fixed::FRACBITS;
            psp.sy = state->misc2 << fixed::FRACBITS;
        }

        if (state->action.index() == 2)
        {
            boost::variant2::get<2>(state->action)(player, psp);
            if (psp.state == nullptr)
            {
                break;
            }
        }
        stateNum = psp.state->nextState;
    } while (psp.tics == 0);
}
void pspr::fireWeapon(player::Player& player)
{
    // TODO(kyle)
}
void pspr::thrust(player::Player& player, tables::Angle angle, fixed::Fixed move)
{
    // TODO(kyle)
}
void pspr::bringUpWeapon(player::Player& player)
{
    // TODO(kyle)
}
