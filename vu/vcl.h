#include "vu.h"

static void VCL(int vd, int vs, int vt, int element)
{
    int ge, le;
    register int i;
	
    if (element == 0x0) /* if (element >> 1 == 00) */
        for (i = 0; i < 8; i++)
        {
            const int j = i;
            const unsigned short VS = (unsigned short)VR[vs].s[i];
            const unsigned short VT = (unsigned short)VR[vt].s[j];
            const int eq = (((VCO >> (i + 8)) & 1) == 0); /* !(NOTEQUAL) */

            if ((VCO >> i) & 1)
            {
                ge = (VCC >> (i + 8)) & 1;
                if (eq)
                {
                    const int sum = VS + VT;
                    int ce = (VCE >> i) & 1;
                    int lz = ((sum & 0x0000FFFF) == 0x00000000);
                    int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                    le = (ce & (lz | uz)) | (!ce & (lz & uz));
                }
                else
                    le = (VCC >> i) & 1;
                VACC[i].s[LO] = le ? -VT : VS;
            }
            else
            {
                le = (VCC >> i) & 1;
                if (eq)
                    ge = (VS - VT >= 0);
                else
                    ge = (VCC >> (i + 8)) & 1;
                VACC[i].s[LO] = ge ? VT : VS;
            }
            VCC &= ~(0x0101 << i);
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
    else if ((element & 0xE) == 02) /* scalar quarter */
        for (i = 0; i < 8; i++)
        {
            const int j = (i & 0xE) | (element & 01);
            const unsigned short VS = (unsigned short)VR[vs].s[i];
            const unsigned short VT = (unsigned short)VR[vt].s[j];
            const int eq = (((VCO >> (i + 8)) & 1) == 0); /* !(NOTEQUAL) */

            if ((VCO >> i) & 1)
            {
                ge = (VCC >> (i + 8)) & 1;
                if (eq)
                {
                    const int sum = VS + VT;
                    int ce = (VCE >> i) & 1;
                    int lz = ((sum & 0x0000FFFF) == 0x00000000);
                    int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                    le = (ce & (lz | uz)) | (!ce & (lz & uz));
                }
                else
                    le = (VCC >> i) & 1;
                VACC[i].s[LO] = le ? -VT : VS;
            }
            else
            {
                le = (VCC >> i) & 1;
                if (eq)
                    ge = (VS - VT >= 0);
                else
                    ge = (VCC >> (i + 8)) & 1;
                VACC[i].s[LO] = ge ? VT : VS;
            }
            VCC &= ~(0x0101 << i);
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
    else if ((element & 0xC) == 04) /* scalar half */
        for (i = 0; i < 8; i++)
        {
            const int j = (i & 0xC) | (element & 03);
            const unsigned short VS = (unsigned short)VR[vs].s[i];
            const unsigned short VT = (unsigned short)VR[vt].s[j];
            const int eq = (((VCO >> (i + 8)) & 1) == 0); /* !(NOTEQUAL) */

            if ((VCO >> i) & 1)
            {
                ge = (VCC >> (i + 8)) & 1;
                if (eq)
                {
                    const int sum = VS + VT;
                    int ce = (VCE >> i) & 1;
                    int lz = ((sum & 0x0000FFFF) == 0x00000000);
                    int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                    le = (ce & (lz | uz)) | (!ce & (lz & uz));
                }
                else
                    le = (VCC >> i) & 1;
                VACC[i].s[LO] = le ? -VT : VS;
            }
            else
            {
                le = (VCC >> i) & 1;
                if (eq)
                    ge = (VS - VT >= 0);
                else
                    ge = (VCC >> (i + 8)) & 1;
                VACC[i].s[LO] = ge ? VT : VS;
            }
            VCC &= ~(0x0101 << i);
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
    else /* if ((element & 0b1000) == 0b1000) /* scalar whole */
        for (i = 0; i < 8; i++)
        {
            const int j = element & 07;
            const unsigned short VS = (unsigned short)VR[vs].s[i];
            const unsigned short VT = (unsigned short)VR[vt].s[j];
            const int eq = (((VCO >> (i + 8)) & 1) == 0); /* !(NOTEQUAL) */

            if ((VCO >> i) & 1)
            {
                ge = (VCC >> (i + 8)) & 1;
                if (eq)
                {
                    const int sum = VS + VT;
                    int ce = (VCE >> i) & 1;
                    int lz = ((sum & 0x0000FFFF) == 0x00000000);
                    int uz = ((sum & 0xFFFF0000) == 0x00000000); /* !carryout */

                    le = (ce & (lz | uz)) | (!ce & (lz & uz));
                }
                else
                    le = (VCC >> i) & 1;
                VACC[i].s[LO] = le ? -VT : VS;
            }
            else
            {
                le = (VCC >> i) & 1;
                if (eq)
                    ge = (VS - VT >= 0);
                else
                    ge = (VCC >> (i + 8)) & 1;
                VACC[i].s[LO] = ge ? VT : VS;
            }
            VCC &= ~(0x0101 << i);
            VCC |= (ge << (i + 8)) | (le << (i + 0));
        }
    for (i = 0; i < 8; i++)
        VR[vd].s[i] = VACC[i].s[LO];
    VCO = 0x0000;
    VCE = 0x00;
    return;
}
