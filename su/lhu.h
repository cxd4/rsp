void LHU(int rs, int rt, short imm)
{
    register unsigned int addr;

    if (rt == 0)
    {
        message("LHU\nTried to overwrite $zero.", 1);
        return;
    }
    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
/* This is the most common primary RSP opcode where the address is unaligned.
 * Mario, Castlevania, Zelda, like nearly every game has `case 01` below.
 * It is important therefore to understand this corrupt endian:
 *              00010203   00010203
 * MIPS native:  A-B C-D    E-F G-H
 * Intel flip :  D-C B-A    H-G F-E
 *              00  01     00  01
 * That diagram lets us deduce the following halfword transfers:
 *     1.  mov AB by XOR'ing the addr by 1 to mov B-A
 *     2.  mov CD by swapping the HW endian as defined above to move D-C
 *     3.  mov BC by directly accessing *(short) on Intel; do NOT ^ by 1
 *     4.  mov EF as in case 1, GH as in case 2, FG as in case 3
 *     5.  Never seen a game use DE ((addr & 03) == 03), but it's harder. :(
 */
    switch (addr & 0x003)
    {
        case 00:
        DEFAULT:
            addr ^= 02; /* halfword endian swap */
        case 01:
            SR[rt] = *(unsigned short *)(RSP.DMEM + addr);
            return;
        case 02:  goto DEFAULT;
        case 03:
            if (addr == 0xFFF) /* LOL */
            {
                message("LHU\nCrossed DMEM allocation barrier.", 1);
                SR[rt] = (RSP.DMEM[0xFFF ^ 03] << 8) | RSP.DMEM[0x000 ^ 03];
                return;
            }
            message("LHU\nCrossed word endian boundary.", 0);
            SR[rt] = (RSP.DMEM[addr - 03] << 8) | RSP.DMEM[addr + 04];
            return;
    }
}
