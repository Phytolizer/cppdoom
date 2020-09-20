//
// Created by kyle on 9/20/20.
//

#include "wad.hh"
void wad::addDefaultExtension(gsl::not_null<std::string *> path,
                              std::string_view ext)
{
  for (auto p = path->rbegin(); p != path->rend(); --p)
  {
    if (*p == '/' || *p == '\\')
    {
      break;
    }
    if (*p == '.')
    {
      return;
    }
  }
  if (ext[0] != '.')
  {
    *path += ".";
  }
  *path += ext;
}
