void LH(int rs, int rt, short imm)
{
    register unsigned int addr;

    if (rt == 0)
    {
        message("LH\nTried to overwrite $zero.", 1);
        return;
    }
    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
    if ((addr & 0x001) != 0x000) /* For speed, try tests using 0, not 1. */
    { /* `if (addr & 1)` is not explicit because compiler might try == 1. */
        register signed short halfword;

        halfword   = RSP.DMEM[addr ^ 03];
        halfword <<= 8;
        ++addr;
        addr &= 0x00000FFF;
        halfword  |= RSP.DMEM[addr ^ 03];
        SR[rt] = halfword;
        return;
    }
    addr ^= 02; /* halfword endian swap */
    SR[rt] = *(signed short *)(RSP.DMEM + addr);
    return;
}
