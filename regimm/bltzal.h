void BLTZAL(int rs, signed offset)
{
    SR[31]  = *RSP.SP_PC_REG + 4;
    SR[31] &= 0x00000FFC;
    if ((signed)SR[rs] >= 0) return;
    temp_PC  = *RSP.SP_PC_REG;
    temp_PC += offset;
    temp_PC &= 0x00000FFF;
    delay_clock = 1;
    return;
}
