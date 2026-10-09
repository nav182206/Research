/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5573
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c5acdc9ab4e6aa9b05e6242114479333b15d496b
 */

void bdrv_release_dirty_bitmap(BlockDriverState *bs, BdrvDirtyBitmap *bitmap)

{

    BdrvDirtyBitmap *bm, *next;

    QLIST_FOREACH_SAFE(bm, &bs->dirty_bitmaps, list, next) {

        if (bm == bitmap) {

            assert(!bdrv_dirty_bitmap_frozen(bm));

            QLIST_REMOVE(bitmap, list);

            hbitmap_free(bitmap->bitmap);

            g_free(bitmap->name);

            g_free(bitmap);

            return;

        }

    }

}
