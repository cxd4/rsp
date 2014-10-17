/******************************************************************************\
* Project:  Basic MIPS R4000 Instruction Set for Scalar Unit Operations        *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.17                                                         *
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

#include "Rsp_#1.1.h"

#define EXTERN_COMMAND_LIST_GBI
#define EXTERN_COMMAND_LIST_ABI
#define SEMAPHORE_LOCK_CORRECTIONS
#define WAIT_FOR_CPU_HOST

#if (0)
#define SP_EXECUTE_LOG
#define VU_EMULATE_SCALAR_ACCUMULATOR_READ
#endif

#define RSP_INFO_NAME           RSP_info
#define GET_RSP_INFO(member)    (RSP_INFO_NAME.member)
#define GET_RCP_REG(member)     (*RSP_INFO_NAME.member)

extern RSP_INFO RSP_INFO_NAME;
extern u8* DRAM;
extern u8* DMEM;
extern u8* IMEM;

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
#define CONTINUE    {continue;}
#define JUMP        {goto BRANCH;}
#else
#define CONTINUE    {break;}
#define JUMP        {break;}
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
extern void set_PC(int address);

#if (0)
#define MASK_SA(sa) (sa & 31)
/* Force masking in software. */
#else
#define MASK_SA(sa) (sa)
/* Let hardware architecture do the mask for us. */
#endif

#define SR_B(s, i)      (*(i8 *)(((i8 *)(SR + s)) + BES(i)))
#define SR_S(s, i)      (*(i16 *)(((i8 *)(SR + s)) + HES(i)))
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
#define VR_B(vt,element)    (*(i8 *)((i8 *)(VR[vt]) + MES(element)))

/*
 * Optimized byte-access macros for the vector registers.
 * Use these ONLY if you know the element is even (or odd in the second).
 */
#define VR_A(vt,element)    (*(i8 *)((i8 *)(VR[vt]) + element + MES(0x0)))
#define VR_U(vt,element)    (*(i8 *)((i8 *)(VR[vt]) + element - MES(0x0)))

/*
 * Optimized halfword-access macro for indexing eight-element vectors.
 * Use this ONLY if you know the element is even, not odd.
 *
 * If the four-bit element is odd, then there is no solution in one hit.
 */
#define VR_S(vt,element)    (*(i16 *)((i8 *)(VR[vt]) + element))

/*** Scalar, Coprocessor Operations (system control) ***/
#define SP_STATUS_HALT          (0x00000001 <<  0)
#define SP_STATUS_BROKE         (0x00000001 <<  1)
#define SP_STATUS_DMA_BUSY      (0x00000001 <<  2)
#define SP_STATUS_DMA_FULL      (0x00000001 <<  3)
#define SP_STATUS_IO_FULL       (0x00000001 <<  4)
#define SP_STATUS_SSTEP         (0x00000001 <<  5)
#define SP_STATUS_INTR_BREAK    (0x00000001 <<  6)
#define SP_STATUS_SIG0          (0x00000001 <<  7)
#define SP_STATUS_SIG1          (0x00000001 <<  8)
#define SP_STATUS_SIG2          (0x00000001 <<  9)
#define SP_STATUS_SIG3          (0x00000001 << 10)
#define SP_STATUS_SIG4          (0x00000001 << 11)
#define SP_STATUS_SIG5          (0x00000001 << 12)
#define SP_STATUS_SIG6          (0x00000001 << 13)
#define SP_STATUS_SIG7          (0x00000001 << 14)

extern u32* CR[16];

extern void SP_DMA_READ(void);
extern void SP_DMA_WRITE(void);

/*** shared states between the scalar and vector units ***/
extern unsigned short get_VCO(void);
extern unsigned short get_VCC(void);
extern unsigned char get_VCE(void);
extern void set_VCO(unsigned short VCO);
extern void set_VCC(unsigned short VCC);
extern void set_VCE(unsigned char VCE);
extern short vce[8];

extern unsigned short rwR_VCE(void);
extern void rwW_VCE(unsigned short VCE);

extern void MFC2(int rt, int vs, int e);
extern void MTC2(int rt, int vd, int e);
extern void CFC2(int rt, int rd);
extern void CTC2(int rt, int rd);

/*** Modern pseudo-operations (not real instructions, but nice shortcuts) ***/
extern void ULW(int rd, u32 addr);
extern void USW(int rs, u32 addr);

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

NOINLINE extern void MFC0(int rt, int rd);

/*** Scalar, Coprocessor Operations (vector unit, scalar cache transfers) ***/
INLINE extern void LBV(int vt, int element, int offset, int base);
INLINE extern void LSV(int vt, int element, int offset, int base);
INLINE extern void LLV(int vt, int element, int offset, int base);
INLINE extern void LDV(int vt, int element, int offset, int base);
INLINE extern void SBV(int vt, int element, int offset, int base);
INLINE extern void SSV(int vt, int element, int offset, int base);
INLINE extern void SLV(int vt, int element, int offset, int base);
INLINE extern void SDV(int vt, int element, int offset, int base);

/*
 * Group II vector loads and stores:
 * PV and UV (As of RCP implementation, XV and ZV are reserved opcodes.)
 */
INLINE extern void LPV(int vt, int element, int offset, int base);
INLINE extern void LUV(int vt, int element, int offset, int base);
INLINE extern void SPV(int vt, int element, int offset, int base);
INLINE extern void SUV(int vt, int element, int offset, int base);

/*
 * Group III vector loads and stores:
 * HV, FV, and AV (As of RCP implementation, AV opcodes are reserved.)
 */
NOINLINE extern void LHV(int vt, int element, int offset, int base);
NOINLINE extern void LFV(int vt, int element, int offset, int base);
NOINLINE extern void SHV(int vt, int element, int offset, int base);
NOINLINE extern void SFV(int vt, int element, int offset, int base);

/*
 * Group IV vector loads and stores:
 * QV and RV
 */
INLINE extern void LQV(int vt, int element, int offset, int base);
NOINLINE extern void LRV(int vt, int element, int offset, int base);
INLINE extern void SQV(int vt, int element, int offset, int base);
NOINLINE extern void SRV(int vt, int element, int offset, int base);

/*
 * Group V vector loads and stores
 * TV and SWV (As of RCP implementation, LTWV opcode was undesired.)
 */
INLINE extern void LTV(int vt, int element, int offset, int base);
NOINLINE extern void SWV(int vt, int element, int offset, int base);
INLINE extern void STV(int vt, int element, int offset, int base);

NOINLINE extern void run_task(void);

#endif
