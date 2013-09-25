#include <time.h>
#include "rsp.h"

static void (*bench_tests[54])(void) = {
    LBV, SBV,
    LSV, SSV,
    LLV, SLV,
    LDV, SDV,
    LQV, SQV,
    LRV, SRV,
    LPV, SPV,
    LUV, SUV,

    VMULF, VMACF, /* signed single-precision fractions */
    VMULU, VMACU, /* unsigned single-precision fractions */

    VMUDL, VMADL, /* double-precision multiplies using partial products */
    VMUDM, VMADM,
    VMUDN, VMADN,
    VMUDH, VMADH,

    VADD, VSUB, VABS,
    VADDC, VSUBC,
    VSAW,

    VLT, VEQ, VNE, VGE, /* normal select compares */
    VCH, VCL, /* double-precision clip select */
    VCR, /* single-precision, one's complement */
    VMRG,

    VAND, VNAND,
    VOR , VNOR ,
    VXOR, VNXOR,

    VRCPL, VRSQL, /* double-precision reciprocal look-ups */
    VRCPH, VRSQH,

    VMOV, NOP
};

const char test_names[54][8] = {
    "LBV    ","SBV    ",
    "LSV    ","SSV    ",
    "LLV    ","SLV    ",
    "LDV    ","SDV    ",
    "LQV    ","SQV    ",
    "LRV    ","SRV    ",
    "LPV    ","SPV    ",
    "LUV    ","SUV    ",

    "VMULF  ","VMACF  ",
    "VMULU  ","VMACU  ",

    "VMUDL  ","VMADL  ",
    "VMUDM  ","VMADM  ",
    "VMUDN  ","VMADN  ",
    "VMUDH  ","VMADH  ",

    "VADD   ","VSUB   ","VABS   ",
    "VADDC  ","VSUBC  ",
    "VSAW   ",

    "VLT    ","VEQ    ","VNE    ","VGE    ",
    "VCH    ","VCL    ",
    "VCR    ",
    "VMRG   ",

    "VAND   ","VNAND  ",
    "VOR    ","VNOR   ",
    "VXOR   ","VNXOR  ",

    "VRCPL  ","VRSQL  ",
    "VRCPH  ","VRSQH  ",

    "VMOV   ","VNOP   "
};

const char* notice_starting =
    "Ready to start benchmarks.\n"\
    "Close this message to commence tests.  Testing could take minutes.\n";
const char* notice_finished =
    "Finished writing benchmark results.\n"\
    "Check working emulator directory for \"sp_bench.txt\".";

unsigned char DMEM[4096], IMEM[4096];

EXPORT void CALL DllTest(HWND hParent)
{
    FILE* log;
    clock_t t1, t2;
    register int i;
    register long j;

    if (RSP.RDRAM != NULL)
    {
        message("Cannot test the RSP while playing!", 3);
        return;
    }

/*
 * fake cache pointers for testing LWC2 and SWC2
 */
    RSP.DMEM = DMEM;
    RSP.IMEM = IMEM;

/*
 * quick patch for testing VSAW elements
 */
    inst.R.rs = 0x8;

    message(notice_starting, 1);
    log = fopen("sp_bench.txt", "w");
    for (i = 0; i < 54; i++)
    {
        t1 = clock();
        for (j = -0x100000; j < 0; j++)
            bench_tests[i]();
        t2 = clock();
        fprintf(log, "%s:  %ld s\n", test_names[i], t2 - t1);
    }
    fclose(log);
    message(notice_finished, 1);
    return;
}
