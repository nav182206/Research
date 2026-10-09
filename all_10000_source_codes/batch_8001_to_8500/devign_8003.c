/* 
 * Benchmark Sample ID : devign_8003
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2119882c7eb7e2c612b24fc0c8d86f5887d6f1c3
 */

void qmp_block_dirty_bitmap_remove(const char *node, const char *name,

                                   Error **errp)

{

    AioContext *aio_context;

    BlockDriverState *bs;

    BdrvDirtyBitmap *bitmap;



    bitmap = block_dirty_bitmap_lookup(node, name, &bs, &aio_context, errp);

    if (!bitmap || !bs) {

        return;

    }



    if (bdrv_dirty_bitmap_frozen(bitmap)) {

        error_setg(errp,

                   "Bitmap '%s' is currently frozen and cannot be removed",

                   name);

        goto out;

    }

    bdrv_dirty_bitmap_make_anon(bitmap);

    bdrv_release_dirty_bitmap(bs, bitmap);



 out:

    aio_context_release(aio_context);

}
