/* 
 * Benchmark Sample ID : devign_8791
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

void bdrv_disable_copy_on_read(BlockDriverState *bs)

{

    assert(bs->copy_on_read > 0);

    bs->copy_on_read--;

}
