void BLTZ(int rs, signed offset)
{
    int BC;

    BC = ((signed)SR[rs] < 0);
    if (!BC) return;
    temp_PC = (*RSP.SP_PC_REG + offset) & 0x00000FFC;
    return;
}
