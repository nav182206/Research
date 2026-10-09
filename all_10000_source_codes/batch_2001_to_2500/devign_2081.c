/* 
 * Benchmark Sample ID : devign_2081
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aa92d6c4609e174fc6884e4b7b87367fac33cbe9
 */

static int64_t nfs_get_allocated_file_size(BlockDriverState *bs)

{

    NFSClient *client = bs->opaque;

    NFSRPC task = {0};

    struct stat st;



    if (bdrv_is_read_only(bs) &&

        !(bs->open_flags & BDRV_O_NOCACHE)) {

        return client->st_blocks * 512;

    }



    task.st = &st;

    if (nfs_fstat_async(client->context, client->fh, nfs_co_generic_cb,

                        &task) != 0) {

        return -ENOMEM;

    }



    while (!task.complete) {

        nfs_set_events(client);

        aio_poll(client->aio_context, true);

    }



    return (task.ret < 0 ? task.ret : st.st_blocks * 512);

}
