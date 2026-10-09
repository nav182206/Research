/* 
 * Benchmark Sample ID : devign_6367
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

static void pxa2xx_rtc_swupdate(PXA2xxRTCState *s)

{

    int64_t rt = qemu_get_clock(rt_clock);

    if (s->rtsr & (1 << 12))

        s->last_swcr += (rt - s->last_sw) / 10;

    s->last_sw = rt;

}
