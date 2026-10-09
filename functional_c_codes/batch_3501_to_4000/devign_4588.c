/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4588
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8417f904bad50021b432dfea12613345d9fb1f68
 */

static bool s390_cpu_has_work(CPUState *cs)

{

    S390CPU *cpu = S390_CPU(cs);

    CPUS390XState *env = &cpu->env;



    return (cs->interrupt_request & CPU_INTERRUPT_HARD) &&

           (env->psw.mask & PSW_MASK_EXT);

}
