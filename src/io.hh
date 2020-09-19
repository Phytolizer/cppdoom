#ifndef DOOM_IO_HH
#define DOOM_IO_HH

#include <exception>
#include <stdexcept>
#include <string_view>

namespace io
{

class IoException : public std::runtime_error
{
public:
  // cppcheck-suppress noExplicitConstructor
  // implicit conversion is useful here
  IoException(std::string_view info);
};

} // namespace io

#endif
