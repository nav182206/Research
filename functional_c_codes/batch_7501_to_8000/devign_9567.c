/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9567
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

static void icount_adjust_rt(void * opaque)

{

    qemu_mod_timer(icount_rt_timer,

                   qemu_get_clock(rt_clock) + 1000);

    icount_adjust();

}
