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
    switch (addr & 0x003)
    {
        case 00:
        DEFAULT:
            addr ^= 02; /* halfword endian swap */
        case 01:
            SR[rt] = *(signed short *)(RSP.DMEM + addr);
            return;
        case 02:  goto DEFAULT;
        case 03:
            if (addr == 0xFFF) /* LOL */
            {
                message("LH\nCrossed DMEM allocation barrier.", 1);
                SR[rt] = (RSP.DMEM[0xFFF ^ 03] << 8) | RSP.DMEM[0x000 ^ 03];
                SR[rt] = (signed short)SR[rt];
                return;
            }
            message("LH\nCrossed word endian boundary.", 0);
            SR[rt] = (RSP.DMEM[addr - 03] << 8) | RSP.DMEM[addr + 04];
            SR[rt] = (signed short)SR[rt];
            return;
    }
}
