#include "../../vu/vu.h"

void MFC2(int rt, int vd, int element)
{
/*
    if (rt == 0)
        return; // zero permanence already handled in main CPU loop
*/
    if (element == 0xF)
        goto leap;
    SR[rt] = VR_S(vd, element);
    SR[rt] = (signed short)(SR[rt]);
    return;
leap:
    message("MFC2\nCrossed segment allocation barrier.", 0);
    SR[rt] = (VR_B(vd, 0xF) << 8) | VR_B(vd, 0x0);
    SR[rt] = (signed short)(SR[rt]);
    return;
}
