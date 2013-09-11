#include "vu.h"

static void VABS(int vd, int vs, int vt, int e)
{
    register int i;

#ifdef FORCE_STATIC_CLAMP
    for (i = 0; i < N; i++)
    {
        register signed short ti;

        ti  = VR_T(i);
        ti ^= -(VR[vs][i] < 0); /* ti = ~ti */
        ti +=  (VR[vs][i] < 0) & (ti != 0x7FFF); /* abs(-32768) == +32767 */
        ti &= -(VR[vs][i] != 0);
        ACC_R(i) = ti;
    }
#else
    for (i = 0; i < N; i++)
        if (VR[vs][i] < 0)
            ACC_R(i) = -(VR_T(i) ^ (VR_T(i) == -32768));
        else if (VR[vs][i] == 0)
            ACC_R(i) = 0x0000;
        else
            ACC_R(i) = +VR_T(i);
#endif
    for (i = 0; i < N; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

/*
 * -1:  VT *= -1, because VS < 0 // VT ^= -2 if even, or ^= -1, += 1
 *  0:  VT *=  0, because VS = 0 // VT ^= VT
 * +1:  VT *= +1, because VS > 0 // VT ^=  0
 *      VT ^= -1, "negate" -32768 as ~+32767 (corner case hack for N64 SP)
 */
void do_abs(int vs)
{ /* very experimental -- Laid out for explicit division of steps, not speed. */
    signed int neg[8], pos[8];
    signed int nez[8], cch[8]; /* corner case hack -- abs(-32768) == +32767 */
    register int i;
#if (0)
#define MASK_XOR
#endif
    for (i = 0; i < N; i++)
        neg[i]  = (VR[vs][i] <  0x0000);
    for (i = 0; i < N; i++)
        pos[i]  = (VR[vs][i] >  0x0000);
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
        result[i] ^= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (result[i] != -32768);
    for (i = 0; i < N; i++)
        result[i] += cch[i]; /* -(x) === (x ^ -1) + 1 */
#else
    for (i = 0; i < N; i++)
        result[i] *= nez[i];
    for (i = 0; i < N; i++)
        cch[i]  = (result[i] == -32768);
    for (i = 0; i < N; i++)
        result[i] -= cch[i];
#endif
    return;
}

static void VABS_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][i];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VABS7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_abs(vs);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
