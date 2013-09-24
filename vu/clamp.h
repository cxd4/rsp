#ifndef _CLAMP_H
#define _CLAMP_H

/*
 * dependency for 48-bit accumulator access
 */
#include "vu.h"

/*
 * modes of saturation (unofficial labels, just made up by file author)
 */
enum {
    SM_MUL_X, /* clamp acc. bits 31:16, crossing through zero (0x8000:0x7FFF) */
    SM_MUL_Z, /* clamp acc. bits 15:0 with zero-extension (0x0000:0xFFFF) */
    SM_MUL_Q, /* oddified DCT inverse quantization (for N64 SP, VMACQ only) */
    SM_MUL_I, /* (reserved) for VMULI and VMACI (VRNDP and VRNDN) */
    SM_ADD_A, /* VADD and VSUB arithmetic */
    SM_ADD_L, /* VABS dynamic inversion/negation logic */
    SM_DIV_R, /* reciprocal of the vector */
    SM_DIV_S, /* square root of the vector reciprocal */
    EOL /* more stuff here if you want */
};

INLINE void SIGNED_CLAMP(short* VD, int mode)
{
    short hi[N], lo[N];
    register int i;

    switch (mode)
    {
        case SM_MUL_X: /* typical sign-clamp of accumulator-mid (bits 31:16) */
            for (i = 0; i < N; i++)
                lo[i]  = (VACC_H[i] < ~0);
            for (i = 0; i < N; i++)
                lo[i] |= (VACC_H[i] < 0) & !(VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                hi[i]  = (VACC_H[i] >  0);
            for (i = 0; i < N; i++)
                hi[i] |= (VACC_H[i] == 0) & (VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                VD[i]  = VACC_M[i];
            for (i = 0; i < N; i++)
                VD[i] &= -(lo[i] ^ 1);
            for (i = 0; i < N; i++)
                VD[i] |= -(hi[i] ^ 0);
            for (i = 0; i < N; i++)
                VD[i] ^= 0x8000 * (hi[i] | lo[i]);
            return;
        case SM_MUL_Z: /* sign-clamp accumulator-low (bits 15:0) */
            for (i = 0; i < N; i++)
                lo[i]  = (VACC_H[i] < ~0);
            for (i = 0; i < N; i++)
                lo[i] |= (VACC_H[i] < 0) & !(VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                hi[i]  = (VACC_H[i] >  0);
            for (i = 0; i < N; i++)
                hi[i] |= (VACC_H[i] == 0) & (VACC_M[i] < 0);
            for (i = 0; i < N; i++)
                VD[i]  = VACC_L[i];
            for (i = 0; i < N; i++)
                VD[i] &= -(lo[i] ^ 1);
            for (i = 0; i < N; i++)
                VD[i] |= -(hi[i] ^ 0);
            return;
        case SM_MUL_Q: /* possible DCT inverse quantization (VMACQ only) */
            for (i = 0; i < N; i++)
                VD[i]  = (VACC_H[i] << 15) | ((unsigned short)(VACC_M[i]) >> 1);
            message("VMACQ\nClamping unimplemented.", 3);
            for (i = 0; i < N; i++)
                VD[i] &= 0xFFF0;
            return;
        case SM_ADD_A: /* VADD and VSUB */
            message("ADD\nMoved.", 3);
            return;
    }
}

INLINE static void UNSIGNED_CLAMP(short* VD)
{
    short hi[N], lo[N];
    register int i;

    for (i = 0; i < N; i++)
        VD[i] = VACC_M[i];
    for (i = 0; i < N; i++)
        lo[i] = -(VACC_H[i] < 0);
    for (i = 0; i < N; i++)
        hi[i] = -(VACC_M[i] < 0); /* NOTE:  -(VACC_M[i] < 0) ^ lo[i]; */
    for (i = 0; i < N; i++)
        hi[i] = hi[i] | -(VACC_H[i] > 0); /* hi[i] = -(ACC[47..32] > +32767); */
    for (i = 0; i < N; i++)
        VD[i] |=  hi[i];
    for (i = 0; i < N; i++)
        VD[i] &= ~lo[i]; /* in this case, must do AFTER |= hi (See NOTE.) */
    return;
}
#endif
