/* 
 * Benchmark Sample ID : devign_6002
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ea63c05d90ba85d819f9b2472ce6dfba7a403b4
 */

int do_subchannel_work_passthrough(SubchDev *sch)

{

    int ret;

    SCSW *s = &sch->curr_status.scsw;



    if (s->ctrl & SCSW_FCTL_CLEAR_FUNC) {

        /* TODO: Clear handling */

        sch_handle_clear_func(sch);

        ret = 0;

    } else if (s->ctrl & SCSW_FCTL_HALT_FUNC) {

        /* TODO: Halt handling */

        sch_handle_halt_func(sch);

        ret = 0;

    } else if (s->ctrl & SCSW_FCTL_START_FUNC) {

        ret = sch_handle_start_func_passthrough(sch);

    } else {

        /* Cannot happen. */

        return -ENODEV;

    }



    return ret;

}
