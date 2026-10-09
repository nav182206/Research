/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fc5b81d1f6df7342f0963120b2cf3e919d6fc08a
 */

static void tap_set_sndbuf(TAPState *s, int sndbuf, Monitor *mon)

{

#ifdef TUNSETSNDBUF

    if (ioctl(s->fd, TUNSETSNDBUF, &sndbuf) == -1) {

        config_error(mon, "TUNSETSNDBUF ioctl failed: %s\n",

                     strerror(errno));

    }

#else

    config_error(mon, "No '-net tap,sndbuf=<nbytes>' support available\n");

#endif

}
