/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7046
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

static inline unsigned long align_sigframe(unsigned long sp)

{

    unsigned long i;

    i = sp & ~3UL;

    return i;

}
