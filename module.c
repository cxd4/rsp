/******************************************************************************\
* Project:  Module Subsystem Interface to SP Interpreter Core                  *
* Authors:  Iconoclast                                                         *
* Release:  2015.11.27                                                         *
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

#ifdef WIN32
#include <windows.h>
#endif

#include "module.h"
#include "su.h"

RSP_INFO RSP_INFO_NAME;

static const char DLL_about[] =
    "RSP Interpreter by Iconoclast\n"\
    "Thanks for test RDP:  Jabo, ziggy, angrylion\n"\
    "RSP driver examples:  bpoint, zilmar, Ville Linde";

EXPORT void CALL CloseDLL(void)
{
    DRAM = NULL; /* so DllTest benchmark doesn't think ROM is still open */
    return;
}

EXPORT void CALL DllAbout(p_void hParent)
{
    hParent = NULL;
    message(DLL_about);
    return;
}

EXPORT void CALL DllConfig(p_void hParent)
{
    hParent = NULL; /* unused */
    my_system("sp_cfgui");
    update_conf(CFG_FILE);

    if (DMEM == IMEM || GET_RCP_REG(SP_PC_REG) % 4096 == 0x00000000)
        return;
    export_SP_memory();
    return;
}

EXPORT u32 CALL DoRspCycles(u32 cycles)
{
    OSTask_type task_type;

    if (GET_RCP_REG(SP_STATUS_REG) & 0x00000003)
    {
        message("SP_STATUS_HALT");
        return 0x00000000;
    }

    task_type = 0x00000000
#ifdef USE_CLIENT_ENDIAN
      | *((pi32)(DMEM + 0x000FC0U))
#else
      | (u32)DMEM[0xFC0] << 24
      | (u32)DMEM[0xFC1] << 16
      | (u32)DMEM[0xFC2] <<  8
      | (u32)DMEM[0xFC3] <<  0
#endif
    ;
    switch (task_type) {
#ifdef EXTERN_COMMAND_LIST_GBI
    case M_GFXTASK:
        if (CFG_HLE_GFX == 0)
            break;

        if (*(pi32)(DMEM + 0xFF0) == 0x00000000)
            break; /* Resident Evil 2, null task pointers */
        if (GET_RSP_INFO(ProcessDList) == NULL)
            { /* branch */ }
        else
            GET_RSP_INFO(ProcessDList)();
        GET_RCP_REG(SP_STATUS_REG) |= 0x00000203;
        if (GET_RCP_REG(SP_STATUS_REG) & 0x00000040) {
            GET_RCP_REG(MI_INTR_REG) |= 0x00000001; /* R4300 SP interrupt */
            GET_RSP_INFO(CheckInterrupts)();
        } /* SP_STATUS_INTR_BREAK */
        if (GET_RCP_REG(DPC_STATUS_REG) & 0x00000002) {
            message("DPC_CLR_FREEZE");
            GET_RCP_REG(DPC_STATUS_REG) &= ~0x00000002;
        } /* DPC_STATUS_FREEZE */
        return 0;
#endif
#ifdef EXTERN_COMMAND_LIST_ABI
    case M_AUDTASK:
        if (CFG_HLE_AUD == 0)
            break;

        if (GET_RSP_INFO(ProcessAList) == NULL)
            { /* branch */ }
        else
            GET_RSP_INFO(ProcessAList)();
        GET_RCP_REG(SP_STATUS_REG) |= 0x00000203;
        if (GET_RCP_REG(SP_STATUS_REG) & 0x00000040) {
            GET_RCP_REG(MI_INTR_REG) |= 0x00000001; /* R4300 SP interrupt */
            GET_RSP_INFO(CheckInterrupts)();
        } /* SP_STATUS_INTR_BREAK */
        return 0;
#endif
    case M_VIDTASK:
        message("M_VIDTASK");
        break;
    case M_NJPEGTASK:
        break; /* Zelda, Pokemon, others */
    case M_NULTASK:
        message("M_NULTASK");
        break;
    case M_HVQTASK:
        message("M_HVQTASK");
        break;
    case M_HVQMTASK:
        if (GET_RSP_INFO(ShowCFB) == NULL) /* Gfx #1.2 or older specs */
            break;
        GET_RSP_INFO(ShowCFB)(); /* forced FB refresh in case gfx plugin skip */
        break;
    }
    run_task();
    return (cycles);
}

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    PluginInfo -> Version = PLUGIN_API_VERSION;
    PluginInfo -> Type = PLUGIN_TYPE_RSP;
    my_strcpy(PluginInfo -> Name, "Static Interpreter");
    PluginInfo -> NormalMemory = 0;
    PluginInfo -> MemoryBswaped = USE_CLIENT_ENDIAN;
    return;
}

EXPORT void CALL InitiateRSP(RSP_INFO Rsp_Info, pu32 CycleCount)
{
    if (CycleCount != NULL) /* cycle-accuracy not doable with today's hosts */
        *CycleCount = 0x00000000;
    update_conf(CFG_FILE);

    if (Rsp_Info.DMEM == Rsp_Info.IMEM) /* usually dummy RSP data for testing */
        return; /* DMA is not executed just because plugin initiates. */
    while (Rsp_Info.IMEM != Rsp_Info.DMEM + 4096)
        message("Virtual host map noncontiguity.");

    RSP_INFO_NAME = Rsp_Info;
    DRAM = GET_RSP_INFO(RDRAM);
    DMEM = GET_RSP_INFO(DMEM);
    IMEM = GET_RSP_INFO(IMEM);

    CR[0x0] = &GET_RCP_REG(SP_MEM_ADDR_REG);
    CR[0x1] = &GET_RCP_REG(SP_DRAM_ADDR_REG);
    CR[0x2] = &GET_RCP_REG(SP_RD_LEN_REG);
    CR[0x3] = &GET_RCP_REG(SP_WR_LEN_REG);
    CR[0x4] = &GET_RCP_REG(SP_STATUS_REG);
    CR[0x5] = &GET_RCP_REG(SP_DMA_FULL_REG);
    CR[0x6] = &GET_RCP_REG(SP_DMA_BUSY_REG);
    CR[0x7] = &GET_RCP_REG(SP_SEMAPHORE_REG);
    GET_RCP_REG(SP_PC_REG) = 0x04001000 & 0xFFF; /* task init bug on Mupen64 */
    CR[0x8] = &GET_RCP_REG(DPC_START_REG);
    CR[0x9] = &GET_RCP_REG(DPC_END_REG);
    CR[0xA] = &GET_RCP_REG(DPC_CURRENT_REG);
    CR[0xB] = &GET_RCP_REG(DPC_STATUS_REG);
    CR[0xC] = &GET_RCP_REG(DPC_CLOCK_REG);
    CR[0xD] = &GET_RCP_REG(DPC_BUFBUSY_REG);
    CR[0xE] = &GET_RCP_REG(DPC_PIPEBUSY_REG);
    CR[0xF] = &GET_RCP_REG(DPC_TMEM_REG);

    MF_SP_STATUS_TIMEOUT = 32767;
    return;
}

EXPORT void CALL RomClosed(void)
{
    FILE* stream;

    GET_RCP_REG(SP_PC_REG) = 0x04001000;

/*
 * Sometimes the end user won't correctly install to the right directory. :(
 * If the config file wasn't installed correctly, politely shut errors up.
 */
    stream = my_fopen(CFG_FILE, "wb");
    my_fwrite(conf, 8, 32 / 8, stream);
    my_fclose(stream);
    return;
}

NOINLINE void message(const char* body)
{
#ifdef WIN32
    char* argv;
    int i, j;

    argv = my_calloc(4096, 1);
    my_strcpy(argv, "CMD /Q /D /C \"TITLE RSP Message&&ECHO ");
    i = 0;
    j = my_strlen(argv);
    while (body[i] != '\0')
    {
        if (body[i] == '\n')
        {
            my_strcat(argv, "&&ECHO ");
            ++i;
            j += 7;
            continue;
        }
        argv[j++] = body[i++];
    }
    my_strcat(argv, "&&PAUSE&&EXIT\"");
    my_system(argv);
    my_free(argv);
#else
    fputs(body, stdout);
    putchar('\n');
#endif
    return;
}

NOINLINE void update_conf(const char* source)
{
    FILE* stream;
    register int i;

/*
 * hazard adjustment
 * If file not found, wipe the registry to 0's (all default settings).
 */
    for (i = 0; i < 32; i++)
        conf[i] = 0x00;

    stream = my_fopen(source, "rb");
    if (stream == NULL) {
        message("Failed to read config.");
        return;
    }
    my_fread(conf, 8, 32 / 8, stream);
    my_fclose(stream);
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
        my_strcat(text, "\n");
        my_strcat(text, code);
        message(text); /* PC offset, MIPS hex. */
        if (output_log == NULL) {} else /* Global pointer not updated?? */
            my_fwrite(endian_swap, 4, 1, output_log);
    }
}
#endif

NOINLINE void export_data_cache(void)
{
    pu8 DMEM_swapped;
    FILE * out;
    register int i;
 /* const int little_endian = GET_RSP_INFO(MemoryBswaped); */

    DMEM_swapped = my_calloc(4096, 1);
    for (i = 0; i < 4096; i++)
        DMEM_swapped[i] = DMEM[BES(i)];
    out = my_fopen("rcpcache.dhex", "wb");
    my_fwrite(DMEM_swapped, 16, 4096 / 16, out);
    my_fclose(out);
    my_free(DMEM_swapped);
    return;
}
NOINLINE void export_instruction_cache(void)
{
    pu8 IMEM_swapped;
    FILE * out;
    register int i;
 /* const int little_endian = GET_RSP_INFO(MemoryBswaped); */

    IMEM_swapped = my_calloc(4096, 1);
    for (i = 0; i < 4096; i++)
        IMEM_swapped[i] = IMEM[BES(i)];
    out = my_fopen("rcpcache.ihex", "wb");
    my_fwrite(IMEM_swapped, 16, 4096 / 16, out);
    my_fclose(out);
    my_free(IMEM_swapped);
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
BOOL WINAPI DllMain(
    HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
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

/*
 * low-level recreations of the C standard library functions for operating
 * systems that define a C run-time or dependency on top of fixed OS calls
 *
 * Currently, this only addresses Microsoft Windows.
 *
 * None of these are meant to out-perform the original functions, by the way
 * (especially with better intrinsic compiler support for stuff like memcpy),
 * just to cut down on I-cache use for performance-irrelevant code sections
 * and to avoid std. lib run-time dependencies on certain operating systems.
 */

NOINLINE p_void my_calloc(size_t count, size_t size)
{
#ifdef WIN32
    return GlobalAlloc(GPTR, size * count);
#else
    return calloc(count, size);
#endif
}

NOINLINE void my_free(p_void ptr)
{
#ifdef WIN32
    while (GlobalFree(ptr) != NULL)
        message("GlobalFree() failure");
#else
    free(ptr);
#endif
    return;
}

NOINLINE size_t my_strlen(const char* str)
{
    size_t ret_slot;

    for (ret_slot = 0; *str != '\0'; ret_slot++, str++);
    return (ret_slot);
}

NOINLINE char* my_strcpy(char* destination, const char* source)
{
    register size_t i;
    const size_t length = my_strlen(source) + 1; /* including null terminator */

    for (i = 0; i < length; i++)
        destination[i] = source[i];
    return (destination);
}

NOINLINE char* my_strcat(char* destination, const char* source)
{
    const size_t length = my_strlen(destination);

    my_strcpy(destination + length, source);
    return (destination);
}

NOINLINE int my_system(char* command)
{
    int ret_slot;
#ifdef WIN32
    static STARTUPINFOA info;
    static PROCESS_INFORMATION info_process;

    info.cb = sizeof(info);
    info.dwFillAttribute =
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    info.dwFlags = STARTF_USEFILLATTRIBUTE | STARTF_USECOUNTCHARS;

    info.dwXCountChars = 80;
    info.dwYCountChars = 20;

    ret_slot = CreateProcessA(
        NULL,
        command,
        NULL,
        NULL,
        FALSE,
        0x00000000,
        NULL,
        NULL,
        &info,
        &info_process
    );

    WaitForSingleObject(info_process.hProcess, INFINITE);
    CloseHandle(info_process.hProcess);
    CloseHandle(info_process.hThread);
#else
    ret_slot = system(command);
#endif
    return (ret_slot);
}

NOINLINE FILE* my_fopen(const char * filename, const char* mode)
{
#ifdef WIN32
#if 0
    if (mode[1] != 'b')
        return NULL; /* non-binary yet to be supported? */
#endif
    return (FILE *)(HANDLE)CreateFileA(
        filename,
        (mode[0] == 'r') ? GENERIC_READ : GENERIC_WRITE,
        (mode[0] == 'r') ? FILE_SHARE_READ : FILE_SHARE_WRITE,
        NULL,
        (mode[0] == 'r') ? OPEN_EXISTING : CREATE_ALWAYS,
#if 0
        FILE_FLAG_WRITE_THROUGH | FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING,
#else
        (mode[0] == 'r') ? FILE_ATTRIBUTE_NORMAL : FILE_FLAG_WRITE_THROUGH,
#endif
        NULL
    );
#else
    return fopen(filename, mode);
#endif
}

NOINLINE int my_fclose(FILE* stream)
{
    int ret_slot;
#ifdef WIN32
    ret_slot = !CloseHandle((HANDLE)stream);
#else
    ret_slot = fclose(stream);
#endif
    return (ret_slot);
}

NOINLINE size_t my_fread(p_void ptr, size_t size, size_t count, FILE* stream)
{
#ifdef WIN32
    DWORD ret_slot;

    ReadFile((HANDLE)stream, ptr, size * count, &ret_slot, NULL);
#else
    size_t ret_slot;

    ret_slot = fread(ptr, size, count, stream);
#endif
    return (size_t)(ret_slot);
}

NOINLINE size_t my_fwrite(p_void ptr, size_t size, size_t count, FILE* stream)
{
#ifdef WIN32
    DWORD ret_slot;

    WriteFile((HANDLE)stream, ptr, size * count, &ret_slot, NULL);
#else
    size_t ret_slot;

    ret_slot = fwrite(ptr, size, count, stream);
#endif
    return (size_t)(ret_slot);
}
