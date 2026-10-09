/* 
 * Benchmark Sample ID : devign_2289
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5eff355460643d09e533024360fe0522f368c07
 */

static int bdrv_rd_badreq_bytes(BlockDriverState *bs,

                                int64_t offset, int count)

{

    int64_t size = bs->total_sectors << SECTOR_BITS;

    return

        count < 0 ||

        size < 0 ||

        count > size ||

        offset > size - count;

}
