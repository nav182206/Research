/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5027
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e90e1f558a194ef75e396ac9ae5128be03e66362
 */

av_cold void ff_ps_ctx_init(PSContext *ps)

{

    ipdopd_reset(ps->ipd_hist, ps->opd_hist);

}
