/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6295
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfd100f242370886bb6732f70f1f7cbd8eb9fedc
 */

void qio_dns_resolver_lookup_result(QIODNSResolver *resolver,

                                    QIOTask *task,

                                    size_t *naddrs,

                                    SocketAddress ***addrs)

{

    struct QIODNSResolverLookupData *data =

        qio_task_get_result_pointer(task);

    size_t i;



    *naddrs = 0;

    *addrs = NULL;

    if (!data) {

        return;

    }



    *naddrs = data->naddrs;

    *addrs = g_new0(SocketAddress *, data->naddrs);

    for (i = 0; i < data->naddrs; i++) {

        (*addrs)[i] = QAPI_CLONE(SocketAddress, data->addrs[i]);

    }

}
