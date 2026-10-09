/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1434
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6482b0ffd12ce83810c10b1a3884a75eba2ade1a
 */

void s390x_cpu_timer(void *opaque)

{

    S390CPU *cpu = opaque;

    CPUS390XState *env = &cpu->env;



    env->pending_int |= INTERRUPT_CPUTIMER;

    cpu_interrupt(CPU(cpu), CPU_INTERRUPT_HARD);

}
