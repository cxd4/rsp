void SLTIU(int rs, int rt, short imm)
{
    if (rt == 0)
    {
        message("SLTI\nTried to overwrite $zero.", 1);
        return;
    }
    SR[rt] = (unsigned)SR[rs] < (unsigned long)(short)imm;
    return;
}

/* Note that, while ADDI and ADDIU behave identically, SLTI and SLTIU do not.
 * The official MIPS reference and the operations manual shows that sign-
 * extension is modified between SLTI and SLTIU, just not for ADDI and ADDIU.
 * There is also a bug in one of the vendor documentations for this system,
 * saying (and self-contradicting) that SLTI and SLTIU behave identically.
 */
