//
// Created by kyle on 9/20/20.
//

#include "deh.hh"

#include "arglex.hh"
#include "doomstat.hh"
#include "enum_ops.hh"
#include "info.hh"
#include "interactions.hh"
#include "sound.hh"
#include "think.hh"
#include "video.hh"

std::vector<action::Action>
    deh::codeptr(static_cast<std::size_t>(info::StateEnum::NUMSTATES));
std::vector<std::string> deh::spriteNames(
    static_cast<std::size_t>(info::SpriteEnum::NUMSPRITES) + 1);
std::vector<std::string>
    deh::musicNames(static_cast<std::size_t>(info::Music::NUMMUSIC) + 1);
std::vector<std::string>
    deh::soundNames(static_cast<std::size_t>(info::Sfx::NUMSFX) + 1);
std::optional<int> deh::dehMaxSoul{};
std::optional<int> deh::dehMegaHealth{};
std::optional<int> deh::dehMaxHealth{};
std::vector<bool>
    deh::mobjInfoBits(static_cast<std::size_t>(info::MobjType::NUMMOBJTYPES),
                      false);

void deh::buildBexTables()
{
  int i = 0;
  for (; i < static_cast<int>(info::StateEnum::EXTRASTATES); i += 1)
  {
    deh::codeptr[i] = info::states[i].action;
  }
  for (; i < static_cast<int>(info::StateEnum::NUMSTATES); i += 1)
  {
    info::State& state = info::states[i];
    state.sprite = info::SpriteEnum::SPR_TNT1;
    state.spriteFrame = 0;
    state.durationTics = -1;
    state.action = action::doNothing;
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
  deh::soundNames[0] = deh::soundNames[static_cast<size_t>(info::Sfx::NUMSFX)] =
      "";

  for (i = 0; i < static_cast<size_t>(info::MobjType::NUMMOBJTYPES); i += 1)
  {
    switch (static_cast<info::MobjType>(i))
    {
    case info::MobjType::MT_WOLFSS:
    case info::MobjType::MT_POSSESSED:
      info::mobjinfo[i].droppedItem = info::MobjType::MT_CLIP;
      break;
    case info::MobjType::MT_SHOTGUY:
      info::mobjinfo[i].droppedItem = info::MobjType::MT_SHOTGUN;
      break;
    case info::MobjType::MT_CHAINGUY:
      info::mobjinfo[i].droppedItem = info::MobjType::MT_CHAINGUN;
      break;
    default:
      info::mobjinfo[i].droppedItem = info::MobjType::MT_NULL;
    }
  }
}
void deh::applyCompatibility()
{
  int comp_max = 0;
  if (doomstat::compatibility_level < doomstat::CompLevel::Doom12)
  {
    comp_max = 199;
  }
  else
  {
    comp_max = 200;
  }
  interactions::max_soul = deh::dehMaxSoul.value_or(comp_max);
  interactions::mega_health = deh::dehMegaHealth.value_or(comp_max);
  if (doomstat::comp[static_cast<std::size_t>(
          doomstat::CompFlag::COMP_MAXHEALTH)])
  {
    interactions::maxhealth = 100;
    interactions::maxhealthbonus = deh::dehMaxHealth.value_or(comp_max);
  }
  else
  {
    interactions::maxhealth = deh::dehMaxHealth.value_or(100);
    interactions::maxhealthbonus = interactions::maxhealth * 2;
  }
  if (!deh::mobjInfoBits[static_cast<std::size_t>(info::MobjType::MT_SKULL)])
  {
    info::mobjinfo[static_cast<std::size_t>(info::MobjType::MT_SKULL)].flags |=
        info::MobjFlag::MF_COUNTKILL;
  }
  else
  {
    info::mobjinfo[static_cast<std::size_t>(info::MobjType::MT_SKULL)].flags &=
        ~info::MobjFlag::MF_COUNTKILL;
  }

  deh::changeCompTranslucency();
}
void deh::changeCompTranslucency()
{
  constexpr std::array predefined_translucency = {
      info::MobjType::MT_FIRE,      info::MobjType::MT_SMOKE,
      info::MobjType::MT_FATSHOT,   info::MobjType::MT_BRUISERSHOT,
      info::MobjType::MT_SPAWNFIRE, info::MobjType::MT_TROOPSHOT,
      info::MobjType::MT_HEADSHOT,  info::MobjType::MT_PLASMA,
      info::MobjType::MT_BFG,       info::MobjType::MT_ARACHPLAZ,
      info::MobjType::MT_PUFF,      info::MobjType::MT_TFOG,
      info::MobjType::MT_IFOG,      info::MobjType::MT_MISC12,
      info::MobjType::MT_INV,       info::MobjType::MT_INS,
      info::MobjType::MT_MEGA,
  };

  for (const auto& t : predefined_translucency)
  {
    if (!deh::mobjInfoBits[static_cast<std::size_t>(t)])
    {
      if (video::getMode() == arglex::VideoMode::ModeGL ||
          doomstat::comp[static_cast<std::size_t>(
              doomstat::CompFlag::COMP_TRANSLUCENCY)])
      {
        info::mobjinfo[static_cast<std::size_t>(t)].flags &=
            ~info::MobjFlag::MF_TRANSLUCENT;
      }
      else
      {
        info::mobjinfo[static_cast<std::size_t>(t)].flags |=
            info::MobjFlag::MF_TRANSLUCENT;
      }
    }
  }
}
