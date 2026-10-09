/* 
 * Benchmark Sample ID : devign_622
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b946a1533209f61a93e34898aebb5b43154b99c3
 */

static TAPState *net_tap_fd_init(VLANState *vlan,

                                 const char *model,

                                 const char *name,

                                 int fd)

{

    TAPState *s;



    s = qemu_mallocz(sizeof(TAPState));

    s->fd = fd;

    s->vc = qemu_new_vlan_client(vlan, model, name, tap_receive, NULL, s);

    s->vc->fd_readv = tap_receive_iov;

    qemu_set_fd_handler(s->fd, tap_send, NULL, s);

    snprintf(s->vc->info_str, sizeof(s->vc->info_str), "fd=%d", fd);

    return s;

}
