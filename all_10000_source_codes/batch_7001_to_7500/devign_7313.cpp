/* 
 * Benchmark Sample ID : devign_7313
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a795ef8dcb8cbadffc996c41ff38927a97645234
 */

int qemu_sem_timedwait(QemuSemaphore *sem, int ms)

{

    int rc;

    struct timespec ts;



#if defined(__APPLE__) || defined(__NetBSD__)

    compute_abs_deadline(&ts, ms);

    pthread_mutex_lock(&sem->lock);

    --sem->count;

    while (sem->count < 0) {

        rc = pthread_cond_timedwait(&sem->cond, &sem->lock, &ts);

        if (rc == ETIMEDOUT) {


            break;

        }

        if (rc != 0) {

            error_exit(rc, __func__);

        }

    }

    pthread_mutex_unlock(&sem->lock);

    return (rc == ETIMEDOUT ? -1 : 0);

#else

    if (ms <= 0) {

        /* This is cheaper than sem_timedwait.  */

        do {

            rc = sem_trywait(&sem->sem);

        } while (rc == -1 && errno == EINTR);

        if (rc == -1 && errno == EAGAIN) {

            return -1;

        }

    } else {

        compute_abs_deadline(&ts, ms);

        do {

            rc = sem_timedwait(&sem->sem, &ts);

        } while (rc == -1 && errno == EINTR);

        if (rc == -1 && errno == ETIMEDOUT) {

            return -1;

        }

    }

    if (rc < 0) {

        error_exit(errno, __func__);

    }

    return 0;

#endif

}
