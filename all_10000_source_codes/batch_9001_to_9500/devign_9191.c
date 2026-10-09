/* 
 * Benchmark Sample ID : devign_9191
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c31b81216619e6b3d986ce63c82357993e10e8e9
 */

static int mszh_decomp(unsigned char * srcptr, int srclen, unsigned char * destptr)

{

    unsigned char *destptr_bak = destptr;

    unsigned char mask = 0;

    unsigned char maskbit = 0;

    unsigned int ofs, cnt;

  

    while (srclen > 0) {

        if (maskbit == 0) {

            mask = *(srcptr++);

            maskbit = 8;

            srclen--;

            continue;

        }

        if ((mask & (1 << (--maskbit))) == 0) {

            *(int*)destptr = *(int*)srcptr;

            srclen -= 4;

            destptr += 4;

            srcptr += 4;

        } else {

            ofs = *(srcptr++);

            cnt = *(srcptr++);

            ofs += cnt * 256;;

            cnt = ((cnt >> 3) & 0x1f) + 1;

            ofs &= 0x7ff;

            srclen -= 2;

            cnt *= 4;

            for (; cnt > 0; cnt--) {

                *(destptr) = *(destptr - ofs);

                destptr++;

            }

        }

    }



    return (destptr - destptr_bak);

}
