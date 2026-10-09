/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2385
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4cb6964244fd6c099383d8b7e99731e72cc844b9
 */

static inline void int8x8_fmul_int32(DCADSPContext *dsp, float *dst,

                                     const int8_t *src, int scale)

{

    dsp->int8x8_fmul_int32(dst, src, scale);

}
