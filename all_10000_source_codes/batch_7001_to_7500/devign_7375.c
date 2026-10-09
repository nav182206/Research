/* 
 * Benchmark Sample ID : devign_7375
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e9bb5aa3ed0b56c484ba96bf1bb3bdd8a9741f3
 */

static int packed_16bpc_bswap(SwsContext *c, const uint8_t *src[],

                              int srcStride[], int srcSliceY, int srcSliceH,

                              uint8_t *dst[], int dstStride[])

{

    int i, j;

    int srcstr = srcStride[0] >> 1;

    int dststr = dstStride[0] >> 1;

    uint16_t       *dstPtr =       (uint16_t *) dst[0];

    const uint16_t *srcPtr = (const uint16_t *) src[0];



    for (i = 0; i < srcSliceH; i++) {

        for (j = 0; j < srcstr; j++) {

            dstPtr[j] = av_bswap16(srcPtr[j]);

        }

        srcPtr += srcstr;

        dstPtr += dststr;

    }



    return srcSliceH;

}
