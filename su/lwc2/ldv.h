/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Doubleword to Vector Unit             *
* Authors:  Iconoclast                                                         *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element & 0x7) /* Assemblers permit unaligned addresses. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("LDV\nWeird element.", 1);
HW_COMPAT:
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element++ ^ 01] = RSP.DMEM[addr++ ^ 03];
        addr &= 0x00000FFF;
        VR[vt].b[element ^ 01] = RSP.DMEM[addr ^ 03];
        return;
    }
    element >>= 01;
    switch (addr & 0x7)
    {
        case 00:
            VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            VR[vt].s[element + 02] = *(short *)(RSP.DMEM + addr + (0x4 ^ 02));
            VR[vt].s[element + 03] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            return;
        case 01:
            message("LDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 02:
            VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr - (0x0 ^ 02));
            VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x6 ^ 02));
            VR[vt].s[element + 02] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            addr += 0x006;
            addr &= 0x00000FFF;
            VR[vt].s[element + 03] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            return;
        case 03:
            message("LDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 04:
            VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            addr += 0x004;
            addr &= 0x00000FFF;
            VR[vt].s[element + 02] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[element + 03] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            return;
        case 05:
            message("LDV\nWeird addr.", 0);
            goto HW_COMPAT;
        case 06:
            VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr - (0x0 ^ 02));
            addr += 0x002;
            addr &= 0x00000FFF;
            VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[element + 02] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            addr += 0x004;
            addr &= 0x00000FFF;
            VR[vt].s[element + 03] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            return;
        case 07:
            message("LDV\nWeird addr.", 0);
            goto HW_COMPAT;
    }
}
