/* 
 * Benchmark Sample ID : devign_7408
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=966439a67830239a6c520c5df6c55627b8153c8b
 */

void do_subfmeo (void)

{

    T1 = T0;

    T0 = ~T0 + xer_ca - 1;

    if (likely(!((uint32_t)~T1 & ((uint32_t)~T1 ^ (uint32_t)T0) &

                 (1UL << 31)))) {

        xer_ov = 0;

    } else {

        xer_so = 1;

        xer_ov = 1;

    }

    if (likely((uint32_t)T1 != UINT32_MAX))

        xer_ca = 1;

}
