/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3650
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e003f17ec518cd96f5d2ac23ce9e14144426235
 */

bool bdrv_all_can_snapshot(BlockDriverState **first_bad_bs)

{

    bool ok = true;

    BlockDriverState *bs;

    BdrvNextIterator it;



    for (bs = bdrv_first(&it); bs; bs = bdrv_next(&it)) {

        AioContext *ctx = bdrv_get_aio_context(bs);



        aio_context_acquire(ctx);

        if (bdrv_is_inserted(bs) && !bdrv_is_read_only(bs)) {

            ok = bdrv_can_snapshot(bs);

        }

        aio_context_release(ctx);

        if (!ok) {


            goto fail;

        }

    }



fail:

    *first_bad_bs = bs;

    return ok;

}
