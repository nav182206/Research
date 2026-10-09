/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4338
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void paio_cancel(BlockDriverAIOCB *blockacb)

{

    struct qemu_paiocb *acb = (struct qemu_paiocb *)blockacb;

    int active = 0;



    mutex_lock(&lock);

    if (!acb->active) {

        TAILQ_REMOVE(&request_list, acb, node);

        acb->ret = -ECANCELED;

    } else if (acb->ret == -EINPROGRESS) {

        active = 1;

    }

    mutex_unlock(&lock);



    if (active) {

        /* fail safe: if the aio could not be canceled, we wait for

           it */

        while (qemu_paio_error(acb) == EINPROGRESS)

            ;

    }



    paio_remove(acb);

}
