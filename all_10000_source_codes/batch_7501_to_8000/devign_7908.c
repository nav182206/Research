/* 
 * Benchmark Sample ID : devign_7908
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3718d8ab65f68de2acccbe6a315907805f54e3cc
 */

int bdrv_in_use(BlockDriverState *bs)

{

    return bs->in_use;

}
