#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rsp_#1.1.h"
#include "rsp.h"

#ifdef FP_CORRECTIONS
#include <float.h>
#endif

#ifdef SP_EXECUTE_LOG
FILE *output_log;
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

#include "execute.h"

__declspec(dllexport) void CloseDLL(void)
{
    return;
}

#ifdef EXTERN_SIMULATE_ALL
#define L_TITLE "Basic RSP Simulator"
#elif defined EXTERN_COMMAND_LIST_GBI || defined EXTERN_COMMAND_LIST_ABI
#define L_TITLE "Iconoclast's MLE Test"
#else
#define L_TITLE "RSP Interpreter"
#endif
#define L_ABOUT "Thanks for test RDP:  Jabo, ziggy, Gonetz\n"\
                "SP thread examples:  bpoint, zilmar, angrylion"

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
#ifdef EXTERN_SIMULATE_ALL
        default:
            message("DoRspCycles", 3);
            return (cycles);
#endif
    }
#ifndef EXTERN_SIMULATE_ALL
    cycles = 0x00100000;
    return rsp_execute(cycles);
#endif
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
    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x00000000; // 0x4001000;
    delay_clock = -1;
    rsp.step_count = 0x00000000;
/* memset((z64_rspinfo.DMEM), 0, 0x2000); // очищаем dmem и imem */
/* This breaks compatibility on Project64 >= 1.7.x .. accurate?
 */
    *CycleCount = 0; // число циклов,перед тем,как вернуть к-ль эмулятору.
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
    delay_clock = -1;
    rsp.step_count = 0x00000000;
    return;
}
