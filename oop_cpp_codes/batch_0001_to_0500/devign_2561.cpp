/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2561
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66dc50f7057b9a0191f54e55764412202306858d
 */

int do_subchannel_work_virtual(SubchDev *sch)

{



    SCSW *s = &sch->curr_status.scsw;



    if (s->ctrl & SCSW_FCTL_CLEAR_FUNC) {

        sch_handle_clear_func(sch);

    } else if (s->ctrl & SCSW_FCTL_HALT_FUNC) {

        sch_handle_halt_func(sch);

    } else if (s->ctrl & SCSW_FCTL_START_FUNC) {

        /* Triggered by both ssch and rsch. */

        sch_handle_start_func_virtual(sch);

    }

    css_inject_io_interrupt(sch);

    return 0;

}
