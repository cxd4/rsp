/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Alternate Bytes from Vector Unit     *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void SHV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    if (element != 0x0)
        goto ILLEGAL_EL;
    addr  = SR[base] + (offset <<= 4);
    addr &= 0x00000FFF;
    if (addr & 0x0000000E)
        goto BAD_ADDR;
/* The official algorithm for ?HV as defined in US patent no. 5,812,147 first
 * checks the least significant bit of `addr` to specify whether to load
 * every even byte or every odd byte.
 *
 * More computationally efficient, however, is to encompass that dynamic
 * check by statically emulating the halfword index intervals `+= 0x002`.
 * Don't forget to swap the endianness of the halfword index barrier `^= 02`.
 */
    addr ^= BES(00) & 0x001;
    RSP.DMEM[addr + HES(0x00E)] = (unsigned char)(VR[vt][07] >> 7);
    RSP.DMEM[addr + HES(0x00C)] = (unsigned char)(VR[vt][06] >> 7);
    RSP.DMEM[addr + HES(0x00A)] = (unsigned char)(VR[vt][05] >> 7);
    RSP.DMEM[addr + HES(0x008)] = (unsigned char)(VR[vt][04] >> 7);
    RSP.DMEM[addr + HES(0x006)] = (unsigned char)(VR[vt][03] >> 7);
    RSP.DMEM[addr + HES(0x004)] = (unsigned char)(VR[vt][02] >> 7);
    RSP.DMEM[addr + HES(0x002)] = (unsigned char)(VR[vt][01] >> 7);
    RSP.DMEM[addr + HES(0x000)] = (unsigned char)(VR[vt][00] >> 7);
    return;
BAD_ADDR: /* "Illegal" command, but on the N64 there is override behavior. */
    message("LHV\nIllegal addr.", 3);
    return;
ILLEGAL_EL:
    message("LHV\nIllegal element.", 3);
    return;
}
