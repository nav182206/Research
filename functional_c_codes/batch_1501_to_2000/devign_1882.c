/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1882
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_has_zero_init_1(BlockDriverState *bs)

{

    return 1;

}
