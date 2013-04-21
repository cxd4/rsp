/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Shortword from Vector Unit           *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset <<= 1);
    addr &= 0x00000FFF;
    if (element == 0xF)
        goto LOL;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR_S(vt, element);
            return;
        case 01:
            *(short *)(RSP.DMEM + addr) = VR_S(vt, element);
            return;
        case 02:
            *(short *)(RSP.DMEM + addr - HES(0x000)) = VR_S(vt, element);
            return;
        case 03:
            message("SSV\nWeird addr.", 3);
            return;
    }
LOL:
    message("SSV\nIllegal element.", 3);
    return;
}
