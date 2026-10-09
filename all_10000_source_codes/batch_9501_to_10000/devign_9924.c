/* 
 * Benchmark Sample ID : devign_9924
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

void qio_dns_resolver_lookup_async(QIODNSResolver *resolver,

                                   SocketAddressLegacy *addr,

                                   QIOTaskFunc func,

                                   gpointer opaque,

                                   GDestroyNotify notify)

{

    QIOTask *task;

    struct QIODNSResolverLookupData *data =

        g_new0(struct QIODNSResolverLookupData, 1);



    data->addr = QAPI_CLONE(SocketAddressLegacy, addr);



    task = qio_task_new(OBJECT(resolver), func, opaque, notify);



    qio_task_run_in_thread(task,

                           qio_dns_resolver_lookup_worker,

                           data,

                           qio_dns_resolver_lookup_data_free);

}
