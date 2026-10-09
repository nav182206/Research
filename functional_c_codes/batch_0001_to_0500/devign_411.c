/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_411
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d8b7e0adf562277180f96ecbd7f1777a384a0308
 */

static int raw_write(BlockDriverState *bs, int64_t sector_num,

                     const uint8_t *buf, int nb_sectors)

{

    return bdrv_write(bs->file, sector_num, buf, nb_sectors);

}
