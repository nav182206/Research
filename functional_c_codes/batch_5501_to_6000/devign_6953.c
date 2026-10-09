/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6953
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4333bb71405f58a8dc8d3255feb3ca5960b0daf8
 */

int coroutine_fn bdrv_is_allocated(BlockDriverState *bs, int64_t sector_num,

                                   int nb_sectors, int *pnum)

{

    return bdrv_get_block_status(bs, sector_num, nb_sectors, pnum);

}
