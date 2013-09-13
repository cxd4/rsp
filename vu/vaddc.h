#include "vu.h"

#if (0)
#define SETCO(i)    (result[i] > 0x0000FFFF)
#elif (1)
#define SETCO(i)    (!!(result[i] & ~0x0000FFFF))
#else
#define SETCO(i)    (!!(result[i] & 0x00010000))
/* Because MAX is 0xFFFF, and MAX + MAX < 0x00020000. */
#endif

#define CMASK(i)    ((i & 0x8) ? (0x0000 << i) : (co[i] << i))
void set_co(void) /* set CARRY and carry out from sum */
{
    int co[8];
    register int i;

    for (i = 0; i < N; i++)
        co[i] = SETCO(i);
#if (0)
    VCO = 0x0000;
    for (i = 0; i < N; i++)
        VCO |= CMASK(i);
#else
    VCO =
        CMASK(0x7) | CMASK(0x6) | CMASK(0x5) | CMASK(0x4)
      | CMASK(0x3) | CMASK(0x2) | CMASK(0x1) | CMASK(0x0);
#endif
    return;
}
static void VADDC_v(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] = (unsigned short)(VR[vs][i]) + (unsigned short)(VR[vt][i]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC0q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x2 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC1q(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x3 & 01) + (i & 0xE)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC0h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x4 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC1h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x5 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC2h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x6 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC3h(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x7 & 03) + (i & 0xC)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC0w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x8 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC1w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0x9 & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC2w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xA & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC3w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xB & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC4w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xC & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC5w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xD & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC6w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xE & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
static void VADDC7w(void)
{
    register int i;
    const int vd = inst.R.sa;
    const int vs = inst.R.rd;
    const int vt = inst.R.rt;

    for (i = 0; i < N; i++)
        result[i] =
            (unsigned short)(VR[vs][i])
          + (unsigned short)(VR[vt][(0xF & 07) + (i & 0x0)]);
    for (i = 0; i < N; i++)
        ACC_L(i) = (short)(result[i]);
    for (i = 0; i < N; i++)
        VR[vd][i] = ACC_L(i);
    set_co();
    return;
}
