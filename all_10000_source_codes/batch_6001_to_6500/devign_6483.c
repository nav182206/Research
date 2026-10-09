/* 
 * Benchmark Sample ID : devign_6483
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=786a4ea82ec9c87e3a895cf41081029b285a5fe5
 */

BdrvDirtyBitmap *bdrv_create_dirty_bitmap(BlockDriverState *bs, int granularity,

                                          Error **errp)

{

    int64_t bitmap_size;

    BdrvDirtyBitmap *bitmap;



    assert((granularity & (granularity - 1)) == 0);



    granularity >>= BDRV_SECTOR_BITS;

    assert(granularity);

    bitmap_size = bdrv_nb_sectors(bs);

    if (bitmap_size < 0) {

        error_setg_errno(errp, -bitmap_size, "could not get length of device");

        errno = -bitmap_size;

        return NULL;

    }

    bitmap = g_new0(BdrvDirtyBitmap, 1);

    bitmap->bitmap = hbitmap_alloc(bitmap_size, ffs(granularity) - 1);

    QLIST_INSERT_HEAD(&bs->dirty_bitmaps, bitmap, list);

    return bitmap;

}
