/* 
 * Benchmark Sample ID : devign_1777
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t exynos4210_pwm_read(void *opaque, target_phys_addr_t offset,

        unsigned size)

{

    Exynos4210PWMState *s = (Exynos4210PWMState *)opaque;

    uint32_t value = 0;

    int index;



    switch (offset) {

    case TCFG0: case TCFG1:

        index = (offset - TCFG0) >> 2;

        value = s->reg_tcfg[index];

        break;



    case TCON:

        value = s->reg_tcon;

        break;



    case TCNTB0: case TCNTB1:

    case TCNTB2: case TCNTB3: case TCNTB4:

        index = (offset - TCNTB0) / 0xC;

        value = s->timer[index].reg_tcntb;

        break;



    case TCMPB0: case TCMPB1:

    case TCMPB2: case TCMPB3:

        index = (offset - TCMPB0) / 0xC;

        value = s->timer[index].reg_tcmpb;

        break;



    case TCNTO0: case TCNTO1:

    case TCNTO2: case TCNTO3: case TCNTO4:

        index = (offset == TCNTO4) ? 4 : (offset - TCNTO0) / 0xC;

        value = ptimer_get_count(s->timer[index].ptimer);

        break;



    case TINT_CSTAT:

        value = s->reg_tint_cstat;

        break;



    default:

        fprintf(stderr,

                "[exynos4210.pwm: bad read offset " TARGET_FMT_plx "]\n",

                offset);

        break;

    }

    return value;

}
