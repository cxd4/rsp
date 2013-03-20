/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Unsigned to Vector Unit (LUV)  *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.24                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LUV(int vt, int element, signed offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0)
    { /* World Driver Championship gfx ucode will do this in intro demo. */
        message("LUV\nWeird element.", 3);
        return;
    }
    switch (addr & 07)
    {
        case 00:
            VR[vt][07] = RSP.DMEM[addr + (07 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (06 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (05 ^ 03)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (04 ^ 03)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (03 ^ 03)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (02 ^ 03)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (01 ^ 03)] << 7;
            VR[vt][00] = RSP.DMEM[addr + (00 ^ 03)] << 7;
            return;
        default:
            message("LUV\nWeird addr.", 3);
            return;
    }
/* Official documentation shows that there are exactly eight executions.
 * Although they must also occur simultaneously in the vector unit, the most
 * significant element (VR[vt][07]) is listed first in the operation
 * definition, whose sequence therefore must be:  `for (i = 7; i != 0; --i)`.
 */
}
