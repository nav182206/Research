/* 
 * Benchmark Sample ID : devign_3080
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3e09d87c6e69c2da684d5aacabe3124ebcb6f8e
 */

static void mvc_fast_memset(CPUS390XState *env, uint32_t l, uint64_t dest,

                            uint8_t byte)

{

    S390CPU *cpu = s390_env_get_cpu(env);

    hwaddr dest_phys;

    hwaddr len = l;

    void *dest_p;

    uint64_t asc = env->psw.mask & PSW_MASK_ASC;

    int flags;



    if (mmu_translate(env, dest, 1, asc, &dest_phys, &flags)) {

        cpu_stb_data(env, dest, byte);

        cpu_abort(CPU(cpu), "should never reach here");

    }

    dest_phys |= dest & ~TARGET_PAGE_MASK;



    dest_p = cpu_physical_memory_map(dest_phys, &len, 1);



    memset(dest_p, byte, len);



    cpu_physical_memory_unmap(dest_p, 1, len, len);

}
