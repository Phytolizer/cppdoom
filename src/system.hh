#ifndef DOOM_SYSTEM_HH
#define DOOM_SYSTEM_HH

#include <optional>
#include <string>

namespace sys
{

std::string doomExeDir();
std::optional<std::string> findFile(std::string_view fname,
                                    std::string_view ext = "");
std::string getVersionString();

namespace internal
{
std::optional<std::string> findFileInternal(std::string_view fname,
                                            std::string_view ext);
}

std::string sigString(int signum);
}

#endif
