/* 
 * Benchmark Sample ID : devign_2491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=86f6ae67e157362f3b141649874213ce01dcc622
 */

void bdrv_dirty_bitmap_deserialize_part(BdrvDirtyBitmap *bitmap,

                                        uint8_t *buf, uint64_t start,

                                        uint64_t count, bool finish)

{

    hbitmap_deserialize_part(bitmap->bitmap, buf, start, count, finish);

}
