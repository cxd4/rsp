#include "vu.h"

static void VCL(int vd, int vs, int vt, int e)
{
    register const unsigned short VCC_old = VCC;
    int ge, le;
    register int i;

    VCC = 0x0000; /* Undergo the correction phase, factoring old VCC bits. */
    for (i = 0; i < N; i++)
    {
        const unsigned short VS = (unsigned short)VR[vs][i];
        const unsigned short VT = (unsigned short)VR_T(i);
        const int eq = (~VCO >> (i + 0x8)) & 0x0001; /* !(NOTEQUAL) */
        const int sn =  (VCO >> (i + 0x0)) & 0x0001; /* CARRY */

        le = VCC_old & (0x0001 << i); /* unless (eq & sn) */
        ge = VCC_old & (0x0100 << i); /* unless (eq & !sn) */
        if (sn)
        {
            if (eq)
            {
                const int sum = VS + VT;
                const int ce = (VCE >> i) & 0x01;
                int lz = ((sum & 0x0000FFFF) == 0x00000000);
                int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                le = (~ce & (lz & uz)) | (ce & (lz | uz));
                le <<= i + 0x0;
            }
            ACC_R(i) = le ? -VT : VS;
        }
        else
        {
            if (eq)
            {
                ge = (VS - VT >= 0);
                ge <<= i + 0x8;
            }
            ACC_R(i) = ge ? VT : VS;
        }
        VCC |= ge | le;
    }
    for (i = 0; i < N; i++)
        ACC_W(i) = ACC_R(i);
    VCO = 0x0000;
    VCE = 0x00;
    return;
}

void do_cl(int vs)
{
    int eq[8], vce[8];
    int ge[8], le[8];
    int lz[8], uz[8];
    int dif[8], gen[8], len[8]; /* temporaries for computing flag corrections */
    signed short sn[8];
    register int i;

    for (i = 0; i < N; i++)
        le[i] = !!(0x0001<<i & VCC);
    for (i = 0; i < N; i++)
        ge[i] = !!(0x0100<<i & VCC);
    for (i = 0; i < N; i++)
        sn[i] = -(VCO>>i & 1);
    for (i = 0; i < N; i++)
        eq[i] =  !(0x0100<<i & VCO);
    for (i = 0; i < N; i++)
        vce[i] = (VCE >> i) & 1;
    VCO = 0x0000;
    VCE = 0x00;
/*
 * Now that we have extracted all the flags, we will essentially be masking
 * them back in where they came from redundantly, unless the corresponding
 * NOTEQUAL bit from VCO upper was not set....
 */
    for (i = 0; i < N; i++)
        VC[i] = VC[i] ^ sn[i];
    for (i = 0; i < N; i++)
        VC[i] = VC[i] - sn[i]; /* conditional negation, if sn */
    for (i = 0; i < N; i++)
        dif[i] = VR[vs][i] - VC[i]; /* of course, if sn, VS + VT, not VS - VT */
    for (i = 0; i < N; i++)
        lz[i] = !(dif[i] &  0x0000FFFF);
    for (i = 0; i < N; i++)
        uz[i] = !(dif[i] & ~0x0000FFFF);
    for (i = 0; i < N; i++)
        gen[i] = lz[i] | uz[i];
    for (i = 0; i < N; i++)
        len[i] = lz[i] & uz[i];
    for (i = 0; i < N; i++)
        gen[i] = gen[i] & vce[i];
    for (i = 0; i < N; i++)
        vce[i] = ~vce[i]; /* vce[i] = (vce[i] ^ 1) */
    for (i = 0; i < N; i++)
        len[i] = len[i] & vce[i]; /* ... & (vce[i] ^ 1) */
    for (i = 0; i < N; i++)
        len[i] = len[i] | gen[i];
    for (i = 0; i < N; i++)
        gen[i] = (dif[i] >= 0x0000);
    for (i = 0; i < N; i++)
        le[i] = (eq[i] &  sn[i]) ? len[i] : le[i];
    for (i = 0; i < N; i++)
        ge[i] = (eq[i] & ~sn[i]) ? gen[i] : ge[i];
    for (i = 0; i < N; i++)
        eq[i] = sn[i] ? le[i] : ge[i];
    for (i = 0; i < N; i++)
        VACC[i].s[LO] = eq[i] ? VC[i] : VR[vs][i];

    VCC = 0x0000;
    for (i = 0; i < N; i++)
        VCC |= le[i] << (i + 0x0);
    for (i = 0; i < N; i++)
        VCC |= ge[i] << (i + 0x8);
    return;
}

static void VCL_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][i];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x2 & 01) + (i & 0xE)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x3 & 01) + (i & 0xE)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x4 & 03) + (i & 0xC)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x5 & 03) + (i & 0xC)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x6 & 03) + (i & 0xC)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x7 & 03) + (i & 0xC)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x8 & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0x9 & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xA & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xB & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xC & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xD & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xE & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
static void VCL7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        VC[i] = VR[vt][(0xF & 07) + (i & 0x0)];
    do_cl(vs);
    for (i = 0; i < N; i++)
        VR[vd][i] = VACC[i].s[LO];
    return;
}
