/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9514
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

socket_sockaddr_to_address_inet(struct sockaddr_storage *sa,

                                socklen_t salen,

                                Error **errp)

{

    char host[NI_MAXHOST];

    char serv[NI_MAXSERV];

    SocketAddressLegacy *addr;

    InetSocketAddress *inet;

    int ret;



    ret = getnameinfo((struct sockaddr *)sa, salen,

                      host, sizeof(host),

                      serv, sizeof(serv),

                      NI_NUMERICHOST | NI_NUMERICSERV);

    if (ret != 0) {

        error_setg(errp, "Cannot format numeric socket address: %s",

                   gai_strerror(ret));

        return NULL;

    }



    addr = g_new0(SocketAddressLegacy, 1);

    addr->type = SOCKET_ADDRESS_LEGACY_KIND_INET;

    inet = addr->u.inet.data = g_new0(InetSocketAddress, 1);

    inet->host = g_strdup(host);

    inet->port = g_strdup(serv);

    if (sa->ss_family == AF_INET) {

        inet->has_ipv4 = inet->ipv4 = true;

    } else {

        inet->has_ipv6 = inet->ipv6 = true;

    }



    return addr;

}
