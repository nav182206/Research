/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3794
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66dc50f7057b9a0191f54e55764412202306858d
 */

int css_do_rsch(SubchDev *sch)

{

    SCSW *s = &sch->curr_status.scsw;

    PMCW *p = &sch->curr_status.pmcw;

    int ret;



    if (~(p->flags) & (PMCW_FLAGS_MASK_DNV | PMCW_FLAGS_MASK_ENA)) {

        ret = -ENODEV;

        goto out;

    }



    if (s->ctrl & SCSW_STCTL_STATUS_PEND) {

        ret = -EINPROGRESS;

        goto out;

    }



    if (((s->ctrl & SCSW_CTRL_MASK_FCTL) != SCSW_FCTL_START_FUNC) ||

        (s->ctrl & SCSW_ACTL_RESUME_PEND) ||

        (!(s->ctrl & SCSW_ACTL_SUSP))) {

        ret = -EINVAL;

        goto out;

    }



    /* If monitoring is active, update counter. */

    if (channel_subsys.chnmon_active) {

        css_update_chnmon(sch);

    }



    s->ctrl |= SCSW_ACTL_RESUME_PEND;

    do_subchannel_work(sch);

    ret = 0;



out:

    return ret;

}
