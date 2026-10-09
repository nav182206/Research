/* 
 * Benchmark Sample ID : devign_2940
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b14ef7c9ab41ea824c3ccadb070ad95567cca84e
 */

static uint32_t unassigned_mem_readb(void *opaque, target_phys_addr_t addr)

{

#ifdef DEBUG_UNASSIGNED

    printf("Unassigned mem read " TARGET_FMT_plx "\n", addr);

#endif

#if defined(TARGET_ALPHA) || defined(TARGET_SPARC) || defined(TARGET_MICROBLAZE)

    do_unassigned_access(addr, 0, 0, 0, 1);

#endif

    return 0;

}
