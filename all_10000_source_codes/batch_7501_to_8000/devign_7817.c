/* 
 * Benchmark Sample ID : devign_7817
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=011de2b512a83aa5e9f8899ed5bbf2f31995b90e
 */

static void net_socket_accept(void *opaque)

{

    NetSocketListenState *s = opaque;

    NetSocketState *s1;

    struct sockaddr_in saddr;

    socklen_t len;

    int fd;



    for(;;) {

        len = sizeof(saddr);

        fd = qemu_accept(s->fd, (struct sockaddr *)&saddr, &len);

        if (fd < 0 && errno != EINTR) {

            return;

        } else if (fd >= 0) {

            break;

        }

    }

    s1 = net_socket_fd_init(s->peer, s->model, s->name, fd, 1);

    if (s1) {

        snprintf(s1->nc.info_str, sizeof(s1->nc.info_str),

                 "socket: connection from %s:%d",

                 inet_ntoa(saddr.sin_addr), ntohs(saddr.sin_port));

    }

}
