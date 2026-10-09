/* 
 * Benchmark Sample ID : devign_8399
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cf7330c759345de2efe9c0df7921189ac5ff11d3
 */

static int pty_chr_write(CharDriverState *chr, const uint8_t *buf, int len)

{

    PtyCharDriver *s = chr->opaque;



    if (!s->connected) {

        /* guest sends data, check for (re-)connect */

        pty_chr_update_read_handler_locked(chr);

        return 0;

    }

    return io_channel_send(s->fd, buf, len);

}
