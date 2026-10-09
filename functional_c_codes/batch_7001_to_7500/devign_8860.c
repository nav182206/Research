/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8860
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f81724d80a1492c73d329242663962139db739b
 */

static void ide_atapi_cmd_read_pio(IDEState *s, int lba, int nb_sectors,

                                   int sector_size)

{

    s->lba = lba;

    s->packet_transfer_size = nb_sectors * sector_size;

    s->elementary_transfer_size = 0;

    s->io_buffer_index = sector_size;

    s->cd_sector_size = sector_size;



    s->status = READY_STAT | SEEK_STAT;

    ide_atapi_cmd_reply_end(s);

}
