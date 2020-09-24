//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_THINK_HH
#define DOOM_THINK_HH

#include "action.hh"
#include "gsl_aliases.hh"

namespace mobj
{
struct MapObject;
}

namespace think
{

using Think = action::Action;

struct Thinker
{
  virtual ~Thinker() = default;
  Thinker* prev{};
  Thinker* next{};
  Think function{};

  Thinker* cnext{};
  Thinker* cprev{};

  uint32_t references{};
};

} // namespace think

#endif // DOOM_THINK_HH
