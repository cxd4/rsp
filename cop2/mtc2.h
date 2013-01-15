/* to-do:  Try to optimize to using accurate, 16-bit single-hit writes. */

void MTC2(int rt, int vd, int element)
{
    VR[vd].b[element ^ 01] = (unsigned short)SR[rt] >> 8;
    ++element;
    if (element == 16)
    {
        message("MTC2\nTried to wrap around VR segment.", 1);
        return;
    }
    VR[vd].b[element ^ 01] = (unsigned char)SR[rt];
    return;
}
