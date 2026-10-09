/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6969
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8dd1d9c396104f0fac4b39a701143df49df2a74
 */

static void netmap_update_fd_handler(NetmapState *s)

{

    qemu_set_fd_handler2(s->me.fd,

                         s->read_poll  ? netmap_can_send : NULL,

                         s->read_poll  ? netmap_send     : NULL,

                         s->write_poll ? netmap_writable : NULL,

                         s);

}
