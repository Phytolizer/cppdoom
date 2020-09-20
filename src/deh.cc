//
// Created by kyle on 9/20/20.
//

#include "deh.hh"

#include "info.hh"
#include "think.hh"

think::ActionF deh::codeptr[static_cast<size_t>(info::StateNum::NUMSTATES)];
std::string
    deh::spriteNames[static_cast<size_t>(info::SpriteNum::NUMSPRITES) + 1]{};
std::string
    deh::musicNames[static_cast<size_t>(info::MusicEnum::NUMMUSIC) + 1]{};
std::string deh::soundNames[static_cast<size_t>(info::SfxEnum::NUMSFX) + 1]{};

void deh::buildBexTables()
{
  int i = 0;
  for (; i < static_cast<int>(info::StateNum::EXTRASTATES); i += 1)
  {
    deh::codeptr[i] = info::states[i].action;
  }
  for (; i < static_cast<int>(info::StateNum::NUMSTATES); i += 1)
  {
    info::State &state = info::states[i];
    state.sprite = info::SpriteNum::SPR_TNT1;
    state.spriteFrame = 0;
    state.durationTics = -1;
    state.action = nullptr;
    state.nextState = static_cast<info::StateNum>(i);
    state.misc1 = 0;
    state.misc2 = 0;
    deh::codeptr[i] = state.action;
  }

  for (i = 0; i < static_cast<size_t>(info::SpriteNum::NUMSPRITES); i += 1)
  {

  }
}
