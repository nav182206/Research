/* 
 * Benchmark Sample ID : devign_4127
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=86f6ae67e157362f3b141649874213ce01dcc622
 */

uint64_t bdrv_dirty_bitmap_serialization_size(const BdrvDirtyBitmap *bitmap,

                                              uint64_t start, uint64_t count)

{

    return hbitmap_serialization_size(bitmap->bitmap, start, count);

}
