/* 
 * Benchmark Sample ID : devign_7728
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=97a2ae34537882df34810d538ab1f51085499d2c
 */

static coroutine_fn int hdev_co_write_zeroes(BlockDriverState *bs,

    int64_t sector_num, int nb_sectors, BdrvRequestFlags flags)

{

    BDRVRawState *s = bs->opaque;

    int rc;



    rc = fd_open(bs);

    if (rc < 0) {

        return rc;

    }

    if (!(flags & BDRV_REQ_MAY_UNMAP)) {

        return -ENOTSUP;

    }

    if (!s->discard_zeroes) {

        return -ENOTSUP;

    }

    return paio_submit_co(bs, s->fd, sector_num, NULL, nb_sectors,

                          QEMU_AIO_DISCARD|QEMU_AIO_BLKDEV);

}
