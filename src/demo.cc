//
// Created by kyle on 9/19/20.
//

#include "demo.hh"
#include "doom.hh"
#include "doomstat.hh"

bool demo::demo_smoothturns = false;
int demo::demo_smoothturnsfactor = 6;
bool demo::isDemoPlayback()
{
  return argMeta.playdemo.has_value() || argMeta.timedemo.has_value() ||
         argMeta.fastdemo.has_value();
}
bool demo::demoCompatibility()
{
  return doomstat::compatibility_level < doomstat::CompLevel::Boom;
}
