/* 
 * Benchmark Sample ID : devign_7874
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=67a0fd2a9bca204d2b39f910a97c7137636a0715
 */

static int64_t coroutine_fn raw_co_get_block_status(BlockDriverState *bs,

                                            int64_t sector_num,

                                            int nb_sectors, int *pnum)

{

    *pnum = nb_sectors;

    return BDRV_BLOCK_RAW | BDRV_BLOCK_OFFSET_VALID | BDRV_BLOCK_DATA |

           (sector_num << BDRV_SECTOR_BITS);

}
