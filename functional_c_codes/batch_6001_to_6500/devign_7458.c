/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void virtio_submit_multiwrite(BlockDriverState *bs, MultiReqBuffer *mrb)

{

    int i, ret;



    if (!mrb->num_writes) {

        return;

    }



    ret = bdrv_aio_multiwrite(bs, mrb->blkreq, mrb->num_writes);

    if (ret != 0) {

        for (i = 0; i < mrb->num_writes; i++) {

            if (mrb->blkreq[i].error) {

                virtio_blk_rw_complete(mrb->blkreq[i].opaque, -EIO);

            }

        }

    }



    mrb->num_writes = 0;

}
