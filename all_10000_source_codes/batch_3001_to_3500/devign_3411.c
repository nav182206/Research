/* 
 * Benchmark Sample ID : devign_3411
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8d0bcba8370a4e8606dee602393a14d0c48e8bfc
 */

int net_init_tap(const NetClientOptions *opts, const char *name,

                 NetClientState *peer, Error **errp)

{

    /* FIXME error_setg(errp, ...) on failure */

    const NetdevTapOptions *tap;



    assert(opts->kind == NET_CLIENT_OPTIONS_KIND_TAP);

    tap = opts->tap;



    if (!tap->has_ifname) {

        error_report("tap: no interface name");

        return -1;

    }



    if (tap_win32_init(peer, "tap", name, tap->ifname) == -1) {

        return -1;

    }



    return 0;

}
