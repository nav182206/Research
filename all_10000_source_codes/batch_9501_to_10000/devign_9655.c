/* 
 * Benchmark Sample ID : devign_9655
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a1c5235510da01a200693fe3cfd87acd2dc1fca
 */

static int tap_set_sndbuf(TAPState *s, const char *sndbuf_str)

{

    int sndbuf = TAP_DEFAULT_SNDBUF;



    if (sndbuf_str) {

        sndbuf = atoi(sndbuf_str);

    }



    if (!sndbuf) {

        sndbuf = INT_MAX;

    }



    if (ioctl(s->fd, TUNSETSNDBUF, &sndbuf) == -1 && sndbuf_str) {

        qemu_error("TUNSETSNDBUF ioctl failed: %s\n", strerror(errno));

        return -1;

    }

    return 0;

}
