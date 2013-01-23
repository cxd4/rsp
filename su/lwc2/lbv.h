/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Byte to Vector Unit (LBV)             *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LBV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + offset;

    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    VR[vt].b[element ^ 01] = RSP.DMEM[addr ^ 03];
    return;
}
