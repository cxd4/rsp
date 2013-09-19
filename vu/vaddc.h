#include "vu.h"

#if (0)
#define SETCO(i)    (res[i] > 0x0000FFFF)
#elif (1)
#define SETCO(i)    (!!(res[i] & ~0x0000FFFF))
#else
#define SETCO(i)    (!!(res[i] & 0x00010000))
/* Because MAX is 0xFFFF, and MAX + MAX < 0x00020000. */
#endif

void set_co(short* VD, short* VS, short* VT)
{ /* set CARRY and carry out from sum */
    unsigned int res[N];
    register int i;

    for (i = 0; i < N; i++)
        res[i] = (unsigned short)(VS[i]) + (unsigned short)(VT[i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(res[i]);
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    for (i = 0; i < N; i++)
        ne[i] = 0;
    for (i = 0; i < N; i++)
        co[i] = SETCO(i);
    return;
}
static void VADDC_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    set_co(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VADDC0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
static void VADDC7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    set_co(VR[vd], VR[vs], SV);
    return;
}
