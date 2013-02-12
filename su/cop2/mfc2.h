#include "../../vu/vu.h"

/* to-do:  Try to optimize to using accurate, 16-bit single-hit writes. */

void MFC2(int rt, int vd, int element)
{
    if (rt == 0)
    {
        message("MFC2\t$zero, vd", 1);
        SR[rt] = 0x00000000;
        return;
    }
    SR[rt]  = (signed char)VR[vd].b[element ^ 01] << 8;
    ++element;
    element &= 0xF; /* With MF, not MT, it is O.K. to wrap around. */
    SR[rt] |= VR[vd].b[element ^ 01]; /* sign-extended halfword load */
    return;
}
