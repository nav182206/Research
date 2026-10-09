/* 
 * Benchmark Sample ID : devign_1262
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b227a8e9aa5f27d29f77ba90d5eb9d0662a1175e
 */

static int find_pte32 (mmu_ctx_t *ctx, int h, int rw)

{

    return _find_pte(ctx, 0, h, rw);

}
