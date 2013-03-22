/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Longword from Vector Unit            *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SLV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 2);
    addr &= 0x00000FFF;
    if (element > 0xC) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR_S(vt, element+0x0);
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR_S(vt, element+0x2);
            return;
        case 02: /* F3DLX 0.95:  "Mario Kart 64" */
            *(short *)(RSP.DMEM + addr - 0x002) = VR_S(vt, element+0x0);
            addr += 0x002 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr) = VR_S(vt, element+0x2);
            return;
        case 01:
        case 03:
            message("SLV\nWeird addr.", 3);
            return;
    }
bitch:
    message("SLV\nIllegal element.", 3);
    return;
}
