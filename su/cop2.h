#include "cop2/cop2.h"

void COP2(int rs, int rt, short imm)
{
    const int rd = (unsigned short)imm >> 11;
    const int element = (imm >> 7) & 0xF;

    SP_COP2[rs](rt, rd, element);
    return;
}
