/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Doubleword from Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 3);
    addr &= 0x00000FFF;
    if (element > 0x8) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 07)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x0);
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR_S(vt, element+0x2);
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR_S(vt, element+0x4);
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR_S(vt, element+0x6);
            return;
        case 01:
            message("SDV\nOdd addr.", 3);
            return;
        case 02:
            *(short *)(RSP.DMEM + addr - (0x000 ^ 02)) = VR_S(vt, element+0x0);
            *(short *)(RSP.DMEM + addr + (0x006 ^ 02)) = VR_S(vt, element+0x2);
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x4);
            addr += 0x006 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr) = VR_S(vt, element+0x6);
            return;
        case 03:
            message("SDV\nOdd addr.", 3);
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x0);
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR_S(vt, element+0x2);
            addr += 0x004;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x4);
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR_S(vt, element+0x6);
            return;
        case 05:
            message("SDV\nOdd addr.", 3);
            return;
        case 06:
            *(short *)(RSP.DMEM + addr - (0x000 ^ 02)) = VR_S(vt, element+0x0);
            addr += 0x002;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x2);
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR_S(vt, element+0x4);
            *(short *)(RSP.DMEM + addr + (0x004 ^ 02)) = VR_S(vt, element+0x6);
            return;
        case 07:
            message("SDV\nOdd addr.", 3);
            return;
    }
bitch:
    message("SDV\nIllegal element.", 3);
    return;
}
