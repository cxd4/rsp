#include "../../vu/vu.h"

void CFC2(int rt, int vcr, int unused)
{
    unused = 0; /* no element specifier */
    if (vcr & 2)
    {
        message("CFC2\nVCE", 1);
        SR[rt] = VCE;
        return;
    }
    SR[rt] = *vCR[vcr &= 1];
    return;
}
