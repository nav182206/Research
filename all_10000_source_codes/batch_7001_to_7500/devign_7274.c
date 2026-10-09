/* 
 * Benchmark Sample ID : devign_7274
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=88b062c2036cfd05b5111147736a08ba05ea05a9
 */

static bool bdrv_drain_poll(BlockDriverState *bs)

{

    bool waited = false;



    while (atomic_read(&bs->in_flight) > 0) {

        aio_poll(bdrv_get_aio_context(bs), true);

        waited = true;

    }

    return waited;

}
