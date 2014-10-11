/******************************************************************************\
* Project:  Standard Integer Type Definitions                                  *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.10                                                         *
* License:  CC0 Public Domain Dedication                                       *
*                                                                              *
* To the extent possible under law, the author(s) have dedicated all copyright *
* and related and neighboring rights to this software to the public domain     *
* worldwide. This software is distributed without any warranty.                *
*                                                                              *
* You should have received a copy of the CC0 Public Domain Dedication along    *
* with this software.                                                          *
* If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.             *
\******************************************************************************/

#ifndef _MY_TYPES_H_
#define _MY_TYPES_H_

/*
 * Use three procedures for standard integer type definitions from C.
 *     1.  If compiling with MSVC, use Microsoft's LLP64 fixed-size types.
 *         If it's not a Microsoft compiler, it isn't using the LLP64 model.
 *     2.  If C99 or later support is found, attempt to #include <stdint.h>
 *         and to use possible C99 type definitions.  The above method for
 *         MSFT compilers has the pro of not raising subtle C89 warnings.
 *     3.  If C99 support was not found, hope for a LP64 model and the best.
 *         Even C89 regulates that short >= 16b; int >= 16b; long >= 32b.
 *
 * While not specifying [un-]signed for non-char results in signed data types
 * as per current standards, some algorithms are best read with an emphasis
 * on the actual need for sign- or zero-extension, if not indifference.
 */
#ifdef _MSC_VER

typedef __int8                  i8;
typedef signed __int8           s8;
typedef unsigned __int8         u8;

typedef __int16                 i16;
typedef signed __int16          s16;
typedef unsigned __int16        u16;

typedef __int32                 i32;
typedef signed __int32          s32;
typedef unsigned __int32        u32;

typedef __int64                 i64;
typedef signed __int64          s64;
typedef unsigned __int64        u64;

#elif (__STDC_VERSION__ >= 199901L) | !defined(__STDC_VERSION__)

#include <stdint.h>

typedef uint8_t                 u8;
typedef uint16_t                u16;
typedef uint32_t                u32;
typedef uint64_t                u64;

typedef int16_t                 i16;
typedef int32_t                 i32;
typedef int64_t                 i64;

typedef i16                     s16;
typedef i32                     s32;
typedef i64                     s64;

/*
 * Type `i8' should be neutral to signedness and representative of the
 * indifference as to whether implementations or optimizations sign or not.
 */
typedef char                    i8;
typedef int8_t                  s8;

#else

typedef char                    i8;
typedef signed char             s8;
typedef unsigned char           u8;

typedef short                   i16;
typedef signed short            s16;
typedef unsigned short          u16;

typedef int                     i32;
typedef signed int              s32;
typedef unsigned int            u32;

typedef long                    i64;
typedef signed long             s64;
typedef unsigned long           u64;

#endif

/*
 * Optimizing compilers aren't necessarily perfect compilers, but they do
 * have that extra chance of supporting explicit [anti-]inline instructions.
 */
#ifdef _MSC_VER
#define INLINE      __inline
#define NOINLINE    __declspec(noinline)
#define ALIGNED     _declspec(align(16))
#elif defined(__GNUC__)
#define INLINE      inline
#define NOINLINE    __attribute__((noinline))
#define ALIGNED     __attribute__((aligned(16)))
#else
#define INLINE
#define NOINLINE
#define ALIGNED
#endif

/*
 * aliasing helpers
 * Strictly put, this may be unspecified behavior, but it's nice to have!
 */
typedef union {
    u8 B[2];
    s8 SB[2];

    i16 W;
    u16 UW;
    s16 SW; /* Here, again, explicitly writing "signed" may help clarity. */
} word_16;
typedef union {
    u8 B[4];
    s8 SB[4];

    i16 H[2];
    u16 UH[2];
    s16 SH[2];

    i32 W;
    u32 UW;
    s32 SW;
} word_32;
typedef union {
    u8 B[8];
    s8 SB[8];

    i16 F[4];
    u16 UF[4];
    s16 SF[4];

    i32 H[2];
    u32 UH[2];
    s32 SH[2];

    i64 W;
    u64 UW;
    s64 SW;
} word_64;

/*
 * extra types of encoding for the well-known MIPS RISC architecture
 * Possibly implement other machine types in future versions of this header.
 */
typedef struct {
    unsigned opcode:  6;
    unsigned rs:  5;
    unsigned rt:  5;
    unsigned rd:  5;
    unsigned sa:  5;
    unsigned function:  6;
} MIPS_type_R;
typedef struct {
    unsigned opcode:  6;
    unsigned rs:  5;
    unsigned rt:  5;
    unsigned imm:  16;
} MIPS_type_I;

/*
 * Maybe worth including, maybe not.
 * It's sketchy since bit-fields pertain to `int' type, of which the size is
 * not necessarily going to be even 4 bytes.  On C compilers for MIPS itself,
 * almost certainly, but is this really important to have?
 */
#if 0
typedef struct {
    unsigned opcode:  6;
    unsigned target:  26;
} MIPS_type_J;
#endif

#endif
