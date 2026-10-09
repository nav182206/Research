/* 
 * Benchmark Sample ID : devign_3660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

static void kqemu_vfree(void *ptr)

{

    /* may be useful some day, but currently we do not need to free */

}
