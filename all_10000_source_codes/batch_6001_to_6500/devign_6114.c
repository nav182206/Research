/* 
 * Benchmark Sample ID : devign_6114
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=79761c6681f0d1cc1c027116fcb4382d41ed3ece
 */

void qemu_sem_post(QemuSemaphore *sem)

{

    int rc;



#if defined(__APPLE__) || defined(__NetBSD__)

    pthread_mutex_lock(&sem->lock);

    if (sem->count == INT_MAX) {

        rc = EINVAL;

    } else if (sem->count++ < 0) {

        rc = pthread_cond_signal(&sem->cond);

    } else {

        rc = 0;

    }

    pthread_mutex_unlock(&sem->lock);

    if (rc != 0) {

        error_exit(rc, __func__);

    }

#else

    rc = sem_post(&sem->sem);

    if (rc < 0) {

        error_exit(errno, __func__);

    }

#endif

}
