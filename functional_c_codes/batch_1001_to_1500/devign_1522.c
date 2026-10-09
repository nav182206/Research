/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1522
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3adb5b9168a57790b5074489b6f0275ac3cc8b5
 */

static void dma_aio_cancel(BlockDriverAIOCB *acb)

{

    DMAAIOCB *dbs = container_of(acb, DMAAIOCB, common);



    if (dbs->acb) {

        bdrv_aio_cancel(dbs->acb);

    }

}
