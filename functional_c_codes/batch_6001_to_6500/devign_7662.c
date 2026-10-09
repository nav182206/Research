/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7662
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a97fed52e57385fc749e6f6ef95be7ebdb81ba9b
 */

void OPPROTO op_store_msr_32 (void)

{

    ppc_store_msr_32(env, T0);

    RETURN();

}
