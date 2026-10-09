/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4789
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b8664c929437d6d079e16979c496a2db40cf2324
 */

av_cold void ff_vp8dsp_init_arm(VP8DSPContext *dsp)

{

    int cpu_flags = av_get_cpu_flags();



    if (have_armv6(cpu_flags))

        ff_vp8dsp_init_armv6(dsp);

    if (have_neon(cpu_flags))

        ff_vp8dsp_init_neon(dsp);

}
