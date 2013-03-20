#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rsp_#1.1.h"
#include "rsp.h"

#ifdef FP_CORRECTIONS
#include <float.h>
#endif

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
    trace_RSP_registers();
    export_SP_memory();
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
__declspec(dllexport) unsigned long _cdecl DoRspCycles(unsigned long cycles)
{
    if (*RSP.SP_STATUS_REG & 0x00000003)
    {
        message("SP_STATUS_HALT", 3);
        return 0x00000000;
    }
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
    run_microcode();
#ifdef SEARCH_INFINITE_LOOPS
    for (cycles = 0; cycles < 32; cycles++)
        MFC0_count[cycles] ^= MFC0_count[cycles];
#endif
    if (!(*RSP.SP_STATUS_REG & 0x00000002)) /* BROKE was not set. */
        message("Halted RSP CPU loop by means of MTC0.", 2);
    return (cycles);
}
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
    while (RSP.IMEM != RSP.DMEM + 4096)
        message("This EXE sucks.\nPick another one.", 3);
/* The real N64 RCP memory map has DMEM and IMEM mapped side-by-side.
 * While an emulator's failure to comply to this layout could be tolerated,
 * assuming an emulator's idiocy slows down (one example) DMA transactions.
 */
    memset(RSP.DMEM, 0x00, 0x2000); /* Warning:  Breaks PJ64 1.7. */
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
    return;
}

#ifdef SEARCH_INFINITE_LOOPS
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
#endif
