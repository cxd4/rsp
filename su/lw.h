void LW(int rs, int rt, short imm)
{
    register unsigned int addr;

    if (rt == 0)
    {
        message("LW\nTried to overwrite $zero.", 1);
        return;
    }
    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
    if (addr & 0x003)
    {
        register int word;

        word   = RSP.DMEM[addr ^ 03];
        word <<= 8;
        ++addr;
        addr &= 0x00000FFF;
        word  |= RSP.DMEM[addr ^ 03];
        word <<= 8;
        ++addr;
        addr &= 0x00000FFF;
        word  |= RSP.DMEM[addr ^ 03];
        word <<= 8;
        ++addr;
        addr &= 0x00000FFF;
        word  |= RSP.DMEM[addr ^ 03];
        SR[rt] = word;
        return;
    }
    SR[rt] = *(int *)(RSP.DMEM + addr);
    return;
}
