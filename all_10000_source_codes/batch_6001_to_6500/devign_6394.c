/* 
 * Benchmark Sample ID : devign_6394
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1fce1ba985d9c5c96e5b9709e1356d1814b8fa9e
 */

static CPAccessResult pmreg_access(CPUARMState *env, const ARMCPRegInfo *ri,

                                   bool isread)

{

    /* Performance monitor registers user accessibility is controlled

     * by PMUSERENR.

     */

    if (arm_current_el(env) == 0 && !env->cp15.c9_pmuserenr) {

        return CP_ACCESS_TRAP;

    }

    return CP_ACCESS_OK;

}
