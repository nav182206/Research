/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1402
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

void qemu_co_queue_run_restart(Coroutine *co)

{

    Coroutine *next;



    trace_qemu_co_queue_run_restart(co);

    while ((next = QSIMPLEQ_FIRST(&co->co_queue_wakeup))) {

        QSIMPLEQ_REMOVE_HEAD(&co->co_queue_wakeup, co_queue_next);

        qemu_coroutine_enter(next, NULL);

    }

}
