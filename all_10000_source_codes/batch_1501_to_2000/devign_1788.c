/* 
 * Benchmark Sample ID : devign_1788
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

socket_sockaddr_to_address_unix(struct sockaddr_storage *sa,

                                socklen_t salen,

                                Error **errp)

{

    SocketAddress *addr;

    struct sockaddr_un *su = (struct sockaddr_un *)sa;



    addr = g_new0(SocketAddress, 1);

    addr->type = SOCKET_ADDRESS_KIND_UNIX;

    addr->u.q_unix = g_new0(UnixSocketAddress, 1);

    if (su->sun_path[0]) {

        addr->u.q_unix->path = g_strndup(su->sun_path,

                                         sizeof(su->sun_path));

    }



    return addr;

}
