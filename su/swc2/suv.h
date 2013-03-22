/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Packed Unsigned from Vector Unit     *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.22                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SUV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF; /* World Driver Championship:  on load START screen */
    if (element == 0xF) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 07)
    {
        case 00:
            RSP.DMEM[addr + (07 ^ 03)] = (unsigned char)(VR[vt][07] >> 7);
            RSP.DMEM[addr + (06 ^ 03)] = (unsigned char)(VR[vt][06] >> 7);
            RSP.DMEM[addr + (05 ^ 03)] = (unsigned char)(VR[vt][05] >> 7);
            RSP.DMEM[addr + (04 ^ 03)] = (unsigned char)(VR[vt][04] >> 7);
            RSP.DMEM[addr + (03 ^ 03)] = (unsigned char)(VR[vt][03] >> 7);
            RSP.DMEM[addr + (02 ^ 03)] = (unsigned char)(VR[vt][02] >> 7);
            RSP.DMEM[addr + (01 ^ 03)] = (unsigned char)(VR[vt][01] >> 7);
            RSP.DMEM[addr + (00 ^ 03)] = (unsigned char)(VR[vt][00] >> 7);
            return;
        default: /* Completely legal, just never seen it be done. */
            message("SUV\nWeird addr.", 3);
            return;
    }
bitch:
    message("SUV\nIllegal element.", 3);
    return;
}
