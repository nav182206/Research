/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5eff355460643d09e533024360fe0522f368c07
 */

static int bdrv_wr_badreq_bytes(BlockDriverState *bs,

                                int64_t offset, int count)

{

    int64_t size = bs->total_sectors << SECTOR_BITS;

    if (count < 0 ||

        offset < 0)

        return 1;



    if (offset > size - count) {

        if (bs->autogrow)

            bs->total_sectors = (offset + count + SECTOR_SIZE - 1) >> SECTOR_BITS;

        else

            return 1;

    }

    return 0;

}
