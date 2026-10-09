/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3098
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

static SocketAddressLegacy *nbd_build_socket_address(const char *sockpath,

                                               const char *bindto,

                                               const char *port)

{

    SocketAddressLegacy *saddr;



    saddr = g_new0(SocketAddressLegacy, 1);

    if (sockpath) {

        saddr->type = SOCKET_ADDRESS_LEGACY_KIND_UNIX;

        saddr->u.q_unix.data = g_new0(UnixSocketAddress, 1);

        saddr->u.q_unix.data->path = g_strdup(sockpath);

    } else {

        InetSocketAddress *inet;

        saddr->type = SOCKET_ADDRESS_LEGACY_KIND_INET;

        inet = saddr->u.inet.data = g_new0(InetSocketAddress, 1);

        inet->host = g_strdup(bindto);

        if (port) {

            inet->port = g_strdup(port);

        } else  {

            inet->port = g_strdup_printf("%d", NBD_DEFAULT_PORT);

        }

    }



    return saddr;

}
