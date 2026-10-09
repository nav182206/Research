/* 
 * Benchmark Sample ID : devign_3620
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8653c0158c23ec592f0041ab48b83d6cc6d152fe
 */

int qemu_paio_cancel(int fd, struct qemu_paiocb *aiocb)

{

    int ret;



    pthread_mutex_lock(&lock);

    if (!aiocb->active) {

        TAILQ_REMOVE(&request_list, aiocb, node);

        aiocb->ret = -ECANCELED;

        ret = QEMU_PAIO_CANCELED;

    } else if (aiocb->ret == -EINPROGRESS)

        ret = QEMU_PAIO_NOTCANCELED;

    else

        ret = QEMU_PAIO_ALLDONE;

    pthread_mutex_unlock(&lock);



    return ret;

}
