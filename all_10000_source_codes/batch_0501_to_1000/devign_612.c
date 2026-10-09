/* 
 * Benchmark Sample ID : devign_612
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fa2a34cd40d124161c748bb0f430dc63c94dd0da
 */

void avfilter_uninit(void)

{

    memset(registered_avfilters, 0, sizeof(registered_avfilters));

    next_registered_avfilter_idx = 0;

}
