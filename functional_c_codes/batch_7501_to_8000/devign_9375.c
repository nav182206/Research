/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9375
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aa92d6c4609e174fc6884e4b7b87367fac33cbe9
 */

static int coroutine_fn nfs_co_flush(BlockDriverState *bs)

{

    NFSClient *client = bs->opaque;

    NFSRPC task;



    nfs_co_init_task(client, &task);



    if (nfs_fsync_async(client->context, client->fh, nfs_co_generic_cb,

                        &task) != 0) {

        return -ENOMEM;

    }



    while (!task.complete) {

        nfs_set_events(client);

        qemu_coroutine_yield();

    }



    return task.ret;

}
