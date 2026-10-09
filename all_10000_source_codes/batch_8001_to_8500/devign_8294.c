/* 
 * Benchmark Sample ID : devign_8294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8dfd5f96515ca20c4eb109cb0ee28e2bb32fc505
 */

static void qio_channel_websock_finalize(Object *obj)

{

    QIOChannelWebsock *ioc = QIO_CHANNEL_WEBSOCK(obj);



    buffer_free(&ioc->encinput);

    buffer_free(&ioc->encoutput);

    buffer_free(&ioc->rawinput);

    buffer_free(&ioc->rawoutput);

    object_unref(OBJECT(ioc->master));

    if (ioc->io_tag) {

        g_source_remove(ioc->io_tag);

    }

    if (ioc->io_err) {

        error_free(ioc->io_err);

    }

}
