/* 
 * Benchmark Sample ID : devign_9980
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9005b2a7589540a3733b3abdcfbccfe7746cd1a1
 */

static void pty_chr_update_read_handler(CharDriverState *chr)

{

    PtyCharDriver *s = chr->opaque;

    GPollFD pfd;



    pfd.fd = g_io_channel_unix_get_fd(s->fd);

    pfd.events = G_IO_OUT;

    pfd.revents = 0;

    g_poll(&pfd, 1, 0);

    if (pfd.revents & G_IO_HUP) {

        pty_chr_state(chr, 0);

    } else {

        pty_chr_state(chr, 1);

    }

}
