/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_856
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=378df4b23753a11be650af7664ca76bc75cb9f01
 */

void cpu_interrupt(CPUArchState *env, int mask)

{

    CPUState *cpu = ENV_GET_CPU(env);



    env->interrupt_request |= mask;

    cpu_unlink_tb(cpu);

}
