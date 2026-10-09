/* 
 * Benchmark Sample ID : devign_8194
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8417f904bad50021b432dfea12613345d9fb1f68
 */

bool s390_cpu_exec_interrupt(CPUState *cs, int interrupt_request)

{

    if (interrupt_request & CPU_INTERRUPT_HARD) {

        S390CPU *cpu = S390_CPU(cs);

        CPUS390XState *env = &cpu->env;



        if (env->ex_value) {

            /* Execution of the target insn is indivisible from

               the parent EXECUTE insn.  */

            return false;

        }

        if (env->psw.mask & PSW_MASK_EXT) {

            s390_cpu_do_interrupt(cs);

            return true;

        }

    }

    return false;

}
