/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5972
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void invalidate_and_set_dirty(target_phys_addr_t addr,

                                     target_phys_addr_t length)

{

    if (!cpu_physical_memory_is_dirty(addr)) {

        /* invalidate code */

        tb_invalidate_phys_page_range(addr, addr + length, 0);

        /* set dirty bit */

        cpu_physical_memory_set_dirty_flags(addr, (0xff & ~CODE_DIRTY_FLAG));

    }

    xen_modified_memory(addr, length);

}
