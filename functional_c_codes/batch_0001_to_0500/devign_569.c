/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_569
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12f8def0e02232d7c6416ad9b66640f973c531d1
 */

void qemu_cond_init(QemuCond *cond)

{

    memset(cond, 0, sizeof(*cond));



    cond->sema = CreateSemaphore(NULL, 0, LONG_MAX, NULL);

    if (!cond->sema) {

        error_exit(GetLastError(), __func__);

    }

    cond->continue_event = CreateEvent(NULL,    /* security */

                                       FALSE,   /* auto-reset */

                                       FALSE,   /* not signaled */

                                       NULL);   /* name */

    if (!cond->continue_event) {

        error_exit(GetLastError(), __func__);

    }

}
