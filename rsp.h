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

RSP_INFO RSP;

int rsp_execute(unsigned long cycles);
offs_t rsp_dasm_one(char *buffer, offs_t pc, UINT32 op);

#define VREG_B(reg, offset) VR[(reg)].b[((offset)^1)]
#define VREG_S(reg, offset) VR[(reg)].s[((offset))]
#define VREG_L(reg, offset) VR[(reg)].l[((offset))]

#endif // ifndef _RSP_H_
