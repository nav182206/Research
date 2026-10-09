/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7657
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9425dc3dba0bd1209aa7a788ea8f3c194fc7c7c5
 */

static void float_to_int16_stride_altivec(int16_t *dst, const float *src,

                                          long len, int stride)

{

    int i, j;

    vector signed short d, s;



    for (i = 0; i < len - 7; i += 8) {

        d = float_to_int16_one_altivec(src + i);

        for (j = 0; j < 8; j++) {

            s = vec_splat(d, j);

            vec_ste(s, 0, dst);

            dst += stride;

        }

    }

}
