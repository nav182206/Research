/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5935
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0d64a61db602696f4f1895a890c65eda5b3b618
 */

void bdrv_detach_aio_context(BlockDriverState *bs)

{

    BdrvAioNotifier *baf;



    if (!bs->drv) {

        return;

    }



    QLIST_FOREACH(baf, &bs->aio_notifiers, list) {

        baf->detach_aio_context(baf->opaque);

    }



    if (bs->io_limits_enabled) {

        throttle_timers_detach_aio_context(&bs->throttle_timers);

    }

    if (bs->drv->bdrv_detach_aio_context) {

        bs->drv->bdrv_detach_aio_context(bs);

    }

    if (bs->file) {

        bdrv_detach_aio_context(bs->file->bs);

    }

    if (bs->backing) {

        bdrv_detach_aio_context(bs->backing->bs);

    }



    bs->aio_context = NULL;

}
