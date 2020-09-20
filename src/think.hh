//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_THINK_HH
#define DOOM_THINK_HH

namespace think
{

using ActionF = void (*)();
using Think = ActionF;

struct Thinker
{
  Thinker *prev;
  Thinker *next;
  Think function;

  Thinker *cnext;
  Thinker *cprev;

  uint32_t references;
};

}

#endif // DOOM_THINK_HH
