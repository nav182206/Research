/* 
 * Benchmark Sample ID : devign_3295
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0c9390d978cbf61e8f16c9f580fa96b305c43568
 */

static void client_close(NBDClient *client)

{

    if (client->closing) {

        return;

    }



    client->closing = true;



    /* Force requests to finish.  They will drop their own references,

     * then we'll close the socket and free the NBDClient.

     */

    qio_channel_shutdown(client->ioc, QIO_CHANNEL_SHUTDOWN_BOTH,

                         NULL);



    /* Also tell the client, so that they release their reference.  */

    if (client->close) {

        client->close(client);

    }

}
