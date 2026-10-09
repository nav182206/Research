/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2987
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

void vnc_zlib_zfree(void *x, void *addr)

{

    qemu_free(addr);

}
