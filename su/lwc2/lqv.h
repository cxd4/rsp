/******************************************************************************\
* Project:  SP VU Emulation Table:  Load Quadword to Vector Unit               *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.30                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

void LQV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;
    int b;
    const int e = element; /* "Boss Game Studios" audio use illegal elements. */

    addr  = SR[base] + (offset << 4);
    b = addr & 0x0000000F;
    addr &= 0x00000FF0;
/* There is a mistake in United States patent no. 5,812,147 by SGI.
 * In multiple other statements, LQV is defined to go all the way to addr|15.
 * This means that if addr&15 is 0, length == 16; addr&15 is 15, length == 1.
 *
 * However, they give an if-else chain for b={0:7} only, which allows a bug
 * exploitable by Resident Evil 2 and, possibly, some Boss Game publications.
 * Conker's Bad Fur Day audio also could have exploited this but covers it.
 */
    switch (b)
    {
        case 0x0:
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x000 ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR_S(vt,e+0x6) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR_S(vt,e+0x8) = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR_S(vt,e+0xA) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0xC) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0xE) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x2:
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x002 ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR_S(vt,e+0x6) = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR_S(vt,e+0x8) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0xA) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0xC) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x4:
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x004 ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR_S(vt,e+0x6) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0x8) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0xA) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x6:
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x006 ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0x6) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0x8) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0x8: /* Resident Evil 2 cinematics and Boss Game Studios */
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x008 ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0x6) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xA: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x00A ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0x4) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xC: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x00C ^ 02));
            VR_S(vt,e+0x2) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        case 0xE: /* "Conker's Bad Fur Day" audio microcode by Rareware */
            VR_S(vt,e+0x0) = *(short *)(RSP.DMEM + addr + (0x00E ^ 02));
            return;
        default:
            message("LQV\nOdd addr.", 3);
            return;
    }
/* Obviously, an alternative "fall-through" version of this switch could be
 * written by removing `addr &= 0x00000FF0;` and adjusting all offsets
 * accordingly, but this is slow and harder to optimize for several reasons.
 */
}
