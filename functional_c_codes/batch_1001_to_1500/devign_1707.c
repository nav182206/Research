/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b09ea7d55cfab5a75912bb56ed1fcd757604a759
 */

static void apic_startup(APICState *s, int vector_num)

{

    CPUState *env = s->cpu_env;

    if (!env->halted)

        return;

    env->eip = 0;

    cpu_x86_load_seg_cache(env, R_CS, vector_num << 8, vector_num << 12,

                           0xffff, 0);

    env->halted = 0;

}
