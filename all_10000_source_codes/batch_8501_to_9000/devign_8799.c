/* 
 * Benchmark Sample ID : devign_8799
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t watch_mem_read(void *opaque, target_phys_addr_t addr,

                               unsigned size)

{

    check_watchpoint(addr & ~TARGET_PAGE_MASK, ~(size - 1), BP_MEM_READ);

    switch (size) {

    case 1: return ldub_phys(addr);

    case 2: return lduw_phys(addr);

    case 4: return ldl_phys(addr);

    default: abort();

    }

}
