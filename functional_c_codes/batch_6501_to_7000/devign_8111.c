/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8111
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80731d9da560461bbdcda5ad4b05f4a8a846fccd
 */

static coroutine_fn int send_co_req(int sockfd, SheepdogReq *hdr, void *data,

                                    unsigned int *wlen)

{

    int ret;



    ret = qemu_co_send(sockfd, hdr, sizeof(*hdr));

    if (ret < sizeof(*hdr)) {

        error_report("failed to send a req, %s", strerror(errno));

        return ret;

    }



    ret = qemu_co_send(sockfd, data, *wlen);

    if (ret < *wlen) {

        error_report("failed to send a req, %s", strerror(errno));

    }



    return ret;

}
