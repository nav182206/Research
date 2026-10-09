/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8455
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

static CharDriverState *qemu_chr_open_stdio(const char *id,

                                            ChardevBackend *backend,

                                            ChardevReturn *ret,

                                            Error **errp)

{

    ChardevStdio *opts = backend->u.stdio;

    CharDriverState *chr;

    struct sigaction act;



    if (is_daemonized()) {

        error_setg(errp, "cannot use stdio with -daemonize");

        return NULL;

    }



    if (stdio_in_use) {

        error_setg(errp, "cannot use stdio by multiple character devices");

        return NULL;

    }



    stdio_in_use = true;

    old_fd0_flags = fcntl(0, F_GETFL);

    tcgetattr(0, &oldtty);

    qemu_set_nonblock(0);

    atexit(term_exit);



    memset(&act, 0, sizeof(act));

    act.sa_handler = term_stdio_handler;

    sigaction(SIGCONT, &act, NULL);



    chr = qemu_chr_open_fd(0, 1);

    chr->chr_close = qemu_chr_close_stdio;

    chr->chr_set_echo = qemu_chr_set_echo_stdio;

    if (opts->has_signal) {

        stdio_allow_signal = opts->signal;

    }

    qemu_chr_fe_set_echo(chr, false);



    return chr;

}
