/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8819
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t unassigned_mem_read(void *opaque, target_phys_addr_t addr,

                                    unsigned size)

{

#ifdef DEBUG_UNASSIGNED

    printf("Unassigned mem read " TARGET_FMT_plx "\n", addr);

#endif

#if defined(TARGET_ALPHA) || defined(TARGET_SPARC) || defined(TARGET_MICROBLAZE)

    cpu_unassigned_access(cpu_single_env, addr, 0, 0, 0, size);

#endif

    return 0;

}
