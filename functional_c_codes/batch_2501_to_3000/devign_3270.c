/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3270
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=baf35cb90204d75404892aa4e52628ae7a00669b
 */

static int bdrv_read_em(BlockDriverState *bs, int64_t sector_num,

                        uint8_t *buf, int nb_sectors)

{

    int async_ret;

    BlockDriverAIOCB *acb;



    async_ret = NOT_DONE;

    qemu_aio_wait_start();

    acb = bdrv_aio_read(bs, sector_num, buf, nb_sectors,

                        bdrv_rw_em_cb, &async_ret);

    if (acb == NULL) {

        qemu_aio_wait_end();

        return -1;

    }

    while (async_ret == NOT_DONE) {

        qemu_aio_wait();

    }

    qemu_aio_wait_end();

    return async_ret;

}
