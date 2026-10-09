/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1554
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f61eddcb2bb5cbbdd1d911b7e937db9affc29028
 */

static int usb_parse(const char *cmdline)

{

    int r;

    r = usb_device_add(cmdline);

    if (r < 0) {

        fprintf(stderr, "qemu: could not add USB device '%s'\n", cmdline);

    }

    return r;

}
