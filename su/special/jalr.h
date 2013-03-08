void JALR(int rs, int unused_rt, int rd, int unused_sa)
{
    unused_rt = 0;
    unused_sa = 0;
    temp_PC = SR[rs] & 0x00000FFC;
    if (rd == 0)
    {
        message("JALR\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rd]  = *RSP.SP_PC_REG + 0x004; /* to-do:  should be 8, wtf `jal.h` */
    SR[rd] &= 0x00000FFC;
    return;
}
