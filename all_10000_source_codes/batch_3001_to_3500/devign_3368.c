/* 
 * Benchmark Sample ID : devign_3368
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=67a0fd2a9bca204d2b39f910a97c7137636a0715
 */

static int64_t coroutine_fn vvfat_co_get_block_status(BlockDriverState *bs,

	int64_t sector_num, int nb_sectors, int* n)

{

    BDRVVVFATState* s = bs->opaque;

    *n = s->sector_count - sector_num;

    if (*n > nb_sectors) {

        *n = nb_sectors;

    } else if (*n < 0) {

        return 0;

    }

    return BDRV_BLOCK_DATA;

}
