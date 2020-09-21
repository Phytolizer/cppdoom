//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_VERSION_HH
#define DOOM_VERSION_HH

#ifndef BUILD_DATE
#define BUILD_DATE __DATE__
#endif

#ifndef BUILD_TIME
#define BUILD_TIME __TIME__
#endif

constexpr const char *version_date = BUILD_DATE " " BUILD_TIME;

#endif // DOOM_VERSION_HH
