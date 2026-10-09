/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=80c27194a7be757ef5a9cec978d1d8faaa4cee81
 */

void op_ddiv (void)

{

    if (T1 != 0) {

        env->LO = (int64_t)T0 / (int64_t)T1;

        env->HI = (int64_t)T0 % (int64_t)T1;

    }

    RETURN();

}
