void LB(int rs, int rt, short imm)
{
    register unsigned int addr;

    if (rt == 0)
    {
        message("LB\nTried to overwrite $zero.", 1);
        return;
    }
    addr = SR[rs] + (signed short)imm;
    addr ^= 03; /* big endian CPU correction */
    addr &= 0xFFF; /* RCP no-exception override:  Force SP DMEM range. */
    SR[rt] = *(signed char *)(RSP.DMEM + addr);
    return;
}

/* Should addr XOR 3 come before or after addr AND 0xFFF?
 *
 * It does not matter, since both orderings have their own perspective of
 * purity of algorithm.  I would not have to pick one over the other,
 * however, if the common N64 plugin system had the byte endian corrected!
 */
