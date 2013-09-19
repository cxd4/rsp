#include "vu.h"

#if (0)
#define SETBI(i)    (res[i] < 0)
#else
#define SETBI(i)    (!!(res[i] & 0x80000000))
#endif
#define SETNE(i)    (res[i] != 0)

#define BMASK(i)    ((i & 0x8) ? (ne[i-8] << i) : (bo[i-0] << i))
void set_bo(short* VD, short* VS, short* VT)
{ /* set CARRY and borrow out from difference */
    unsigned int res[N];
    register int i;

    for (i = 0; i < N; i++)
        res[i] = (unsigned short)(VS[i]) - (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(res[i]);
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    for (i = 0; i < N; i++)
        ne[i] = SETNE(i);
    for (i = 0; i < N; i++)
        co[i] = SETBI(i);
    return;
}
static void VSUBC_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    set_bo(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VSUBC0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
static void VSUBC7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    set_bo(VR[vd], VR[vs], SV);
    return;
}
