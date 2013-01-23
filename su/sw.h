void SW(int rs, int rt, short imm)
{
    register unsigned int addr;

    addr = SR[rs] + (signed short)imm;
    if (addr & 0x003)
    {
        register int word = SR[rt];

        addr += 0x003;
        addr &= 0x00000FFF;
        RSP.DMEM[addr ^ 03] = word & 0x000000FF;
        word >>= 8;
        --addr;
        addr &= 0x00000FFF;
        RSP.DMEM[addr ^ 03] = word & 0x000000FF;
        word >>= 8;
        --addr;
        addr &= 0x00000FFF;
        RSP.DMEM[addr ^ 03] = word & 0x000000FF;
        word >>= 8;
        --addr;
        addr &= 0x00000FFF;
        RSP.DMEM[addr ^ 03] = word & 0x000000FF;
        return;
    }
    *(int *)(RSP.DMEM + (addr & 0xFFF)) = SR[rt];
    return;
}
