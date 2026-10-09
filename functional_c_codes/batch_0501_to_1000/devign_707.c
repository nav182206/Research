/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_707
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37d1e4d9bfac846a1331375aab3d13b54a048c01
 */

static void nfs_process_write(void *arg)

{

    NFSClient *client = arg;



    aio_context_acquire(client->aio_context);

    nfs_service(client->context, POLLOUT);

    nfs_set_events(client);

    aio_context_release(client->aio_context);

}
