/* 
 * Benchmark Sample ID : devign_9251
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6133b39f3c36623425a6ede9e89d93175fde15cd
 */

void qemu_aio_coroutine_enter(AioContext *ctx, Coroutine *co)
{
    Coroutine *self = qemu_coroutine_self();
    CoroutineAction ret;
    trace_qemu_aio_coroutine_enter(ctx, self, co, co->entry_arg);
    if (co->caller) {
        fprintf(stderr, "Co-routine re-entered recursively\n");
    co->caller = self;
    co->ctx = ctx;
    /* Store co->ctx before anything that stores co.  Matches
     * barrier in aio_co_wake and qemu_co_mutex_wake.
     */
    smp_wmb();
    ret = qemu_coroutine_switch(self, co, COROUTINE_ENTER);
    qemu_co_queue_run_restart(co);
    /* Beware, if ret == COROUTINE_YIELD and qemu_co_queue_run_restart()
     * has started any other coroutine, "co" might have been reentered
     * and even freed by now!  So be careful and do not touch it.
     */
    switch (ret) {
    case COROUTINE_YIELD:
        return;
    case COROUTINE_TERMINATE:
        assert(!co->locks_held);
        trace_qemu_coroutine_terminate(co);
        coroutine_delete(co);
        return;
    default:
