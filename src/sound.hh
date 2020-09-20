//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_SOUND_HH
#define DOOM_SOUND_HH

#include <string>
#include <vector>

namespace sound
{

enum class MidiPlayerName
{
  Sdl,
  FluidSynth,
  Opl2,
  PortMidi,
};

struct MusicInfo
{
  std::string name;
  int lumpNum;
  const void *data;
  int handle;
};

extern MusicInfo music[];

struct SfxInfo
{
  std::string name;
  // FIXME actually a bool?
  bool singularity;
  int priority;
  SfxInfo *link;
  int pitch;
  int volume;
  void *data;
  int usefulness;
  int lumpNum;
};

extern SfxInfo sfx[];

extern std::string snd_midiplayer;
extern std::vector<std::string> midiplayers;

} // namespace sound

#endif // DOOM_SOUND_HH
