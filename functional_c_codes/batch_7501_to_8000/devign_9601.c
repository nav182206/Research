/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9601
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aa92d6c4609e174fc6884e4b7b87367fac33cbe9
 */

static int coroutine_fn nfs_co_readv(BlockDriverState *bs,

                                     int64_t sector_num, int nb_sectors,

                                     QEMUIOVector *iov)

{

    NFSClient *client = bs->opaque;

    NFSRPC task;



    nfs_co_init_task(client, &task);

    task.iov = iov;



    if (nfs_pread_async(client->context, client->fh,

                        sector_num * BDRV_SECTOR_SIZE,

                        nb_sectors * BDRV_SECTOR_SIZE,

                        nfs_co_generic_cb, &task) != 0) {

        return -ENOMEM;

    }



    while (!task.complete) {

        nfs_set_events(client);

        qemu_coroutine_yield();

    }



    if (task.ret < 0) {

        return task.ret;

    }



    /* zero pad short reads */

    if (task.ret < iov->size) {

        qemu_iovec_memset(iov, task.ret, 0, iov->size - task.ret);

    }



    return 0;

}
