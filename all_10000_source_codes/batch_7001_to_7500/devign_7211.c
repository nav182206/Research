/* 
 * Benchmark Sample ID : devign_7211
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void ide_sector_write(IDEState *s)

{

    int64_t sector_num;

    int n;



    s->status = READY_STAT | SEEK_STAT | BUSY_STAT;

    sector_num = ide_get_sector(s);

#if defined(DEBUG_IDE)

    printf("sector=%" PRId64 "\n", sector_num);

#endif

    n = s->nsector;

    if (n > s->req_nb_sectors) {

        n = s->req_nb_sectors;

    }



    if (!ide_sect_range_ok(s, sector_num, n)) {

        ide_rw_error(s);

        return;

    }



    s->iov.iov_base = s->io_buffer;

    s->iov.iov_len  = n * BDRV_SECTOR_SIZE;

    qemu_iovec_init_external(&s->qiov, &s->iov, 1);



    block_acct_start(bdrv_get_stats(s->bs), &s->acct,

                     n * BDRV_SECTOR_SIZE, BLOCK_ACCT_READ);

    s->pio_aiocb = bdrv_aio_writev(s->bs, sector_num, &s->qiov, n,

                                   ide_sector_write_cb, s);

}
