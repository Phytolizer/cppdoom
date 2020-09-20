//
// Created by kyle on 9/20/20.
//

#include "deh.hh"

#include "info.hh"
#include "sound.hh"
#include "think.hh"

think::ActionF deh::codeptr[static_cast<size_t>(info::StateEnum::NUMSTATES)];
std::string
    deh::spriteNames[static_cast<size_t>(info::SpriteEnum::NUMSPRITES) + 1]{};
std::string
    deh::musicNames[static_cast<size_t>(info::Music::NUMMUSIC) + 1]{};
std::string deh::soundNames[static_cast<size_t>(info::Sfx::NUMSFX) + 1]{};

void deh::buildBexTables()
{
  int i = 0;
  for (; i < static_cast<int>(info::StateEnum::EXTRASTATES); i += 1)
  {
    deh::codeptr[i] = info::states[i].action;
  }
  for (; i < static_cast<int>(info::StateEnum::NUMSTATES); i += 1)
  {
    info::State &state = info::states[i];
    state.sprite = info::SpriteEnum::SPR_TNT1;
    state.spriteFrame = 0;
    state.durationTics = -1;
    state.action = nullptr;
    state.nextState = static_cast<info::StateEnum>(i);
    state.misc1 = 0;
    state.misc2 = 0;
    deh::codeptr[i] = state.action;
  }

  for (i = 0; i < static_cast<size_t>(info::SpriteEnum::NUMSPRITES); i += 1)
  {
    deh::spriteNames[i] = info::sprnames[i];
  }
  deh::spriteNames[static_cast<size_t>(info::SpriteEnum::NUMSPRITES)] = "";
  for (i = 1; i < static_cast<size_t>(info::Music::NUMMUSIC); i += 1)
  {
    deh::musicNames[i] = sound::music[i].name;
  }
  deh::musicNames[0] =
      deh::musicNames[static_cast<size_t>(info::Music::NUMMUSIC)] = "";
  for (i = 1; i < static_cast<size_t>(info::Sfx::NUMSFX); i += 1)
  {
    deh::spriteNames[i] = sound::sfx[i].name;
  }
  deh::soundNames[0] =
      deh::soundNames[static_cast<size_t>(info::Sfx::NUMSFX)] = "";

  for (i = 0; i < static_cast<size_t>(info::MobjType::NUMMOBJTYPES); i += 1)
  {
    // TODO
  }
}
