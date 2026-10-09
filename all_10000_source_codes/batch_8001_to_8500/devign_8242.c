/* 
 * Benchmark Sample ID : devign_8242
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static bool cmd_read_dma(IDEState *s, uint8_t cmd)

{

    bool lba48 = (cmd == WIN_READDMA_EXT);



    if (!s->bs) {

        ide_abort_command(s);

        return true;

    }



    ide_cmd_lba48_transform(s, lba48);

    ide_sector_start_dma(s, IDE_DMA_READ);



    return false;

}
