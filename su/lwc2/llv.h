/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Longword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.05.06                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LLV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset <<= 2);
    addr &= 0x00000FFF;
    element += 0x1;
    element &= ~01; /* advance adaptation to odd-indexed halfword entries */
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR_H(vt, element+0x0) = *(short *)(RSP.DMEM + addr + HES(0x000));
            VR_H(vt, element+0x2) = *(short *)(RSP.DMEM + addr + HES(0x002));
            return;
        case 02: /* F3DLX 1.23:  "All-Star Baseball '99" */
            VR_H(vt, element+0x0) = *(short *)(RSP.DMEM + addr - HES(0x000));
            addr += 0x002 + HES(00);
            addr &= 0x00000FFF;
            VR_H(vt, element+0x2) = *(short *)(RSP.DMEM + addr);
            return;
        case 01:
        case 03:
            message("LLV\nOdd addr.", 3);
            return;
    }
}
