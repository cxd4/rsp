void LW(int rs, int rt, short imm)
{
    register unsigned int addr;
    register int word;

    if (rt == 0)
    {
        message("LW\nTried to overwrite $zero.", 1);
        return;
    }
    addr  = SR[rs] + (signed short)imm;
    addr &= 0xFFF;
    if ((addr & 0x003) == 0x000)
    {
        SR[rt] = *(int *)(RSP.DMEM + addr);
        return;
    }
    if (addr > 0xFFC)
    {
        message("LW\nCrossed DMEM allocation barrier.", 1);
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
    word   = RSP.DMEM[addr ^ 03];
    word <<= 8;
    ++addr;
    word  |= RSP.DMEM[addr ^ 03];
    word <<= 8;
    ++addr;
    word  |= RSP.DMEM[addr ^ 03];
    word <<= 8;
    ++addr;
    word  |= RSP.DMEM[addr ^ 03];
    SR[rt] = word;
    return;
}
