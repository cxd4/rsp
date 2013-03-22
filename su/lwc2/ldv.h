/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Doubleword to Vector Unit             *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    switch (addr & 0x7)
    {
        case 00:
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            return;
        case 01: /* standard ABI ucodes (unlike e.g. MusyX w/ even addresses) */
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 00));
            VR_S(vt, element+0x2)  = RSP.DMEM[addr - 0x001] << 8;
            VR_S(vt, element+0x2) |= RSP.DMEM[addr + 0x006];
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr + (0x004 ^ 00));
            VR_S(vt, element+0x6)  = RSP.DMEM[addr + 0x003] << 8;
            addr += 0x007 + 03; /* byte endian swap adjust */
            addr &= 0x00000FFF;
            VR_S(vt, element+0x6) |= RSP.DMEM[addr];
            return;
        case 02:
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            addr += 0x006 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr);
            return;
        case 03: /* standard ABI ucodes (unlike e.g. MusyX w/ even addresses) */
            VR_S(vt, element+0x0)  = RSP.DMEM[addr - 0x003] << 8;
            VR_S(vt, element+0x0) |= RSP.DMEM[addr + 0x004];
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 00));
            VR_S(vt, element+0x4)  = RSP.DMEM[addr + 0x001] << 8;
            addr += 0x005 + 03;
            addr &= 0x00000FFF;
            VR_S(vt, element+0x4) |= RSP.DMEM[addr];
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            return;
        case 04:
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            addr += 0x004;
            addr &= 0x00000FFF;
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            return;
        case 05: /* standard ABI ucodes (unlike e.g. MusyX w/ even addresses) */
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 00));
            VR_S(vt, element+0x2)  = RSP.DMEM[addr - 0x001] << 8;
            addr += 0x003 + 03;
            addr &= 0x00000FFF;
            VR_S(vt, element+0x2) |= RSP.DMEM[addr];
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            VR_S(vt, element+0x6)  = RSP.DMEM[addr - 0x003] << 8;
            VR_S(vt, element+0x6) |= RSP.DMEM[addr + 0x004];
            return;
        case 06:
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            addr += 0x002;
            addr &= 0x00000FFF;
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x4) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            return;
        case 07: /* standard ABI ucodes (unlike e.g. MusyX w/ even addresses) */
            VR_S(vt, element+0x0)  = RSP.DMEM[addr - 0x003] << 8;
            addr += 0x001 + 03;
            addr &= 0x00000FFF;
            VR_S(vt, element+0x0) |= RSP.DMEM[addr];
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            VR_S(vt, element+0x4)  = RSP.DMEM[addr - 0x003] << 8;
            VR_S(vt, element+0x4) |= RSP.DMEM[addr + 0x004];
            VR_S(vt, element+0x6) = *(short *)(RSP.DMEM + addr + (0x002 ^ 00));
            return;
    }
}
