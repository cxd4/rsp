/******************************************************************************\
* Project:  SP VU Emulation Table:  Store Shortword from Vector Unit           *
* Authors:  Iconoclast                                                         *
* Release:  2013.03.15                                                         *
* License:  none (public domain)                                               *
\******************************************************************************/

/* To-do:  Even though odd elements aren't exactly legal for SP operations,
 * they must in this case be supported because:
 *     a) The RSP assembler allows the generation of such commands.
 *     b) The RCP features exception overrides for illegal cases.
 *     c) Many N64 applications apply this illegal instruction.
 *
 * The efficient way to update vector registers indexing by ANY element value
 * is to define each vector register in the virtual file as an array of 8
 * 16-bit shortwords, not a dynamic union in C indexing from the right
 * (little endian), so that endian-swapping may be eliminated completely.
 * That is a massive rewrite though and will take time.
 */

void SSV(int vt, int element, signed int offset, int base)
{
    register unsigned int addr;

    addr  = SR[base] + (offset << 1);
    addr &= 0x00000FFF;
    if ((element & 0x1) != 0x0) /* `addr`, not the element, may be unaligned. */
    { /* F3DEX makes use of this typical illegal RCP exception override. */
        RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 0x1];
        ++addr;
        addr &= 0x00000FFF;
        ++element;
        element &= 0xF;
        RSP.DMEM[addr ^ 03] = VR[vt].b[element ^ 0x1];
        return;
    }
    element >>= 1;
    switch (addr & 03)
    {
        case 00: /* word-aligned */
            *(short *)(RSP.DMEM + (addr + 0x002)) = VR[vt].s[element];
            return;
        case 01:
            *(short *)(RSP.DMEM + (addr | 0x000)) = VR[vt].s[element];
            return;
        case 02:
            *(short *)(RSP.DMEM + (addr - 0x002)) = VR[vt].s[element];
            return;
        case 03:
            RSP.DMEM[addr - 0x003] = (unsigned short)(VR[vt].s[element]) >> 8;
            RSP.DMEM[(addr + 0x004) & 0xFFF] = VR[vt].s[element] & 0x00FF;
            return;
    }
}

/* Note regarding memory endianness.
 * The MIPS architecture is bi-endian.
 * The union access `VR[vt].s[element]` indexes from the rightmost halfword.
 * Halfwords in the vector registers are actually ordered left-to-right.
 */
