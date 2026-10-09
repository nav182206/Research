/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4997
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15a29c39d9ef15b0783c04b3228e1c55f6701ee3
 */

av_cold void ff_mlpdsp_init(MLPDSPContext *c)

{

    c->mlp_filter_channel = mlp_filter_channel;



    if (ARCH_X86)

        ff_mlpdsp_init_x86(c);

}
