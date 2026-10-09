/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8307
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=86f6ae67e157362f3b141649874213ce01dcc622
 */

uint64_t bdrv_dirty_bitmap_serialization_align(const BdrvDirtyBitmap *bitmap)

{

    return hbitmap_serialization_align(bitmap->bitmap);

}
