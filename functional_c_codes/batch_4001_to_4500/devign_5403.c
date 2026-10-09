/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5403
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=63d5ef869e5e57de4875cd64b6f197cbb5763adf
 */

static QIOChannel *nbd_negotiate_handle_starttls(NBDClient *client,

                                                 uint32_t length)

{

    QIOChannel *ioc;

    QIOChannelTLS *tioc;

    struct NBDTLSHandshakeData data = { 0 };



    TRACE("Setting up TLS");

    ioc = client->ioc;

    if (length) {

        if (nbd_negotiate_drop_sync(ioc, length) != length) {

            return NULL;

        }

        nbd_negotiate_send_rep(ioc, NBD_REP_ERR_INVALID, NBD_OPT_STARTTLS);

        return NULL;

    }



    nbd_negotiate_send_rep(client->ioc, NBD_REP_ACK, NBD_OPT_STARTTLS);



    tioc = qio_channel_tls_new_server(ioc,

                                      client->tlscreds,

                                      client->tlsaclname,

                                      NULL);

    if (!tioc) {

        return NULL;

    }



    TRACE("Starting TLS handshake");

    data.loop = g_main_loop_new(g_main_context_default(), FALSE);

    qio_channel_tls_handshake(tioc,

                              nbd_tls_handshake,

                              &data,

                              NULL);



    if (!data.complete) {

        g_main_loop_run(data.loop);

    }

    g_main_loop_unref(data.loop);

    if (data.error) {

        object_unref(OBJECT(tioc));

        error_free(data.error);

        return NULL;

    }



    return QIO_CHANNEL(tioc);

}
