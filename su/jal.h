void JAL(int unused_rs, int unused_rt, short target)
{
    unused_rs = 0;
    unused_rt = 0;
    SR[31]  = *RSP.SP_PC_REG; /* Link FIRST, */
    SR[31] += 0x00000004;
    SR[31] &= 0x00000FFC;
    target <<= 2;
    temp_PC = target & 0x00000FFC; /* THEN jump (processor manual order). */
    return;
}

/* To do:  Somehow MAME source base has a stable hack for updating the PC
 * offset quickly and in a way that link instructions only need to add 4,
 * not 8.  Maybe this is stable for most games, if not all, but I think I
 * should figure out a way to restore the original, natural method where
 * the link instruction needs to add 8.  (The link register might serve
 * another, unusual purpose besides branching back that could cause
 * incorrect data to be served in response.)
 */
