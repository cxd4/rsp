/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Packed Signed from Vector Unit (SPV) *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.24                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SPV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 8);

    addr &= 0x00000FFF;
    if (element || addr & 0x007)
    {
        register int i;

        message("SPV\nCrossed doubleword index barrier.", 0);
        for (i = 0; i < 8; i++)
        {
            if (element < 8)
                RSP.DMEM[addr ^ 03] = VR[vt].b[(element << 1) ^ 01];
            else
                RSP.DMEM[addr ^ 03] = (char)(VR[vt].s[element & 07] >> 7);
            ++addr;
            ++element;
            element &= 0xF;
        }
        return;
    }
    RSP.DMEM[addr + (07 ^ 03)] = VR[vt].b[0xE ^ 01];
    RSP.DMEM[addr + (06 ^ 03)] = VR[vt].b[0xC ^ 01];
    RSP.DMEM[addr + (05 ^ 03)] = VR[vt].b[0xA ^ 01];
    RSP.DMEM[addr + (04 ^ 03)] = VR[vt].b[0x8 ^ 01];
    RSP.DMEM[addr + (03 ^ 03)] = VR[vt].b[0x6 ^ 01];
    RSP.DMEM[addr + (02 ^ 03)] = VR[vt].b[0x4 ^ 01];
    RSP.DMEM[addr + (01 ^ 03)] = VR[vt].b[0x2 ^ 01];
    RSP.DMEM[addr + (00 ^ 03)] = VR[vt].b[0x0 ^ 01];
/* Official documentation shows that there are exactly eight executions.
 * Although they must also occur simultaneously in the vector unit, the most
 * significant element (VR[vt].s[07]) is listed first in the operation
 * definition, whose sequence therefore must be:  `for (i = 7; i != 0; --i)`.
 */
    return;
}
