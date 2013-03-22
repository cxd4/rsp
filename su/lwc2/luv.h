/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Unsigned to Vector Unit        *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LUV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 07)
    {
        case 00:
            VR[vt][07] = RSP.DMEM[addr + (0x007 ^ 03)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0x006 ^ 03)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0x005 ^ 03)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x004 ^ 03)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 03)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 03)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 03)] << 7;
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 03)] << 7;
            return;
        default: /* Completely legal, just never seen it be done. */
            message("LUV\nWeird addr.", 3);
            return;
    }
bitch:
    message("LUV\nIllegal element.", 3);
    return;
}
