/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Packed Unsigned from Vector Unit     *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.24                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SUV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + (offset * 8);

    addr &= 0x00000FFF; /* World Driver Championship:  on load START screen */
    if (element || addr & 0x007)
    {
        register int i;

        message("SUV\nCrossed doubleword index barrier.", 0);
        for (i = 0; i < 8; i++)
        {
            if (element < 8)
                RSP.DMEM[addr ^ 03] = (unsigned char)(VR[vt].s[element] >> 7);
            else
                RSP.DMEM[addr ^ 03] = VR[vt].b[((element & 0x7) << 1) ^ 01];
            ++addr;
            ++element;
            element &= 0xF;
        }
        return;
    }
    RSP.DMEM[addr + (07 ^ 03)] = (unsigned char)(VR[vt].s[07] >> 7);
    RSP.DMEM[addr + (06 ^ 03)] = (unsigned char)(VR[vt].s[06] >> 7);
    RSP.DMEM[addr + (05 ^ 03)] = (unsigned char)(VR[vt].s[05] >> 7);
    RSP.DMEM[addr + (04 ^ 03)] = (unsigned char)(VR[vt].s[04] >> 7);
    RSP.DMEM[addr + (03 ^ 03)] = (unsigned char)(VR[vt].s[03] >> 7);
    RSP.DMEM[addr + (02 ^ 03)] = (unsigned char)(VR[vt].s[02] >> 7);
    RSP.DMEM[addr + (01 ^ 03)] = (unsigned char)(VR[vt].s[01] >> 7);
    RSP.DMEM[addr + (00 ^ 03)] = (unsigned char)(VR[vt].s[00] >> 7);
/* Official documentation shows that there are exactly eight executions.
 * Although they must also occur simultaneously in the vector unit, the most
 * significant element (VR[vt].s[07]) is listed first in the operation
 * definition, whose sequence therefore must be:  `for (i = 7; i != 0; --i)`.
 */
    return;
}
