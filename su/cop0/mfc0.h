void scan_ICACHE_for_cycle_fault(int cr);
/* My colossal attempt at covering up for faults in the host CPU emulator
 * (the main MIPS CPU, like Project64.exe) concerning cycle timing and
 * related inaccuracies.  Days of frustration were spent writing this.
 * I teach the software to teach its self, to intelligently "guess" which
 * CPU-RSP synchronization signal bit (SP_STATUS_SIG[?]) failed to get set.
 *
 * Additionally, I then XOR this bit in/out and assume this responsibility
 * over the main emulator EXE, although doing that update to the SP status
 * register is probably not necessary (especially since zilmar's method gets
 * away with just a simple break exiting out of the hung-up microcode).
 */

void MFC0(int rt, int rd)
{
    if (rt == 0)
    {
        message("MFC0\t$zero, rd", 1);
        SR[000] = 0x00000000;
        return;
    }
    switch (rd)
    {
        case 0x0:
            SR[rt] = *RSP.SP_MEM_ADDR_REG;
            return;
        case 0x1:
            SR[rt] = *RSP.SP_DRAM_ADDR_REG;
            return;
        case 0x2: /* have not verified / been able to test yet ? */
            message("MFC0\nDMA_READ_LENGTH", 2);
            SR[rt] = *RSP.SP_RD_LEN_REG;
            return;
        case 0x3:
            message("MFC0\nDMA_WRITE_LENGTH", 3);
            return; /* dunno what to do, so error */
        case 0x4:
#ifdef SEARCH_INFINITE_LOOPS
            ++MFC0_count[rt];
            if (MFC0_count[rt] > MAX_WAIT)
                scan_ICACHE_for_cycle_fault(rt);
#endif
            SR[rt] = *RSP.SP_STATUS_REG;
            return;
        case 0x5:
            if (*RSP.SP_DMA_FULL_REG)
                message("MFC0\nDMA_FULL", 3);
            SR[rt] = 0x00000000;
            return;
        case 0x6:
            if (*RSP.SP_DMA_BUSY_REG)
                message("MFC0\nDMA_BUSY", 3);
            SR[rt] = 0x00000000;
            return;
        case 0x7:
            SR[rt] = *RSP.SP_SEMAPHORE_REG;
            *RSP.SP_SEMAPHORE_REG = 0x00000001;
            *RSP.SP_SEMAPHORE_REG = 0x00000000; /* no cupport by CPU? */
            return; /* prevented MTC0 DPC status flags on NUS-CIC-6105 boots */
        case 0x8:
            SR[rt] = *RSP.DPC_START_REG;
            return;
        case 0x9:
            SR[rt] = *RSP.DPC_END_REG;
            return;
        case 0xA:
            SR[rt] = *RSP.DPC_CURRENT_REG;
            return;
        case 0xB:
            if (*RSP.DPC_STATUS_REG & 0x00000600) /* end/start valid ? */
            { /* CP0 register locking/unlocking not added yet. */
                message("MFC0\nCMD_STATUS", 2);
                *RSP.DPC_STATUS_REG &= ~0x00000600;
            }
            SR[rt] = *RSP.DPC_STATUS_REG;
            return;
        case 0xC:
            SR[rt] = *RSP.DPC_CLOCK_REG;
            return;
        case 0xD:
            SR[rt] = *RSP.DPC_BUFBUSY_REG;
            return;
        case 0xE:
            SR[rt] = *RSP.DPC_PIPEBUSY_REG;
            return;
        case 0xF:
            SR[rt] = *RSP.DPC_TMEM_REG;
            return;
    }
}

void scan_ICACHE_for_cycle_fault(int cr)
{
    char disasm[80]; /* Unused if priority < MIN; also sprintf is unused. */
    int TR[32]; /* limited simulation of the RSP's MIPS GPRs */
    register int i, i_tmp;
/* We are not going to simulate the scalar control registers (CP0) or any of
 * the vector register file internals under CP2.  Stuff under COP2 and MTC0
 * has proven to have no applied effect on recovering CPU timing faults.
 * Anything to do with SP DMA or vector loads/stores (?WC2) has no direct
 * effect on the scalar registers used for conditional timing branches.
 */

    for (i = 0; i < 32; i++)
        TR[i] = SR[i];
/* To scan accurately, we must execute part of the RSP in a new thread!
 * For example, the scan must track conditional branches and J/R, JAL/R.
 * More importantly, ROM may use register indirection (reading SP_STATUS
 * into a temporary register, operating it to a modified state whilst
 * buffering it over to a new register, hiding the intelligent formula
 * which conceals the exact SP_STATUS signal bit the host CPU is missing.
 */
    i = temp_PC /*(*RSP.SP_PC_REG - 1*0x004)*/ & 0x00000FFC;
/* The `MAX_WAIT`-th `MFC0 rt, SP_STATUS` encountered was PC + 0.
 * We want to check PC - 4 (just before the "infinith" or w/e read from
 * SP_STATUS) to see if the MFC0 was in the delay slot of a branch operation.
 *
 * ... No fucking thanks to Gauntlet Legends.
 */
    i_tmp = -1; /* If this becomes a valid PC it updates `i` with real PC. */

/* Now we begin the sub-RSP CPU loop in this new temporary thread.
 * We should NOT encounter a break op, or any MTC0 operation setting a break.
 * We should encounter an ANDI instruction telling us which SP status signal
 * bit the CPU host (e.g. Project64) failed to set for RCP-CPU sync, so that
 * we can mask this bit in and break out of the permanent loop fault.
 *
 * There is a narrow chance, that a game could use ORI, AND, or OR to isolate
 * a single bit (e.g. octet var |= 0b11101111), indirectly, or even use
 * arithmetic operations like addition and subtraction followed by a SLTI/U
 * to indirectly measure whether the CPU confirmed cycle-accuracy, but we are
 * not going to emulate that possibility for now, just display an error.
 *
 * I have implemented basic simulation of register indirection (do a MFC0 to
 * load SP_STATUS into register a, mov reg. a to the real reg. b to be
 * scanned by the next ANDI encountered using it), but no games trying this?
 */
    do
    {
        int BC; /* branch condition */
        const unsigned int inst = *(unsigned int *)(RSP.IMEM + i);
        const int po   = (inst & 0xFFFFFFFF) >> 26; /* primary op-code */
        short int imm  = (inst & 0x0000FFFF);
        const int MWrs = (inst & 0x03E00000) >> 21;
        const int MWrt = (inst & 0x001F0000) >> 16;
        const int MWrd = (inst & 0x0000FFFF) >> 11; // mov ecx, ax; shr ecx, 11
        const int MWsa = (inst & 0x000007C0) >>  7;

        sprintf(disasm, "PC:  0x%03X\ninst:  0x%08X", i & 0xFFC, inst);
        message(disasm, 0);
        i += 0x004;
        i &= 0x00000FFC;
        if (i_tmp != -1)
        {
            i = i_tmp & 0x00000FFC;
            i_tmp = -1;
        }
        TR[0] ^= TR[0]; /* Just to avoid constantly checking MIPS GPR `zero`. */
        switch (po)
        {
            case 000: /* SPECIAL */
                if (cr == MWrt || cr == MWrs)
                {
                    message("SPECIAL\nTransposed rt?", 2);
                    cr = MWrd;
                }
                switch (inst & 0x0000003F)
                {
                    case 000: /* SLL */
                        TR[MWrd] = TR[MWrt] << MWsa;
                        continue;
                    case 002: /* SRL */
                        TR[MWrd] = (unsigned int)(TR[MWrt]) >> MWsa;
                        continue;
                    case 003: /* SRA */
                        TR[MWrd] = TR[MWrt] >> MWsa;
                        continue;
                    case 004: /* SLLV */
                        TR[MWrd] = TR[MWrt] << (TR[MWrs] & 31);
                        continue;
                    case 006: /* SRLV */
                        TR[MWrd] = (unsigned int)(TR[MWrt]) >> (TR[MWrs] & 31);
                        continue;
                    case 007: /* SRAV */
                        TR[MWrd] = TR[MWrt] >> (TR[MWrs] & 31);
                        continue;
                    case 010: /* JR */
                        i_tmp = TR[MWrs] & 0x00000FFC;
                        continue;
                    case 011: /* JALR */
                        i_tmp = TR[MWrs] & 0x00000FFC;
                        TR[MWrd] = (i + 0x008) & 0xFFC;
                        continue;
                    case 015: /* BREAK */
                        message("?...Uhh", 3);
                        return;
                    case 040: /* ADD */
                    case 041: /* ADDU */
                        TR[MWrd] = TR[MWrs] + TR[MWrt];
                        continue;
                    case 042: /* SUB */
                    case 043: /* SUBU */
                        TR[MWrd] = TR[MWrs] - TR[MWrt];
                        continue;
                    case 044: /* AND */
                        message("Search\nAND", 2); /* not implemented */
                        TR[MWrd] = TR[MWrs] & TR[MWrt];
                        continue;
                    case 045: /* OR */
                        TR[MWrd] = TR[MWrs] | TR[MWrt];
                        continue;
                    case 046: /* XOR */
                        TR[MWrd] = TR[MWrs] ^ TR[MWrt];
                        continue;
                    case 047: /* NOR */
                        TR[MWrd] = ~(TR[MWrs] | TR[MWrt]);
                        continue;
                    case 052: /* SLT */
                        TR[MWrd] = TR[MWrs] < TR[MWrt];
                        continue;
                    case 053: /* SLTU */
                        TR[MWrd] = (unsigned)(TR[MWrs]) < (unsigned)(TR[MWrt]);
                        continue;
                    default:
                        message("RESERVED\nSPECIAL", 3);
                        continue;
                }
            case 001: /* REGIMM */
                switch (MWrt)
                {
                    default:
                        message("RESERVED\nREGIMM", 3);
                        continue;
                    case 020: /* BLTZAL */
                    case 021: /* BGEZAL */
                        TR[31] = (i + 0x008) & 0x00000FFC;
                    case 000: /* BLTZ */
                    case 001: /* BGEZ */
                        BC = (MWrt & 1) ? (TR[MWrs] >= 0) : (TR[MWrs] < 0);
                        if (!BC) continue;
                }
                i_tmp = (unsigned short)(inst) << 2;
                i_tmp = (i_tmp + i + 4) & 0x00000FFC;
                message("Did I fuck these up?", 2); /* Fucking branches. */
                continue;
            case 003: /* JAL */
                TR[31] = (i + 8) & 0x00000FFC;
            case 002: /* J */
                i_tmp = (inst & 0x000003FF) << 2;
                continue;
            case 004: /* BEQ */
            case 005: /* BNE */
                BC = (po & 1) ? (TR[MWrs] != TR[MWrt]) : (TR[MWrs] == TR[MWrt]);
                if (!BC) continue;
                i_tmp = i + (imm << 2);
                continue;
            case 006: /* BLEZ */
            case 007: /* BGTZ */
                BC = (po & 1) ? (TR[MWrs] > 0) : (TR[MWrs] <= 0);
                if (!BC) continue;
                i_tmp = i + (imm << 2);
                continue;
            case 010: /* ADDI */
            case 011: /* ADDIU */
                if (cr == MWrs)
                {
                    message("ADDI\nTransposed rt?", 2);
                    cr = MWrt;
                }
                TR[MWrt] = TR[MWrs] + imm;
                continue;
            case 012: /* SLTI */
                TR[MWrt] = (TR[MWrs] < (signed short)imm);
                continue;
            case 013: /* SLTIU */
                TR[MWrt] = ((unsigned int)TR[MWrs] < (unsigned long)(short)imm);
                continue;
            case 014: /* ANDI:  Real way to check SP signal bits. */
                if (MWrs != cr)
                    message("Possible indirection?", 2);
                switch ((unsigned char)(imm >> 7))
                {
                    case 0x00:
                        message("No signals?", 3);
                        return;
                    case 0x01:
                        message("SIG0", 1);
                        *RSP.SP_STATUS_REG ^= 0x00000080;
                        return;
                    case 0x02:
                        message("SIG1", 1);
                        *RSP.SP_STATUS_REG ^= 0x00000100;
                        return;
                    case 0x04:
                        message("SIG2", 1);
                        *RSP.SP_STATUS_REG ^= 0x00000200;
                        return;
                    case 0x08:
                        message("SIG3", 1);
                        *RSP.SP_STATUS_REG ^= 0x00000400;
                        return;
                    case 0x10:
                        message("SIG4", 1);
                        *RSP.SP_STATUS_REG ^= 0x00000800;
                        return;
                    case 0x20:
                        message("SIG5", 1);
                        *RSP.SP_STATUS_REG ^= 0x00001000;
                        return;
                    case 0x40:
                        message("SIG6", 1);
                        *RSP.SP_STATUS_REG ^= 0x00002000;
                        return;
                    case 0x80:
                        message("SIG7", 1);
                        *RSP.SP_STATUS_REG ^= 0x00004000;
                        return;
                    default: /* Which signal is CPU missing?? */
                        message("Signal hybrid!", 2);
                        *RSP.SP_STATUS_REG ^= 0x00007F80;
                        return; /* This might not work.... */
                }
            case 015: /* ORI:  A very slim possibility for "extracting" bits. */
                if (cr == MWrs)
                {
                    message("ORI\nTransposed rt?", 2);
                    cr = MWrt;
                }
                TR[MWrt] = TR[MWrs] | imm;
                message("ORI\nScan unsupported.", 2);
                continue; /* This is the other method for isolating sig bits. */
            case 016: /* XORI */
                if (cr == MWrs)
                {
                    message("XORI\nTransposed rt?", 2);
                    cr = MWrt;
                }
                TR[MWrt] = TR[MWrs] & imm;
                continue; /* XOR cannot be used to isolate individual bits... */
            case 017: /* LUI */
                TR[MWrt] = imm << 16;
                continue; /* Meh ... LUI is just a potential indirection. */
            case 020: /* COP0 */
            {
                if (MWrs != 0)
                   message("No scan for MTC0.", 3);
                /* TR[MWrt] = CR[MWrd]; // eh... need to set up a ptr table */
                if (MWrd != 4) /* not reading from SP_STATUS */
                    if (MWrt == cr)
                        message("wut", 2); /* overwrite?? */
                    else
                        continue; /* Nobody cares. */
                if (MWrt != cr) /* Possible indirection! */
                { /* >.< *facepalm* two MERGED cycle-acc. fails?? */
                    message("Voided a co-mfc0.", 2);
                    continue; /* Dunno how to implement this. */
                } /* else, correct block start to real mfc0 start */
                i = *RSP.SP_PC_REG & 0x00000FFF;
                continue;
            }
            case 022: /* COP2 */
                message("No scan for COP2.", 2);
/* We most likely can ignore COP2 in the search because it primarily
 * interfaces with the vector unit (VU) register file and vector controls.
 * VSAW is probably the only VU opcode that can affect the main MIPS GPRs.
 */
                continue;
            case 040: /* LB */
                BC  = TR[MWrs] + (signed short)(imm);
                BC &= 0x00000FFF;
                TR[MWrt] = *(char *)(RSP.DMEM + BC);
            case 041: /* LH */
                message("LH", 2); /* unsupported */
            case 043: /* LW */
                BC  = TR[MWrs] + (signed short)(imm);
                BC &= 0x00000FFF;
                TR[MWrt] = *(int *)(RSP.DMEM + BC); /* fast hack for WDC/SR64 */
                continue;
            case 044: /* LBU */
            case 045: /* LHU */
                message("meh...no big deal", 2); /* never seen a game use */
            case 050: /* SB */
            case 051: /* SH */
            case 053: /* SW */
                message("Stores?\nNah.", 2);
                continue; /* These can almost NEVER pose an indirection. */
            case 062: /* LWC2 */
            case 072: /* SWC2 */
                message("Kiss my ass!", 2);
                continue; /* Same reasons we get to omit COP2. */
            default:
                message("RESERVED", 3);
                continue;
        }
    } while (i == i);
}
