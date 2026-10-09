/* 
 * Benchmark Sample ID : devign_7144
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c9fe0caf7a1abde7ca0b1a359f551103064867b1
 */

static void FUNC(transquant_bypass16x16)(uint8_t *_dst, int16_t *coeffs,

                                         ptrdiff_t stride)

{

    int x, y;

    pixel *dst = (pixel *)_dst;



    stride /= sizeof(pixel);



    for (y = 0; y < 16; y++) {

        for (x = 0; x < 16; x++) {

            dst[x] += *coeffs;

            coeffs++;

        }

        dst += stride;

    }

}
