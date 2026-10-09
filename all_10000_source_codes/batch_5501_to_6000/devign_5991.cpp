/* 
 * Benchmark Sample ID : devign_5991
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=130a03855098a4057c227bc658c0688f8665b71f
 */

static void breakpoint_handler(CPUX86State *env)

{

    CPUBreakpoint *bp;



    if (env->watchpoint_hit) {

        if (env->watchpoint_hit->flags & BP_CPU) {

            env->watchpoint_hit = NULL;

            if (check_hw_breakpoints(env, 0))

                raise_exception_env(EXCP01_DB, env);

            else

                cpu_resume_from_signal(env, NULL);

        }

    } else {

        QTAILQ_FOREACH(bp, &env->breakpoints, entry)

            if (bp->pc == env->eip) {

                if (bp->flags & BP_CPU) {

                    check_hw_breakpoints(env, 1);

                    raise_exception_env(EXCP01_DB, env);

                }

                break;

            }

    }

    if (prev_debug_excp_handler)

        prev_debug_excp_handler(env);

}
