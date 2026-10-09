/* 
 * Benchmark Sample ID : devign_3246
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d68c05380cebf563915412182643a8be04ef890b
 */

av_cold void ff_dither_init_x86(DitherDSPContext *ddsp,

                                enum AVResampleDitherMethod method)

{

    int cpu_flags = av_get_cpu_flags();



    if (EXTERNAL_SSE2(cpu_flags)) {

        ddsp->quantize      = ff_quantize_sse2;

        ddsp->ptr_align     = 16;

        ddsp->samples_align = 8;

    }



    if (method == AV_RESAMPLE_DITHER_RECTANGULAR) {

        if (EXTERNAL_SSE2(cpu_flags)) {

            ddsp->dither_int_to_float = ff_dither_int_to_float_rectangular_sse2;

        }

        if (EXTERNAL_AVX(cpu_flags)) {

            ddsp->dither_int_to_float = ff_dither_int_to_float_rectangular_avx;

        }

    } else {

        if (EXTERNAL_SSE2(cpu_flags)) {

            ddsp->dither_int_to_float = ff_dither_int_to_float_triangular_sse2;

        }

        if (EXTERNAL_AVX(cpu_flags)) {

            ddsp->dither_int_to_float = ff_dither_int_to_float_triangular_avx;

        }

    }

}
