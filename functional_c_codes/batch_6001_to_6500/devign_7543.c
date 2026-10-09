/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7543
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b64bd51efa9bbf30df1b2f91477d2805678d0b93
 */

int bdrv_get_dirty(BlockDriverState *bs, BdrvDirtyBitmap *bitmap,

                   int64_t sector)

{

    if (bitmap) {

        return hbitmap_get(bitmap->bitmap, sector);

    } else {

        return 0;

    }

}
