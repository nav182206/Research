/* 
 * Benchmark Sample ID : devign_2225
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void cpu_handle_debug_exception(CPUState *env)

{

    CPUWatchpoint *wp;



    if (!env->watchpoint_hit)

        TAILQ_FOREACH(wp, &env->watchpoints, entry)

            wp->flags &= ~BP_WATCHPOINT_HIT;



    if (debug_excp_handler)

        debug_excp_handler(env);

}
