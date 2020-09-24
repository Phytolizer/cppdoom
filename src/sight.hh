//
// Created by kyle on 9/24/20.
//

#ifndef EZBOOM_SIGHT_HH
#define EZBOOM_SIGHT_HH

namespace sight
{

using CrossSubsectorF = bool (*)(int);
extern CrossSubsectorF crossSubsector;

bool crossSubsectorPrBoom(int num);
bool crossSubsectorDoom(int num);
bool crossSubsectorBoom(int num);

} // namespace sight

#endif // EZBOOM_SIGHT_HH
