/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1350
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e2710e790c09e49e86baa58c6063af0097cc8cb0
 */

av_cold void ff_fmt_convert_init_arm(FmtConvertContext *c, AVCodecContext *avctx)

{

    int cpu_flags = av_get_cpu_flags();



    if (have_vfp(cpu_flags)) {

        if (!have_vfpv3(cpu_flags)) {

            c->int32_to_float_fmul_scalar = ff_int32_to_float_fmul_scalar_vfp;

            c->int32_to_float_fmul_array8 = ff_int32_to_float_fmul_array8_vfp;

        }

    }



    if (have_neon(cpu_flags)) {

        c->int32_to_float_fmul_scalar = ff_int32_to_float_fmul_scalar_neon;

    }

}
