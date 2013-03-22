/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Bytes from Vector Unit     *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.22                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SHV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 4);
    addr &= 0x00000FFF;
    if (element != 0x0) /* We need an explicit `goto` for stupid compilers. */
        goto bitch; /* Blame M$ for their ineptitude with branch weighs. */
    if (addr & 0x0000000E)
        goto ass;
/* The official algorithm for ?HV as defined in US patent no. 5,812,147 first
 * checks the least significant bit of `addr` to specify whether to load
 * every even byte or every odd byte.
 *
 * More computationally efficient, however, is to encompass that dynamic
 * check by statically emulating the halfword index intervals `+= 0x002`.
 * Don't forget to swap the endianness of the halfword index barrier `^= 02`.
 */
    addr ^= 0x001; /* Because MIPS is bi-endian, and Intel isn't. */
    RSP.DMEM[addr + (0x00E ^ 02)] = (unsigned char)(VR[vt][07] >> 7);
    RSP.DMEM[addr + (0x00C ^ 02)] = (unsigned char)(VR[vt][06] >> 7);
    RSP.DMEM[addr + (0x00A ^ 02)] = (unsigned char)(VR[vt][05] >> 7);
    RSP.DMEM[addr + (0x008 ^ 02)] = (unsigned char)(VR[vt][04] >> 7);
    RSP.DMEM[addr + (0x006 ^ 02)] = (unsigned char)(VR[vt][03] >> 7);
    RSP.DMEM[addr + (0x004 ^ 02)] = (unsigned char)(VR[vt][02] >> 7);
    RSP.DMEM[addr + (0x002 ^ 02)] = (unsigned char)(VR[vt][01] >> 7);
    RSP.DMEM[addr + (0x000 ^ 02)] = (unsigned char)(VR[vt][00] >> 7);
    return;
bitch:
    message("SHV\nIllegal element.", 3);
    return;
ass:
    message("SHV\nIllegal addr.", 3);
    return;
}
