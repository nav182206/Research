/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2722
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4a41a2d68a684241aca96dba066e0699941b730d
 */

static void nbd_teardown_connection(NbdClientSession *client)

{

    struct nbd_request request = {

        .type = NBD_CMD_DISC,

        .from = 0,

        .len = 0

    };



    nbd_send_request(client->sock, &request);



    /* finish any pending coroutines */

    shutdown(client->sock, 2);

    nbd_recv_coroutines_enter_all(client);



    qemu_aio_set_fd_handler(client->sock, NULL, NULL, NULL);

    closesocket(client->sock);

    client->sock = -1;

}
