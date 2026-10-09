/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7691
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a90a7425cf592a3afeff3eaf32f543b83050ee5c
 */

static void tap_update_fd_handler(TAPState *s)

{

    qemu_set_fd_handler2(s->fd,

                         s->read_poll && s->enabled ? tap_can_send : NULL,

                         s->read_poll && s->enabled ? tap_send     : NULL,

                         s->write_poll && s->enabled ? tap_writable : NULL,

                         s);

}
