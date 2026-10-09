/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6724
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void dma_bdrv_unmap(DMAAIOCB *dbs)

{

    int i;



    for (i = 0; i < dbs->iov.niov; ++i) {

        dma_memory_unmap(dbs->sg->as, dbs->iov.iov[i].iov_base,

                         dbs->iov.iov[i].iov_len, dbs->dir,

                         dbs->iov.iov[i].iov_len);

    }

    qemu_iovec_reset(&dbs->iov);

}
