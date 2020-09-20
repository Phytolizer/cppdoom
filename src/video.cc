//
// Created by kyle on 9/19/20.
//

#include "video.hh"

#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

#include "doom.hh"

int video::process_affinity_mask;
int video::process_priority;
void video::preInitGraphics()
{
  unsigned int flags = 0;
  if (!argMeta.noDrawers || !argMeta.noSound)
  {
    flags = SDL_INIT_VIDEO;
  }

  int code = SDL_Init(flags);
  if (code < 0)
  {
    spdlog::error("Could not initialize SDL: {}", SDL_GetError());
    exit(-1);
  }
}
