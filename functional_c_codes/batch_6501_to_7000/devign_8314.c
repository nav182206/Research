/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8314
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0f8c289ad539feb5135c545bea947b310a893f4b
 */

static NetSocketState *net_socket_fd_init(NetClientState *peer,

                                          const char *model, const char *name,

                                          int fd, int is_connected)

{

    int so_type = -1, optlen=sizeof(so_type);



    if(getsockopt(fd, SOL_SOCKET, SO_TYPE, (char *)&so_type,

        (socklen_t *)&optlen)< 0) {

        fprintf(stderr, "qemu: error: getsockopt(SO_TYPE) for fd=%d failed\n",

                fd);

        closesocket(fd);

        return NULL;

    }

    switch(so_type) {

    case SOCK_DGRAM:

        return net_socket_fd_init_dgram(peer, model, name, fd, is_connected);

    case SOCK_STREAM:

        return net_socket_fd_init_stream(peer, model, name, fd, is_connected);

    default:

        /* who knows ... this could be a eg. a pty, do warn and continue as stream */

        fprintf(stderr, "qemu: warning: socket type=%d for fd=%d is not SOCK_DGRAM or SOCK_STREAM\n", so_type, fd);

        return net_socket_fd_init_stream(peer, model, name, fd, is_connected);

    }

    return NULL;

}
