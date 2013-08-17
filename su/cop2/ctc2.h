#include "../../vu/vu.h"

void CTC2(int rt, int vcr, int unused)
{
    unused = 0; /* no element specifier */
    if (vcr & 2)
    {
        message("CTC2\nVCE", 1);
        VCE = (unsigned char)SR[rt];
        return;
    }
    *vCR[vcr &= 1] = (unsigned short)SR[rt];
    return;
}
