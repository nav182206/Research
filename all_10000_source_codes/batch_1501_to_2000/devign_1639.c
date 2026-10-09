/* 
 * Benchmark Sample ID : devign_1639
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=80c27194a7be757ef5a9cec978d1d8faaa4cee81
 */

void op_div (void)

{

    if (T1 != 0) {

        env->LO = (int32_t)((int32_t)T0 / (int32_t)T1);

        env->HI = (int32_t)((int32_t)T0 % (int32_t)T1);

    }

    RETURN();

}
