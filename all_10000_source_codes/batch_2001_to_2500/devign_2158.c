/* 
 * Benchmark Sample ID : devign_2158
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3a2319792ad5c0f0f8c3d2f4d02b95fd7efbc69
 */

void slavio_intctl_set_cpu(void *opaque, unsigned int cpu, CPUState *env)

{

    SLAVIO_INTCTLState *s = opaque;



    s->cpu_envs[cpu] = env;

}
