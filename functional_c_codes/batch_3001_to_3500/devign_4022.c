/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4022
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6886b98036a8f8f5bce8b10756ce080084cef11b
 */

void xtensa_breakpoint_handler(CPUState *cs)

{

    XtensaCPU *cpu = XTENSA_CPU(cs);

    CPUXtensaState *env = &cpu->env;



    if (cs->watchpoint_hit) {

        if (cs->watchpoint_hit->flags & BP_CPU) {

            uint32_t cause;



            cs->watchpoint_hit = NULL;

            cause = check_hw_breakpoints(env);

            if (cause) {

                debug_exception_env(env, cause);

            }

            cpu_resume_from_signal(cs, NULL);

        }

    }

}
