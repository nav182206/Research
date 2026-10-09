/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=76ef2cf5493a215efc351f48ae7094d6c183fcac
 */

int raw_get_aio_fd(BlockDriverState *bs)

{

    BDRVRawState *s;



    if (!bs->drv) {

        return -ENOMEDIUM;

    }



    if (bs->drv == bdrv_find_format("raw")) {

        bs = bs->file;

    }



    /* raw-posix has several protocols so just check for raw_aio_readv */

    if (bs->drv->bdrv_aio_readv != raw_aio_readv) {

        return -ENOTSUP;

    }



    s = bs->opaque;

    if (!s->use_aio) {

        return -ENOTSUP;

    }

    return s->fd;

}
