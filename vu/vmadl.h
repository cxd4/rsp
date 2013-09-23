#include "vu.h"

INLINE static void do_madl(short* VD, short* VS, short* VT)
{
    unsigned long addend[N];
    register int i;

    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VS[i])*(unsigned short)(VT[i]) >> 16;
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_L[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_L[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(addend[i] >> 16);
    for (i = 0; i < N; i++)
        addend[i] = (unsigned short)(VACC_M[i]) + addend[i];
    for (i = 0; i < N; i++)
        VACC_M[i] = (short)(addend[i]);
    for (i = 0; i < N; i++)
        VACC_H[i] += addend[i] >> 16;
    SIGNED_CLAMP(VD, SM_MUL_Z);
    return;
}

static void VMADL(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_madl(VR[vd], VR[vs], ST);
    return;
}

static void VMADL_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_madl(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VMADL0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
static void VMADL7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_madl(VR[vd], VR[vs], SV);
    return;
}
