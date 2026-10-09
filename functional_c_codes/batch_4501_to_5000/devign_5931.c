/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5931
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a03ef88f77af045a2eb9629b5ce774a3fb973c5e
 */

static int coroutine_fn blkreplay_co_pwritev(BlockDriverState *bs,

    uint64_t offset, uint64_t bytes, QEMUIOVector *qiov, int flags)

{

    uint64_t reqid = request_id++;

    int ret = bdrv_co_pwritev(bs->file->bs, offset, bytes, qiov, flags);

    block_request_create(reqid, bs, qemu_coroutine_self());

    qemu_coroutine_yield();



    return ret;

}
