/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_858
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce5b1bbf624b977a55ff7f85bb3871682d03baff
 */

static void superh_cpu_initfn(Object *obj)

{

    CPUState *cs = CPU(obj);

    SuperHCPU *cpu = SUPERH_CPU(obj);

    CPUSH4State *env = &cpu->env;



    cs->env_ptr = env;

    cpu_exec_init(cs, &error_abort);



    env->movcal_backup_tail = &(env->movcal_backup);



    if (tcg_enabled()) {

        sh4_translate_init();

    }

}
