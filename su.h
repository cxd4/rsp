/******************************************************************************\
* Project:  Basic MIPS R4000 Instruction Set for Scalar Unit Operations        *
* Authors:  Iconoclast                                                         *
* Release:  2015.01.30                                                         *
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

#ifndef _SU_H_
#define _SU_H_

#include <stdio.h>
#include "my_types.h"
#include "rsp.h"

#define EXTERN_COMMAND_LIST_GBI
#define EXTERN_COMMAND_LIST_ABI
#define SEMAPHORE_LOCK_CORRECTIONS
#define WAIT_FOR_CPU_HOST

#if (0)
#define SP_EXECUTE_LOG
#define VU_EMULATE_SCALAR_ACCUMULATOR_READ
#endif

extern int CPU_running;

extern RSP_INFO RSP_INFO_NAME;
extern pu8 DRAM;
extern pu8 DMEM;
extern pu8 IMEM;

extern u8 conf[32];

/*
 * RSP virtual registers (of scalar unit)
 * The most important are the 32 general-purpose scalar registers.
 * We have the convenience of using a 32-bit machine (Win32) to emulate
 * another 32-bit machine (MIPS/N64), so the most natural way to accurately
 * emulate the scalar GPRs is to use the standard `int` type.  Situations
 * specifically requiring sign-extension or lack thereof are forcibly
 * applied as defined in the MIPS quick reference card and user manuals.
 * Remember that these are not the same "GPRs" as in the MIPS ISA and totally
 * abandon their designated purposes on the master CPU host (the VR4300),
 * hence most of the MIPS names "k0, k1, t0, t1, v0, v1 ..." no longer apply.
 */
extern i32 SR[32];

#define FIT_IMEM(PC)    (PC & 0xFFF & 0xFFC)

#ifdef EMULATE_STATIC_PC
#define CONTINUE    continue
#define JUMP        goto BRANCH
#else
#define CONTINUE    break
#define JUMP        break
#endif

#ifdef EMULATE_STATIC_PC
#define BASE_OFF    0x000
#else
#define BASE_OFF    0x004
#endif

#ifndef EMULATE_STATIC_PC
int stage;
#endif

extern int temp_PC;
#ifdef WAIT_FOR_CPU_HOST
extern short MFC0_count[32];
/* Keep one C0 MF status read count for each scalar register. */
#endif

#define SLOT_OFF    (BASE_OFF + 0x000)
#define LINK_OFF    (BASE_OFF + 0x004)
extern void set_PC(unsigned int address);

#if (0x7FFFFFFFul >> 037 != 0x7FFFFFFFul >> ~0U)
#define MASK_SA(sa) (sa & 037)
/* Force masking in software. */
#else
#define MASK_SA(sa) (sa)
/* Let hardware architecture do the mask for us. */
#endif

#define SR_B(s, i)      (*(pi8)(((pi8)(SR + s)) + BES(i)))
#define SR_S(s, i)      (*(pi16)(((pi8)(SR + s)) + HES(i)))
#define SE(x, b)        (-(x & (1 << b)) | (x & ~(~0 << b)))
#define ZE(x, b)        (+(x & (1 << b)) | (x & ~(~0 << b)))

/*
 * Since RSP vectors are stored 100% accurately as big-endian arrays for the
 * proper vector operation math to be done, LWC2 and SWC2 emulation code will
 * have to look a little different.  zilmar's method is to distort the endian
 * using an array of unions, permitting hacked byte- and halfword-precision.
 */

/*
 * Universal byte-access macro for 16*8 halfword vectors.
 * Use this macro if you are not sure whether the element is odd or even.
 */
#define VR_B(vt,element)    (*(pi8)((pi8)(VR[vt]) + MES(element)))

/*
 * Optimized byte-access macros for the vector registers.
 * Use these ONLY if you know the element is even (or odd in the second).
 */
#define VR_A(vt,element)    (*(pi8)((pi8)(VR[vt]) + element + MES(0x0)))
#define VR_U(vt,element)    (*(pi8)((pi8)(VR[vt]) + element - MES(0x0)))

/*
 * Optimized halfword-access macro for indexing eight-element vectors.
 * Use this ONLY if you know the element is even, not odd.
 *
 * If the four-bit element is odd, then there is no solution in one hit.
 */
#define VR_S(vt,element)    (*(pi16)((pi8)(VR[vt]) + element))

/*** Scalar, Coprocessor Operations (system control) ***/
#define SP_STATUS_HALT          (0x00000001ul <<  0)
#define SP_STATUS_BROKE         (0x00000001ul <<  1)
#define SP_STATUS_DMA_BUSY      (0x00000001ul <<  2)
#define SP_STATUS_DMA_FULL      (0x00000001ul <<  3)
#define SP_STATUS_IO_FULL       (0x00000001ul <<  4)
#define SP_STATUS_SSTEP         (0x00000001ul <<  5)
#define SP_STATUS_INTR_BREAK    (0x00000001ul <<  6)
#define SP_STATUS_SIG0          (0x00000001ul <<  7)
#define SP_STATUS_SIG1          (0x00000001ul <<  8)
#define SP_STATUS_SIG2          (0x00000001ul <<  9)
#define SP_STATUS_SIG3          (0x00000001ul << 10)
#define SP_STATUS_SIG4          (0x00000001ul << 11)
#define SP_STATUS_SIG5          (0x00000001ul << 12)
#define SP_STATUS_SIG6          (0x00000001ul << 13)
#define SP_STATUS_SIG7          (0x00000001ul << 14)

extern pu32 CR[16];

extern void SP_DMA_READ(void);
extern void SP_DMA_WRITE(void);

/*** shared states between the scalar and vector units ***/
extern u16 get_VCO(void);
extern u16 get_VCC(void);
extern u8 get_VCE(void);
extern void set_VCO(u16 VCO);
extern void set_VCC(u16 VCC);
extern void set_VCE(u8 VCE);
extern i16 cf_vce[8];

extern u16 rwR_VCE(void);
extern void rwW_VCE(u16 VCE);

extern void MFC2(unsigned int rt, unsigned int vs, unsigned int e);
extern void MTC2(unsigned int rt, unsigned int vd, unsigned int e);
extern void CFC2(unsigned int rt, unsigned int rd);
extern void CTC2(unsigned int rt, unsigned int rd);

/*** Modern pseudo-operations (not real instructions, but nice shortcuts) ***/
extern void ULW(unsigned int rd, u32 addr);
extern void USW(unsigned int rs, u32 addr);

/*
 * The scalar unit controls the primary R4000 operations implementation,
 * which inherently includes interfacing with the vector unit under COP2.
 *
 * Although no scalar unit operations are computational vector operations,
 * several of them will access machine states shared with the vector unit.
 *
 * We will need access to the vector unit's vector register file and its
 * vector control register file used mainly for vector select instructions.
 */
#include "vu/select.h"

NOINLINE extern void res_S(void);

extern void SP_CP0_MF(unsigned int rt, unsigned int rd);

/*
 * example syntax (basically the same for all LWC2/SWC2 ops):
 * LTWV    $v0[0], -64($at)
 * SBV     $v0[9], 0xFFE($0)
 */
typedef void(*mwc2_func)(
    unsigned int vt,
    unsigned int element,
    signed int offset,
    unsigned int base
);

extern mwc2_func LWC2[2 * 8*2];
extern mwc2_func SWC2[2 * 8*2];

extern void res_lsw(
    unsigned int vt,
    unsigned int element,
    signed int offset,
    unsigned int base
);

/*** Scalar, Coprocessor Operations (vector unit, scalar cache transfers) ***/
extern void LBV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LSV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LLV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LDV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SBV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SSV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SLV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SDV(unsigned vt, unsigned element, signed offset, unsigned base);

/*
 * Group II vector loads and stores:
 * PV and UV (As of RCP implementation, XV and ZV are reserved opcodes.)
 */
extern void LPV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LUV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SPV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SUV(unsigned vt, unsigned element, signed offset, unsigned base);

/*
 * Group III vector loads and stores:
 * HV, FV, and AV (As of RCP implementation, AV opcodes are reserved.)
 */
extern void LHV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LFV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SHV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SFV(unsigned vt, unsigned element, signed offset, unsigned base);

/*
 * Group IV vector loads and stores:
 * QV and RV
 */
extern void LQV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void LRV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SQV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SRV(unsigned vt, unsigned element, signed offset, unsigned base);

/*
 * Group V vector loads and stores
 * TV and SWV (As of RCP implementation, LTWV opcode was undesired.)
 */
extern void LTV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void SWV(unsigned vt, unsigned element, signed offset, unsigned base);
extern void STV(unsigned vt, unsigned element, signed offset, unsigned base);

NOINLINE extern void run_task(void);

/*
 * Unfortunately, SSE machine code takes up so much space in the instruction
 * cache when populated enough in something like an interpreter switch
 * statement, that the compiler starts looking for ways to create branches
 * and jumps where the C code specifies none.  This complex set of macros
 * is intended to minimize the compiler's obligation to choose doing this
 * since SSE2 has no static shuffle operation with a variable mask operand.
 */
#ifdef ARCH_MIN_SSE2
#define EXECUTE_VU() { target = *(v16 *)VR[vt]; \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_0Q() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(00, 00, 02, 02)), SHUFFLE(04, 04, 06, 06)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_1Q() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(01, 01, 03, 03)), SHUFFLE(05, 05, 07, 07)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_0H() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(00, 00, 00, 00)), SHUFFLE(04, 04, 04, 04)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_1H() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(01, 01, 01, 01)), SHUFFLE(05, 05, 05, 05)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_2H() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(02, 02, 02, 02)), SHUFFLE(06, 06, 06, 06)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_3H() { \
    target = _mm_shufflehi_epi16(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(03, 03, 03, 03)), SHUFFLE(07, 07, 07, 07)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_0W() { \
    target = _mm_shuffle_epi32(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(00, 00, 00, 00)), SHUFFLE(0/2, 0/2, 0/2, 0/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_1W() { \
    target = _mm_shuffle_epi32(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(01, 01, 01, 01)), SHUFFLE(1/2, 1/2, 1/2, 1/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_2W() { \
    target = _mm_shuffle_epi32(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(02, 02, 02, 02)), SHUFFLE(2/2, 2/2, 2/2, 2/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_3W() { \
    target = _mm_shuffle_epi32(_mm_shufflelo_epi16(*(v16 *)VR[vt], \
        SHUFFLE(03, 03, 03, 03)), SHUFFLE(3/2, 3/2, 3/2, 3/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_4W() { \
    target = _mm_shuffle_epi32(_mm_shufflehi_epi16(*(v16 *)VR[vt], \
        SHUFFLE(04, 04, 04, 04)), SHUFFLE(4/2, 4/2, 4/2, 4/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_5W() { \
    target = _mm_shuffle_epi32(_mm_shufflehi_epi16(*(v16 *)VR[vt], \
        SHUFFLE(05, 05, 05, 05)), SHUFFLE(5/2, 5/2, 5/2, 5/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_6W() { \
    target = _mm_shuffle_epi32(_mm_shufflehi_epi16(*(v16 *)VR[vt], \
        SHUFFLE(06, 06, 06, 06)), SHUFFLE(6/2, 6/2, 6/2, 6/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#define EXECUTE_VU_7W() { \
    target = _mm_shuffle_epi32(_mm_shufflehi_epi16(*(v16 *)VR[vt], \
        SHUFFLE(07, 07, 07, 07)), SHUFFLE(7/2, 7/2, 7/2, 7/2)); \
    *(v16 *)(VR[vd]) = vector_op(source, target); }
#else
#define EXECUTE_VU() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x0); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_0Q() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x2); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_1Q() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x3); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_0H() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x4); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_1H() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x5); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_2H() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x6); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_3H() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x7); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_0W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x8); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_1W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0x9); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_2W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xA); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_3W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xB); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_4W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xC); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_5W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xD); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_6W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xE); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#define EXECUTE_VU_7W() { \
    vector_copy(target, VR[vt]); SHUFFLE_VECTOR(target, 0xF); \
    vector_op(source, target); vector_copy(VR[vd], V_result); }
#endif

#endif
