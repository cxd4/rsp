#include "vu.h"

INLINE static void do_ne(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        clip[i] = 0;
    for (i = 0; i < N; i++)
        comp[i] = (VS[i] != VT[i]);
    for (i = 0; i < N; i++)
        comp[i] = comp[i] | ne[i];
#if (0)
    merge(VACC_L, comp, VS, VT); /* correct but redundant */
#else
    vector_copy(VACC_L, VS);
#endif
    vector_copy(VD, VACC_L);

    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = 0;
    return;
}

static void VNE(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;

    do_ne(VR[vd], VR[vs], ST);
    return;
}

static void VNE_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_ne(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VNE0q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x2);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE1q(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x3);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE0h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x4);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE1h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x5);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE2h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x6);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE3h(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x7);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE0w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x8);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE1w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0x9);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE2w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xA);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE3w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xB);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE4w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xC);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE5w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xD);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE6w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xE);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
static void VNE7w(void)
{
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    SHUFFLE_VECTOR(SV, VR[vt], 0xF);
    do_ne(VR[vd], VR[vs], SV);
    return;
}
