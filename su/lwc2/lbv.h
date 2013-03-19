/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Byte to Vector Unit                   *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.10                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LBV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + offset;
    addr &= 0x00000FFF; /* RCP no-exception override:  Force SP DMEM range. */
    VR[vt].b[element ^ 01] = RSP.DMEM[addr ^ 03];
    return;
}

/* Note regarding memory endianness.
 * The MIPS architecture is bi-endian.
 * The union access `VR[vt].b[element ^ 01]` indexes from the rightmost byte.
 * Bytes in the vector registers are actually ordered left-to-right.
 *
 * Additionally, Intel 16-bit writes are the reverse endian of RSP HW writes.
 * Therefore, `element` must be XOR'd by 0b1 to invert the endianness to big.
 */
