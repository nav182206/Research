/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9238
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4b0e0f31bf0f618a634dcfdca45e72cdfb0b48b5
 */

av_cold void ff_lpc_end(LPCContext *s)

{

    av_freep(&s->windowed_samples);

}
