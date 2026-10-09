/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3373
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d42cf28837801cd1f835089fe9db2a42a1af55cd
 */

static void bdrv_drain_poll(BlockDriverState *bs)

{

    while (bdrv_requests_pending(bs)) {

        /* Keep iterating */

        aio_poll(bdrv_get_aio_context(bs), true);

    }

}
