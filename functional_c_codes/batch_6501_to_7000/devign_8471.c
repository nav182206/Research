/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8471
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b61359781958759317ee6fd1a45b59be0b7dbbe1
 */

void memory_region_add_subregion_overlap(MemoryRegion *mr,

                                         hwaddr offset,

                                         MemoryRegion *subregion,

                                         int priority)

{

    subregion->may_overlap = true;

    subregion->priority = priority;

    memory_region_add_subregion_common(mr, offset, subregion);

}
