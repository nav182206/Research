/* 
 * Benchmark Sample ID : devign_1368
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=480cff632221dc4d4889bf72dd0f09cd35096bc1
 */

void qemu_coroutine_enter(Coroutine *co)

{

    Coroutine *self = qemu_coroutine_self();

    CoroutineAction ret;



    trace_qemu_coroutine_enter(self, co, co->entry_arg);



    if (co->caller) {

        fprintf(stderr, "Co-routine re-entered recursively\n");

        abort();

    }



    co->caller = self;

    co->ctx = qemu_get_current_aio_context();



    /* Store co->ctx before anything that stores co.  Matches

     * barrier in aio_co_wake.

     */

    smp_wmb();



    ret = qemu_coroutine_switch(self, co, COROUTINE_ENTER);



    qemu_co_queue_run_restart(co);



    switch (ret) {

    case COROUTINE_YIELD:

        return;

    case COROUTINE_TERMINATE:

        assert(!co->locks_held);

        trace_qemu_coroutine_terminate(co);

        coroutine_delete(co);

        return;

    default:

        abort();

    }

}
