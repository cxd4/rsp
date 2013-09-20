#include "vu.h"

void do_eq(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] == VT[i]);
    for (i = 0; i < N; i++)
        comp[i] = comp[i] & (ne[i] ^= 1);
#if (0)
    for (i = 0; i < N; i++)
        ACC_L(i) = comp[i] ? VS[i] : VT[i]; /* correct but redundant */
#else
    for (i = 0; i < N; i++)
        ACC_L(i) = VT[i];
#endif
    memcpy(VD, VACC_L, N*sizeof(short));

    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

static void VEQ_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_eq(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VEQ0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
static void VEQ7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_eq(VR[vd], VR[vs], SV);
    return;
}
