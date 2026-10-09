/* 
 * Benchmark Sample ID : devign_3103
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

static int qio_dns_resolver_lookup_sync_nop(QIODNSResolver *resolver,

                                            SocketAddress *addr,

                                            size_t *naddrs,

                                            SocketAddress ***addrs,

                                            Error **errp)

{

    *naddrs = 1;

    *addrs = g_new0(SocketAddress *, 1);

    (*addrs)[0] = QAPI_CLONE(SocketAddress, addr);



    return 0;

}
