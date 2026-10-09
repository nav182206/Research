/* 
 * Benchmark Sample ID : devign_7702
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e99c631f116221d169ea53953d91b8aa74d297a
 */

static void net_socket_update_fd_handler(NetSocketState *s)

{

    qemu_set_fd_handler2(s->fd,

                         s->read_poll  ? net_socket_can_send : NULL,

                         s->read_poll  ? s->send_fn : NULL,

                         s->write_poll ? net_socket_writable : NULL,

                         s);

}
