/* 
 * Benchmark Sample ID : devign_5064
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void omap_pwl_write(void *opaque, target_phys_addr_t addr,

                           uint64_t value, unsigned size)

{

    struct omap_pwl_s *s = (struct omap_pwl_s *) opaque;

    int offset = addr & OMAP_MPUI_REG_MASK;



    if (size != 1) {

        return omap_badwidth_write8(opaque, addr, value);

    }



    switch (offset) {

    case 0x00:	/* PWL_LEVEL */

        s->level = value;

        omap_pwl_update(s);

        break;

    case 0x04:	/* PWL_CTRL */

        s->enable = value & 1;

        omap_pwl_update(s);

        break;

    default:

        OMAP_BAD_REG(addr);

        return;

    }

}
