/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2068
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

void nbd_client_session_attach_aio_context(NbdClientSession *client,

                                           AioContext *new_context)

{

    aio_set_fd_handler(new_context, client->sock,

                       nbd_reply_ready, NULL, client);

}
