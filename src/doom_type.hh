//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_DOOM_TYPE_HH
#define DOOM_DOOM_TYPE_HH

namespace doom_type
{

#ifdef __GNUC__
#if defined(_WIN32) && !defined(__clang__)
#define PACKEDATTR __attribute__((packed, gcc_struct))
#else
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define PACKEDATTR __attribute__((packed))
#endif
#else
#define PACKEDATTR
#endif

} // namespace doom_type

#endif // DOOM_DOOM_TYPE_HH
