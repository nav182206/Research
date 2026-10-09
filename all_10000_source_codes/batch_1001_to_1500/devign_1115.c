/* 
 * Benchmark Sample ID : devign_1115
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3fb5bf5730b90c08d5d1c027900efae210d9b326
 */

void memory_region_set_address(MemoryRegion *mr, hwaddr addr)

{

    MemoryRegion *parent = mr->parent;

    int priority = mr->priority;

    bool may_overlap = mr->may_overlap;



    if (addr == mr->addr || !parent) {

        mr->addr = addr;

        return;

    }



    memory_region_transaction_begin();

    memory_region_ref(mr);

    memory_region_del_subregion(parent, mr);

    if (may_overlap) {

        memory_region_add_subregion_overlap(parent, addr, mr, priority);

    } else {

        memory_region_add_subregion(parent, addr, mr);

    }

    memory_region_unref(mr);

    memory_region_transaction_commit();

}
