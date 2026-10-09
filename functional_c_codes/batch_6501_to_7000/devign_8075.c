/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8075
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

int nbd_client_session_init(NbdClientSession *client, BlockDriverState *bs,

                            int sock, const char *export, Error **errp)

{

    int ret;



    /* NBD handshake */

    logout("session init %s\n", export);

    qemu_set_block(sock);

    ret = nbd_receive_negotiate(sock, export,

                                &client->nbdflags, &client->size,

                                &client->blocksize, errp);

    if (ret < 0) {

        logout("Failed to negotiate with the NBD server\n");

        closesocket(sock);

        return ret;

    }



    qemu_co_mutex_init(&client->send_mutex);

    qemu_co_mutex_init(&client->free_sema);

    client->bs = bs;

    client->sock = sock;



    /* Now that we're connected, set the socket to be non-blocking and

     * kick the reply mechanism.  */

    qemu_set_nonblock(sock);

    nbd_client_session_attach_aio_context(client, bdrv_get_aio_context(bs));



    logout("Established connection with NBD server\n");

    return 0;

}
