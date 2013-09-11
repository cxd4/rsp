#include "vu.h"

static void VCH(int vd, int vs, int vt, int e)
{
    int ge, le, neq;
    register int i;

    VCO = 0x0000;
    VCC = 0x0000;
    VCE = 0x00;
    for (i = 0; i < N; i++)
    {
        const signed short VS = VR[vs][i];
        const signed short VT = VR_T(i);
        const int sn = (VS ^ VT) < 0; /* sn = (unsigned short)(VS ^ VT) >> 15 */

        if (sn)
        {
            ge = (VT < 0);
            le = (VS + VT <= 0);
            neq = (VS + VT == -1); /* compare extension */
            VCE |= neq << i;
            neq ^= !(VS + VT == 0); /* !(x | y) = x ^ !(y), if (x & y) != 1 */
            ACC_R(i) = le ? -VT : VS;
            VCO |= (neq <<= (i + 0x8)) | (sn << (i + 0x0)); /* sn = 1 */
        }
        else
        {
            le = (VT < 0);
            ge = (VS - VT >= 0);
            neq = !(VS - VT == 0);
            VCE |= 0x00 << i;
            ACC_R(i) = ge ? VT : VS;
            VCO |= (neq <<= (i + 0x8)) | (sn << (i + 0x0)); /* sn = 0 */
        }
        VCC |=  (ge <<= (i + 0x8)) | (le <<= (i + 0x0));
    }
    for (i = 0; i < N; i++)
        ACC_W(i) = ACC_R(i);
    return;
}

void do_ch(int vs)
{
    int eq[8], neq[8], vce[8];
    int ge[8], le[8];
    short VS[8];
    signed short sn[8];
    register int i;

    for (i = 0; i < N; i++)
        sn[i] = VR[vs][i] ^ VC[i];
    for (i = 0; i < N; i++)
        sn[i] = sn[i] >> 15;
    for (i = 0; i < N; i++)
        le[i] = (VC[i] < 0);
    for (i = 0; i < N; i++)
        VC[i] ^= sn[i]; /* if (sn == ~0) {VT = ~VT;} else {VT =  VT;} */
    for (i = 0; i < N; i++)
        vce[i]  = (VR[vs][i] == VC[i]); /* (VR[vs][i] + ~VC[i] == ~1); */
    for (i = 0; i < N; i++)
        vce[i] &= sn[i];
    for (i = 0; i < N; i++)
        VC[i] -= sn[i]; /* converts ~(VT) into -(VT) by subtracting -1 or 0 */
    for (i = 0; i < N; i++)
        eq[i]  = (VR[vs][i] == VC[i]);
    for (i = 0; i < N; i++)
        eq[i] |= vce[i];
    for (i = 0; i < N; i++)
        neq[i] = eq[i] ^ 1;
    for (i = 0; i < N; i++)
        VS[i] = VR[vs][i] - VC[i];
    for (i = 0; i < N; i++)
        VS[i] = VS[i] * sn[i]; /* VS - VT if !(sn); VT - VS if (sn) */
    for (i = 0; i < N; i++)
        ge[i] = (VS[i] >= 0x0000);
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = ge[i] ? VC[i] : VR[vs][i];
    for (i = 0; i < N; i++)
        ge[i] <<= 8; /* By default, unless (sn), VCC[i+8] = ge;VCC[i+0] = le; */
    for (i = 0; i < N; i++)
        sn[i] &= 0x0008; /* mutated to shift offset:  zero or eight */
    for (i = 0; i < N; i++)
        ge[i] >>= sn[i];
    for (i = 0; i < N; i++)
        le[i] <<= sn[i];
    for (i = 0; i < N; i++)
        sn[i] >>= 3;

    VCC = 0x0000;
    for (i = 0; i < N; i++)
        VCC |= ge[i] | le[i];
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        VCO |= neq[i]<<(i + 0x8) | sn[i]<<(i + 0x0);
    VCE = 0x00;
    for (i = 0; i < N; i++)
        VCE |= vce[i] << i;
    return;
}

static void VCH_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][i];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCH7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_ch(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
