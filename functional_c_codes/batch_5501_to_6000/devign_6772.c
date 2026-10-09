/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6772
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3ab9a2a5577d445252724af4067d2a7c8a378efa
 */

static void rv40_v_strong_loop_filter(uint8_t *src, const int stride,

                                      const int alpha, const int lims,

                                      const int dmode, const int chroma)

{

    rv40_strong_loop_filter(src, 1, stride, alpha, lims, dmode, chroma);

}
