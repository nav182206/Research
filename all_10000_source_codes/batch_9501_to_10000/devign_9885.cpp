/* 
 * Benchmark Sample ID : devign_9885
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=88b062c2036cfd05b5111147736a08ba05ea05a9
 */

static int blk_prw(BlockBackend *blk, int64_t offset, uint8_t *buf,

                   int64_t bytes, CoroutineEntry co_entry,

                   BdrvRequestFlags flags)

{

    AioContext *aio_context;

    QEMUIOVector qiov;

    struct iovec iov;

    Coroutine *co;

    BlkRwCo rwco;



    iov = (struct iovec) {

        .iov_base = buf,

        .iov_len = bytes,

    };

    qemu_iovec_init_external(&qiov, &iov, 1);



    rwco = (BlkRwCo) {

        .blk    = blk,

        .offset = offset,

        .qiov   = &qiov,

        .flags  = flags,

        .ret    = NOT_DONE,

    };



    co = qemu_coroutine_create(co_entry, &rwco);

    qemu_coroutine_enter(co);



    aio_context = blk_get_aio_context(blk);

    while (rwco.ret == NOT_DONE) {

        aio_poll(aio_context, true);

    }



    return rwco.ret;

}
