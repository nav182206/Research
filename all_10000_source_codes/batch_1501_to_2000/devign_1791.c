/* 
 * Benchmark Sample ID : devign_1791
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3718d8ab65f68de2acccbe6a315907805f54e3cc
 */

void bdrv_set_in_use(BlockDriverState *bs, int in_use)

{

    assert(bs->in_use != in_use);

    bs->in_use = in_use;

}
