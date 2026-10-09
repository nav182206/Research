/* 
 * Benchmark Sample ID : devign_4075
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=31fe14d15d08d613ff38abb249911e98c7966b86
 */

void spapr_events_init(sPAPREnvironment *spapr)

{

    spapr->epow_irq = xics_alloc(spapr->icp, 0, 0, false);

    spapr->epow_notifier.notify = spapr_powerdown_req;

    qemu_register_powerdown_notifier(&spapr->epow_notifier);

    spapr_rtas_register(RTAS_CHECK_EXCEPTION, "check-exception",

                        check_exception);

}
