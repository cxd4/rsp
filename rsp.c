#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tmmintrin.h>
#include "Rsp_#1.1.h"
#include "rsp.h"

#ifdef FP_CORRECTIONS
#include <float.h>
#endif

#ifdef SP_EXECUTE_LOG
static FILE *output_log;
#endif

__declspec(dllimport) int __stdcall MessageBoxA(
    HWND hWnd,
    const char *lpText,
    const char *lpCaption,
    unsigned int uType);
/* No need to import the Windows API, just a message trace function. */
void message(char *body, int priority)
{
    const unsigned int type_index[4] = {
        0x00000000, /* no icon or effect `MB_OK`, for O.K. encounters */
        0x00000020, /* MB_ICONQUESTION -- curious situation in emulator */
        0x00000030, /* MB_ICONEXCLAMATION -- might be missing RSP support */
        0x00000010  /* MB_ICONHAND -- definite error or problem in emulator */
    };

    priority &= 03;
    switch (MINIMUM_MESSAGE_PRIORITY)
    { /* exit table for voiding messages of lower priority */
        default:  return;
        case 03:  if (priority < MINIMUM_MESSAGE_PRIORITY) return;
        case 02:  if (priority < MINIMUM_MESSAGE_PRIORITY) return;
        case 01:  if (priority < MINIMUM_MESSAGE_PRIORITY) return;
        case 00:  break;
    }
    MessageBoxA(NULL, body, NULL, type_index[priority]);
    return;
}

extern int SearchSimpleBlockEscapes();

#include "su/su.h"
#include "vu/vu.h"

__declspec(dllexport) void CloseDLL(void)
{
    return;
}
__declspec(dllexport) void DllAbout(HWND hParent)
{
    MessageBoxA(hParent, L_ABOUT, L_TITLE, 0x00000040);
    return;
}
#ifdef SP_EXECUTE_LOG
__declspec(dllexport) void DllConfig(HWND hParent)
{
    if (output_log == NULL)
    {
        output_log = fopen("simd_log.bin", "ab");
        return;
    }
    fclose(output_log);
    output_log = NULL;
    hParent = NULL;
    return;
}
#endif
#ifdef HYBRID_INTERPRETER_STYLE
#include "execute.h"
#else
__declspec(dllexport) unsigned long _cdecl DoRspCycles(unsigned long cycles)
{
    switch (*(unsigned int *)(RSP.DMEM + 0xFC0))
    { /* Simulation barrier to redirect processing externally. */
#ifdef EXTERN_COMMAND_LIST_GBI
        case 0x00000001:
            if (RSP.ProcessDList == 0) {} else
                RSP.ProcessDList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            return 0;
#endif
#ifdef EXTERN_COMMAND_LIST_ABI
        case 0x00000002: /* OSTask.type == M_AUDTASK */
            if (RSP.ProcessAList == 0) {} else
                RSP.ProcessAList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            return 0;
#endif
    }
#if (defined EXTERN_COMMAND_LIST_GBI && defined EXTERN_COMMAND_LIST_ABI)
    {
        const char digits[16] = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
        };
        const unsigned int task = *(unsigned int *)(RSP.DMEM + 0xFC0);
        char task_hex[9] = "";

        task_hex[00] = digits[(task & 0xF0000000) >> 28];
        task_hex[01] = digits[(task & 0x0F000000) >> 24];
        task_hex[02] = digits[(task & 0x00F00000) >> 20];
        task_hex[03] = digits[(task & 0x000F0000) >> 16];
        task_hex[04] = digits[(task & 0x0000F000) >> 12];
        task_hex[05] = digits[(task & 0x00000F00) >>  8];
        task_hex[06] = digits[(task & 0x000000F0) >>  4];
        task_hex[07] = digits[(task & 0x0000000F) >>  0];
        MessageBoxA(NULL, task_hex, "OSTask.type", 0x00000000);
    }
#endif
    while ((*RSP.SP_STATUS_REG & 0x00000001) == 0x00000000) /* RSP running */
    {
        register unsigned int inst;

        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG);
        if (temp_PC >= 0) /* test temp_PC & 0x80000000 , jns temp_PC */
        {
            *RSP.SP_PC_REG = temp_PC; /* have not masked 0x04001000 to PC */
            temp_PC = 0x00000000 ^ 0xFFFFFFFF;
        }
        else
        {
            *RSP.SP_PC_REG += 0x004;
            *RSP.SP_PC_REG &= 0x00000FFC;
        }
#ifdef SP_EXECUTE_LOG
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
            sprintf(text, "%s\ncR:%i\ncS:100", text, cycles);
            message(text, 0); /* PC offset, MIPS hex, ratio cyclesRem:base. */
            if (output_log == NULL) {} else /* Global pointer not updated?? */
                fwrite(endian_swap, 4, 1, output_log);
        }
#endif
        if (inst >> 25 == 0x25) /* is a VU instruction */
        {
            const int vd = (inst >>  6) & 0x0000001F;
            const int vs = (unsigned short)inst >> 11;
            const int vt = (inst >> 16) & 0x0000001F;
            int e  = (inst >> 21) & 0x0000000F;

#ifdef VU_OVERRIDE_WEIRD_ELEMENT
            if (e == 1)
            { /* Illegal assembly instruction, but valid RSP machine code. */
                message("Weird vector element specifier.", 2;
            }
#endif
            inst &= 0x0000003F;
            SP_COP2_VECTOP[inst](vd, vs, vt, e);
            continue;
        }
        else
        {
            const int rs = (inst & 0x03E00000) >> 21;
            const int rt = (inst >> 16) & 0x0000001F; /* Try to mov upper HW. */
            const short imm = (short)inst; /* (un)signed is sub-op-defined. */

            inst >>= 26;
            SP_PRIMARY[inst](rs, rt, imm);
        }
        /* --cycles; */
        if (*RSP.SP_STATUS_REG & 0x00000020) /* SP_STATUS_SSTEP by debugger. */
        {
            message("Omitted SP debug interface.", 0); /*
            if (rsp.step_count)
                --rsp.step_count;
            else
            {
                *RSP.SP_STATUS_REG |= 0x00000002;
                message("SP_STATUS_BROKE", 3);
            } */
        }
    }
#ifdef SEARCH_INFINITE_LOOPS
    for (cycles = 0; cycles < 32; cycles++)
        MFC0_count[cycles] ^= MFC0_count[cycles];
#endif
    if (!(*RSP.SP_STATUS_REG & 0x00000002)) /* BROKE was not set. */
        message("Halted RSP CPU loop by means of MTC0.", 2);
    return (cycles);
}
#endif
__declspec(dllexport) void GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    PluginInfo -> Version = 0x0101;
    PluginInfo -> Type = PLUGIN_TYPE_RSP;
strcpy(/* Not meant to be a CRT dependency--should optimize to QWORD moves. */
    PluginInfo -> Name, "Iconoclast's LLE SP Interpreter");
    PluginInfo -> NormalMemory = 0;
    PluginInfo -> MemoryBswaped = 1;
    return;
}
__declspec(dllexport) void InitiateRSP(RSP_INFO Rsp_Info, unsigned long *CycleCount)
{
    *CycleCount = 0; // число циклов,перед тем,как вернуть к-ль эмулятору.
    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x00000000; // 0x4001000;
    temp_PC = -1;
    /* memset((RSP.DMEM), 0, 0x2000); // Warning:  Breaks PJ64 1.7. */
    while (RSP.IMEM != RSP.DMEM + 4096)
        message("This EXE sucks.\nPick another one.", 3);
/* The real N64 RCP memory map has DMEM and IMEM mapped side-by-side.
 * While an emulator's failure to comply to this layout could be tolerated,
 * assuming an emulator's idiocy slows down (one example) DMA transactions.
 */
#ifdef SP_EXECUTE_LOG
    output_log = fopen("simd_log.bin", "ab");
#endif
    return;
}
__declspec(dllexport) void InitiateRSPDebugger(DEBUG_INFO DebugInfo)
{
    DebugInfo.UpdateMemory();
    return;
}
__declspec(dllexport) void RomClosed(void)
{
    *RSP.SP_PC_REG = 0x00000000;
    temp_PC = -1;
    return;
}

int SearchSimpleBlockEscapes()
{
    unsigned short ICACHE_ptr[8]; /* up to 8 results? */
    int missed_branches = 0;
    register unsigned int inst;
    register int i = *RSP.SP_PC_REG & 0x00000FFF;

    i -= 2*0x004; /* accounting for branch delay slot for ICACHE load */
    while (i != temp_PC)
    { /* NOT `while (temp_PC < i)`, 'cause loop might overlap IMEM[0xFFF]. */
        i -= 0x004; /* For SMALL infinite loops, new PC can't be > current. */
        i &= 0x00000FFF; /* ... except, obviously, the chance of PC overflow. */
        inst = *(unsigned int *)(RSP.IMEM + i);
        switch (inst >> 26)
        {
         /* case 000: // SPECIAL has two unconditional jump sub-op-codes. */
            case 001: /* conditional branches using REGIMM */
                message("ICACHE miss\nREGIMM + 1", 3);
         /* case 002:
            case 003: // unconditional jumps (but WHY?)
                message("WTF!\nJ, JAL in block cut.", 3);
                continue; /* There can't be a bug in my loop analysis...? */
            case 004: /* conditional branches using BEQ, BNE, BLEZ, BGTZ ... */
            case 005: /* BNE */
            case 006: /* BLEZ */
            case 007: /* BGTZ */
                ICACHE_ptr[missed_branches] = (unsigned short)(inst << 2);
                ++missed_branches;
                /* message("ICACHE Miss\nBGTZ + 1", 1); */
                continue;
            default: /* primary/reserved MIPS op-codes which do not affect PC */
                continue; /* Nobody cares. */
        }
    }
    if (missed_branches == 0)
    {
        int response = MessageBoxA(NULL, "Skip?", "Infinite Wait", 0x00000034);

        return (response == 06) ? -1 : +1;
    }
    else if (missed_branches == 1)
    {
        int response;

        inst = *(unsigned int *)(RSP.IMEM + *RSP.SP_PC_REG - 2*0x004);
        response = MessageBoxA(NULL, "Flip?", "Infinite Wait", 0x00000034);
        if (response == 06)
        {
            if ((inst & 0xF8000000) != 0x08000000) /* not an uncond. jump */
                message("Split exit chain.", 3);
            temp_PC = (i + ICACHE_ptr[0]) & 0x00000FFC;
            return -1;
        }
        return +1;
    }
    else
    {
        message("Too many cache misses to sort.", 3);
        return +1; /* ^ More like, too lazy to implement. :P */
    }
}
