/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Signed to Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LPV(int vt, int element, signed offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element != 0x0) /* The element must be aligned, not the address. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("LPV\nIllegal element.", 3);
        return;
    }
    switch (addr & 07)
    {
        case 00:
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 03)] << 8;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 03)] << 8;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 03)] << 8;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 03)] << 8;
            VR[vt][04] = RSP.DMEM[addr + (0x004 ^ 03)] << 8;
            VR[vt][05] = RSP.DMEM[addr + (0x005 ^ 03)] << 8;
            VR[vt][06] = RSP.DMEM[addr + (0x006 ^ 03)] << 8;
            VR[vt][07] = RSP.DMEM[addr + (0x007 ^ 03)] << 8;
            return;
        case 04: /* WWF No Mercy F3DLX 2.08, Resident Evil 2 in-game 3-D */
            VR[vt][00] = RSP.DMEM[addr + (0x000 ^ 03)] << 8;
            VR[vt][01] = RSP.DMEM[addr + (0x001 ^ 03)] << 8;
            VR[vt][02] = RSP.DMEM[addr + (0x002 ^ 03)] << 8;
            VR[vt][03] = RSP.DMEM[addr + (0x003 ^ 03)] << 8;
            addr += 0x004;
            addr &= 0x00000FFF;
            VR[vt][04] = RSP.DMEM[addr + (0x000 ^ 03)] << 8;
            VR[vt][05] = RSP.DMEM[addr + (0x001 ^ 03)] << 8;
            VR[vt][06] = RSP.DMEM[addr + (0x002 ^ 03)] << 8;
            VR[vt][07] = RSP.DMEM[addr + (0x003 ^ 03)] << 8;
            return;
        default: /* Completely legal, just never seen it be done. */
            message("LPV\nWeird addr.", 3);
            return;
    }
}
