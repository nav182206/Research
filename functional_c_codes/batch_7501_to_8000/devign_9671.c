/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9671
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void trim_aio_cancel(BlockAIOCB *acb)

{

    TrimAIOCB *iocb = container_of(acb, TrimAIOCB, common);



    /* Exit the loop so ide_issue_trim_cb will not continue  */

    iocb->j = iocb->qiov->niov - 1;

    iocb->i = (iocb->qiov->iov[iocb->j].iov_len / 8) - 1;



    iocb->ret = -ECANCELED;



    if (iocb->aiocb) {

        bdrv_aio_cancel_async(iocb->aiocb);

        iocb->aiocb = NULL;

    }

}
