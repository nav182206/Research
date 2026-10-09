/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1377
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=91cda45b69e45a089f9989979a65db3f710c9925
 */

hwaddr ppc_hash32_get_phys_page_debug(CPUPPCState *env, target_ulong addr)

{

    struct mmu_ctx_hash32 ctx;



    if (unlikely(ppc_hash32_get_physical_address(env, &ctx, addr, 0, ACCESS_INT)

                 != 0)) {

        return -1;

    }



    return ctx.raddr & TARGET_PAGE_MASK;

}
