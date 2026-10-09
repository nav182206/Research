/* 
 * Benchmark Sample ID : devign_2627
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6d0ceb80ffe18ad4b28aab7356f440636c0be7be
 */

static int coroutine_fn blkreplay_co_pwrite_zeroes(BlockDriverState *bs,

    int64_t offset, int count, BdrvRequestFlags flags)

{

    uint64_t reqid = request_id++;

    int ret = bdrv_co_pwrite_zeroes(bs->file, offset, count, flags);

    block_request_create(reqid, bs, qemu_coroutine_self());

    qemu_coroutine_yield();



    return ret;

}
