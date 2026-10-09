/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1213
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

static uint32_t qpi_mem_readl(void *opaque, target_phys_addr_t addr)

{

    CPUState *env;



    env = cpu_single_env;

    if (!env)

        return 0;

    return env->eflags & (IF_MASK | IOPL_MASK);

}
