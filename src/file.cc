#include "file.hh"

#include <cstddef>
#include <cstdlib>
#include <fmt/core.h>
#include <rang.hpp>
#include <string_view>

#if not(defined(__unix__)) && not(defined(__APPLE__) && defined(__MACH__))
#include "win/getline.h"
#endif

void file::File::FileDeleter::operator()(std::FILE *handle)
{
  if (fclose(handle))
  {
    throw io::IoException{
        fmt::format("could not close file: {}", strerror(errno))};
  }
}

file::File::File(std::string_view name, std::string_view mode)
    : handle(fopen(name.data(), mode.data()))
{
  if (!handle)
  {
    throw io::IoException{
        fmt::format("could not open file '{}' with mode '{}': {}", name, mode,
                    strerror(errno))};
  }
}

std::vector<std::byte> file::File::read(std::size_t nbytes)
{
  std::vector<std::byte> buf{nbytes};
  std::size_t nread =
      fread(buf.data(), sizeof(std::byte), nbytes, handle.get());
  if (nread != nbytes)
  {
    throw io::IoException{fmt::format("could not read {} bytes from file: {}",
                                      nbytes, strerror(errno))};
  }
  return buf;
}

std::string file::File::readLine()
{
  char *line = nullptr;
  std::size_t n = 0;

  size_t nread = getline(&line, &n, handle.get());
  if (nread == -1)
  {
    std::free(line);
    if (eof())
    {
      return std::string{};
    }
    else
    {
      throw io::IoException{
          fmt::format("could not read line from file: {}", strerror(errno))};
    }
  }
  std::string out{line, line + strlen(line)};
  std::free(line);
  return out;
}

void file::File::write(const std::vector<std::byte> &toWrite)
{
  std::size_t nwritten =
      fwrite(toWrite.data(), sizeof(std::byte), toWrite.size(), handle.get());
  if (nwritten != toWrite.size())
  {
    throw io::IoException{fmt::format("could not write {} bytes to file: {}",
                                      toWrite.size(), strerror(errno))};
  }
}

bool file::File::eof()
{
  return feof(handle.get());
}
std::string file::File::readUntil(char delim) noexcept(false)
{
  char *line = nullptr;
  std::size_t n = 0;
  std::size_t nread = getdelim(&line, &n, delim, handle.get());
  if (nread == -1)
  {
    if (eof())
    {
      return std::string{};
    }
    else
    {
      throw io::IoException{fmt::format(
          "could not read until delimiter from file: {}", strerror(errno))};
    }
  }
  std::string out{line, line + strlen(line)};
  std::free(line);
  return out;
}
std::size_t file::File::length()
{
  std::size_t pos = ftell(handle.get());
  fseek(handle.get(), 0, SEEK_END);
  std::size_t len = ftell(handle.get());
  fseek(handle.get(), pos, SEEK_SET);
  return len;
}
void file::File::seekTo(size_t offset)
{
  if (fseek(handle.get(), offset, SEEK_SET))
  {
    throw io::IoException{fmt::format("could not seek to offset {}: {}", offset,
                                      strerror(errno))};
  }
}
file::File::File() = default;
