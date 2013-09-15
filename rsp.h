#ifndef _RSP_H_
#define _RSP_H_

#include "Rsp_#1.1.h"
RSP_INFO RSP;

#ifdef _MSC_VER
#define INLINE      __inline
#define NOINLINE    __noinline
#else
#define INLINE      inline
#define NOINLINE    __attribute__((noinline))
#endif

#ifdef WINUSERAPI
__declspec(dllimport) int __stdcall MessageBoxA(
    HWND hWnd,
    const char *lpText,
    const char *lpCaption,
    unsigned int uType);
/* No need to import the Windows API, just a message trace function. */
const unsigned int type_index[4] = {
    0x00000000, /* no icon or effect `MB_OK`, for O.K. encounters */
    0x00000020, /* MB_ICONQUESTION -- curious situation in emulator */
    0x00000030, /* MB_ICONEXCLAMATION -- might be missing RSP support */
    0x00000010  /* MB_ICONHAND -- definite error or problem in emulator */
};
__attribute__((noinline)) void message(const char* body, int priority)
{
    priority &= 03;
    if (priority < MINIMUM_MESSAGE_PRIORITY)
        return;
    MessageBoxA(NULL, body, NULL, type_index[priority]);
    return;
}
#else
NOINLINE void message(const char* body, int priority)
{ /* Avoid SHELL32/ADVAPI32/USER32 dependencies by using standard C to print. */
    char argv[4096] = "CMD /D /S /Q /T:0E /K \"ECHO ";
    int i = 0;
    int j = strlen(argv);

    priority &= 03;
    if (priority < MINIMUM_MESSAGE_PRIORITY)
        return;
    while (body[i] != '\0')
    {
        if (body[i] == '\n')
        {
            argv[j++] = '&';
            argv[j++] = '&';
            argv[j++] = 'E';
            argv[j++] = 'C';
            argv[j++] = 'H';
            argv[j++] = 'O';
            argv[j++] = ' ';
            ++i;
            continue;
        }
        argv[j++] = body[i++];
    }
    strcat(argv, "\"");
    system(argv);
}
#endif

void update_conf(void)
{
    FILE* stream;
    unsigned char checksum;
    register int i, test;

    stream = fopen(CFG_FILE, "rb");
    if (stream == NULL)
    { /* try GetModulePath or whatever to correct the path? */
        message("Failed to read config.", 3);
        return;
    }
    for (i = 0; i < 32; i++)
    {
        test = fgetc(stream);
        conf[i] = (unsigned char)(test);
    }
    /* my own little checksum code, not really useful :P */
    checksum = 0x00000000;
    for (i = 0; i < 31; i++)
        checksum = checksum
                 + !!(conf[i] & 0x80)
                 + !!(conf[i] & 0x40)
                 + !!(conf[i] & 0x20)
                 + !!(conf[i] & 0x10)
                 + !!(conf[i] & 0x08)
                 + !!(conf[i] & 0x04)
                 + !!(conf[i] & 0x02)
                 + !!(conf[i] & 0x01);
    if (checksum != CFG_CHECKSUM)
    {
        message("Checksum mismatch.", 3);
        memset(conf, 0x00, 32);
        return;
    }
    return;
}

static int stage;
#ifdef WAIT_FOR_CPU_HOST
static int MFC0_count[32];
/* Keep one C0 MF status read count for each scalar register. */
#endif

#include "su/su.h"
#include "vu/vu.h"

extern void step_SP_commands(unsigned long inst);
extern void export_SP_memory(void);
extern void trace_RSP_registers(void);
static FILE *output_log;

/* Allocate the RSP CPU loop to its own functional space. */
extern void run_task(void);
#include "execute.h"

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
    register int i;
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
    fprintf(out, "SP_MEM_ADDR:    %08lX    CMD_START:      %08lX\n",
        *RSP.SP_MEM_ADDR_REG, *RSP.DPC_START_REG);
    fprintf(out, "SP_DRAM_ADDR:   %08lX    CMD_END:        %08lX\n",
        *RSP.SP_DRAM_ADDR_REG, *RSP.DPC_END_REG);
    fprintf(out, "SP_DMA_RD_LEN:  %08lX    CMD_CURRENT:    %08lX\n",
        *RSP.SP_RD_LEN_REG, *RSP.DPC_CURRENT_REG);
    fprintf(out, "SP_DMA_WR_LEN:  %08lX    CMD_STATUS:     %08lX\n",
        *RSP.SP_WR_LEN_REG, *RSP.DPC_STATUS_REG);
    fprintf(out, "SP_STATUS:      %08lX    CMD_CLOCK:      %08lX\n",
        *RSP.SP_STATUS_REG, *RSP.DPC_CLOCK_REG);
    fprintf(out, "SP_DMA_FULL:    %08lX    CMD_BUSY:       %08lX\n",
        *RSP.SP_DMA_FULL_REG, *RSP.DPC_BUFBUSY_REG);
    fprintf(out, "SP_DMA_BUSY:    %08lX    CMD_PIPE_BUSY:  %08lX\n",
        *RSP.SP_DMA_BUSY_REG, *RSP.DPC_PIPEBUSY_REG);
    fprintf(out, "SP_SEMAPHORE:   %08lX    CMD_TMEM_BUSY:  %08lX\n",
        *RSP.SP_SEMAPHORE_REG, *RSP.DPC_TMEM_REG);
    fprintf(out, "SP_PC_REG:      04001%03lX\n\n", *RSP.SP_PC_REG & 0x00000FFF);
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
    fprintf(out, " t6:  %08X, $s8:  %08X,\n", SR[14], SR[30]);
    fprintf(out, " t7:  %08X, $ra:  %08X\n\n", SR[15], SR[31]);

    for (i = 0; i < 10; i++)
        fprintf(
            out,
           " $v%i:  [%04hX][%04hX][%04hX][%04hX][%04hX][%04hX][%04hX][%04hX]\n",
            i,
            VR[i][00], VR[i][01], VR[i][02], VR[i][03],
            VR[i][04], VR[i][05], VR[i][06], VR[i][07]);
    for (i = 10; i < 32; i++) /* decimals "10" and higher with two characters */
        fprintf(
            out,
            "$v%i:  [%04hX][%04hX][%04hX][%04hX][%04hX][%04hX][%04hX][%04hX]\n",
            i,
            VR[i][00], VR[i][01], VR[i][02], VR[i][03],
            VR[i][04], VR[i][05], VR[i][06], VR[i][07]);
    fprintf(out, "\n");
/*
 * The SU has its fair share of registers, but the VU has its counterparts.
 * Just like we have the scalar 16 system control registers for the RSP CP0,
 * we have also a tiny group of special-purpose, vector control registers.
 */
    fprintf(out, "$vco:  0x%04X\n", get_VCO());
    fprintf(out, "$vcc:  0x%04X\n", get_VCC());
    fprintf(out, "$vce:  0x%02X\n", get_VCE());
    fprintf(out, "\n");
    for (i = 0; i < 8; i++)
        fprintf(
            out, "ACC[%o]:  [%04X][%04X][%04X]\n", i,
            ACC_H(i), ACC_M(i), ACC_L(i));
    fprintf(out, "\n");
    fprintf(out, "DivIn:  %i\n", DivIn);
    fprintf(out, "DivOut:  %i\n", DivOut);
    /* MovIn:  This reg. might exist for VMOV, but it is obsolete to emulate. */
    fprintf(out, DPH ? "DPH:  true\n" : "DPH:  false\n");
    fclose(out);
    return;
}

#endif
