/* 
 * Benchmark Sample ID : devign_1381
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

static inline void menelaus_rtc_start(MenelausState *s)

{

    s->rtc.next += qemu_get_clock(rt_clock);

    qemu_mod_timer(s->rtc.hz_tm, s->rtc.next);

}
