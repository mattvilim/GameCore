/*
 * Game Core Copyright (C) 2014 Matthew Vilim
 *
 * src/shared/macros.h
 */

#ifndef MACROS_H
#define MACROS_H

#ifndef __has_builtin
# define __has_builtin(x) 0
#endif

/*********************
 * SIZE CALCULATIONS *
 ********************/
#define ARRAY_SIZE(array)            (sizeof(array) / sizeof(array[0]))
#define MEMBER_SIZE(type, member)    sizeof(((type *)0)->member)

/***************************
 * BIT MANIPULATION MACROS *
 **************************/
// create masks
#define BIT(i)                   (1 << i)
#define MASK_LEN(len, low)       ((BIT(len) - 1) << (low))
#define MASK_RANGE(high, low)    MASK_LEN((high) - (low) + 1, low)
// miscellaneous tricks
#define LOW_BIT(val)        ((val) & -(val))
#define LOW_BIT_IDX(val)    ((val) != 0 ? ((val) / LOW_BIT(val)) : 0)
// read/write masks
#define BIT_FIELD_READ(in, mask)         (((in) & (mask)) >> LOW_BIT_IDX(mask))
#define BIT_FIELD_WRITE(in, mask, val)    (((in) & ~(mask)) | ((val) << LOW_BIT_IDX(mask)))

/********************
 * COMMON BIT MASKS *
 ********************/
 #define MASK_LOW_B     MASK_RANGE( 7, 0)
 #define MASK_HIGH_B    MASK_RANGE(15, 8)
 #define MASK_LOW_W     MASK_RANGE(15, 0)
 #define MASK_HIGH_W    MASK_RANGE(31, 16)
 #define MAKS_DW        MASK_RANGE(31, 0)

/*********************
 * ENDIAN CONVERSION *
 *********************/
#ifdef __BIG_ENDIAN__
# define ARCH_NATIVE_BIG_ENDIAN     __BIG_ENDIAN__
#else
# error native architecture endianness must be defined
#endif

#if __has_builtin(__builtin_bswap32)
# define BYTE_SWAP32(val) __builtin_bswap32(val)
#else
# define BYTE_SWAP32(val) ((((val) & MASK_RANGE(31, 24)) >> 24) \
                         | (((val) & MASK_RANGE(23, 16)) >> 8)  \
                         | (((val) & MASK_RANGE(15, 8))  << 8)  \
                         | (((val) & MASK_RANGE(7, 0))   << 24))
#endif

#if __has_builtin(__builtin_bswap16)
# define BYTE_SWAP16(val) __builtin_bswap16(val)
#else
# define BYTE_SWAP16(val) ((val >> 8) | (val << 8))
#endif

#if ARCH_NATIVE_BIG_ENDIAN
# define ENDIAN_CONV_DWORD(val)   BYTE_SWAP32(val)
# define ENDIAN_CONV_WORD(val)    BYTE_SWAP16(val)
#else
# define ENDIAN_CONV_DWORD(val)   (val)
# define ENDIAN_CONV_WORD(val)    (val)
#endif

#define GBYTES_LOG2(n) (30 + (n))
#define MBYTES_LOG2(n) (20 + (n))
#define KBYTES_LOG2(n) (10 + (n))

#if __has_attribute(always_inline)
# define INLINE_FORCE inline __attribute__((always_inline))
#else
# warn functions might not be inlined
# define INLINE_FORCE inline
#endif

#endif
