/* 
 * Benchmark Sample ID : devign_304
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3adb5b9168a57790b5074489b6f0275ac3cc8b5
 */

static void reschedule_dma(void *opaque)

{

    DMAAIOCB *dbs = (DMAAIOCB *)opaque;



    qemu_bh_delete(dbs->bh);

    dbs->bh = NULL;

    dma_bdrv_cb(opaque, 0);

}
