/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Longword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LLV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 2);
    addr &= 0x00000FFF;
    if (element & 0x3) /* Assemblers permit unaligned addresses. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("LLV\nWeird element.", 3);
        return;
    }
    element >>= 1;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR[vt].s[element + 00] = *(short *)(RSP.DMEM + addr + (0x0 ^ 02));
            VR[vt].s[element + 01] = *(short *)(RSP.DMEM + addr + (0x2 ^ 02));
            return;
        case 01:
        case 02:
        case 03:
            message("LLV\nWeird addr.", 3);
            return;
    }
}
