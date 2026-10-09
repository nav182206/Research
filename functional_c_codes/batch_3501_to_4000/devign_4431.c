/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4431
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

static BlockDriverAIOCB *raw_aio_readv(BlockDriverState *bs,

        int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

        BlockDriverCompletionFunc *cb, void *opaque)

{

    RawAIOCB *acb;



    acb = raw_aio_setup(bs, sector_num, qiov, nb_sectors, cb, opaque);

    if (!acb)

        return NULL;

    if (qemu_paio_read(&acb->aiocb) < 0) {

        raw_aio_remove(acb);

        return NULL;

    }

    return &acb->common;

}
