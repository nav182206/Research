/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1869
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f53a829bb9ef14be800556cbc02d8b20fc1050a7
 */

static int nbd_co_readv_1(NbdClientSession *client, int64_t sector_num,

                          int nb_sectors, QEMUIOVector *qiov,

                          int offset)

{

    struct nbd_request request = { .type = NBD_CMD_READ };

    struct nbd_reply reply;

    ssize_t ret;



    request.from = sector_num * 512;

    request.len = nb_sectors * 512;



    nbd_coroutine_start(client, &request);

    ret = nbd_co_send_request(client, &request, NULL, 0);

    if (ret < 0) {

        reply.error = -ret;

    } else {

        nbd_co_receive_reply(client, &request, &reply, qiov, offset);

    }

    nbd_coroutine_end(client, &request);

    return -reply.error;



}
