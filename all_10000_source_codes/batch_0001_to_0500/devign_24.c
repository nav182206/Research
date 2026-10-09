/* 
 * Benchmark Sample ID : devign_24
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f61bece684d9685b07895508e6c1c733b5564ccf
 */

av_cold void ff_float_dsp_init_ppc(AVFloatDSPContext *fdsp, int bit_exact)

{

#if HAVE_ALTIVEC

    if (!(av_get_cpu_flags() & AV_CPU_FLAG_ALTIVEC))

        return;



    fdsp->vector_fmul = ff_vector_fmul_altivec;

    fdsp->vector_fmul_add = ff_vector_fmul_add_altivec;

    fdsp->vector_fmul_reverse = ff_vector_fmul_reverse_altivec;



    if (!bit_exact) {

        fdsp->vector_fmul_window = ff_vector_fmul_window_altivec;

    }

#endif

}
