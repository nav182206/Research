/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9025
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=88be7b4be4aa17c88247e162bdd7577ea79db94f
 */

int bdrv_all_find_snapshot(const char *name, BlockDriverState **first_bad_bs)

{

    QEMUSnapshotInfo sn;

    int err = 0;

    BlockDriverState *bs;

    BdrvNextIterator *it = NULL;



    while (err == 0 && (it = bdrv_next(it, &bs))) {

        AioContext *ctx = bdrv_get_aio_context(bs);



        aio_context_acquire(ctx);

        if (bdrv_can_snapshot(bs)) {

            err = bdrv_snapshot_find(bs, &sn, name);

        }

        aio_context_release(ctx);

    }



    *first_bad_bs = bs;

    return err;

}
