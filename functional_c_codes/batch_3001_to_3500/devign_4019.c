/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4019
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=958c717df97ea9ca47a2253b8371130fe5f22980
 */

static void nbd_request_put(NBDRequest *req)

{

    NBDClient *client = req->client;



    if (req->data) {

        qemu_vfree(req->data);

    }

    g_slice_free(NBDRequest, req);



    if (client->nb_requests-- == MAX_NBD_REQUESTS) {

        qemu_notify_event();

    }

    nbd_client_put(client);

}
