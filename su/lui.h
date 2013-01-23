void LUI(int unused_rs, int rt, short imm)
{
    unused_rs = 0;
    if (rt == 0)
    {
        message("LUI\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = imm << 16;
    return;
}
