/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8851
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=91f4a44ff4fa55e0a48f71c432a1dc3158d662b9
 */

static int packed_16bpc_bswap(SwsContext *c, const uint8_t *src[],

                              int srcStride[], int srcSliceY, int srcSliceH,

                              uint8_t *dst[], int dstStride[])

{

    int i, j, p;



    for (p = 0; p < 4; p++) {

        int srcstr = srcStride[p] >> 1;

        int dststr = dstStride[p] >> 1;

        uint16_t       *dstPtr =       (uint16_t *) dst[p];

        const uint16_t *srcPtr = (const uint16_t *) src[p];

        int min_stride         = FFMIN(srcstr, dststr);

        if(!dstPtr || !srcPtr)

            continue;

        for (i = 0; i < (srcSliceH >> c->chrDstVSubSample); i++) {

            for (j = 0; j < min_stride; j++) {

                dstPtr[j] = av_bswap16(srcPtr[j]);

            }

            srcPtr += srcstr;

            dstPtr += dststr;

        }

    }



    return srcSliceH;

}
