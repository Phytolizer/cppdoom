#include "file.hh"

#include <bits/c++config.h>
#include <cstdlib>
#include <fmt/core.h>
#include <rang.hpp>

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

  ssize_t nread = getline(&line, &n, handle.get());
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
  std::string out{line, line + n};
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
