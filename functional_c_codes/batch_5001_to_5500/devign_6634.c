/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6634
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static bool cmd_write_pio(IDEState *s, uint8_t cmd)

{

    bool lba48 = (cmd == WIN_WRITE_EXT);



    if (!s->bs) {

        ide_abort_command(s);

        return true;

    }



    ide_cmd_lba48_transform(s, lba48);



    s->req_nb_sectors = 1;

    s->status = SEEK_STAT | READY_STAT;

    ide_transfer_start(s, s->io_buffer, 512, ide_sector_write);



    s->media_changed = 1;



    return false;

}
