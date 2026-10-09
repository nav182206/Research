/* 
 * Benchmark Sample ID : devign_1303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=027d9a7d2911e993cdcbd21c7c35d1dd058f05bb
 */

void cpu_exit(CPUState *cpu)

{

    cpu->exit_request = 1;

    /* Ensure cpu_exec will see the exit request after TCG has exited.  */

    smp_wmb();

    cpu->tcg_exit_req = 1;

}
