/* 
 * Benchmark Sample ID : devign_1241
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2254b559cbcfc0418135f09add37c0a5866b1981
 */

static void hScale8To19_c(SwsContext *c, int16_t *_dst, int dstW, const uint8_t *src,

                          const int16_t *filter, const int16_t *filterPos,

                          int filterSize)

{

    int i;

    int32_t *dst = (int32_t *) _dst;

    for (i=0; i<dstW; i++) {

        int j;

        int srcPos= filterPos[i];

        int val=0;

        for (j=0; j<filterSize; j++) {

            val += ((int)src[srcPos + j])*filter[filterSize*i + j];

        }

        //filter += hFilterSize;

        dst[i] = FFMIN(val>>3, (1<<19)-1); // the cubic equation does overflow ...

        //dst[i] = val>>7;

    }

}
