/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1675
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=615b5dcf2decbc5f0abb512d13d7e5db2385fa23
 */

void bdrv_release_named_dirty_bitmaps(BlockDriverState *bs)

{

    bdrv_do_release_matching_dirty_bitmap(bs, NULL, true);

}
