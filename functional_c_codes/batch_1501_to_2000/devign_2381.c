/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2381
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=17e2377abf16c3951d7d34521ceade4d7dc31d01
 */

void qemu_free(void *ptr)

{

    free(ptr);

}
