#include "lwc2/lwc2.h"

void LWC2(int rs, int rt, short imm)
{
    const int rd = (unsigned short)imm >> 11;
    const int element = (imm >> 7) & 0xF;
    const signed int offset = (imm & 0x003F) | (imm & 0x0040 ? ~077 : 0);

    SP_LWC2[rd](rt, element, offset, rs);
    return;
}
