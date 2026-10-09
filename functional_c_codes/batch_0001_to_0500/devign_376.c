/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_376
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void ide_bus_reset(IDEBus *bus)

{

    bus->unit = 0;

    bus->cmd = 0;

    ide_reset(&bus->ifs[0]);

    ide_reset(&bus->ifs[1]);

    ide_clear_hob(bus);



    /* pending async DMA */

    if (bus->dma->aiocb) {

#ifdef DEBUG_AIO

        printf("aio_cancel\n");

#endif

        bdrv_aio_cancel(bus->dma->aiocb);

        bus->dma->aiocb = NULL;

    }



    /* reset dma provider too */

    if (bus->dma->ops->reset) {

        bus->dma->ops->reset(bus->dma);

    }

}
