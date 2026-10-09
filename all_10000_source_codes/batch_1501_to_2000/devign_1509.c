/* 
 * Benchmark Sample ID : devign_1509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f8c35c1d59c9fecf79f6d5a02cd09f472a6f411d
 */

void bdrv_register(BlockDriver *bdrv)

{

    /* Block drivers without coroutine functions need emulation */

    if (!bdrv->bdrv_co_readv) {

        bdrv->bdrv_co_readv = bdrv_co_readv_em;

        bdrv->bdrv_co_writev = bdrv_co_writev_em;



        if (!bdrv->bdrv_aio_readv) {

            /* add AIO emulation layer */

            bdrv->bdrv_aio_readv = bdrv_aio_readv_em;

            bdrv->bdrv_aio_writev = bdrv_aio_writev_em;

        } else if (!bdrv->bdrv_read) {

            /* add synchronous IO emulation layer */

            bdrv->bdrv_read = bdrv_read_em;

            bdrv->bdrv_write = bdrv_write_em;

        }

    }



    if (!bdrv->bdrv_aio_flush)

        bdrv->bdrv_aio_flush = bdrv_aio_flush_em;



    QLIST_INSERT_HEAD(&bdrv_drivers, bdrv, list);

}
