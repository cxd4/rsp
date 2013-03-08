void JR(int rs, int unused_rt, int unused_rd, int unused_sa)
{
    unused_rt = 0;
    unused_rd = 0;
    unused_sa = 0;
    temp_PC = SR[rs] & 0x00000FFC;
    return;
}
