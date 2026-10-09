/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5695
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6769da29c7a3caa9de4020db87f495de692cf8e2
 */

static size_t handle_aiocb_flush(struct qemu_paiocb *aiocb)

{

    int ret;



    ret = qemu_fdatasync(aiocb->aio_fildes);

    if (ret == -1)

        return -errno;

    return 0;

}
