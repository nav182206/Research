/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_11
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6687b79d636cd60ed9adb1177d0d946b58fa7717
 */

int net_init_tap(QemuOpts *opts, const char *name, VLANState *vlan)

{

    const char *ifname;



    ifname = qemu_opt_get(opts, "ifname");



    if (!ifname) {

        error_report("tap: no interface name");

        return -1;

    }



    if (tap_win32_init(vlan, "tap", name, ifname) == -1) {

        return -1;

    }



    return 0;

}
