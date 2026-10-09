/* 
 * Benchmark Sample ID : devign_2028
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a246d06fe0dc6c2ea65e95327624b4537ff9bd0d
 */

static void FUNC(transquant_bypass8x8)(uint8_t *_dst, int16_t *coeffs,

                                       ptrdiff_t stride)

{

    int x, y;

    pixel *dst = (pixel *)_dst;



    stride /= sizeof(pixel);



    for (y = 0; y < 8; y++) {

        for (x = 0; x < 8; x++) {

            dst[x] += *coeffs;

            coeffs++;

        }

        dst += stride;

    }

}
