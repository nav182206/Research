/* 
 * Benchmark Sample ID : devign_9876
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d42cf28837801cd1f835089fe9db2a42a1af55cd
 */

static void bdrv_co_drain_bh_cb(void *opaque)

{

    BdrvCoDrainData *data = opaque;

    Coroutine *co = data->co;

    BlockDriverState *bs = data->bs;



    bdrv_dec_in_flight(bs);

    bdrv_drain_poll(bs);

    data->done = true;

    qemu_coroutine_enter(co);

}
