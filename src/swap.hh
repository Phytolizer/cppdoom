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
#define DOOM_SWAP_S (signed short)__arch__swab16
#endif
#ifdef __arch__swab32
#define DOOM_SWAP_L (signed long)__arch__swab32
#endif
#endif /* HAVE_ASM_BYTEORDER_H */

#ifdef HAVE_LIBKERN_OSBYTEORDER_H
#include <libkern/OSByteOrder.h>

#define DOOM_SWAP_S (short)OSSwapInt16
#define DOOM_SWAP_L (long)OSSwapInt32
#endif

#ifndef DOOM_SWAP_L
#define DOOM_SWAP_L(x)                                                         \
  ((long int)((((unsigned long int)(x)&0x000000ffU) << 24) |                   \
              (((unsigned long int)(x)&0x0000ff00U) << 8) |                    \
              (((unsigned long int)(x)&0x00ff0000U) >> 8) |                    \
              (((unsigned long int)(x)&0xff000000U) >> 24)))
#endif

#ifndef DOOM_SWAP_S
#define DOOM_SWAP_S(x)                                                         \
  ((short int)((((unsigned short int)(x)&0x00ff) << 8) |                       \
               (((unsigned short int)(x)&0xff00) >> 8)))
#endif
#ifdef WORDS_BIGENDIAN

#define DOOM_WTOHL(x) DOOM_SWAP_L(x)
#define DOOM_HTOWL(x) DOOM_SWAP_L(x)
#define DOOM_WTOHS(x) DOOM_SWAP_S(x)
#define DOOM_HTOWS(x) DOOM_SWAP_S(x)

#define DOOM_NTOHL(x) DOOM_SWAP_L(x)
#define DOOM_HTONL(x) DOOM_SWAP_L(x)
#define DOOM_NTOHS(x) DOOM_SWAP_S(x)
#define DOOM_HTONS(x) DOOM_SWAP_S(x)

#else

#define DOOM_WTOHL(x) (long int)(x)
#define DOOM_HTOWL(x) (long int)(x)
#define DOOM_WTOHS(x) (short int)(x)
#define DOOM_HTOWS(x) (short int)(x)

#define DOOM_NTOHL(x) (long int)(x)
#define DOOM_HTONL(x) (long int)(x)
#define DOOM_NTOHS(x) (short int)(x)
#define DOOM_HTONS(x) (short int)(x)

#endif

#define LITTLE_LONG(x) DOOM_WTOHL(x)
#define LITTLE_SHORT(x) DOOM_HTOWS(x)

#endif // DOOM_SWAP_HH
