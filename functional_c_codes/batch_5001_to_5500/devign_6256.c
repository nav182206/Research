/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6256
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8e46bbf362458fc3e4638a53249248a1ee40b912
 */

bool memory_region_present(MemoryRegion *parent, hwaddr addr)

{

    MemoryRegion *mr = memory_region_find(parent, addr, 1).mr;

    if (!mr) {

        return false;

    }

    memory_region_unref(mr);

    return true;

}
