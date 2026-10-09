/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2241
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=79997def65fd2313b48a5f3c3a884c6149ae9b5d
 */

static void mdct512(AC3MDCTContext *mdct, float *out, float *in)

{

    mdct->fft.mdct_calc(&mdct->fft, out, in);

}
