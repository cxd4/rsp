#ifndef _RSP_H_
#define _RSP_H_

#include "Rsp_#1.1.h"
#include "z64.h"

typedef union
{
	UINT64 d[2];
	UINT32 l[4];
	INT16 s[8];
	UINT8 b[16];
} VECTOR_REG;

VECTOR_REG VR[32];
unsigned long int SR[32];

static int SP_CLOCK;
static int SP_PC;
static int temp_PC;
static int delay_clock;
/* Intermediary datum for maintaining the correct, real RSP PC after each
 * instruction, in conjunction with the maintained clock timing.
 */

typedef struct
{  
    unsigned int step_count; /* новое в 0.122u7 */
    int square_root_res;
    int square_root_high;
    int reciprocal_res;
    int reciprocal_high;
} RSP_REGS;

RSP_INFO RSP;

int rsp_execute(unsigned long cycles);
offs_t rsp_dasm_one(char *buffer, offs_t pc, UINT32 op);

extern RSP_REGS rsp; // __attribute__((aligned(16)));

#define VREG_B(reg, offset) VR[(reg)].b[((offset)^1)]
#define VREG_S(reg, offset) VR[(reg)].s[((offset))]
#define VREG_L(reg, offset) VR[(reg)].l[((offset))]

#define ACCUM(x)    VACC[x].q
#define ACCUM_H(x)  VACC[x].w[HI]
#define ACCUM_M(x)  VACC[x].w[MD]
#define ACCUM_L(x)  VACC[x].w[LO]

void ReverseEndian(unsigned char *start, register unsigned short int length)
{ /* For MIPS-size machine words only:  Invert 32-bit endianness. */
    register unsigned short int i = 0x0000;

    if (length & 03)
        length &= ~03;
    while (i < length)
    {
        unsigned char prebuffer[04];

        prebuffer[03] = *(start + (i + 0));
        prebuffer[02] = *(start + (i + 1));
        prebuffer[01] = *(start + (i + 2));
        prebuffer[00] = *(start + (i + 3));
        *(start + (i + 3)) = prebuffer[03];
        *(start + (i + 2)) = prebuffer[02];
        *(start + (i + 1)) = prebuffer[01];
        *(start + (i + 0)) = prebuffer[00];
        i += 0x0004;
    }
    return;
}

#endif // ifndef _RSP_H_
