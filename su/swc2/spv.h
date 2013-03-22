/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Packed Signed from Vector Unit       *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SPV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 07)
    {
        case 00:
            RSP.DMEM[addr + (0x007 ^ 03)] = (unsigned char)(VR[vt][07] >> 8);
            RSP.DMEM[addr + (0x006 ^ 03)] = (unsigned char)(VR[vt][06] >> 8);
            RSP.DMEM[addr + (0x005 ^ 03)] = (unsigned char)(VR[vt][05] >> 8);
            RSP.DMEM[addr + (0x004 ^ 03)] = (unsigned char)(VR[vt][04] >> 8);
            RSP.DMEM[addr + (0x003 ^ 03)] = (unsigned char)(VR[vt][03] >> 8);
            RSP.DMEM[addr + (0x002 ^ 03)] = (unsigned char)(VR[vt][02] >> 8);
            RSP.DMEM[addr + (0x001 ^ 03)] = (unsigned char)(VR[vt][01] >> 8);
            RSP.DMEM[addr + (0x000 ^ 03)] = (unsigned char)(VR[vt][00] >> 8);
            return;
        default: /* Completely legal, just never seen it be done. */
            message("SPV\nWeird addr.", 3);
            return;
    }
bitch:
    message("SPV\nIllegal element.", 3);
    return;
}
