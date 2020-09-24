//
// Created by kyle on 9/19/20.
//

#ifndef DOOM_VIDEO_HH
#define DOOM_VIDEO_HH

#include "arglex.hh"
namespace video
{

extern int process_affinity_mask;
extern int process_priority;
extern arglex::VideoMode current_videomode;

void preInitGraphics();
arglex::VideoMode getMode();

} // namespace video

#endif // DOOM_VIDEO_HH
