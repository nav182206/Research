/* 
 * Benchmark Sample ID : devign_7855
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4237dfa635900e4d1cdc6038d5efe3507f45f0c
 */

void bdrv_set_dirty(BlockDriverState *bs, int64_t cur_sector,

                    int nr_sectors)

{

    BdrvDirtyBitmap *bitmap;

    QLIST_FOREACH(bitmap, &bs->dirty_bitmaps, list) {

        hbitmap_set(bitmap->bitmap, cur_sector, nr_sectors);

    }

}
