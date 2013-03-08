void BLEZ(int rs, int unused_rt, short offset)
{
    int BC;

    unused_rt = 0;
    BC = ((signed)SR[rs] <= 0);
    if (!BC) return;
    offset <<= 2;
    temp_PC = (*RSP.SP_PC_REG + offset) & 0x00000FFC;
    return;
}
