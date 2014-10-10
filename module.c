/******************************************************************************\
* Project:  Module Subsystem Interface to SP Interpreter Core                  *
* Authors:  Iconoclast                                                         *
* Release:  2014.10.09                                                         *
* License:  CC0 Public Domain Dedication                                       *
*                                                                              *
* To the extent possible under law, the author(s) have dedicated all copyright *
* and related and neighboring rights to this software to the public domain     *
* worldwide. This software is distributed without any warranty.                *
*                                                                              *
* You should have received a copy of the CC0 Public Domain Dedication along    *
* with this software.                                                          *
* If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.             *
\******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "module.h"
#include "su.h"

RSP_INFO RSP;

static const char DLL_about[] =
    "RSP Interpreter by Iconoclast&&ECHO."\
    "&&ECHO "\
    "Thanks for test RDP:  Jabo, ziggy, angrylion\n"\
    "RSP driver examples:  bpoint, zilmar, Ville Linde";

EXPORT void CALL CloseDLL(void)
{
    RSP.RDRAM = NULL; /* so DllTest benchmark doesn't think ROM is still open */
    return;
}
EXPORT void CALL DllAbout(struct_p hParent)
{
    hParent = NULL;
    message(DLL_about);
    return;
}
EXPORT void CALL DllConfig(struct_p hParent)
{
    hParent = NULL;
    system("sp_cfgui"); /* This launches an EXE by default (if not, BAT/CMD). */
    update_conf(CFG_FILE);
    if (RSP.DMEM == RSP.IMEM || *RSP.SP_PC_REG == 0x00000000)
        return;

    export_SP_memory();
    return;
}
EXPORT unsigned int CALL DoRspCycles(unsigned int cycles)
{
    if (*RSP.SP_STATUS_REG & 0x00000003)
    {
        message("SP_STATUS_HALT");
        return 0x00000000;
    }
    switch (*(unsigned int *)(RSP.DMEM + 0xFC0))
    { /* Simulation barrier to redirect processing externally. */
#ifdef EXTERN_COMMAND_LIST_GBI
        case 0x00000001:
            if (CFG_HLE_GFX == 0)
                break;
            if (*(unsigned int *)(RSP.DMEM + 0xFF0) == 0x00000000)
                break; /* Resident Evil 2 */
            if (RSP.ProcessDList == NULL) {/*branch next*/} else
                RSP.ProcessDList();
            *RSP.SP_STATUS_REG |= 0x00000203;
            if (*RSP.SP_STATUS_REG & 0x00000040) /* SP_STATUS_INTR_BREAK */
            {
                *RSP.MI_INTR_REG |= 0x00000001; /* VR4300 SP interrupt */
                RSP.CheckInterrupts();
            }
            if (*RSP.DPC_STATUS_REG & 0x00000002) /* DPC_STATUS_FREEZE */
            {
                message("DPC_CLR_FREEZE");
                *RSP.DPC_STATUS_REG &= ~0x00000002;
            }
            return 0;
#endif
#ifdef EXTERN_COMMAND_LIST_ABI
        case 0x00000002: /* OSTask.type == M_AUDTASK */
            if (CFG_HLE_AUD == 0)
                break;
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
    run_task();
    return (cycles);
}

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    PluginInfo -> Version = 0x0101; /* zilmar #1.1 (only standard RSP spec) */
    PluginInfo -> Type = PLUGIN_TYPE_RSP;
strcpy(
    PluginInfo -> Name, "Static Interpreter");
    PluginInfo -> NormalMemory = 0;
    PluginInfo -> MemoryBswaped = 1;
    return;
}

EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, unsigned int *CycleCount)
{
    if (CycleCount != NULL) /* cycle-accuracy not doable with today's hosts */
        *CycleCount = 0x00000000;
    update_conf(CFG_FILE);

    if (Rsp_Info.DMEM == Rsp_Info.IMEM) /* usually dummy RSP data for testing */
        return; /* DMA is not executed just because plugin initiates. */
    while (Rsp_Info.IMEM != Rsp_Info.DMEM + 4096)
        message("Virtual host map noncontiguity.");

    RSP = Rsp_Info;
    *RSP.SP_PC_REG = 0x04001000 & 0x00000FFF; /* task init bug on Mupen64 */
    CR[0x0] = RSP.SP_MEM_ADDR_REG;
    CR[0x1] = RSP.SP_DRAM_ADDR_REG;
    CR[0x2] = RSP.SP_RD_LEN_REG;
    CR[0x3] = RSP.SP_WR_LEN_REG;
    CR[0x4] = RSP.SP_STATUS_REG;
    CR[0x5] = RSP.SP_DMA_FULL_REG;
    CR[0x6] = RSP.SP_DMA_BUSY_REG;
    CR[0x7] = RSP.SP_SEMAPHORE_REG;
    CR[0x8] = RSP.DPC_START_REG;
    CR[0x9] = RSP.DPC_END_REG;
    CR[0xA] = RSP.DPC_CURRENT_REG;
    CR[0xB] = RSP.DPC_STATUS_REG;
    CR[0xC] = RSP.DPC_CLOCK_REG;
    CR[0xD] = RSP.DPC_BUFBUSY_REG;
    CR[0xE] = RSP.DPC_PIPEBUSY_REG;
    CR[0xF] = RSP.DPC_TMEM_REG;
    return;
}
EXPORT void CALL RomClosed(void)
{
    *RSP.SP_PC_REG = 0x00000000;
    return;
}

NOINLINE void message(const char* body)
{ /* Avoid SHELL32/ADVAPI32/USER32 dependencies by using standard C to print. */
    char argv[4096] = "CMD /Q /D /C \"TITLE RSP Message&&ECHO ";
    int i = 0;
    int j = strlen(argv);

/*
 * I'm just using system() to call the Windows command shell to print text.
 * When the subsystem permits, use printf to trace messages, not this crap.
 * I don't use WIN32 MessageBox because that's just extra OS dependencies. :P
 */
    while (body[i] != '\0')
    {
        if (body[i] == '\n')
        {
            strcat(argv, "&&ECHO ");
            ++i;
            j += 7;
            continue;
        }
        argv[j++] = body[i++];
    }
    strcat(argv, "&&PAUSE&&EXIT\"");
    system(argv);
    return;
}

NOINLINE void update_conf(const char* source)
{
    FILE* stream;
    char line[CHARACTERS_PER_LINE] = "";
    char key[CHARACTERS_PER_LINE], value[CHARACTERS_PER_LINE];
    register int i, test;

    stream = fopen(source, "r");
    if (stream == NULL)
    { /* try GetModulePath or whatever to correct the path? */
        message("Failed to read config.");
        return;
    }
    do
    {
        int bvalue;

        line[0] = '\0';
        key[0] = '\0';
        value[0] = '\0';
        for (i = 0; i < CHARACTERS_PER_LINE; i++)
        {
            test = fgetc(stream);
            if (test < 0) /* either EOF or invalid ASCII characters */
                break;
            line[i] = (char)(test);
            if (line[i] == '\n')
                break;
        }
        line[i] = '\0';

        for (i = 0; i < CHARACTERS_PER_LINE && line[i] != '='; i++);
        line[i] = '\0';
        strcpy(key, line);
        strcpy(value, line + i + 1);

        bvalue = atoi(value);
        if (strcmp(key, "DisplayListToGraphicsPlugin") == 0)
            CFG_HLE_GFX = (u8)(bvalue);
        else if (strcmp(key, "AudioListToAudioPlugin") == 0)
            CFG_HLE_AUD = (u8)(bvalue);
        else if (strcmp(key, "WaitForCPUHost") == 0)
            CFG_WAIT_FOR_CPU_HOST = bvalue;
        else if (strcmp(key, "SupportCPUSemaphoreLock") == 0)
            CFG_MEND_SEMAPHORE_LOCK = bvalue;
    } while (test >= 0);
    fclose(stream);
    return;
}

#ifdef SP_EXECUTE_LOG
void step_SP_commands(uint32_t inst)
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
        message(text); /* PC offset, MIPS hex. */
        if (output_log == NULL) {} else /* Global pointer not updated?? */
            fwrite(endian_swap, 4, 1, output_log);
    }
}
#endif

NOINLINE void export_data_cache(void)
{
    FILE* out;
    register uint32_t addr;

    out = fopen("rcpcache.dhex", "wb");
#if (0)
    for (addr = 0x00000000; addr < 0x00001000; addr += 0x00000001)
        fputc(RSP.DMEM[BES(addr & 0x00000FFF)], out);
#else
    for (addr = 0x00000000; addr < 0x00001000; addr += 0x00000004)
    {
        fputc(RSP.DMEM[addr + 0x000 + BES(0x000)], out);
        fputc(RSP.DMEM[addr + 0x001 + MES(0x000)], out);
        fputc(RSP.DMEM[addr + 0x002 - MES(0x000)], out);
        fputc(RSP.DMEM[addr + 0x003 - BES(0x000)], out);
    }
#endif
    fclose(out);
    return;
}
NOINLINE void export_instruction_cache(void)
{
    FILE* out;
    register uint32_t addr;

    out = fopen("rcpcache.ihex", "wb");
#if (0)
    for (addr = 0x00000000; addr < 0x00001000; addr += 0x00000001)
        fputc(RSP.IMEM[BES(addr & 0x00000FFF)], out);
#else
    for (addr = 0x00000000; addr < 0x00001000; addr += 0x00000004)
    {
        fputc(RSP.IMEM[addr + 0x000 + BES(0x000)], out);
        fputc(RSP.IMEM[addr + 0x001 + MES(0x000)], out);
        fputc(RSP.IMEM[addr + 0x002 - MES(0x000)], out);
        fputc(RSP.IMEM[addr + 0x003 - BES(0x000)], out);
    }
#endif
    fclose(out);
    return;
}
void export_SP_memory(void)
{
    export_data_cache();
    export_instruction_cache();
    return;
}

/*
 * Microsoft linker defaults to an entry point of `_DllMainCRTStartup',
 * which attaches several CRT dependencies.  To eliminate CRT dependencies,
 * we direct the linker to cursor the entry point to the lower-level
 * `DllMain' symbol or, alternatively, link with /NOENTRY for no entry point.
 */
#ifdef WIN32
int __stdcall DllMain(void* hModule, u32 ul_reason_for_call, void* lpReserved)
{
    hModule = lpReserved = NULL; /* unused */
    switch (ul_reason_for_call)
    {
case 1: /* DLL_PROCESS_ATTACH */
        break;
case 2: /* DLL_THREAD_ATTACH */
        break;
case 3: /* DLL_THREAD_DETACH */
        break;
case 0: /* DLL_PROCESS_DETACH */
        break;
    }
    return 1; /* TRUE */
}
#endif
