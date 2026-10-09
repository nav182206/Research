/* 
 * Benchmark Sample ID : devign_3067
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=23326164ae6fe8d94b7eff123e03f97ca6978d33
 */

static inline int memory_access_size(MemoryRegion *mr, int l, hwaddr addr)

{

    if (l >= 4 && (((addr & 3) == 0 || mr->ops->impl.unaligned))) {

        return 4;

    }

    if (l >= 2 && (((addr & 1) == 0) || mr->ops->impl.unaligned)) {

        return 2;

    }

    return 1;

}
