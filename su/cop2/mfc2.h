#include "../../vu/vu.h"

void MFC2(int rt, int vd, int element)
{
    if (rt == 0)
    {
        message("MFC2\t$zero, vd", 1);
        SR[rt] = 0x00000000;
        return;
    }
    if ((element & 0x1) != 0x0)
    {
        message("MFC2\nUnaligned element.", 0); /* A few games will try this. */
        --element; /* element ^= 01; // halfword byte entry swap */
        SR[rt]  = (signed char)VR[vd].b[element] << 8;
        element += 0x3; /* endian_swap((e + 1) ^ 01) */
        element &= 0xF;
        SR[rt] |= (unsigned char)VR[vd].b[element];
    }
    element = (unsigned int)(element) >> 1;
    SR[rt] = (signed short)VR[vd].s[element];
    return;
}
