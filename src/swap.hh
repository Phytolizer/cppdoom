//
// Created by kyle on 9/20/20.
//

#ifndef DOOM_SWAP_HH
#define DOOM_SWAP_HH

#ifdef __GNUG__
#pragma interface
#endif

/* CPhipps - now the endianness handling, converting input or output to/from
 * the machine's endianness to that wanted for this type of I/O
 *
 * To find our own endianness, use config.h
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* Endianess handling. */

/* cph - First the macros to do the actual byte swapping */

/* leban
 * rather than continue the confusing tradition of redefining the
 * stardard macro, we now present the doom_ntoh and doom_hton macros....
 * might as well use the xdoom macros.
 */

/* Try to use superfast macros on systems that support them */
#ifdef HAVE_ASM_BYTEORDER_H
#include <asm/byteorder.h>
#ifdef __arch__swab16
template <typename T> constexpr short int DOOM_SWAP_S(T x)
{
    return static_cast<short int>(__arch__swab16(x));
}
#endif
#ifdef __arch__swab32
template <typename T> constexpr long int DOOM_SWAP_L(T x)
{
    return static_cast<long int>(__arch__swab32);
}
#endif
#endif /* HAVE_ASM_BYTEORDER_H */

#ifdef HAVE_LIBKERN_OSBYTEORDER_H
#include <libkern/OSByteOrder.h>

#define DOOM_SWAP_S (short)OSSwapInt16
#define DOOM_SWAP_L (long)OSSwapInt32
#endif

template <typename T> constexpr long int DOOM_SWAP_L(T x)
{
    return static_cast<long int>(((static_cast<unsigned long int>(x) & 0x000000ffU) << 24) |
                                 ((static_cast<unsigned long int>(x) & 0x0000ff00U)) << 8 |
                                 ((static_cast<unsigned long int>(x) & 0x00ff0000U)) >> 8 |
                                 ((static_cast<unsigned long int>(x) & 0xff000000U)) >> 24);
}

template <typename T> constexpr short int DOOM_SWAP_S(T x)
{
    return static_cast<short int>(((static_cast<unsigned short int>(x) & 0x00ff) << 8) |
                                  ((static_cast<unsigned short int>(x) & 0xff00) >> 8));
}
#ifdef WORDS_BIGENDIAN

template <typename T> long int DOOM_WTOHL(T x)
{
    return DOOM_SWAP_L(x);
}
template <typename T> long int DOOM_HTOWL(T x)
{
    return DOOM_SWAP_L(x);
}
template <typename T> short int DOOM_WTOHS(T x)
{
    return DOOM_SWAP_S(x);
}
template <typename T> short int DOOM_HTOWS(T x)
{
    return DOOM_SWAP_S(x);
}

template <typename T> long int DOOM_NTOHL(T x)
{
    return DOOM_SWAP_L(x);
}
template <typename T> long int DOOM_HTONL(T x)
{
    return DOOM_SWAP_L(x);
}
template <typename T> short int DOOM_NTOHS(T x)
{
    return DOOM_SWAP_S(x);
}
template <typename T> short int DOOM_HTONS(T x)
{
    return DOOM_SWAP_S(x);
}

#else

template <typename T> constexpr long int DOOM_WTOHL(T x)
{
    return static_cast<long int>(x);
}
template <typename T> constexpr long int DOOM_HTOWL(T x)
{
    return static_cast<long int>(x);
}
template <typename T> constexpr short int DOOM_WTOHS(T x)
{
    return static_cast<short int>(x);
}
template <typename T> constexpr short int DOOM_HTOWS(T x)
{
    return static_cast<short int>(x);
}

template <typename T> constexpr long int DOOM_NTOHL(T x)
{
    return static_cast<long int>(x);
}
template <typename T> constexpr long int DOOM_HTONL(T x)
{
    return static_cast<long int>(x);
}
template <typename T> constexpr short int DOOM_NTOHS(T x)
{
    return static_cast<short int>(x);
}
template <typename T> constexpr short int DOOM_HTONS(T x)
{
    return static_cast<short int>(x);
}

#endif

template <typename T> constexpr long int LITTLE_LONG(T x)
{
    return DOOM_WTOHL(x);
}
template <typename T> constexpr short int LITTLE_SHORT(T x)
{
    return DOOM_WTOHS(x);
}

#endif // DOOM_SWAP_HH
