/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Alternate Bytes to Vector Unit        *
* Authors:  Iconoclast                                                         *
* Release:  2013.04.20                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LHV(int vt, int element, signed int offset, int base)
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
    addr ^= MES(00);
    VR[vt][07] = RSP.DMEM[addr + HES(0x00E)] << 7;
    VR[vt][06] = RSP.DMEM[addr + HES(0x00C)] << 7;
    VR[vt][05] = RSP.DMEM[addr + HES(0x00A)] << 7;
    VR[vt][04] = RSP.DMEM[addr + HES(0x008)] << 7;
    VR[vt][03] = RSP.DMEM[addr + HES(0x006)] << 7;
    VR[vt][02] = RSP.DMEM[addr + HES(0x004)] << 7;
    VR[vt][01] = RSP.DMEM[addr + HES(0x002)] << 7;
    VR[vt][00] = RSP.DMEM[addr + HES(0x000)] << 7;
    return;
BAD_ADDR: /* "Illegal" command, but on the N64 there is override behavior. */
    message("LHV\nIllegal addr.", 3);
    return;
ILLEGAL_EL:
    message("LHV\nIllegal element.", 3);
    return;
}
