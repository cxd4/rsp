#include "../../vu/vu.h"

void MTC2(int rt, int vd, int element)
{
    if ((element & 0x1) != 0x0)
    {
        message("MTC2\nUnaligned element.", 1);
        --element; /* element ^= 01; // halfword byte entry swap */
        VR[vd].b[element] = (unsigned short)SR[rt] >> 8;
        element += 0x3; /* endian_swap((e + 1) ^ 01) */
        if (element == (0x0 ^ 01))
        {
            message("MTC2\nTried to wrap around VR segment.", 0);
            return;
        }
        VR[vd].b[element] = (unsigned char)SR[rt];
        return;
    }
    element = (unsigned int)(element) >> 1;
    VR[vd].s[element] = (short)SR[rt];
    return;
}
