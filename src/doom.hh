#include "arglex.hh"

#include <vector>
#include <string>

extern arglex::ArgMeta argMeta;
extern int realtic_clock_rate;

enum class EndoomMode
{
  colors = 1,
  nonasciichars = 2,
  droplastline = 4,
};

extern int endoom_mode;
extern std::vector<std::string> wad_files;
extern std::vector<std::string> deh_files;
