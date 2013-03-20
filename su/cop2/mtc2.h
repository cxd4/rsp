#include "../../vu/vu.h"

void MTC2(int rt, int vd, int element)
{
    if ((element & 0x1) != 0x0)
    {
        message("MTC2\nUnaligned element.", 3);
        return;
    }
    element = (unsigned int)(element) >> 1;
    VR[vd][element] = (short)SR[rt];
    return;
}
