/* 
 * Benchmark Sample ID : devign_9081
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=faadf50e2962dd54175647a80bd6fc4319c91973
 */

target_phys_addr_t cpu_get_phys_page_debug (CPUState *env, target_ulong addr)

{

    mmu_ctx_t ctx;



    if (unlikely(get_physical_address(env, &ctx, addr, 0, ACCESS_INT, 1) != 0))

        return -1;



    return ctx.raddr & TARGET_PAGE_MASK;

}
