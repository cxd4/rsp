/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Shortword to Vector Unit              *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 1);
    addr &= 0x00000FFF;
    if ((element & 0x1) != 0x0) /* Assemblers permit unaligned addresses. */
    { /* Technically an illegal instruction to assemble, but H/W allows it. */
        message("LSV\nOdd element.", 3);
        return;
    }
    element >>= 1;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR[vt].s[element] = *(short *)(RSP.DMEM + (addr + 0x002));
            return;
        case 01:
            VR[vt].s[element] = *(short *)(RSP.DMEM + (addr | 0x000));
            return;
        case 02:
            VR[vt].s[element] = *(short *)(RSP.DMEM + (addr - 0x002));
            return;
        case 03:
            message("LSV\nWeird addr.", 3);
            return;
    }
}

/* Note regarding memory endianness.
 * The MIPS architecture is bi-endian.
 * The union access `VR[vt].s[element]` indexes from the rightmost halfword.
 * Halfwords in the vector registers are actually ordered left-to-right.
 */
