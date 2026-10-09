/* 
 * Benchmark Sample ID : devign_7703
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void bdrv_throttle_read_timer_cb(void *opaque)

{

    BlockDriverState *bs = opaque;

    qemu_co_enter_next(&bs->throttled_reqs[0]);

}
