/* 
 * Benchmark Sample ID : devign_2405
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=29638d4db90d5e3fc107c1beb40808f53cc7acaa
 */

static void filter1(int32_t *dst, const int32_t *src, int32_t coeff, ptrdiff_t len)

{

    int i;



    for (i = 0; i < len; i++)

        dst[i] -= mul23(src[i], coeff);

}
