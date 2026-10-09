/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3923
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e91171e30235ae99ab8060988aa3c9536692bba8
 */

void ptimer_set_limit(ptimer_state *s, uint64_t limit, int reload)

{

    /*

     * Artificially limit timeout rate to something

     * achievable under QEMU.  Otherwise, QEMU spends all

     * its time generating timer interrupts, and there

     * is no forward progress.

     * About ten microseconds is the fastest that really works

     * on the current generation of host machines.

     */



    if (!use_icount && limit * s->period < 10000 && s->period) {

        limit = 10000 / s->period;

    }



    s->limit = limit;

    if (reload)

        s->delta = limit;

    if (s->enabled && reload) {

        s->next_event = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);

        ptimer_reload(s);

    }

}
