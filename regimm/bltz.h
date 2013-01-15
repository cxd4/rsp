void BLTZ(int rs, signed offset)
{
    if ((signed)SR[rs] >= 0) return;
    temp_PC  = *RSP.SP_PC_REG;
    temp_PC += offset;
    temp_PC &= 0x00000FFF;
    delay_clock = 1;
    return;
}
