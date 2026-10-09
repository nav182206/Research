/* 
 * Benchmark Sample ID : devign_6078
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8653c0158c23ec592f0041ab48b83d6cc6d152fe
 */

ssize_t qemu_paio_return(struct qemu_paiocb *aiocb)

{

    ssize_t ret;



    pthread_mutex_lock(&lock);

    ret = aiocb->ret;

    pthread_mutex_unlock(&lock);



    return ret;

}
