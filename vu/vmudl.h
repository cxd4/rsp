#include "vu.h"

static void VMUDL(int vd, int vs, int vt, int e)
{
    register unsigned int product;
    register int i;

    for (i = 0; i < N; i++)
    {
        product = (unsigned short)VR[vs][i] * (unsigned short)VR_T(i);
        VACC[i].DW = product >> 16;
    }
    for (i = 0; i < N; i++) /* Sign-clamp bits 15..0 of ACC to dest. VR. */
        VR_D(i) = VACC[i].s[LO]; /* No arithmetic checks needed. */
    return;
}

static void VMUDL_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][i]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x2 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x3 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x4 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x5 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x6 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x7 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x8 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0x9 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xA & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xB & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xC & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xD & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xE & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
static void VMUDL7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        MUDL_acc[i].W =
            (unsigned short)(VR[vs][i])
          * (unsigned short)(VR[vt][(0xF & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        VACC[i].DW = MUDL_acc[i].H[1];
    for (i = 0; i < N; i++)
        VR[vd][i] = MUDL_acc[i].H[1];
    return;
}
