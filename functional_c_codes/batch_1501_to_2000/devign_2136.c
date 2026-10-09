/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2136
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=049e24a191c212d9468db84169197887f2c91586
 */

void HELPER(wfe)(CPUARMState *env)

{

    CPUState *cs = CPU(arm_env_get_cpu(env));



    /* Don't actually halt the CPU, just yield back to top

     * level loop. This is not going into a "low power state"

     * (ie halting until some event occurs), so we never take

     * a configurable trap to a different exception level.

     */

    cs->exception_index = EXCP_YIELD;

    cpu_loop_exit(cs);

}
