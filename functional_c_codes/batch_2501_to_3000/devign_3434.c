/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3434
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b29a0341d7ed7e7df4bf77a41db8e614f1ddb645
 */

void op_mfc0_ebase (void)

{

    T0 = (int32_t)env->CP0_EBase;

    RETURN();

}
