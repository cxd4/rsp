#include "vu.h"

static void VABS(int vd, int vs, int vt, int e)
{
    register int i;

#ifdef FORCE_STATIC_CLAMP
    for (i = 0; i < 8; i++)
    {
        register signed short ti;

        ti  = VR_T(i);
        ti ^= -(VR[vs][i] < 0); /* ti = ~ti */
        ti +=  (VR[vs][i] < 0) & (ti != 0x7FFF); /* abs(-32768) == +32767 */
        ti &= -(VR[vs][i] != 0);
        ACC_R(i) = ti;
    }
#else
    for (i = 0; i < 8; i++)
        if (VR[vs][i] < 0)
            ACC_R(i) = -(VR_T(i) ^ (VR_T(i) == -32768));
        else if (VR[vs][i] == 0)
            ACC_R(i) = 0x0000;
        else
            ACC_R(i) = +VR_T(i);
#endif
    for (i = 0; i < 8; i++)
        ACC_W(i) = ACC_R(i);
    return;
}
