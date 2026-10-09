/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7563
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static bool cmd_read_multiple(IDEState *s, uint8_t cmd)

{

    bool lba48 = (cmd == WIN_MULTREAD_EXT);



    if (!s->bs || !s->mult_sectors) {

        ide_abort_command(s);

        return true;

    }



    ide_cmd_lba48_transform(s, lba48);

    s->req_nb_sectors = s->mult_sectors;

    ide_sector_read(s);

    return false;

}
