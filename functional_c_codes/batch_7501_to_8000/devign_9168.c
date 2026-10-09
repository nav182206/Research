/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9168
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dd673288a8ff73ad77fcc1c255486d2466a772e1
 */

static void pc_cpu_reset(void *opaque)

{

    X86CPU *cpu = opaque;

    CPUX86State *env = &cpu->env;



    cpu_reset(CPU(cpu));

    env->halted = !cpu_is_bsp(env);

}
