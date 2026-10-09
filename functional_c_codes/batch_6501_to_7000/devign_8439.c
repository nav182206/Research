/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8439
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b0f74c87a1dbd6b0c5e4de7f1c5cb40197e3fbe9
 */

static inline void menelaus_rtc_start(struct menelaus_s *s)

{

    s->rtc.next =+ qemu_get_clock(rt_clock);

    qemu_mod_timer(s->rtc.hz, s->rtc.next);

}
