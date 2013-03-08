void BGEZAL(int rs, signed offset)
{
    int BC;

    SR[31]  = *RSP.SP_PC_REG + 4; /* wtf, should be 8 */
    SR[31] &= 0x00000FFC;
    BC = ((signed)SR[rs] >= 0);
    if (!BC) return;
    temp_PC = (*RSP.SP_PC_REG + offset) & 0x00000FFC;
    return;
}
