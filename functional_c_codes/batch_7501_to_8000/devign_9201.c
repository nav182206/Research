/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9201
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=24fa90499f8b24bcba2960a3316d797f9b80b5e9
 */

void qemu_mutex_init(QemuMutex *mutex)

{

    int err;

    pthread_mutexattr_t mutexattr;



    pthread_mutexattr_init(&mutexattr);

    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);

    err = pthread_mutex_init(&mutex->lock, &mutexattr);

    pthread_mutexattr_destroy(&mutexattr);

    if (err)

        error_exit(err, __func__);

}
