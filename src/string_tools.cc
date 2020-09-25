//
// Created by kyle on 9/20/20.
//

#include "string_tools.hh"

#include <string_view>
#include <strtk.hpp>

bool string_tools::hasTrailingSlash(std::string_view s)
{
    return strtk::ends_with(s.data(), "/") || strtk::ends_with(s.data(), "\\");
}
