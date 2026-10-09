/* 
 * Benchmark Sample ID : devign_9046
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6d0ceb80ffe18ad4b28aab7356f440636c0be7be
 */

void vm_start(void)

{

    RunState requested;



    qemu_vmstop_requested(&requested);

    if (runstate_is_running() && requested == RUN_STATE__MAX) {

        return;

    }



    /* Ensure that a STOP/RESUME pair of events is emitted if a

     * vmstop request was pending.  The BLOCK_IO_ERROR event, for

     * example, according to documentation is always followed by

     * the STOP event.

     */

    if (runstate_is_running()) {

        qapi_event_send_stop(&error_abort);

    } else {


        cpu_enable_ticks();

        runstate_set(RUN_STATE_RUNNING);

        vm_state_notify(1, RUN_STATE_RUNNING);

        resume_all_vcpus();

    }



    qapi_event_send_resume(&error_abort);

}
