/* 
 * Benchmark Sample ID : devign_4372
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7cd1e32a860895ccca89eb90a0226efbcd969b55
 */

int bdrv_write(BlockDriverState *bs, int64_t sector_num,

               const uint8_t *buf, int nb_sectors)

{

    BlockDriver *drv = bs->drv;

    if (!bs->drv)

        return -ENOMEDIUM;

    if (bs->read_only)

        return -EACCES;

    if (bdrv_check_request(bs, sector_num, nb_sectors))

        return -EIO;



    return drv->bdrv_write(bs, sector_num, buf, nb_sectors);

}
