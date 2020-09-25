#include "io.hh"

io::IoException::IoException(std::string_view info) : std::runtime_error(info.data())
{
}
