/* 
 * Benchmark Sample ID : devign_7577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9b536adcbefb72090f43c9715ce042e37e47af73
 */

static bool bdrv_requests_pending_all(void)

{

    BlockDriverState *bs;

    QTAILQ_FOREACH(bs, &bdrv_states, device_list) {

        if (bdrv_requests_pending(bs)) {

            return true;

        }

    }

    return false;

}
