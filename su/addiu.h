void ADDIU(int rs, int rt, short imm)
{
    if (rt == 0)
    {
        message("ADDIU\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = SR[rs] + (signed short)imm;
    return;
}

/* No doubt that it will be noticed, this file is nearly identical to ADDI.
 * It should not be misleading, because in the MIPS architecture, the only
 * difference between ADDI and ADDIU was whether a trap exception was raised
 * on integer overflow.  Because there are no exception-handling facilities
 * on the RCP, it is definitive that ADDI and ADDIU behave identically.
 */
