//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_THINK_HH
#define DOOM_THINK_HH

#include "pspr.hh"
#include <gsl/gsl>

namespace mobj
{
struct MapObject;
}

namespace think
{

struct Context
{
  pspr::PSpDef *psp;
};

using ActionF = void (*)(gsl::not_null<mobj::MapObject *>, const Context &);
using Think = ActionF;

struct Thinker
{
  virtual ~Thinker() = default;
  Thinker *prev{};
  Thinker *next{};
  Think function{};

  Thinker *cnext{};
  Thinker *cprev{};

  uint32_t references{};
};

} // namespace think

#endif // DOOM_THINK_HH
