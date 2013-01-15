/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Byte from Vector Unit (SBV)          *
* Creator:  R. J. Swedlow                                                      *
* Release:  2012.12.28                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SBV(int vt, int element, signed offset, int base)
{
    register unsigned int addr = SR[base] + offset;

    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 01];
    return;
}
