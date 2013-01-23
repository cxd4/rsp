#include "special/special.h"

void SPECIAL(int rs, int rt, short imm)
{
    const int rd = (unsigned short)imm >> 11;
    const int sa = (imm >> 6) % 32; /* Shift only thirty-two-bit registers. */

    imm &= 0x003F;
    SP_SPECIAL[imm](rs, rt, rd, sa);
    return;
}
