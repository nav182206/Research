/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9716
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void dma_aio_cancel(BlockAIOCB *acb)

{

    DMAAIOCB *dbs = container_of(acb, DMAAIOCB, common);



    trace_dma_aio_cancel(dbs);



    if (dbs->acb) {

        bdrv_aio_cancel_async(dbs->acb);

    }

}
