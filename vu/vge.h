#include "vu.h"

void VGE(int vd, int vs, int vt, int element)
{
    VCF[01] = 0x0000;
    switch (element)
    {
        case 0x0: /* none:  { 00, 01, 02, 03, 04, 05, 06, 07 } */
        case 0x1:
            if (VR[vs].s[00] < VR[vt].s[00]) {
                VACC[00].w[LO] = VR[vt].s[00];
                goto ITERATION_none_A1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[00])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_none_A1;
/* to-do:  OR, `if ((VCF[00] | 0x0101) == VCF[00])`, but no solution for XOR.
 * One of these is probably faster since AND uses an imm while OR uses a reg.
 * However in most cases it is probably not that important, since this if()
 * check is rarely reached unless games were deliberately designed for this!
 */
            VCF[01] |= 0x0001;
ITERATION_none_A1:
            if (VR[vs].s[01] < VR[vt].s[01]) {
                VACC[01].w[LO] = VR[vt].s[01];
                goto ITERATION_none_A2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[01])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_none_A2;
            VCF[01] |= 0x0002;
ITERATION_none_A2:
            if (VR[vs].s[02] < VR[vt].s[02]) {
                VACC[02].w[LO] = VR[vt].s[02];
                goto ITERATION_none_A3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[02])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_none_A3;
            VCF[01] |= 0x0004;
ITERATION_none_A3:
            if (VR[vs].s[03] < VR[vt].s[03]) {
                VACC[03].w[LO] = VR[vt].s[03];
                goto ITERATION_none_A4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[03])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_none_A4;
            VCF[01] |= 0x0008;
ITERATION_none_A4:
            if (VR[vs].s[04] < VR[vt].s[04]) {
                VACC[04].w[LO] = VR[vt].s[04];
                goto ITERATION_none_A5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[04])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_none_A5;
            VCF[01] |= 0x0010;
ITERATION_none_A5:
            if (VR[vs].s[05] < VR[vt].s[05]) {
                VACC[05].w[LO] = VR[vt].s[05];
                goto ITERATION_none_A6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[05])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_none_A6;
            VCF[01] |= 0x0020;
ITERATION_none_A6:
            if (VR[vs].s[06] < VR[vt].s[06]) {
                VACC[06].w[LO] = VR[vt].s[06];
                goto ITERATION_none_A7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[06])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_none_A7;
            VCF[01] |= 0x0040;
ITERATION_none_A7:
            if (VR[vs].s[07] < VR[vt].s[07]) {
                VACC[07].w[LO] = VR[vt].s[07];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[07])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x2: /* 0Q:  { 00, 00, 02, 02, 04, 04, 06, 06 } */
            if (VR[vs].s[00] < VR[vt].s[00]) {
                VACC[00].w[LO] = VR[vt].s[00];
                goto ITERATION_0Q_B1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[00])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_0Q_B1;
            VCF[01] |= 0x0001;
ITERATION_0Q_B1:
            if (VR[vs].s[01] < VR[vt].s[00]) {
                VACC[01].w[LO] = VR[vt].s[00];
                goto ITERATION_0Q_B2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[00])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_0Q_B2;
            VCF[01] |= 0x0002;
ITERATION_0Q_B2:
            if (VR[vs].s[02] < VR[vt].s[02]) {
                VACC[02].w[LO] = VR[vt].s[02];
                goto ITERATION_0Q_B3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[02])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_0Q_B3;
            VCF[01] |= 0x0004;
ITERATION_0Q_B3:
            if (VR[vs].s[03] < VR[vt].s[02]) {
                VACC[03].w[LO] = VR[vt].s[02];
                goto ITERATION_0Q_B4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[02])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_0Q_B4;
            VCF[01] |= 0x0008;
ITERATION_0Q_B4:
            if (VR[vs].s[04] < VR[vt].s[04]) {
                VACC[04].w[LO] = VR[vt].s[04];
                goto ITERATION_0Q_B5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[04])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_0Q_B5;
            VCF[01] |= 0x0010;
ITERATION_0Q_B5:
            if (VR[vs].s[05] < VR[vt].s[04]) {
                VACC[05].w[LO] = VR[vt].s[04];
                goto ITERATION_0Q_B6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[04])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_0Q_B6;
            VCF[01] |= 0x0020;
ITERATION_0Q_B6:
            if (VR[vs].s[06] < VR[vt].s[06]) {
                VACC[06].w[LO] = VR[vt].s[06];
                goto ITERATION_0Q_B7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[06])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_0Q_B7;
            VCF[01] |= 0x0040;
ITERATION_0Q_B7:
            if (VR[vs].s[07] < VR[vt].s[06]) {
                VACC[07].w[LO] = VR[vt].s[06];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[06])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x3: /* 1Q:  { 01, 01, 03, 03, 05, 05, 07, 07 } */
            if (VR[vs].s[00] < VR[vt].s[01]) {
                VACC[00].w[LO] = VR[vt].s[01];
                goto ITERATION_1Q_C1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[01])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_1Q_C1;
            VCF[01] |= 0x0001;
ITERATION_1Q_C1:
            if (VR[vs].s[01] < VR[vt].s[01]) {
                VACC[01].w[LO] = VR[vt].s[01];
                goto ITERATION_1Q_C2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[01])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_1Q_C2;
            VCF[01] |= 0x0002;
ITERATION_1Q_C2:
            if (VR[vs].s[02] < VR[vt].s[03]) {
                VACC[02].w[LO] = VR[vt].s[03];
                goto ITERATION_1Q_C3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[03])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_1Q_C3;
            VCF[01] |= 0x0004;
ITERATION_1Q_C3:
            if (VR[vs].s[03] < VR[vt].s[03]) {
                VACC[03].w[LO] = VR[vt].s[03];
                goto ITERATION_1Q_C4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[03])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_1Q_C4;
            VCF[01] |= 0x0008;
ITERATION_1Q_C4:
            if (VR[vs].s[04] < VR[vt].s[05]) {
                VACC[04].w[LO] = VR[vt].s[05];
                goto ITERATION_1Q_C5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[05])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_1Q_C5;
            VCF[01] |= 0x0010;
ITERATION_1Q_C5:
            if (VR[vs].s[05] < VR[vt].s[05]) {
                VACC[05].w[LO] = VR[vt].s[05];
                goto ITERATION_1Q_C6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[05])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_1Q_C6;
            VCF[01] |= 0x0020;
ITERATION_1Q_C6:
            if (VR[vs].s[06] < VR[vt].s[07]) {
                VACC[06].w[LO] = VR[vt].s[07];
                goto ITERATION_1Q_C7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[07])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_1Q_C7;
            VCF[01] |= 0x0040;
ITERATION_1Q_C7:
            if (VR[vs].s[07] < VR[vt].s[07]) {
                VACC[07].w[LO] = VR[vt].s[07];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[07])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x4: /* 0H:  { 00, 00, 00, 00, 04, 04, 04, 04 } */
            if (VR[vs].s[00] < VR[vt].s[00]) {
                VACC[00].w[LO] = VR[vt].s[00];
                goto ITERATION_0H_D1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[00])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_0H_D1;
            VCF[01] |= 0x0001;
ITERATION_0H_D1:
            if (VR[vs].s[01] < VR[vt].s[00]) {
                VACC[01].w[LO] = VR[vt].s[00];
                goto ITERATION_0H_D2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[00])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_0H_D2;
            VCF[01] |= 0x0002;
ITERATION_0H_D2:
            if (VR[vs].s[02] < VR[vt].s[00]) {
                VACC[02].w[LO] = VR[vt].s[00];
                goto ITERATION_0H_D3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[00])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_0H_D3;
            VCF[01] |= 0x0004;
ITERATION_0H_D3:
            if (VR[vs].s[03] < VR[vt].s[00]) {
                VACC[03].w[LO] = VR[vt].s[00];
                goto ITERATION_0H_D4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[00])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_0H_D4;
            VCF[01] |= 0x0008;
ITERATION_0H_D4:
            if (VR[vs].s[04] < VR[vt].s[04]) {
                VACC[04].w[LO] = VR[vt].s[04];
                goto ITERATION_0H_D5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[04])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_0H_D5;
            VCF[01] |= 0x0010;
ITERATION_0H_D5:
            if (VR[vs].s[05] < VR[vt].s[04]) {
                VACC[05].w[LO] = VR[vt].s[04];
                goto ITERATION_0H_D6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[04])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_0H_D6;
            VCF[01] |= 0x0020;
ITERATION_0H_D6:
            if (VR[vs].s[06] < VR[vt].s[04]) {
                VACC[06].w[LO] = VR[vt].s[04];
                goto ITERATION_0H_D7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[04])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_0H_D7;
            VCF[01] |= 0x0040;
ITERATION_0H_D7:
            if (VR[vs].s[07] < VR[vt].s[04]) {
                VACC[07].w[LO] = VR[vt].s[04];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[04])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x5: /* 1H:  { 01, 01, 01, 01, 05, 05, 05, 05 } */
            if (VR[vs].s[00] < VR[vt].s[01]) {
                VACC[00].w[LO] = VR[vt].s[01];
                goto ITERATION_1H_E1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[01])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_1H_E1;
            VCF[01] |= 0x0001;
ITERATION_1H_E1:
            if (VR[vs].s[01] < VR[vt].s[01]) {
                VACC[01].w[LO] = VR[vt].s[01];
                goto ITERATION_1H_E2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[01])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_1H_E2;
            VCF[01] |= 0x0002;
ITERATION_1H_E2:
            if (VR[vs].s[02] < VR[vt].s[01]) {
                VACC[02].w[LO] = VR[vt].s[01];
                goto ITERATION_1H_E3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[01])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_1H_E3;
            VCF[01] |= 0x0004;
ITERATION_1H_E3:
            if (VR[vs].s[03] < VR[vt].s[01]) {
                VACC[03].w[LO] = VR[vt].s[01];
                goto ITERATION_1H_E4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[01])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_1H_E4;
            VCF[01] |= 0x0008;
ITERATION_1H_E4:
            if (VR[vs].s[04] < VR[vt].s[05]) {
                VACC[04].w[LO] = VR[vt].s[05];
                goto ITERATION_1H_E5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[05])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_1H_E5;
            VCF[01] |= 0x0010;
ITERATION_1H_E5:
            if (VR[vs].s[05] < VR[vt].s[05]) {
                VACC[05].w[LO] = VR[vt].s[05];
                goto ITERATION_1H_E6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[05])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_1H_E6;
            VCF[01] |= 0x0020;
ITERATION_1H_E6:
            if (VR[vs].s[06] < VR[vt].s[05]) {
                VACC[06].w[LO] = VR[vt].s[05];
                goto ITERATION_1H_E7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[05])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_1H_E7;
            VCF[01] |= 0x0040;
ITERATION_1H_E7:
            if (VR[vs].s[07] < VR[vt].s[05]) {
                VACC[07].w[LO] = VR[vt].s[05];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[05])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x6: /* 2H:  { 02, 02, 02, 02, 06, 06, 06, 06 } */
            if (VR[vs].s[00] < VR[vt].s[02]) {
                VACC[00].w[LO] = VR[vt].s[02];
                goto ITERATION_2H_F1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[02])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_2H_F1;
            VCF[01] |= 0x0001;
ITERATION_2H_F1:
            if (VR[vs].s[01] < VR[vt].s[02]) {
                VACC[01].w[LO] = VR[vt].s[02];
                goto ITERATION_2H_F2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[02])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_2H_F2;
            VCF[01] |= 0x0002;
ITERATION_2H_F2:
            if (VR[vs].s[02] < VR[vt].s[02]) {
                VACC[02].w[LO] = VR[vt].s[02];
                goto ITERATION_2H_F3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[02])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_2H_F3;
            VCF[01] |= 0x0004;
ITERATION_2H_F3:
            if (VR[vs].s[03] < VR[vt].s[02]) {
                VACC[03].w[LO] = VR[vt].s[02];
                goto ITERATION_2H_F4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[02])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_2H_F4;
            VCF[01] |= 0x0008;
ITERATION_2H_F4:
            if (VR[vs].s[04] < VR[vt].s[06]) {
                VACC[04].w[LO] = VR[vt].s[06];
                goto ITERATION_2H_F5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[06])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_2H_F5;
            VCF[01] |= 0x0010;
ITERATION_2H_F5:
            if (VR[vs].s[05] < VR[vt].s[06]) {
                VACC[05].w[LO] = VR[vt].s[06];
                goto ITERATION_2H_F6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[06])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_2H_F6;
            VCF[01] |= 0x0020;
ITERATION_2H_F6:
            if (VR[vs].s[06] < VR[vt].s[06]) {
                VACC[06].w[LO] = VR[vt].s[06];
                goto ITERATION_2H_F7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[06])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_2H_F7;
            VCF[01] |= 0x0040;
ITERATION_2H_F7:
            if (VR[vs].s[07] < VR[vt].s[06]) {
                VACC[07].w[LO] = VR[vt].s[06];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[06])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x7: /* 3H:  { 03, 03, 03, 03, 07, 07, 07, 07 } */
            if (VR[vs].s[00] < VR[vt].s[03]) {
                VACC[00].w[LO] = VR[vt].s[03];
                goto ITERATION_3H_G1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == VR[vt].s[03])
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_3H_G1;
            VCF[01] |= 0x0001;
ITERATION_3H_G1:
            if (VR[vs].s[01] < VR[vt].s[03]) {
                VACC[01].w[LO] = VR[vt].s[03];
                goto ITERATION_3H_G2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == VR[vt].s[03])
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_3H_G2;
            VCF[01] |= 0x0002;
ITERATION_3H_G2:
            if (VR[vs].s[02] < VR[vt].s[03]) {
                VACC[02].w[LO] = VR[vt].s[03];
                goto ITERATION_3H_G3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == VR[vt].s[03])
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_3H_G3;
            VCF[01] |= 0x0004;
ITERATION_3H_G3:
            if (VR[vs].s[03] < VR[vt].s[03]) {
                VACC[03].w[LO] = VR[vt].s[03];
                goto ITERATION_3H_G4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == VR[vt].s[03])
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_3H_G4;
            VCF[01] |= 0x0008;
ITERATION_3H_G4:
            if (VR[vs].s[04] < VR[vt].s[07]) {
                VACC[04].w[LO] = VR[vt].s[07];
                goto ITERATION_3H_G5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == VR[vt].s[07])
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_3H_G5;
            VCF[01] |= 0x0010;
ITERATION_3H_G5:
            if (VR[vs].s[05] < VR[vt].s[07]) {
                VACC[05].w[LO] = VR[vt].s[07];
                goto ITERATION_3H_G6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == VR[vt].s[07])
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_3H_G6;
            VCF[01] |= 0x0020;
ITERATION_3H_G6:
            if (VR[vs].s[06] < VR[vt].s[07]) {
                VACC[06].w[LO] = VR[vt].s[07];
                goto ITERATION_3H_G7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == VR[vt].s[07])
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_3H_G7;
            VCF[01] |= 0x0040;
ITERATION_3H_G7:
            if (VR[vs].s[07] < VR[vt].s[07]) {
                VACC[07].w[LO] = VR[vt].s[07];
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == VR[vt].s[07])
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        case 0x8: /* 0:  { 00, 00, 00, 00, 00, 00, 00, 00 } */
        case 0x9: /* 1:  { 01, 01, 01, 01, 01, 01, 01, 01 } */
        case 0xA: /* 2:  { 02, 02, 02, 02, 02, 02, 02, 02 } */
        case 0xB: /* 3:  { 03, 03, 03, 03, 03, 03, 03, 03 } */
        case 0xC: /* 4:  { 04, 04, 04, 04, 04, 04, 04, 04 } */
        case 0xD: /* 5:  { 05, 05, 05, 05, 05, 05, 05, 05 } */
        case 0xE: /* 6:  { 06, 06, 06, 06, 06, 06, 06, 06 } */
        case 0xF: /* 7:  { 07, 07, 07, 07, 07, 07, 07, 07 } */{
            register short source = VR[vt].s[element & 07];
            if (VR[vs].s[00] < source) {
                VACC[00].w[LO] = source;
                goto ITERATION_I_H1;
            }
            VACC[00].w[LO] = VR[vs].s[00];
            if (VR[vs].s[00] == source)
                if ((VCF[00] & 0x0101) == 0x0101) goto ITERATION_I_H1;
            VCF[01] |= 0x0001;
ITERATION_I_H1:
            if (VR[vs].s[01] < source) {
                VACC[01].w[LO] = source;
                goto ITERATION_I_H2;
            }
            VACC[01].w[LO] = VR[vs].s[01];
            if (VR[vs].s[01] == source)
                if ((VCF[00] & 0x0202) == 0x0202) goto ITERATION_I_H2;
            VCF[01] |= 0x0002;
ITERATION_I_H2:
            if (VR[vs].s[02] < source) {
                VACC[02].w[LO] = source;
                goto ITERATION_I_H3;
            }
            VACC[02].w[LO] = VR[vs].s[02];
            if (VR[vs].s[02] == source)
                if ((VCF[00] & 0x0404) == 0x0404) goto ITERATION_I_H3;
            VCF[01] |= 0x0004;
ITERATION_I_H3:
            if (VR[vs].s[03] < source) {
                VACC[03].w[LO] = source;
                goto ITERATION_I_H4;
            }
            VACC[03].w[LO] = VR[vs].s[03];
            if (VR[vs].s[03] == source)
                if ((VCF[00] & 0x0808) == 0x0808) goto ITERATION_I_H4;
            VCF[01] |= 0x0008;
ITERATION_I_H4:
            if (VR[vs].s[04] < source) {
                VACC[04].w[LO] = source;
                goto ITERATION_I_H5;
            }
            VACC[04].w[LO] = VR[vs].s[04];
            if (VR[vs].s[04] == source)
                if ((VCF[00] & 0x1010) == 0x1010) goto ITERATION_I_H5;
            VCF[01] |= 0x0010;
ITERATION_I_H5:
            if (VR[vs].s[05] < source) {
                VACC[05].w[LO] = source;
                goto ITERATION_I_H6;
            }
            VACC[05].w[LO] = VR[vs].s[05];
            if (VR[vs].s[05] == source)
                if ((VCF[00] & 0x2020) == 0x2020) goto ITERATION_I_H6;
            VCF[01] |= 0x0020;
ITERATION_I_H6:
            if (VR[vs].s[06] < source) {
                VACC[06].w[LO] = source;
                goto ITERATION_I_H7;
            }
            VACC[06].w[LO] = VR[vs].s[06];
            if (VR[vs].s[06] == source)
                if ((VCF[00] & 0x4040) == 0x4040) goto ITERATION_I_H7;
            VCF[01] |= 0x0040;
ITERATION_I_H7:
            if (VR[vs].s[07] < source) {
                VACC[07].w[LO] = source;
                goto MOV_FILE_VACC_TO_VR;
            }
            VACC[07].w[LO] = VR[vs].s[07];
            if (VR[vs].s[07] == source)
                if ((VCF[00] & 0x8080) == 0x8080) goto MOV_FILE_VACC_TO_VR;
            VCF[01] |= 0x0080;
            goto MOV_FILE_VACC_TO_VR;
        }
    }
MOV_FILE_VACC_TO_VR:
    VR[vd].s[00] = VACC[00].w[01];
    VR[vd].s[01] = VACC[01].w[01];
    VR[vd].s[02] = VACC[02].w[01];
    VR[vd].s[03] = VACC[03].w[01];
    VR[vd].s[04] = VACC[04].w[01];
    VR[vd].s[05] = VACC[05].w[01];
    VR[vd].s[06] = VACC[06].w[01];
    VR[vd].s[07] = VACC[07].w[01];
    VCF[00] = 0x0000;
    return;
}
