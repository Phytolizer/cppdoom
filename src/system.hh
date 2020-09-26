#ifndef DOOM_SYSTEM_HH
#define DOOM_SYSTEM_HH

#include <optional>
#include <spdlog/spdlog.h>
#include <string>
#include <unistd.h>

namespace sys
{

std::string doomExeDir();
std::optional<std::string> findFile(std::string_view fname, std::string_view ext = "");
std::string getVersionString();

namespace internal
{
std::optional<std::string> findFileInternal(std::string_view fname, std::string_view ext);
} // namespace internal

std::string sigString(int signum);
int fileLength(int handle);
template <typename T> void read(int handle, T* buf, std::size_t size)
{
    int index = 0;
    auto* cbuf = reinterpret_cast<unsigned char*>(buf);
    while (size > 0)
    {
        auto readCount = ::read(handle, &cbuf[index], size * sizeof(T));
        if (readCount <= 0)
        {
            const char* errMsg;
            if (readCount != 0)
            {
                errMsg = strerror(errno);
            }
            else
            {
                errMsg = "EOF";
            }
            spdlog::error("sys::read: read failed: {}", errMsg);
            exit(-1);
        }
        size -= readCount;
        index += readCount;
    }
}
} // namespace sys

#endif
