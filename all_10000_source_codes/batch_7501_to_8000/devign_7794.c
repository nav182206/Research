/* 
 * Benchmark Sample ID : devign_7794
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void omap_os_timer_write(void *opaque, target_phys_addr_t addr,

                                uint64_t value, unsigned size)

{

    struct omap_32khz_timer_s *s = (struct omap_32khz_timer_s *) opaque;

    int offset = addr & OMAP_MPUI_REG_MASK;



    if (size != 4) {

        return omap_badwidth_write32(opaque, addr, value);

    }



    switch (offset) {

    case 0x00:	/* TVR */

        s->timer.reset_val = value & 0x00ffffff;

        break;



    case 0x04:	/* TCR */

        OMAP_RO_REG(addr);

        break;



    case 0x08:	/* CR */

        s->timer.ar = (value >> 3) & 1;

        s->timer.it_ena = (value >> 2) & 1;

        if (s->timer.st != (value & 1) || (value & 2)) {

            omap_timer_sync(&s->timer);

            s->timer.enable = value & 1;

            s->timer.st = value & 1;

            omap_timer_update(&s->timer);

        }

        break;



    default:

        OMAP_BAD_REG(addr);

    }

}
