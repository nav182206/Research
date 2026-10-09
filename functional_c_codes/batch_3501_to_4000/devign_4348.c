/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4348
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2d1a35bef0ed96b3f23535e459c552414ccdbafd
 */

bool memory_region_is_logging(MemoryRegion *mr)

{

    return mr->dirty_log_mask;

}
