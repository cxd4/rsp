/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Packed Signed to Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.05.14                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LPV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;

    if (element != 0x0)
        goto ILLEGAL_EL;
    addr  = SR[base] + (offset <<= 3);
    b = addr;
    addr &= 0x00000FF8;
    switch (b &= 07)
    {
        case 00:
            VR[vt][07] = RSP.DMEM[addr + BES(0x007)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][00] = RSP.DMEM[addr + BES(0x000)] << 8;
            return;
        case 01: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += BES(0x008);
            addr &= 0x00000FFF;
            VR[vt][07] = RSP.DMEM[addr] << 8;
            return;
        case 02: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][06] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x001)] << 8;
            return;
        case 03: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][05] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x002)] << 8;
            return;
        case 04: /* F3DLX 2.08 "WWF No Mercy", Resident Evil 2 in-game 3-D */
            VR[vt][00] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][04] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x003)] << 8;
            return;
        case 05: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][03] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x004)] << 8;
            return;
        case 06: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x006)] << 8;
            VR[vt][01] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][02] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x005)] << 8;
            return;
        case 07: /* F3DZEX 2.08J "Doubutsu no Mori" (Animal Forest) CFB layer */
            VR[vt][00] = RSP.DMEM[addr + BES(0x007)] << 8;
            addr += 0x008;
            addr &= 0x00000FFF;
            VR[vt][01] = RSP.DMEM[addr + BES(0x000)] << 8;
            VR[vt][02] = RSP.DMEM[addr + BES(0x001)] << 8;
            VR[vt][03] = RSP.DMEM[addr + BES(0x002)] << 8;
            VR[vt][04] = RSP.DMEM[addr + BES(0x003)] << 8;
            VR[vt][05] = RSP.DMEM[addr + BES(0x004)] << 8;
            VR[vt][06] = RSP.DMEM[addr + BES(0x005)] << 8;
            VR[vt][07] = RSP.DMEM[addr + BES(0x006)] << 8;
            return;
    }
ILLEGAL_EL:
    message("LPV\nIllegal element.", 3);
    return;
}
