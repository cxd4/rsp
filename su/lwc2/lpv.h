/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Signed to Vector Unit (LPV)    *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.24                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LPV(int vt, int element, signed offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0)
    { /* Resident Evil 2 gfx ucode 3-D in-game will do this. */
        message("LPV\nWeird element.", 3);
        return;
    }
    switch (addr & 07)
    {
        case 00:
            VR[vt].s[07] = RSP.DMEM[addr + (07 ^ 03)] << 8;
            VR[vt].s[06] = RSP.DMEM[addr + (06 ^ 03)] << 8;
            VR[vt].s[05] = RSP.DMEM[addr + (05 ^ 03)] << 8;
            VR[vt].s[04] = RSP.DMEM[addr + (04 ^ 03)] << 8;
            VR[vt].s[03] = RSP.DMEM[addr + (03 ^ 03)] << 8;
            VR[vt].s[02] = RSP.DMEM[addr + (02 ^ 03)] << 8;
            VR[vt].s[01] = RSP.DMEM[addr + (01 ^ 03)] << 8;
            VR[vt].s[00] = RSP.DMEM[addr + (00 ^ 03)] << 8;
            return;
        default:
            message("LPV\nWeird addr.", 3);
            return;
    }
/* Official documentation shows that there are exactly eight executions.
 * Although they must also occur simultaneously in the vector unit, the most
 * significant element (VR[vt].s[07]) is listed first in the operation
 * definition, whose sequence therefore must be:  `for (i = 7; i != 0; --i)`.
 */
}
