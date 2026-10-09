/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8222
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac03ee5331612e44beb393df2b578c951d27dc0d
 */

void cpu_exec_step_atomic(CPUState *cpu)

{

    start_exclusive();



    /* Since we got here, we know that parallel_cpus must be true.  */

    parallel_cpus = false;

    cpu_exec_step(cpu);

    parallel_cpus = true;



    end_exclusive();

}
