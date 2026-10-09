/* 
 * Benchmark Sample ID : devign_9658
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a354bd935a800dd2d98ac8f30707e2912c80ae6
 */

static void ptimer_trigger(ptimer_state *s)

{

    if (s->bh) {

        qemu_bh_schedule(s->bh);

    }

}
