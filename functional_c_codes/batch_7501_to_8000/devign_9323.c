/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9323
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7a2c4b82340d621bff462672b29c88d2020d68c1
 */

static void cmd_read_cdvd_capacity(IDEState *s, uint8_t* buf)

{

    uint64_t total_sectors = s->nb_sectors >> 2;



    if (total_sectors == 0) {

        ide_atapi_cmd_error(s, SENSE_NOT_READY, ASC_MEDIUM_NOT_PRESENT);

        return;

    }



    /* NOTE: it is really the number of sectors minus 1 */

    cpu_to_ube32(buf, total_sectors - 1);

    cpu_to_ube32(buf + 4, 2048);

    ide_atapi_cmd_reply(s, 8, 8);

}
