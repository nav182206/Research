/* 
 * Benchmark Sample ID : devign_7836
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

uint64_t cpu_get_tsc(CPUX86State *env)

{

    /* Note: when using kqemu, it is more logical to return the host TSC

       because kqemu does not trap the RDTSC instruction for

       performance reasons */

#ifdef CONFIG_KQEMU

    if (env->kqemu_enabled) {

        return cpu_get_real_ticks();

    } else

#endif

    {

        return cpu_get_ticks();

    }

}
