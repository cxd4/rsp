#include "vu.h"

static void VMRG(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        ACC_R(i) = VCC & (0x0001 << i) ? VR[vs][i] : VR_T(i);
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}
