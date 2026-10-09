/* 
 * Benchmark Sample ID : devign_3460
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b8afb520e479e693c227aa39c2fb7670743e104f
 */

BdrvDirtyBitmap *bdrv_create_dirty_bitmap(BlockDriverState *bs, int granularity)

{

    int64_t bitmap_size;

    BdrvDirtyBitmap *bitmap;



    assert((granularity & (granularity - 1)) == 0);



    granularity >>= BDRV_SECTOR_BITS;

    assert(granularity);

    bitmap_size = (bdrv_getlength(bs) >> BDRV_SECTOR_BITS);

    bitmap = g_malloc0(sizeof(BdrvDirtyBitmap));

    bitmap->bitmap = hbitmap_alloc(bitmap_size, ffs(granularity) - 1);

    QLIST_INSERT_HEAD(&bs->dirty_bitmaps, bitmap, list);

    return bitmap;

}
