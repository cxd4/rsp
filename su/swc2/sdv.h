/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Doubleword from Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element & 0x7) /* The element must be aligned, not the address. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("SDV\nIllegal element.", 3);
        return;
    }
    element = (unsigned int)(element) >> 1;
    switch (addr & 07)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt][element + 01];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt][element + 02];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt][element + 03];
            return;
        case 01:
            message("SDV\naddr2..0 = 1", 3);
            return;
        case 02:
            *(short *)(RSP.DMEM + addr - (0x000 ^ 02)) = VR[vt][element + 00];
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR[vt][element + 01];
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 02];
            addr += 0x006 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr) = VR[vt][element + 03];
            return;
        case 03:
            message("SDV\naddr2..0 = 3", 3);
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt][element + 01];
            addr += 0x004;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 02];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt][element + 03];
            return;
        case 05:
            message("SDV\naddr2..0 = 5", 3);
            return;
        case 06:
            *(short *)(RSP.DMEM + addr - (0x000 ^ 02)) = VR[vt][element + 00];
            addr += 0x002;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 01];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt][element + 02];
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR[vt][element + 03];
            return;
        case 07:
            message("SDV\naddr2..0 = 7", 3);
            return;
    }
}
