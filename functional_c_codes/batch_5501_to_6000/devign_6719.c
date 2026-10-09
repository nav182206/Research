/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6719
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

char *socket_address_to_string(struct SocketAddressLegacy *addr, Error **errp)

{

    char *buf;

    InetSocketAddress *inet;



    switch (addr->type) {

    case SOCKET_ADDRESS_LEGACY_KIND_INET:

        inet = addr->u.inet.data;

        if (strchr(inet->host, ':') == NULL) {

            buf = g_strdup_printf("%s:%s", inet->host, inet->port);

        } else {

            buf = g_strdup_printf("[%s]:%s", inet->host, inet->port);

        }

        break;



    case SOCKET_ADDRESS_LEGACY_KIND_UNIX:

        buf = g_strdup(addr->u.q_unix.data->path);

        break;



    case SOCKET_ADDRESS_LEGACY_KIND_FD:

        buf = g_strdup(addr->u.fd.data->str);

        break;



    case SOCKET_ADDRESS_LEGACY_KIND_VSOCK:

        buf = g_strdup_printf("%s:%s",

                              addr->u.vsock.data->cid,

                              addr->u.vsock.data->port);

        break;



    default:

        abort();

    }

    return buf;

}
