/* 
 * Benchmark Sample ID : devign_2682
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=213189ab65d83ecd9072f27c80a15dcb91b6bdbf
 */

static void ide_dma_restart_cb(void *opaque, int running, int reason)

{

    BMDMAState *bm = opaque;

    if (!running)

        return;

    if (bm->status & BM_STATUS_DMA_RETRY) {

        bm->status &= ~BM_STATUS_DMA_RETRY;

        ide_dma_restart(bm->ide_if);

    } else if (bm->status & BM_STATUS_PIO_RETRY) {

        bm->status &= ~BM_STATUS_PIO_RETRY;

        ide_sector_write(bm->ide_if);

    }

}
