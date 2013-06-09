/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Doubleword from Vector Unit          *
* Authors:  Iconoclast                                                         *
* Release:  2013.06.09                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SDV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset <<= 3);
    addr &= 0x00000FFF;
    element += 0x1;
    element &= ~01; /* advance adaptation to odd-indexed halfword entries */
    switch (addr & 07)
    {
        case 00:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x006)) = VR_H(vt, element);
            return;
        case 01: /* "Tetrisphere" audio ucode */
            *(short *)(RSP.DMEM + addr) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + 0x002 - BES(00)] = (char)(VR_H(vt, element) >> 8);
            RSP.DMEM[addr + 0x003 + BES(00)] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x004) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + 0x006 - BES(00)] = (char)(VR_H(vt, element) >> 8);
            addr += 0x007 + BES(00);
            addr &= 0x00000FFF;
            RSP.DMEM[addr] = (unsigned char)VR_H(vt, element);
            return;
        case 02:
            *(short *)(RSP.DMEM + addr + 0x000 - HES(00)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x002 + HES(00)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x004 - HES(00)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            addr += 0x006 + HES(00);
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr) = VR_H(vt, element);
            return;
        case 03: /* "Tetrisphere" audio ucode */
            RSP.DMEM[addr - BES(0x000)] = (char)(VR_H(vt, element) >> 8);
            RSP.DMEM[addr + 0x001 + BES(00)] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x002) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + 0x004 - BES(00)] = (char)(VR_H(vt, element) >> 8);
            addr += 0x005 + BES(00);
            addr &= 0x00000FFF;
            RSP.DMEM[addr] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x001 - BES(00)) = VR_H(vt, element);
            return;
        case 04:
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            addr += 0x004;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR_H(vt, element);
            return;
        case 05: /* "Tetrisphere" audio ucode */
            *(short *)(RSP.DMEM + addr) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + 0x002 - BES(00)] = (char)(VR_H(vt, element) >> 8);
            addr += 0x003;
            addr &= 0x00000FFF;
            RSP.DMEM[addr + BES(0x000)] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x001) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + BES(0x003)] = (char)(VR_H(vt, element) >> 8);
            RSP.DMEM[addr + BES(0x004)] = (unsigned char)VR_H(vt, element);
            return;
        case 06:
            *(short *)(RSP.DMEM + addr - HES(0x000)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            addr += 0x002;
            addr &= 0x00000FFF;
            *(short *)(RSP.DMEM + addr + HES(0x000)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x002)) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + HES(0x004)) = VR_H(vt, element);
            return;
        case 07: /* "Tetrisphere" audio ucode */
            RSP.DMEM[addr - BES(0x000)] = (char)(VR_H(vt, element) >> 8);
            addr += 0x001;
            addr &= 0x00000FFF;
            RSP.DMEM[addr + BES(0x000)] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x001) = VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            RSP.DMEM[addr + BES(0x003)] = (char)(VR_H(vt, element) >> 8);
            RSP.DMEM[addr + BES(0x004)] = (unsigned char)VR_H(vt, element);
            element += 0x2;
            element &= 0xF;
            *(short *)(RSP.DMEM + addr + 0x005) = VR_H(vt, element);
            return;
    }
}
