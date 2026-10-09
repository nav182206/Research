/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4837
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e003f17ec518cd96f5d2ac23ce9e14144426235
 */

int bdrv_inactivate_all(void)

{

    BlockDriverState *bs = NULL;

    BdrvNextIterator it;

    int ret = 0;

    int pass;



    for (bs = bdrv_first(&it); bs; bs = bdrv_next(&it)) {

        aio_context_acquire(bdrv_get_aio_context(bs));

    }



    /* We do two passes of inactivation. The first pass calls to drivers'

     * .bdrv_inactivate callbacks recursively so all cache is flushed to disk;

     * the second pass sets the BDRV_O_INACTIVE flag so that no further write

     * is allowed. */

    for (pass = 0; pass < 2; pass++) {

        for (bs = bdrv_first(&it); bs; bs = bdrv_next(&it)) {

            ret = bdrv_inactivate_recurse(bs, pass);

            if (ret < 0) {


                goto out;

            }

        }

    }



out:

    for (bs = bdrv_first(&it); bs; bs = bdrv_next(&it)) {

        aio_context_release(bdrv_get_aio_context(bs));

    }



    return ret;

}
