/* 
 * Benchmark Sample ID : devign_5004
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

int qio_dns_resolver_lookup_sync(QIODNSResolver *resolver,

                                 SocketAddress *addr,

                                 size_t *naddrs,

                                 SocketAddress ***addrs,

                                 Error **errp)

{

    switch (addr->type) {

    case SOCKET_ADDRESS_KIND_INET:

        return qio_dns_resolver_lookup_sync_inet(resolver,

                                                 addr,

                                                 naddrs,

                                                 addrs,

                                                 errp);



    case SOCKET_ADDRESS_KIND_UNIX:

    case SOCKET_ADDRESS_KIND_VSOCK:

    case SOCKET_ADDRESS_KIND_FD:

        return qio_dns_resolver_lookup_sync_nop(resolver,

                                                addr,

                                                naddrs,

                                                addrs,

                                                errp);



    default:

        abort();

    }

}
