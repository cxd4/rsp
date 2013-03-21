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
    if (element & 0x3) /* The element must be aligned, not the address. */
    { /* F3DEX2 and some Rareware ucodes will force this illegal operation. */
        const int a = !(element & 0x1);

        message("SLV\nIllegal element.", 0);
        element = (unsigned int)(element) >> 1;
        RSP.DMEM[addr ^ 03] = (unsigned char)(VR[vt][element] >> (8*a));
        ++addr;
        addr &= 0x00000FFF;
        element += !a;
        RSP.DMEM[addr ^ 03] = (unsigned char)(VR[vt][element & 07] >> (8*!a));
        ++addr;
        addr &= 0x00000FFF;
        element += a;
        RSP.DMEM[addr ^ 03] = (unsigned char)(VR[vt][element & 07] >> (8*a));
        ++addr;
        addr &= 0x00000FFF;
        element += !a;
        RSP.DMEM[addr ^ 03] = (unsigned char)(VR[vt][element & 07] >> (8*!a));
        return;
    }
    element = (unsigned int)(element) >> 1;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + addr + (0x000 ^ 02)) = VR[vt][element + 00];
            *(short *)(RSP.DMEM + addr + (0x002 ^ 02)) = VR[vt][element + 01];
            return;
        case 02: /* F3DLX 0.95:  "Mario Kart 64" */
            *(short *)(RSP.DMEM + addr - 0x002) = VR[vt][element + 00];
            addr += 0x002 + 02; /* halfword endian swap adjust */
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr) = VR[vt][element + 01];
            return;
        case 01:
        case 03:
            message("SLV\nWeird addr.", 3);
            return;
    }
}
