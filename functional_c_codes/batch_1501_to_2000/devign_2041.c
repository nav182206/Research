/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2041
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a03ef88f77af045a2eb9629b5ce774a3fb973c5e
 */

int coroutine_fn blk_co_preadv(BlockBackend *blk, int64_t offset,

                               unsigned int bytes, QEMUIOVector *qiov,

                               BdrvRequestFlags flags)

{

    int ret;



    trace_blk_co_preadv(blk, blk_bs(blk), offset, bytes, flags);



    ret = blk_check_byte_request(blk, offset, bytes);

    if (ret < 0) {

        return ret;

    }



    /* throttling disk I/O */

    if (blk->public.throttle_state) {

        throttle_group_co_io_limits_intercept(blk, bytes, false);

    }



    return bdrv_co_preadv(blk_bs(blk), offset, bytes, qiov, flags);

}
