#include "vu.h"

/*
 * -1:  VT *= -1, because VS < 0 // VT ^= -2 if even, or ^= -1, += 1
 *  0:  VT *=  0, because VS = 0 // VT ^= VT
 * +1:  VT *= +1, because VS > 0 // VT ^=  0
 *      VT ^= -1, "negate" -32768 as ~+32767 (corner case hack for N64 SP)
 */
void do_abs(short* VD, short* VS, short* VT)
{
    signed int neg[N], pos[N];
    signed int nez[N], cch[N]; /* corner case hack -- abs(-32768) == +32767 */
    short res[N];
    register int i;

    for (i = 0; i < N; i++)
        res[i] = VT[i];
#if (0)
#define MASK_XOR
#endif
    for (i = 0; i < N; i++)
        neg[i]  = (VS[i] <  0x0000);
    for (i = 0; i < N; i++)
        pos[i]  = (VS[i] >  0x0000);
    for (i = 0; i < N; i++)
        nez[i]  = 0;
#ifdef MASK_XOR
    for (i = 0; i < N; i++)
        neg[i]  = -neg[i];
    for (i = 0; i < N; i++)
        nez[i] += neg[i];
#else
    for (i = 0; i < N; i++)
        nez[i] -= neg[i];
#endif
    for (i = 0; i < N; i++)
        nez[i] += pos[i];
#ifdef MASK_XOR
    for (i = 0; i < N; i++)
        res[i] ^= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (res[i] != -32768);
    for (i = 0; i < N; i++)
        res[i] += cch[i]; /* -(x) === (x ^ -1) + 1 */
#else
    for (i = 0; i < N; i++)
        res[i] *= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (res[i] == -32768);
    for (i = 0; i < N; i++)
        res[i] -= cch[i];
#endif
    for (i = 0; i < N; i++)
        ACC_L(i) = res[i];
    for (i = 0; i < N; i++)
        VD[i] = ACC_L(i);
    return;
}

static void VABS_v(void)
{
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    do_abs(VR[vd], VR[vs], VR[vt]);
    return;
}
static void VABS0q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x2);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS1q(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x3);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS0h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x4);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS1h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x5);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS2h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x6);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS3h(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x7);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS0w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x8);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS1w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0x9);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS2w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xA);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS3w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xB);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS4w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xC);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS5w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xD);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS6w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xE);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
static void VABS7w(void)
{
    VECTOR VT;
    short SV[N];
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    VT = SHUFFLE_VECTOR(VR[vt], 0xF);
    STORE_VECTOR(SV, VT);
    do_abs(VR[vd], VR[vs], SV);
    return;
}
