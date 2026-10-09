/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5066
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

static void memory_region_iorange_destructor(IORange *iorange)

{

    g_free(container_of(iorange, MemoryRegionIORange, iorange));

}
