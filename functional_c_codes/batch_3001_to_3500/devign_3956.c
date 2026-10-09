/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b1fe60cd3525871a4c593ad8c2b39b89c19c00d0
 */

static void intel_hda_update_int_sts(IntelHDAState *d)

{

    uint32_t sts = 0;

    uint32_t i;



    /* update controller status */

    if (d->rirb_sts & ICH6_RBSTS_IRQ) {

        sts |= (1 << 30);

    }

    if (d->rirb_sts & ICH6_RBSTS_OVERRUN) {

        sts |= (1 << 30);

    }

    if (d->state_sts & d->wake_en) {

        sts |= (1 << 30);

    }



    /* update stream status */

    for (i = 0; i < 8; i++) {

        /* buffer completion interrupt */

        if (d->st[i].ctl & (1 << 26)) {

            sts |= (1 << i);

        }

    }



    /* update global status */

    if (sts & d->int_ctl) {

        sts |= (1 << 31);

    }



    d->int_sts = sts;

}
