/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3857
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66b9b43c42049bcae37668e890fedde9a72c8167
 */

static uint64_t watch_mem_read(void *opaque, hwaddr addr,

                               unsigned size)

{

    check_watchpoint(addr & ~TARGET_PAGE_MASK, size, BP_MEM_READ);

    switch (size) {

    case 1: return ldub_phys(&address_space_memory, addr);

    case 2: return lduw_phys(&address_space_memory, addr);

    case 4: return ldl_phys(&address_space_memory, addr);

    default: abort();

    }

}
