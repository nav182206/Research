/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7732
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad2296ab3a131d3560c385e43437841987166804
 */

static av_always_inline SoftFloat autocorr_calc(int64_t accu)

{

        int nz, mant, expo, round;

        int i = (int)(accu >> 32);

        if (i == 0) {

            nz = 1;

        } else {

            nz = 0;

            while (FFABS(i) < 0x40000000) {

                i <<= 1;

                nz++;

            }

            nz = 32-nz;

        }



        round = 1 << (nz-1);

        mant = (int)((accu + round) >> nz);

        mant = (mant + 0x40)>>7;

        mant <<= 6;

        expo = nz + 15;

        return av_int2sf(mant, 30 - expo);

}
