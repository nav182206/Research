/* 
 * Benchmark Sample ID : devign_8773
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=41a2b9596c9ed2a827e16e749632752dd2686647
 */

static void ide_reset(IDEState *s)

{

    if (s->is_cf)

        s->mult_sectors = 0;

    else

        s->mult_sectors = MAX_MULT_SECTORS;

    s->cur_drive = s;

    s->select = 0xa0;

    s->status = READY_STAT;

    ide_set_signature(s);

    /* init the transfer handler so that 0xffff is returned on data

       accesses */

    s->end_transfer_func = ide_dummy_transfer_stop;

    ide_dummy_transfer_stop(s);

    s->media_changed = 0;

}
