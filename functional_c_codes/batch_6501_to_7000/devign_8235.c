/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8235
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b64bd51efa9bbf30df1b2f91477d2805678d0b93
 */

void bdrv_set_dirty_bitmap(BdrvDirtyBitmap *bitmap,

                           int64_t cur_sector, int64_t nr_sectors)

{

    assert(bdrv_dirty_bitmap_enabled(bitmap));

    hbitmap_set(bitmap->bitmap, cur_sector, nr_sectors);

}
