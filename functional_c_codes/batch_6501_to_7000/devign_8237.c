/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8237
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=63f0f45f2e89b60ff8245fec81328ddfde42a303
 */

static BlockDriverAIOCB *curl_aio_readv(BlockDriverState *bs,

        int64_t sector_num, QEMUIOVector *qiov, int nb_sectors,

        BlockDriverCompletionFunc *cb, void *opaque)

{

    CURLAIOCB *acb;



    acb = qemu_aio_get(&curl_aiocb_info, bs, cb, opaque);



    acb->qiov = qiov;

    acb->sector_num = sector_num;

    acb->nb_sectors = nb_sectors;



    acb->bh = qemu_bh_new(curl_readv_bh_cb, acb);

    qemu_bh_schedule(acb->bh);

    return &acb->common;

}
