/* 
 * Benchmark Sample ID : devign_9498
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e0d9c6f93729c9bfc98fcafcd73098bb8e131aeb
 */

int qcow2_backing_read1(BlockDriverState *bs, QEMUIOVector *qiov,

                  int64_t sector_num, int nb_sectors)

{

    int n1;

    if ((sector_num + nb_sectors) <= bs->total_sectors)

        return nb_sectors;

    if (sector_num >= bs->total_sectors)

        n1 = 0;

    else

        n1 = bs->total_sectors - sector_num;



    qemu_iovec_memset(qiov, 0, 512 * (nb_sectors - n1));



    return n1;

}
