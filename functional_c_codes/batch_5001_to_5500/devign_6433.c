/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6433
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68a7439a150d6b4da99082ab454b9328b151bc25
 */

static uint64_t unassigned_mem_read(void *opaque, hwaddr addr,

                                    unsigned size)

{

#ifdef DEBUG_UNASSIGNED

    printf("Unassigned mem read " TARGET_FMT_plx "\n", addr);

#endif

    if (current_cpu != NULL) {

        cpu_unassigned_access(current_cpu, addr, false, false, 0, size);

    }

    return -1ULL;

}
