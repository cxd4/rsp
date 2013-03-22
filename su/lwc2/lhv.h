/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Alternate Bytes to Vector Unit        *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LHV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 0x0000000F)
    {
        case 0x0:
            VR[vt][07] = RSP.DMEM[addr + (0xF ^ 02)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0xD ^ 02)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0xB ^ 02)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x9 ^ 02)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x7 ^ 02)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x5 ^ 02)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x3 ^ 02)] << 7;
            VR[vt][00] = RSP.DMEM[addr + (0x1 ^ 02)] << 7;
            return;
        case 0x1:
            --addr;
            VR[vt][07] = RSP.DMEM[addr + (0xE ^ 02)] << 7;
            VR[vt][06] = RSP.DMEM[addr + (0xC ^ 02)] << 7;
            VR[vt][05] = RSP.DMEM[addr + (0xA ^ 02)] << 7;
            VR[vt][04] = RSP.DMEM[addr + (0x8 ^ 02)] << 7;
            VR[vt][03] = RSP.DMEM[addr + (0x6 ^ 02)] << 7;
            VR[vt][02] = RSP.DMEM[addr + (0x4 ^ 02)] << 7;
            VR[vt][01] = RSP.DMEM[addr + (0x2 ^ 02)] << 7;
            VR[vt][00] = RSP.DMEM[addr + (0x0 ^ 02)] << 7;
            return;
        default:
            message("LHV\nIllegal addr.", 3);
            return;
    }
bitch:
    message("LHV\nIllegal element.", 3);
    return;
}
