/* 
 * Benchmark Sample ID : devign_5459
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=44b6789299a8acca3f25331bc411055cafc7bb06
 */

static void blkverify_aio_cb(void *opaque, int ret)

{

    BlkverifyAIOCB *acb = opaque;



    switch (++acb->done) {

    case 1:

        acb->ret = ret;

        break;



    case 2:

        if (acb->ret != ret) {

            blkverify_err(acb, "return value mismatch %d != %d", acb->ret, ret);

        }



        if (acb->verify) {

            acb->verify(acb);

        }



        aio_bh_schedule_oneshot(bdrv_get_aio_context(acb->common.bs),

                                blkverify_aio_bh, acb);

        break;

    }

}
