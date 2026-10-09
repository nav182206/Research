/* 
 * Benchmark Sample ID : devign_9127
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ff2b68aa70d10b7eae813b04e9a23723dbd89ebd
 */

static void nbd_client_close(NBDClient *client)

{

    qemu_set_fd_handler2(client->sock, NULL, NULL, NULL, NULL);

    close(client->sock);

    client->sock = -1;

    if (client->close) {

        client->close(client);

    }

    nbd_client_put(client);

}
