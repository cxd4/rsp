#include "../../vu/vu.h"

void CTC2(int rt, int vcr, int unused)
{
    unused = 0; /* no element specifier */
    switch (vcr & 03) /* RCP no-exception override */
    {
        case 00:
            VCO = (unsigned short)SR[rt];
            return;
        case 01:
            VCC = (unsigned short)SR[rt];
            return;
        case 02:
            message("CTC2\nVCE", 1);
            VCE = (unsigned char)SR[rt];
            return;
        case 03:
            message("CTC2\nInvalid vector control register.", 2);
            VCE = (unsigned char)SR[rt]; /* override behavior (zilmar) */
            return;
    }
}
