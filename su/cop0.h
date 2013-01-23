#include "cop0/cop0.h"

void COP0(int rs, int rt, short imm)
{
    const int rd = (unsigned short)imm >> 11;

    if (rd & 16)
    { /* The assembler permits $cn for n <= 31, but dox show n <= 15 so wtf? */
        message("COP0", 3);
        return;
    }
    SP_COP0[rs](rt, rd);
    return;
}
