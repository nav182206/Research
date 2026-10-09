/* 
 * Benchmark Sample ID : devign_861
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f3c7d0389fe8a2792fd4c1cf151b885de03c8f62
 */

static void omap_timer_clk_setup(struct omap_mpu_timer_s *timer)

{

    omap_clk_adduser(timer->clk,

                    qemu_allocate_irqs(omap_timer_clk_update, timer, 1)[0]);

    timer->rate = omap_clk_getrate(timer->clk);

}
