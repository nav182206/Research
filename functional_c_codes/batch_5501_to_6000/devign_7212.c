/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7212
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_write(BlockDriverState *bs, int64_t sector_num,

               const uint8_t *buf, int nb_sectors)

{

    return bdrv_rw_co(bs, sector_num, (uint8_t *)buf, nb_sectors, true, 0);

}
