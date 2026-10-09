/* 
 * Benchmark Sample ID : devign_8191
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9445673ea67c272616b9f718396e267caa6446b7
 */

static QIOChannelSocket *nbd_establish_connection(SocketAddress *saddr,

                                                  Error **errp)

{

    QIOChannelSocket *sioc;

    Error *local_err = NULL;



    sioc = qio_channel_socket_new();

    qio_channel_set_name(QIO_CHANNEL(sioc), "nbd-client");



    qio_channel_socket_connect_sync(sioc,

                                    saddr,

                                    &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        return NULL;

    }



    qio_channel_set_delay(QIO_CHANNEL(sioc), false);



    return sioc;

}
