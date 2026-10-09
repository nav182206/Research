/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6161
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

void OPPROTO op_divw (void)

{

    if (unlikely(((int32_t)T0 == INT32_MIN && (int32_t)T1 == -1) ||

                 (int32_t)T1 == 0)) {

        T0 = (int32_t)((-1) * ((uint32_t)T0 >> 31));

    } else {

        T0 = (int32_t)T0 / (int32_t)T1;

    }

    RETURN();

}
