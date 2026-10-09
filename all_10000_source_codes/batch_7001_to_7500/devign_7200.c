/* 
 * Benchmark Sample ID : devign_7200
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t omap_wd_timer_read(void *opaque, target_phys_addr_t addr,

                                   unsigned size)

{

    struct omap_watchdog_timer_s *s = (struct omap_watchdog_timer_s *) opaque;



    if (size != 2) {

        return omap_badwidth_read16(opaque, addr);

    }



    switch (addr) {

    case 0x00:	/* CNTL_TIMER */

        return (s->timer.ptv << 9) | (s->timer.ar << 8) |

                (s->timer.st << 7) | (s->free << 1);



    case 0x04:	/* READ_TIMER */

        return omap_timer_read(&s->timer);



    case 0x08:	/* TIMER_MODE */

        return s->mode << 15;

    }



    OMAP_BAD_REG(addr);

    return 0;

}
