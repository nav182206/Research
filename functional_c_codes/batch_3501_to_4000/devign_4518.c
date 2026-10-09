/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4518
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a1aff5bf6786e6e8478373e4ada869a4ef2a7fc4
 */

static inline int media_present(IDEState *s)

{

    return (s->nb_sectors > 0);

}
