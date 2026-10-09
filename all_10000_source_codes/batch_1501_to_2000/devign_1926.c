/* 
 * Benchmark Sample ID : devign_1926
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=89135716fd4c2963e01e0155547c47bf709f1aa3
 */

av_cold void ff_mlpdsp_init_arm(MLPDSPContext *c)

{

    int cpu_flags = av_get_cpu_flags();



    if (have_armv5te(cpu_flags)) {

        c->mlp_filter_channel = ff_mlp_filter_channel_arm;


    }

}
