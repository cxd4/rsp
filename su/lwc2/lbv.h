/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Byte to Vector Unit                   *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LBV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + offset;
    addr &= 0x00000FFF;
    VR_B(vt, element) = RSP.DMEM[BES(addr)];
    return;
}
