#include "vu.h"

static void VABS(int vd, int vs, int vt, int e)
{
    register int i;

    for (i = 0; i < 8; i++)
        if (VR[vs][i] < 0)
            ACC_R(i) = -(VR_T(i) ^ (VR_T(i) == -32768));
        else if (VR[vs][i] == 0)
            ACC_R(i) = 0x0000;
        else
            ACC_R(i) = +VR_T(i);
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}
