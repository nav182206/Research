/* 
 * Benchmark Sample ID : devign_4889
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

int bdrv_read_unthrottled(BlockDriverState *bs, int64_t sector_num,

                          uint8_t *buf, int nb_sectors)

{

    bool enabled;

    int ret;



    enabled = bs->io_limits_enabled;

    bs->io_limits_enabled = false;

    ret = bdrv_read(bs, sector_num, buf, nb_sectors);

    bs->io_limits_enabled = enabled;

    return ret;

}
