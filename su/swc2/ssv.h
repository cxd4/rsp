/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Shortword from Vector Unit           *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.01                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 1);
    addr &= 0x00000FFF;
    if (element == 0xF) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + (addr + 0x002)) = VR_S(vt, element);
            return;
        case 01:
            *(short *)(RSP.DMEM + (addr | 0x000)) = VR_S(vt, element);
            return;
        case 02:
            *(short *)(RSP.DMEM + (addr - 0x002)) = VR_S(vt, element);
            return;
        case 03: /* Mostly useful for continuing from erroneous CPU requests. */
            RSP.DMEM[addr - 0x003] = VR_B(vt, element + 0x0);
            addr += 0x001 + 03; /* byte endian swap adjust */
            addr &= 0x00000FFF;
            RSP.DMEM[addr] = VR_B(vt, element + 0x1);
            return;
    }
bitch:
    message("SSV\nIllegal element.", 3);
    return;
}
