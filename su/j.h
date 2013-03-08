void J(int unused_rs, int unused_rt, short target)
{
    unused_rs = 0;
    unused_rt = 0;
    target <<= 2;
    temp_PC = target & 0x00000FFC;
    return;
}
