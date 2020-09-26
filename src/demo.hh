//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_DEMO_HH
#define DOOM_DEMO_HH

#include "gsl_aliases.hh"

#include <string_view>

namespace player
{
struct Player;
}

namespace demo
{

extern bool demo_smoothturns;
extern int demo_smoothturnsfactor;
extern std::string getwad_cmdline;
constexpr int SMOOTH_PLAYING_MAXFACTOR = 16;

bool isDemoPlayback();
bool demoCompatibility();
bool tryGetWad(std::string_view name);

namespace smooth_playing
{

void reset(NotNull<player::Player*> player);

} // namespace smooth_playing

} // namespace demo

#endif // DOOM_DEMO_HH
