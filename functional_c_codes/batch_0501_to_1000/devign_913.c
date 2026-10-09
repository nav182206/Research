/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_913
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b626b51a6721e53817155af720243f59072e424f
 */

void nbd_client_close(BlockDriverState *bs)

{

    NbdClientSession *client = nbd_get_client_session(bs);

    struct nbd_request request = {

        .type = NBD_CMD_DISC,

        .from = 0,

        .len = 0

    };



    if (client->ioc == NULL) {

        return;

    }



    nbd_send_request(client->ioc, &request);



    nbd_teardown_connection(bs);

}
