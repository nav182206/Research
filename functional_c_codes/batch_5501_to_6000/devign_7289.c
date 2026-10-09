/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7289
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2374e73edafff0586cbfb67c333c5a7588f81fd5
 */

void helper_stq_raw(uint64_t t0, uint64_t t1)

{

    stq_raw(t1, t0);

}
