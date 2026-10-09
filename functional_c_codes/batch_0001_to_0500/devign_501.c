/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_501
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9f82d013be0d8d9c5d9f51bb76e337a0a5a5cac
 */

static void do_dcbz(CPUPPCState *env, target_ulong addr, int dcache_line_size,

                    uintptr_t raddr)

{

    int i;



    addr &= ~(dcache_line_size - 1);

    for (i = 0; i < dcache_line_size; i += 4) {

        cpu_stl_data_ra(env, addr + i, 0, raddr);

    }

    if (env->reserve_addr == addr) {

        env->reserve_addr = (target_ulong)-1ULL;

    }

}
