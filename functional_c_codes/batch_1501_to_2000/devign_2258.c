/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2258
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=75554a3ca10a7ad295d2a3d2e14ee6ba90f94c8b
 */

static inline void omap_gp_timer_trigger(struct omap_gp_timer_s *timer)

{

    if (timer->pt)

        /* TODO in overflow-and-match mode if the first event to

         * occurs is the match, don't toggle.  */

        omap_gp_timer_out(timer, !timer->out_val);

    else

        /* TODO inverted pulse on timer->out_val == 1?  */

        qemu_irq_pulse(timer->out);

}
