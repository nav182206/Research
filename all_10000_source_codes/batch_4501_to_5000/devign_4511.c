/* 
 * Benchmark Sample ID : devign_4511
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f22d85e9e67262db34504f4079745f9843da6a92
 */

static void guest_fsfreeze_cleanup(void)

{

    int64_t ret;

    Error *err = NULL;



    if (guest_fsfreeze_state.status == GUEST_FSFREEZE_STATUS_FROZEN) {

        ret = qmp_guest_fsfreeze_thaw(&err);

        if (ret < 0 || err) {

            slog("failed to clean up frozen filesystems");

        }

    }

}
