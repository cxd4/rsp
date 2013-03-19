#ifndef _RSP_H_
#define _RSP_H_

#include "Rsp_#1.1.h"

typedef union
{
    short s[8];
    unsigned char b[16];
} VECTOR_REG;

VECTOR_REG VR[32];
static int SR[32];
static int temp_PC;

#ifdef SEARCH_INFINITE_LOOPS
static int MFC0_count[32];
/* There are only 32 possible MIPS MFC0 instruction words reading from
 * SP_STATUS that a normal assembler would generate, because rt and rd are
 * the only variable operands to a MFC0 operation, and rd == SP_STATUS.
 * Due to the possibility of conflicting SP_STATUS reads within the same loop
 * caused by faulty cycle timing by the host CPU, it is wiser to keep count
 * over how many times an exact MFC0 was encountered, not the opcode itself.
 */
#endif

RSP_INFO RSP;

extern void run_microcode(void);

#ifdef SP_EXECUTE_LOG
static FILE *output_log;
#endif

#ifdef SP_EXECUTE_LOG
void step_SP_commands(unsigned long inst)
{
    if (output_log)
    {
        const char digits[16] = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
        };
        char text[256];
        char offset[4] = "";
        char code[9] = "";
        unsigned char endian_swap[4];

        endian_swap[00] = (unsigned char)(inst >> 24);
        endian_swap[01] = (unsigned char)(inst >> 16);
        endian_swap[02] = (unsigned char)(inst >>  8);
        endian_swap[03] = (unsigned char)inst;
        offset[00] = digits[(*RSP.SP_PC_REG & 0xF00) >> 8];
        offset[01] = digits[(*RSP.SP_PC_REG & 0x0F0) >> 4];
        offset[02] = digits[(*RSP.SP_PC_REG & 0x00F) >> 0];
        code[00] = digits[(inst & 0xF0000000) >> 28];
        code[01] = digits[(inst & 0x0F000000) >> 24];
        code[02] = digits[(inst & 0x00F00000) >> 20];
        code[03] = digits[(inst & 0x000F0000) >> 16];
        code[04] = digits[(inst & 0x0000F000) >> 12];
        code[05] = digits[(inst & 0x00000F00) >>  8];
        code[06] = digits[(inst & 0x000000F0) >>  4];
        code[07] = digits[(inst & 0x0000000F) >>  0];
        strcpy(text, offset);
        strcat(text, "\n");
        strcat(text, code);
        message(text, 0); /* PC offset, MIPS hex. */
        if (output_log == NULL) {} else /* Global pointer not updated?? */
            fwrite(endian_swap, 4, 1, output_log);
    }
}

void export_SP_memory(void)
{ /* cache memory and dynamic RAM shared by CPU */
    FILE *out = fopen("SP_CACHE.BIN", "wb");
    fwrite(RSP.DMEM, sizeof(unsigned char), 0x1FFF + 1, out);
    fclose(out);
    out = fopen("SP_DRAM.BIN", "wb");
    fwrite(RSP.RDRAM, sizeof(unsigned char), 0x3FFFFF + 1, out);
    return;
}

void trace_RSP_registers(void)
{ /* no interface--using file I/O only */
    FILE *out = fopen("SP_STATE.TXT", "w");

    fprintf(out, "RCP Communications Register Display\n\n");
    fclose(out);
    out = fopen("SP_STATE.TXT", "a");
/* The precise names for RSP CP0 registers are somewhat difficult to define.
 * Generally, I have tried to adhere to the names shared from bpoint/zilmar,
 * while also merging the concrete purpose and correct assembler references.
 * Whether or not you find these names agreeable is mostly a matter of seeing
 * them from the RCP's point of view or the CPU host's mapped point of view.
 */
    fprintf(out, "SP_MEM_ADDR:    %08X    CMD_START:      %08X\n",
        *RSP.SP_MEM_ADDR_REG, *RSP.DPC_START_REG);
    fprintf(out, "SP_DRAM_ADDR:   %08X    CMD_END:        %08X\n",
        *RSP.SP_DRAM_ADDR_REG, *RSP.DPC_END_REG);
    fprintf(out, "SP_DMA_RD_LEN:  %08X    CMD_CURRENT:    %08X\n",
        *RSP.SP_RD_LEN_REG, *RSP.DPC_CURRENT_REG);
    fprintf(out, "SP_DMA_WR_LEN:  %08X    CMD_STATUS:     %08X\n",
        *RSP.SP_WR_LEN_REG, *RSP.DPC_STATUS_REG);
    fprintf(out, "SP_STATUS:      %08X    CMD_CLOCK:      %08X\n",
        *RSP.SP_STATUS_REG, *RSP.DPC_CLOCK_REG);
    fprintf(out, "SP_DMA_FULL:    %08X    CMD_BUSY:       %08X\n",
        *RSP.SP_DMA_FULL_REG, *RSP.DPC_BUFBUSY_REG);
    fprintf(out, "SP_DMA_BUSY:    %08X    CMD_PIPE_BUSY:  %08X\n",
        *RSP.SP_DMA_BUSY_REG, *RSP.DPC_PIPEBUSY_REG);
    fprintf(out, "SP_SEMAPHORE:   %08X    CMD_TMEM_BUSY:  %08X\n",
        *RSP.SP_SEMAPHORE_REG, *RSP.DPC_TMEM_REG);
    fprintf(out, "SP_PC_REG:      04001%03X\n\n", *RSP.SP_PC_REG & 0x00000FFF);
/* (PC is only from the CPU point of view, mapped between both halves.) */
/* There is no memory map for remaining registers not shared by the CPU.
 * The scalar register (SR) file is straightforward and based on the
 * GPR file in the MIPS ISA.  However, the RSP assembly language is still
 * different enough from the MIPS assembly language, in that tokens such as
 * "$zero" and "$s0" are no longer valid.  "$k0", for example, is not a valid
 * RSP register name because on MIPS it was kernel-use, but on the RSP free.
 * To be colorful/readable, however, I have set the modern MIPS names anyway.
 */
    fprintf(out, "zero  %08X,  s0:  %08X,\n", SR[ 0], SR[16]);
    fprintf(out, "$at:  %08X,  s1:  %08X,\n", SR[ 1], SR[17]);
    fprintf(out, " v0:  %08X,  s2:  %08X,\n", SR[ 2], SR[18]);
    fprintf(out, " v1:  %08X,  s3:  %08X,\n", SR[ 3], SR[19]);
    fprintf(out, " a0:  %08X,  s4:  %08X,\n", SR[ 4], SR[20]);
    fprintf(out, " a1:  %08X,  s5:  %08X,\n", SR[ 5], SR[21]);
    fprintf(out, " a2:  %08X,  s6:  %08X,\n", SR[ 6], SR[22]);
    fprintf(out, " a3:  %08X,  s7:  %08X,\n", SR[ 7], SR[23]);
    fprintf(out, " t0:  %08X,  t8:  %08X,\n", SR[ 8], SR[24]);
    fprintf(out, " t1:  %08X,  t9:  %08X,\n", SR[ 9], SR[25]);
    fprintf(out, " t2:  %08X,  k0:  %08X,\n", SR[10], SR[26]);
    fprintf(out, " t3:  %08X,  k1:  %08X,\n", SR[11], SR[27]);
    fprintf(out, " t4:  %08X,  gp:  %08X,\n", SR[12], SR[28]);
    fprintf(out, " t5:  %08X, $sp:  %08X,\n", SR[13], SR[29]);
    fprintf(out, " t6:  %08X, $fp:  %08X,\n", SR[14], SR[30]);
    fprintf(out, " t7:  %08X, $ra:  %08X\n\n", SR[15], SR[31]);
/* (Yes, I rebelliously used the MIPS32 "$fp" modern alias over lazy "$s8".) */
/* The RSP vector registers are incontestedly named $v[n] and nothing else.
 * The problem is organizing the contents by HW/B elements and proper endian.
 */
    fprintf(out, " $v0:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 0].s[07], VR[ 0].s[06], VR[ 0].s[05], VR[ 0].s[04],
        VR[ 0].s[03], VR[ 0].s[02], VR[ 0].s[01], VR[ 0].s[00]);
    fprintf(out, " $v1:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 1].s[07], VR[ 1].s[06], VR[ 1].s[05], VR[ 1].s[04],
        VR[ 1].s[03], VR[ 1].s[02], VR[ 1].s[01], VR[ 1].s[00]);
    fprintf(out, " $v2:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 2].s[07], VR[ 2].s[06], VR[ 2].s[05], VR[ 2].s[04],
        VR[ 2].s[03], VR[ 2].s[02], VR[ 2].s[01], VR[ 2].s[00]);
    fprintf(out, " $v3:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 3].s[07], VR[ 3].s[06], VR[ 3].s[05], VR[ 3].s[04],
        VR[ 3].s[03], VR[ 3].s[02], VR[ 3].s[01], VR[ 3].s[00]);
    fprintf(out, " $v4:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 4].s[07], VR[ 4].s[06], VR[ 4].s[05], VR[ 4].s[04],
        VR[ 4].s[03], VR[ 4].s[02], VR[ 4].s[01], VR[ 4].s[00]);
    fprintf(out, " $v5:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 5].s[07], VR[ 5].s[06], VR[ 5].s[05], VR[ 5].s[04],
        VR[ 5].s[03], VR[ 5].s[02], VR[ 5].s[01], VR[ 5].s[00]);
    fprintf(out, " $v6:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 6].s[07], VR[ 6].s[06], VR[ 6].s[05], VR[ 6].s[04],
        VR[ 6].s[03], VR[ 6].s[02], VR[ 6].s[01], VR[ 6].s[00]);
    fprintf(out, " $v7:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 7].s[07], VR[ 7].s[06], VR[ 7].s[05], VR[ 7].s[04],
        VR[ 7].s[03], VR[ 7].s[02], VR[ 7].s[01], VR[ 7].s[00]);
    fprintf(out, " $v8:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 8].s[07], VR[ 8].s[06], VR[ 8].s[05], VR[ 8].s[04],
        VR[ 8].s[03], VR[ 8].s[02], VR[ 8].s[01], VR[ 8].s[00]);
    fprintf(out, " $v9:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[ 9].s[07], VR[ 9].s[06], VR[ 9].s[05], VR[ 9].s[04],
        VR[ 9].s[03], VR[ 9].s[02], VR[ 9].s[01], VR[ 9].s[00]);
    fprintf(out, "$v10:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[10].s[07], VR[10].s[06], VR[10].s[05], VR[10].s[04],
        VR[10].s[03], VR[10].s[02], VR[10].s[01], VR[10].s[00]);
    fprintf(out, "$v11:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[11].s[07], VR[11].s[06], VR[11].s[05], VR[11].s[04],
        VR[11].s[03], VR[11].s[02], VR[11].s[01], VR[11].s[00]);
    fprintf(out, "$v12:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[12].s[07], VR[12].s[06], VR[12].s[05], VR[12].s[04],
        VR[12].s[03], VR[12].s[02], VR[12].s[01], VR[12].s[00]);
    fprintf(out, "$v13:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[13].s[07], VR[13].s[06], VR[13].s[05], VR[13].s[04],
        VR[13].s[03], VR[13].s[02], VR[13].s[01], VR[13].s[00]);
    fprintf(out, "$v14:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[14].s[07], VR[14].s[06], VR[14].s[05], VR[14].s[04],
        VR[14].s[03], VR[14].s[02], VR[14].s[01], VR[14].s[00]);
    fprintf(out, "$v15:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[15].s[07], VR[15].s[06], VR[15].s[05], VR[15].s[04],
        VR[15].s[03], VR[15].s[02], VR[15].s[01], VR[15].s[00]);
    fprintf(out, "$v16:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[16].s[07], VR[16].s[06], VR[16].s[05], VR[16].s[04],
        VR[16].s[03], VR[16].s[02], VR[16].s[01], VR[16].s[00]);
    fprintf(out, "$v17:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[17].s[07], VR[17].s[06], VR[17].s[05], VR[17].s[04],
        VR[17].s[03], VR[17].s[02], VR[17].s[01], VR[17].s[00]);
    fprintf(out, "$v18:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[18].s[07], VR[18].s[06], VR[18].s[05], VR[18].s[04],
        VR[18].s[03], VR[18].s[02], VR[18].s[01], VR[18].s[00]);
    fprintf(out, "$v19:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[19].s[07], VR[19].s[06], VR[19].s[05], VR[19].s[04],
        VR[19].s[03], VR[19].s[02], VR[19].s[01], VR[19].s[00]);
    fprintf(out, "$v20:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[20].s[07], VR[20].s[06], VR[20].s[05], VR[20].s[04],
        VR[20].s[03], VR[20].s[02], VR[20].s[01], VR[20].s[00]);
    fprintf(out, "$v21:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[21].s[07], VR[21].s[06], VR[21].s[05], VR[21].s[04],
        VR[21].s[03], VR[21].s[02], VR[21].s[01], VR[21].s[00]);
    fprintf(out, "$v22:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[22].s[07], VR[22].s[06], VR[22].s[05], VR[22].s[04],
        VR[22].s[03], VR[22].s[02], VR[22].s[01], VR[22].s[00]);
    fprintf(out, "$v23:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[23].s[07], VR[23].s[06], VR[23].s[05], VR[23].s[04],
        VR[23].s[03], VR[23].s[02], VR[23].s[01], VR[23].s[00]);
    fprintf(out, "$v24:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[24].s[07], VR[24].s[06], VR[24].s[05], VR[24].s[04],
        VR[24].s[03], VR[24].s[02], VR[24].s[01], VR[24].s[00]);
    fprintf(out, "$v25:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[25].s[07], VR[25].s[06], VR[25].s[05], VR[25].s[04],
        VR[25].s[03], VR[25].s[02], VR[25].s[01], VR[25].s[00]);
    fprintf(out, "$v26:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[26].s[07], VR[26].s[06], VR[26].s[05], VR[26].s[04],
        VR[26].s[03], VR[26].s[02], VR[26].s[01], VR[26].s[00]);
    fprintf(out, "$v27:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[27].s[07], VR[27].s[06], VR[27].s[05], VR[27].s[04],
        VR[27].s[03], VR[27].s[02], VR[27].s[01], VR[27].s[00]);
    fprintf(out, "$v28:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[28].s[07], VR[28].s[06], VR[28].s[05], VR[28].s[04],
        VR[28].s[03], VR[28].s[02], VR[28].s[01], VR[28].s[00]);
    fprintf(out, "$v29:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[29].s[07], VR[29].s[06], VR[29].s[05], VR[29].s[04],
        VR[29].s[03], VR[29].s[02], VR[29].s[01], VR[29].s[00]);
    fprintf(out, "$v30:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n",
        VR[30].s[07], VR[30].s[06], VR[30].s[05], VR[30].s[04],
        VR[30].s[03], VR[30].s[02], VR[30].s[01], VR[30].s[00]);
    fprintf(out, "$v31:  [%04X][%04X][%04X][%04X][%04X][%04X][%04X][%04X]\n\n"
      , VR[31].s[07], VR[31].s[06], VR[31].s[05], VR[31].s[04],
        VR[31].s[03], VR[31].s[02], VR[31].s[01], VR[31].s[00]);
/* The SU has its fair share of registers, but the VU has its counterparts.
 * Just like we have the scalar 16 system control registers for the RSP CP0,
 * we have also a tiny group of special-purpose, vector control registers.
 */
    fprintf(out, "$vco:  [%02X][%02X]\n", (VCO >> 8), VCO & 0x00FF);
    fprintf(out, "$vcc:  [%02X][%02X]\n", (VCC >> 8), VCC & 0x00FF);
    fprintf(out, "$vce:  %02X\n\n", VCE); /* 8-bit vector cnd. flags register */
/* Last and least are the 48-bit accumulator elements, which literally may or
 * may not be considered as "registers" but are still useful to debug, in
 * spite of how near-pointless emulating them is (mostly VSAR/VSAW, VMAC*).
 *
 * I have not confirmed memory endianness controversies for ordering bytes.
 * I decided, better to print 48 bits, not 3 pairs of 16, cause basically
 * every write to the accumulator updates potentially all 48 bits, not 1 HW.
 * ("%012X" seems a better idea than [%04X][%04X][%04X], similar to above.)
 * Without VSAR/VSAW, all single HW R/W's are the low 16 bits of acc. only.
 */
    fprintf(out, "VACC[0]:  %012X\n", VACC[00].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[1]:  %012X\n", VACC[01].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[2]:  %012X\n", VACC[02].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[3]:  %012X\n", VACC[03].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[4]:  %012X\n", VACC[04].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[5]:  %012X\n", VACC[05].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[6]:  %012X\n", VACC[06].DW & 0xFFFFFFFFFFFF);
    fprintf(out, "VACC[7]:  %012X\n\n", VACC[07].DW & 0xFFFFFFFFFFFF);
/* I lied (sort of).  Can't possibly forget the internal registers used by
 * the computational vector divide operations!  (Hmmm okay now I lied.)
 */
    fprintf(out, "DivIn:  %i\n", DivIn);
    fprintf(out, "DivOut:  %i\n", DivOut);
    /* MovIn:  This reg. might exist for VMOV, but it is obsolete to emulate. */
    fprintf(out, DPH ? "DPH:  true\n" : "DPH:  false\n");
    fclose(out);
    return;
}
#endif

#endif // ifndef _RSP_H_
