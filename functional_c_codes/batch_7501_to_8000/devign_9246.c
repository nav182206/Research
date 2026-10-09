/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9246
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7f0d763ce60fd0563cb71c85ae0f86ee71b7edcc
 */

void DBDMA_register_channel(void *dbdma, int nchan, qemu_irq irq,

                            DBDMA_rw rw, DBDMA_flush flush,

                            void *opaque)

{

    DBDMAState *s = dbdma;

    DBDMA_channel *ch = &s->channels[nchan];



    DBDMA_DPRINTF("DBDMA_register_channel 0x%x\n", nchan);



    ch->irq = irq;

    ch->channel = nchan;

    ch->rw = rw;

    ch->flush = flush;

    ch->io.opaque = opaque;

    ch->io.channel = ch;

}
