/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_603
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a6ded7cfcb33e06ade98c5791eae06453f65668
 */

AVVDPAUContext *av_vdpau_alloc_context(void)

{

    return av_mallocz(sizeof(AVVDPAUContext));

}
