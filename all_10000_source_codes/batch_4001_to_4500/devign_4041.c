/* 
 * Benchmark Sample ID : devign_4041
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3e10c7b4377c1cbc0a4fbc12312c2cf41c0cda7
 */

void OPPROTO op_check_subfo_64 (void)

{

    if (likely(!(((uint64_t)(~T2) ^ (uint64_t)T1 ^ UINT64_MAX) &

                 ((uint64_t)(~T2) ^ (uint64_t)T0) & (1ULL << 63)))) {

        xer_ov = 0;

    } else {

        xer_ov = 1;

        xer_so = 1;

    }

    RETURN();

}
