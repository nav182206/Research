/* 
 * Benchmark Sample ID : devign_6371
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=21e00fa55f3fdfcbb20da7c6876c91ef3609b387
 */

void memory_region_set_skip_dump(MemoryRegion *mr)

{

    mr->skip_dump = true;

}
