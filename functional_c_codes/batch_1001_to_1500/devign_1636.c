/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1636
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f75bd73c319a1224a64a1b5ad680b1a37ed2d7a
 */

void qemu_thread_create(QemuThread *thread, const char *name,

                       void *(*start_routine)(void*),

                       void *arg, int mode)

{

    sigset_t set, oldset;

    int err;

    pthread_attr_t attr;



    err = pthread_attr_init(&attr);

    if (err) {

        error_exit(err, __func__);

    }

    if (mode == QEMU_THREAD_DETACHED) {

        err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        if (err) {

            error_exit(err, __func__);

        }

    }



    /* Leave signal handling to the iothread.  */

    sigfillset(&set);

    pthread_sigmask(SIG_SETMASK, &set, &oldset);

    err = pthread_create(&thread->thread, &attr, start_routine, arg);

    if (err)

        error_exit(err, __func__);



    if (name_threads) {

        qemu_thread_set_name(thread, name);

    }



    pthread_sigmask(SIG_SETMASK, &oldset, NULL);



    pthread_attr_destroy(&attr);

}
