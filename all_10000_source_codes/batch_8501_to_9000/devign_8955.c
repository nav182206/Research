/* 
 * Benchmark Sample ID : devign_8955
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9ceb76d55abfed9426a819024aa3a4b87266c9f
 */

static void start_input(DBDMA_channel *ch, int key, uint32_t addr,

                       uint16_t req_count, int is_last)

{

    DBDMA_DPRINTF("start_input\n");



    /* KEY_REGS, KEY_DEVICE and KEY_STREAM

     * are not implemented in the mac-io chip

     */



    if (!addr || key > KEY_STREAM3) {

        kill_channel(ch);

        return;

    }



    ch->io.addr = addr;

    ch->io.len = req_count;

    ch->io.is_last = is_last;

    ch->io.dma_end = dbdma_end;

    ch->io.is_dma_out = 0;

    ch->processing = 1;

    ch->rw(&ch->io);

}
