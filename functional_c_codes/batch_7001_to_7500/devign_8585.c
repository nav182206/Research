/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8585
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=966439a67830239a6c520c5df6c55627b8153c8b
 */

void OPPROTO op_check_addo_64 (void)

{

    if (likely(!(((uint64_t)T2 ^ (uint64_t)T1 ^ UINT64_MAX) &

                 ((uint64_t)T2 ^ (uint64_t)T0) & (1ULL << 63)))) {

        xer_ov = 0;

    } else {

        xer_so = 1;

        xer_ov = 1;

    }

    RETURN();

}
