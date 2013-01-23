void BEQ(int rs, int rt, short offset)
{
    if (SR[rs] != SR[rt]) return;
    offset <<= 2;
    temp_PC = *RSP.SP_PC_REG + (offset & 0xFFC);
    delay_clock = 1;
    return;
}
