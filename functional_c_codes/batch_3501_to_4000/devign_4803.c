/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4803
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2254b559cbcfc0418135f09add37c0a5866b1981
 */

static void hScale16To19_c(SwsContext *c, int16_t *_dst, int dstW, const uint8_t *_src,

                           const int16_t *filter,

                           const int16_t *filterPos, int filterSize)

{

    int i;

    int32_t *dst = (int32_t *) _dst;

    const uint16_t *src = (const uint16_t *) _src;

    int bits = av_pix_fmt_descriptors[c->srcFormat].comp[0].depth_minus1;

    int sh = bits - 4;



    for (i = 0; i < dstW; i++) {

        int j;

        int srcPos = filterPos[i];

        int val = 0;



        for (j = 0; j < filterSize; j++) {

            val += src[srcPos + j] * filter[filterSize * i + j];

        }

        // filter=14 bit, input=16 bit, output=30 bit, >> 11 makes 19 bit

        dst[i] = FFMIN(val >> sh, (1 << 19) - 1);

    }

}
