#include "regimm/regimm.h"

void REGIMM(int rs, int rt, short imm)
{
    imm <<= 2; /* 16-bit "offset" (type definition from "immediate") */
    SP_REGIMM[rt](rs, imm);
    return;
}
