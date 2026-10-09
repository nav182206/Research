/* 
 * Benchmark Sample ID : devign_928
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12de9a396acbc95e25c5d60ed097cc55777eaaed
 */

static inline int find_pte (CPUState *env, mmu_ctx_t *ctx, int h, int rw)

{

#if defined(TARGET_PPC64)

    if (env->mmu_model == POWERPC_MMU_64B ||

        env->mmu_model == POWERPC_MMU_64BRIDGE)

        return find_pte64(ctx, h, rw);

#endif



    return find_pte32(ctx, h, rw);

}
