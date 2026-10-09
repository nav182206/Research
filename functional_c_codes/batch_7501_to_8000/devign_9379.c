/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9379
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

static void pxa2xx_rtc_piupdate(PXA2xxRTCState *s)

{

    int64_t rt = qemu_get_clock(rt_clock);

    if (s->rtsr & (1 << 15))

        s->last_swcr += rt - s->last_pi;

    s->last_pi = rt;

}
