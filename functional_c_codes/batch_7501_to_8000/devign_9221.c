/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9221
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3e10c7b4377c1cbc0a4fbc12312c2cf41c0cda7
 */

void do_addmeo (void)

{

    T1 = T0;

    T0 += xer_ca + (-1);

    if (likely(!((uint32_t)T1 &

                 ((uint32_t)T1 ^ (uint32_t)T0) & (1UL << 31)))) {

        xer_ov = 0;

    } else {

        xer_ov = 1;

        xer_so = 1;

    }

    if (likely(T1 != 0))

        xer_ca = 1;

}
