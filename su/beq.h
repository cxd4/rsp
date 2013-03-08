void BEQ(int rs, int rt, short offset)
{
    int BC;

    BC = (SR[rs] == SR[rt]);
    if (!BC) return;
    offset <<= 2;
    temp_PC = (*RSP.SP_PC_REG + offset) & 0x00000FFC;
    return;
}
