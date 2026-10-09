/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5440
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c1f2448998062f25df395cd239169400a4c41ed6
 */

static void pty_chr_update_read_handler_locked(CharDriverState *chr)

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
