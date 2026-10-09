/* 
 * Benchmark Sample ID : devign_7104
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e0c6cce44729d94e2a5507a4b6d031f23e8bd7b6
 */

void ff_float_dsp_init_x86(AVFloatDSPContext *fdsp)

{

#if HAVE_YASM

    int mm_flags = av_get_cpu_flags();



    if (mm_flags & AV_CPU_FLAG_SSE && HAVE_SSE) {

        fdsp->vector_fmul = ff_vector_fmul_sse;

        fdsp->vector_fmac_scalar = ff_vector_fmac_scalar_sse;

    }

    if (mm_flags & AV_CPU_FLAG_AVX && HAVE_AVX) {

        fdsp->vector_fmul = ff_vector_fmul_avx;

        fdsp->vector_fmac_scalar = ff_vector_fmac_scalar_avx;

    }

#endif

}
