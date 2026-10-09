/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2086
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

static void nbd_teardown_connection(NbdClientSession *client)

{

    /* finish any pending coroutines */

    shutdown(client->sock, 2);

    nbd_recv_coroutines_enter_all(client);



    nbd_client_session_detach_aio_context(client);

    closesocket(client->sock);

    client->sock = -1;

}
