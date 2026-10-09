/* 
 * Benchmark Sample ID : devign_6592
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void OPPROTO op_divd (void)

{

    if (unlikely(((int64_t)T0 == INT64_MIN && (int64_t)T1 == -1) ||

                 (int64_t)T1 == 0)) {

        T0 = (int64_t)((-1ULL) * ((uint64_t)T0 >> 63));

    } else {

        T0 = (int64_t)T0 / (int64_t)T1;

    }

    RETURN();

}
