void BLEZ(int rs, int unused_rt, short offset)
{
    unused_rt = 0;
    if ((signed)SR[rs] > 0) return;
    offset <<= 2;
    temp_PC = *RSP.SP_PC_REG + (offset & 0xFFC);
    delay_clock = 1;
    return;
}
