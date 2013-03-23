/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Byte to Vector Unit                   *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LBV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + offset;
    addr &= 0x00000FFF;
    addr ^= 0x003; /* byte endian swap */
    VR_B(vt, element) = RSP.DMEM[addr];
    return;
}
