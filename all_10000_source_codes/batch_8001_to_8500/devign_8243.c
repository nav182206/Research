/* 
 * Benchmark Sample ID : devign_8243
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

static void timer_start(SpiceTimer *timer, uint32_t ms)

{

    qemu_mod_timer(timer->timer, qemu_get_clock(rt_clock) + ms);

}
