/* 
 * Benchmark Sample ID : devign_997
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

int socket_dgram(SocketAddress *remote, SocketAddress *local, Error **errp)

{

    int fd;



    switch (remote->type) {

    case SOCKET_ADDRESS_KIND_INET:

        fd = inet_dgram_saddr(remote->u.inet, local ? local->u.inet : NULL, errp);

        break;



    default:

        error_setg(errp, "socket type unsupported for datagram");

        fd = -1;

    }

    return fd;

}
