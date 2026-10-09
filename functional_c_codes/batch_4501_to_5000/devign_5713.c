/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5713
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1833e1f96456fd8fc17463246fe0b2050e68efb
 */

static inline void RET_CHG_FLOW (DisasContext *ctx)

{

    ctx->exception = EXCP_MTMSR;

}
