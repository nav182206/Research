/* 
 * Benchmark Sample ID : devign_9922
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void pmac_ide_flush(DBDMA_io *io)

{

    MACIOIDEState *m = io->opaque;



    if (m->aiocb) {

        bdrv_drain_all();

    }

}
