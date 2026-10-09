/* 
 * Benchmark Sample ID : devign_8360
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f3e31012e334f3410e04abae7f88565df17c91a
 */

void cpu_disable_ticks(void)

{

    /* Here, the really thing protected by seqlock is cpu_clock_offset. */

    seqlock_write_lock(&timers_state.vm_clock_seqlock);

    if (timers_state.cpu_ticks_enabled) {

        timers_state.cpu_ticks_offset = cpu_get_ticks();

        timers_state.cpu_clock_offset = cpu_get_clock_locked();

        timers_state.cpu_ticks_enabled = 0;

    }

    seqlock_write_unlock(&timers_state.vm_clock_seqlock);

}
