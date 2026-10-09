/* 
 * Benchmark Sample ID : devign_7892
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12f8def0e02232d7c6416ad9b66640f973c531d1
 */

void qemu_cond_broadcast(QemuCond *cond)

{

    BOOLEAN result;

    /*

     * As in pthread_cond_signal, access to cond->waiters and

     * cond->target is locked via the external mutex.

     */

    if (cond->waiters == 0) {

        return;

    }



    cond->target = 0;

    result = ReleaseSemaphore(cond->sema, cond->waiters, NULL);

    if (!result) {

        error_exit(GetLastError(), __func__);

    }



    /*

     * At this point all waiters continue. Each one takes its

     * slice of the semaphore. Now it's our turn to wait: Since

     * the external mutex is held, no thread can leave cond_wait,

     * yet. For this reason, we can be sure that no thread gets

     * a chance to eat *more* than one slice. OTOH, it means

     * that the last waiter must send us a wake-up.

     */

    WaitForSingleObject(cond->continue_event, INFINITE);

}
