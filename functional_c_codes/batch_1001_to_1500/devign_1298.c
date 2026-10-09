/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1298
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0181b202cc42133eacd74bad33745cf1ba699e6b
 */

static void ps_add_squares_c(INTFLOAT *dst, const INTFLOAT (*src)[2], int n)

{

    int i;

    for (i = 0; i < n; i++)

        dst[i] += AAC_MADD28(src[i][0], src[i][0], src[i][1], src[i][1]);

}
