/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_493
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b227a8e9aa5f27d29f77ba90d5eb9d0662a1175e
 */

static int pte64_check (mmu_ctx_t *ctx,

                        target_ulong pte0, target_ulong pte1, int h, int rw)

{

    return _pte_check(ctx, 1, pte0, pte1, h, rw);

}
