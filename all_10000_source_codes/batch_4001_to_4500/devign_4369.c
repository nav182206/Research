/* 
 * Benchmark Sample ID : devign_4369
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2347dd7b6841c1543ceb49cb232d596eb5dd1ca3
 */

static int coroutine_fn nfs_co_writev(BlockDriverState *bs,

                                        int64_t sector_num, int nb_sectors,

                                        QEMUIOVector *iov)

{

    NFSClient *client = bs->opaque;

    NFSRPC task;

    char *buf = NULL;



    nfs_co_init_task(client, &task);



    buf = g_malloc(nb_sectors * BDRV_SECTOR_SIZE);

    qemu_iovec_to_buf(iov, 0, buf, nb_sectors * BDRV_SECTOR_SIZE);



    if (nfs_pwrite_async(client->context, client->fh,

                         sector_num * BDRV_SECTOR_SIZE,

                         nb_sectors * BDRV_SECTOR_SIZE,

                         buf, nfs_co_generic_cb, &task) != 0) {

        g_free(buf);

        return -ENOMEM;

    }



    while (!task.complete) {

        nfs_set_events(client);

        qemu_coroutine_yield();

    }



    g_free(buf);



    if (task.ret != nb_sectors * BDRV_SECTOR_SIZE) {

        return task.ret < 0 ? task.ret : -EIO;

    }



    return 0;

}
