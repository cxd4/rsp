#include "../../vu/vu.h"

void MTC2(int rt, int vd, int element)
{
    VR_S(vd, element) = (short)SR[rt];
    return; /* If element = 0xF, it does not matter; loads do not wrap over. */
}
