#include "vu.h"

void VMULF(int vd, int vs, int vt, int element)
{
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[00]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[01]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[02]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[03]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[04]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[05]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[06]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[07]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[00]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[00]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[02]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[02]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[04]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[04]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[06]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[06]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[01]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[01]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[03]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[03]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[05]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[05]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[07]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[07]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[00]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[00]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[00]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[00]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[04]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[04]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[04]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[04]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[01]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[01]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[01]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[01]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[05]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[05]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[05]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[05]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[02]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[02]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[02]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[02]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[06]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[06]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[06]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[06]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[03]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[03]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[03]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[03]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[07]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[07]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[07]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[07]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */
            element &= 07;
            VACC[00].q = (long long)(VR[vs].s[00] * VR[vt].s[element]) + 0x4000;
            VACC[01].q = (long long)(VR[vs].s[01] * VR[vt].s[element]) + 0x4000;
            VACC[02].q = (long long)(VR[vs].s[02] * VR[vt].s[element]) + 0x4000;
            VACC[03].q = (long long)(VR[vs].s[03] * VR[vt].s[element]) + 0x4000;
            VACC[04].q = (long long)(VR[vs].s[04] * VR[vt].s[element]) + 0x4000;
            VACC[05].q = (long long)(VR[vs].s[05] * VR[vt].s[element]) + 0x4000;
            VACC[06].q = (long long)(VR[vs].s[06] * VR[vt].s[element]) + 0x4000;
            VACC[07].q = (long long)(VR[vs].s[07] * VR[vt].s[element]) + 0x4000;
            goto STORE_ACCUMULATOR_RESULTS;
    }
STORE_ACCUMULATOR_RESULTS:
    VACC[00].q <<= 17; /* Any zilmar-based RSP emulator is doing this. */
    VACC[01].q <<= 17; /* The original method to emulate the 8 48-bit RSP */
    VACC[02].q <<= 17; /* vector accumulators has always been to virtualize */
    VACC[03].q <<= 17; /* them using 64-bit union segments, with the lowest- */
    VACC[04].q <<= 17; /* order 16 bits totally unused.  Therefore, low, */
    VACC[05].q <<= 17; /* middle, and high accumulator assignments must be */
    VACC[06].q <<= 17; /* targeted to the left 16 bits.  For accuracy I hope */
    VACC[07].q <<= 17; /* to have later revised this against using 64 bits. */
#ifdef VU_EMULATE_FRACTION_SATURATE_UNDERFLOW
    if (VACC[00].q == (long long)0xFFFF800080000000) { /* -140735340871680. */    
        VACC[00].q = +140739635838976; /* 800080000000 [hex] */
        VR[vd].s[00] = 0x7FFF;
    } else {
        VR[vd].s[00] = VACC[00].w[MD];
    }
    if (VACC[01].q == (long long)0xFFFF800080000000) {
        VACC[01].q = +140739635838976;
        VR[vd].s[01] = 0x7FFF;
    } else {
        VR[vd].s[01] = VACC[01].w[MD];
    }
    if (VACC[02].q == (long long)0xFFFF800080000000) {
        VACC[02].q = +140739635838976;
        VR[vd].s[02] = 0x7FFF;
    } else {
        VR[vd].s[02] = VACC[02].w[MD];
    }
    if (VACC[03].q == (long long)0xFFFF800080000000) {
        VACC[03].q = +140739635838976;
        VR[vd].s[03] = 0x7FFF;
    } else {
        VR[vd].s[03] = VACC[03].w[MD];
    }
    if (VACC[04].q == (long long)0xFFFF800080000000) {
        VACC[04].q = +140739635838976;
        VR[vd].s[04] = 0x7FFF;
    } else {
        VR[vd].s[04] = VACC[04].w[MD];
    }
    if (VACC[05].q == (long long)0xFFFF800080000000) {
        VACC[05].q = +140739635838976;
        VR[vd].s[05] = 0x7FFF;
    } else {
        VR[vd].s[05] = VACC[05].w[MD];
    }
    if (VACC[06].q == (long long)0xFFFF800080000000) {
        VACC[06].q = +140739635838976;
        VR[vd].s[06] = 0x7FFF;
    } else {
        VR[vd].s[06] = VACC[06].w[MD];
    }
    if (VACC[07].q == (long long)0xFFFF800080000000) {
        VACC[07].q = +140739635838976;
        VR[vd].s[07] = 0x7FFF;
    } else {
        VR[vd].s[07] = VACC[07].w[MD];
    }
#else
    VR[vd].s[00] = VACC[00].w[MD];
    VR[vd].s[01] = VACC[01].w[MD];
    VR[vd].s[02] = VACC[02].w[MD];
    VR[vd].s[03] = VACC[03].w[MD];
    VR[vd].s[04] = VACC[04].w[MD];
    VR[vd].s[05] = VACC[05].w[MD];
    VR[vd].s[06] = VACC[06].w[MD];
    VR[vd].s[07] = VACC[07].w[MD];
#endif
    return;
}
