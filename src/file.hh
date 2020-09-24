#ifndef DOOM_FILE_HH
#define DOOM_FILE_HH

#include <cstddef>
#include <cstdio>
#include <fmt/core.h>
#include <gsl/gsl>
#include <memory>
#include <vector>

#include "io.hh"

namespace file
{

class File
{
  struct FileDeleter
  {
    void operator()(std::FILE* handle) noexcept(false);
  };
  std::unique_ptr<std::FILE, FileDeleter> handle;
  std::string_view name;

public:
  File();
  File(std::string_view name, std::string_view mode) noexcept(false);

  std::vector<std::byte> read(std::size_t nbytes) noexcept(false);
  template <typename T> void readTo(gsl::not_null<T*> buffer) noexcept(false);
  template <typename T>
  void readToArr(gsl::not_null<std::vector<T>*> buffer) noexcept(false);
  std::string readLine() noexcept(false);
  std::string readUntil(char delim) noexcept(false);
  void seekTo(size_t offset) noexcept(false);
  void write(const std::vector<std::byte>& toWrite) noexcept(false);

  bool eof();
  std::size_t length();
};

} // namespace file

template <typename T>
void file::File::readTo(gsl::not_null<T*> buffer) noexcept(false)
{
  auto nread = fread(buffer, sizeof(T), 1, handle.get());
  if (nread != 1)
  {
    if (eof())
    {
      throw io::IoException(
          fmt::format("early end-of-file reading {} bytes", sizeof(T)));
    }
    else
    {
      throw io::IoException(fmt::format("error reading {} bytes: {}", sizeof(T),
                                        strerror(errno)));
    }
  }
}

template <typename T>
void file::File::readToArr(gsl::not_null<std::vector<T>*> buffer) noexcept(
    false)
{
  auto nread =
      fread(buffer->data(), sizeof(T) * buffer->size(), 1, handle.get());
  if (nread != 1)
  {
    if (eof())
    {
      throw io::IoException{fmt::format("early end-of-file reading {} bytes",
                                        sizeof(T) * buffer->size())};
    }
    else
    {
      throw io::IoException{fmt::format("error reading {} bytes: {}",
                                        sizeof(T) * buffer->size(),
                                        strerror(errno))};
    }
  }
}

#endif
