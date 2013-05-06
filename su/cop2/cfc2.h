#include "../../vu/vu.h"

void CFC2(int rt, int vcr, int unused)
{
/*
    if (rt == 0)
        return; // zero permanence already handled in main CPU loop
*/
    unused = 0; /* no element specifier */
    switch (vcr & 03) /* RCP no-exception override */
    {
        case 00:
            SR[rt] = (signed short)VCO;
            return;
        case 01:
            SR[rt] = (signed short)VCC;
            return;
        case 02:
            message("CFC2\nVCE", 1);
            SR[rt] = VCE;
            return;
        case 03:
            message("CFC2\nInvalid vector control register.", 2);
            SR[rt] = VCE; /* override behavior (zilmar) */
            return;
    }
}
