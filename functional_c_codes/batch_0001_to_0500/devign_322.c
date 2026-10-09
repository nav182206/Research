/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_322
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a03ef88f77af045a2eb9629b5ce774a3fb973c5e
 */

static int coroutine_fn raw_co_pwrite_zeroes(BlockDriverState *bs,

                                             int64_t offset, int count,

                                             BdrvRequestFlags flags)

{

    return bdrv_co_pwrite_zeroes(bs->file->bs, offset, count, flags);

}
