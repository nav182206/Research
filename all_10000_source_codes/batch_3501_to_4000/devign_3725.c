/* 
 * Benchmark Sample ID : devign_3725
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=546a7dc40e8b8b6440a052e2b5cdfe9aadcaccf6
 */

int qcow2_backing_read1(BlockDriverState *bs, QEMUIOVector *qiov,

                        int64_t offset, int bytes)

{

    uint64_t bs_size = bs->total_sectors * BDRV_SECTOR_SIZE;

    int n1;



    if ((offset + bytes) <= bs_size) {

        return bytes;

    }



    if (offset >= bs_size) {

        n1 = 0;

    } else {

        n1 = bs_size - offset;

    }



    qemu_iovec_memset(qiov, n1, 0, bytes - n1);



    return n1;

}
