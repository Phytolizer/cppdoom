#ifndef DOOM_FILE_HH
#define DOOM_FILE_HH

#include <bits/c++config.h>
#include <cstddef>
#include <cstdio>
#include <memory>
#include <vector>

#include "io.hh"

namespace file
{

class File
{
  struct FileDeleter
  {
    void operator()(std::FILE *handle) noexcept(false);
  };
  std::unique_ptr<std::FILE, FileDeleter> handle;
  std::string_view name;

public:
  File(std::string_view name, std::string_view mode) noexcept(false);

  std::vector<std::byte> read(std::size_t nbytes) noexcept(false);
  std::string readLine() noexcept(false);
  void write(const std::vector<std::byte> &toWrite) noexcept(false);
  bool eof();
};

} // namespace file

#endif
