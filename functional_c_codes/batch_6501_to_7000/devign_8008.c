/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8008
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static int bdrv_check_request(BlockDriverState *bs, int64_t sector_num,

                              int nb_sectors)

{

    if (nb_sectors < 0 || nb_sectors > BDRV_REQUEST_MAX_SECTORS) {

        return -EIO;

    }



    return bdrv_check_byte_request(bs, sector_num * BDRV_SECTOR_SIZE,

                                   nb_sectors * BDRV_SECTOR_SIZE);

}
