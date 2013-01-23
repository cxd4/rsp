void JALR(int rs, int unused_rt, int rd, int unused_sa)
{
    unused_rt = 0;
    unused_sa = 0;
    temp_PC = SR[rs];
    delay_clock = 1;
    if (rd == 0)
    {
        message("JALR\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rd] = (*RSP.SP_PC_REG + 0x004) & 0xFFC; /* to-do:  should be 8 */
    return;
}
