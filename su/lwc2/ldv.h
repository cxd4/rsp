/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Doubleword to Vector Unit             *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element & 0x7) /* The element must be aligned, not the address. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("LDV\nIllegal element.", 3);
        return;
    }
    element = (unsigned int)(element) >> 1;
    switch (addr & 0x7)
    {
        case 00:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            return;
        case 01:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 00));
            VR[vt][element + 01]  = RSP.DMEM[addr - 0x001] << 8;
            VR[vt][element + 01] |= RSP.DMEM[addr + 0x006];
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr + (0x004 ^ 00));
            VR[vt][element + 03]  = RSP.DMEM[addr + 0x003] << 8;
            addr += 0x007 + 03; /* byte endian swap adjust */
            addr &= 0x00000FFF;
            VR[vt][element + 03] |= RSP.DMEM[addr];
            return;
        case 02:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            addr += 0x006 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr);
            return;
        case 03:
            VR[vt][element + 00]  = RSP.DMEM[addr - 0x003] << 8;
            VR[vt][element + 00] |= RSP.DMEM[addr + 0x004];
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 00));
            VR[vt][element + 02]  = RSP.DMEM[addr + 0x001] << 8;
            addr += 0x005 + 03;
            addr &= 0x00000FFF;
            VR[vt][element + 02] |= RSP.DMEM[addr];
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            return;
        case 04:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            addr += 0x004;
            addr &= 0x00000FFF;
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            return;
        case 05:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr + (0x000 ^ 00));
            VR[vt][element + 01]  = RSP.DMEM[addr - 0x001] << 8;
            addr += 0x003 + 03;
            addr &= 0x00000FFF;
            VR[vt][element + 01] |= RSP.DMEM[addr];
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            VR[vt][element + 03]  = RSP.DMEM[addr - 0x003] << 8;
            VR[vt][element + 03] |= RSP.DMEM[addr + 0x004];
            return;
        case 06:
            VR[vt][element + 00] = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            addr += 0x002;
            addr &= 0x00000FFF;
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR[vt][element + 02] = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            return;
        case 07:
            VR[vt][element + 00]  = RSP.DMEM[addr - 0x003] << 8;
            addr += 0x001 + 03;
            addr &= 0x00000FFF;
            VR[vt][element + 00] |= RSP.DMEM[addr];
            VR[vt][element + 01] = *(short *)(RSP.DMEM + addr - (0x002 ^ 00));
            VR[vt][element + 02]  = RSP.DMEM[addr - 0x003] << 8;
            VR[vt][element + 02] |= RSP.DMEM[addr + 0x004];
            VR[vt][element + 03] = *(short *)(RSP.DMEM + addr + (0x002 ^ 00));
            return;
    }
}
