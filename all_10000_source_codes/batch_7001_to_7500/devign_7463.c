/* 
 * Benchmark Sample ID : devign_7463
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_pwrite_sync(BlockDriverState *bs, int64_t offset,

    const void *buf, int count)

{

    int ret;



    ret = bdrv_pwrite(bs, offset, buf, count);

    if (ret < 0) {

        return ret;

    }



    /* No flush needed for cache modes that already do it */

    if (bs->enable_write_cache) {

        bdrv_flush(bs);

    }



    return 0;

}
