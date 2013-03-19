/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Doubleword from Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element & 0x7) /* Assemblers permit unaligned addresses. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("SDV\nWeird element.", 3);
HW_COMPAT:
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr++ ^ 03] = VR[vt].b[element++ ^ 01];
        addr &= 0x00000FFF;
        element &= 0xF;
        RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 01];
        return;
    }
    element >>= 1;
    switch (addr & 07)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 01];
            *(short *)(RSP.DMEM + addr + (0x4 ^ 02)) = VR[vt].s[element + 02];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[element + 03];
            return;
        case 01:
            message("SDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 02:
            *(short *)(RSP.DMEM + addr - (0x0 ^ 02)) = VR[vt].s[element + 00];
            *(short *)(RSP.DMEM + addr + (0x6 ^ 02)) = VR[vt].s[element + 01];
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 02];
            addr += 0x006;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 03];
            return;
        case 03:
            message("SDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 04:
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 00];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 01];
            addr += 0x004;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 02];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 03];
            return;
        case 05:
            message("SDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 06:
            *(short *)(RSP.DMEM + addr - (0x0 ^ 02)) = VR[vt].s[element + 00];
            addr += 0x002;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 01];
            *(short *)(RSP.DMEM + addr + (0x2 ^ 02)) = VR[vt].s[element + 02];
            addr += 0x004;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x0 ^ 02)) = VR[vt].s[element + 03];
            return;
        case 07:
            message("SDV\nWeird addr.", 0);
            goto HW_COMPAT;
    }
}
