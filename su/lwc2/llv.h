/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Longword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.19                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LLV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset <<= 2);
    addr &= 0x00000FFF;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            return;
        case 02: /* F3DLX 1.23:  "All-Star Baseball '99" */
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr - (0x000 ^ 02));
            addr += 0x002 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr);
            return;
        case 01:
        case 03:
            message("LLV\nOdd addr.", 3);
            return;
    }
}
