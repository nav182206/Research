/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1818
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8786db7cb96f8ce5c75c6e1e074319c9dca8d356
 */

void memory_global_sync_dirty_bitmap(MemoryRegion *address_space)

{

    AddressSpace *as = memory_region_to_address_space(address_space);

    FlatRange *fr;



    FOR_EACH_FLAT_RANGE(fr, &as->current_map) {

        MEMORY_LISTENER_UPDATE_REGION(fr, as, Forward, log_sync);

    }

}
