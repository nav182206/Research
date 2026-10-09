/* 
 * Benchmark Sample ID : devign_1428
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=966439a67830239a6c520c5df6c55627b8153c8b
 */

void do_divduo (void)

{

    if (likely((uint64_t)T1 != 0)) {

        xer_ov = 0;

        T0 = (uint64_t)T0 / (uint64_t)T1;

    } else {

        xer_so = 1;

        xer_ov = 1;

        T0 = 0;

    }

}
