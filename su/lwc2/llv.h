/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Longword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.21                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LLV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 2);
    addr &= 0x00000FFF;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR_S(vt, element+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt, element+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            return;
        case 01:
        case 02:
        case 03:
            message("LLV\nWeird addr.", 3);
            return;
    }
}
