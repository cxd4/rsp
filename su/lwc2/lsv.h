/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Shortword to Vector Unit              *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset <<= 1);
    addr &= 0x00000FFF;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            VR_S(vt, element) = *(short *)(RSP.DMEM + addr + HES(0x000));
            return;
        case 01:
            VR_S(vt, element) = *(short *)(RSP.DMEM + addr);
            return;
        case 02:
            VR_S(vt, element) = *(short *)(RSP.DMEM + addr - HES(0x000));
            return;
        case 03:
            message("LSV\nWeird addr.", 3);
            return;
    }
}
