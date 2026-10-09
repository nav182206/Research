/* 
 * Benchmark Sample ID : devign_2822
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=17e2377abf16c3951d7d34521ceade4d7dc31d01
 */

void *qemu_malloc(size_t size)

{

    return malloc(size);

}
