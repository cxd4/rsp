/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Packed Unsigned from Vector Unit     *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SUV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;

    addr  = SR[base] + (offset <<= 3);
    b = addr & 0x00000007;
    addr &= 0x00000FF8; /* World Driver Championship:  on load START screen */
    if (element != 0x0)
        goto ILLEGAL_EL;
    switch (b)
    {
        case 00:
            RSP.DMEM[addr + BES(0x007)] = (unsigned char)(VR[vt][07] >> 7);
            RSP.DMEM[addr + BES(0x006)] = (unsigned char)(VR[vt][06] >> 7);
            RSP.DMEM[addr + BES(0x005)] = (unsigned char)(VR[vt][05] >> 7);
            RSP.DMEM[addr + BES(0x004)] = (unsigned char)(VR[vt][04] >> 7);
            RSP.DMEM[addr + BES(0x003)] = (unsigned char)(VR[vt][03] >> 7);
            RSP.DMEM[addr + BES(0x002)] = (unsigned char)(VR[vt][02] >> 7);
            RSP.DMEM[addr + BES(0x001)] = (unsigned char)(VR[vt][01] >> 7);
            RSP.DMEM[addr + BES(0x000)] = (unsigned char)(VR[vt][00] >> 7);
            return;
        default: /* Completely legal, just never seen it be done. */
            message("SUV\nWeird addr.", 3);
            return;
    }
ILLEGAL_EL:
    message("SUV\nIllegal element.", 3);
    return;
}
