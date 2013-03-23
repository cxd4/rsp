/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Byte from Vector Unit                *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.23                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SBV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + offset;
    addr &= 0x00000FFF;
    addr ^= 0x003; /* byte endian swap */
    RSP.DMEM[addr] = VR_B(vt, element);
    return;
}
