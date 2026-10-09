/* 
 * Benchmark Sample ID : devign_9962
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f897bf751fbd95e4015b95d202c706548586813a
 */

static void virtio_blk_free_request(VirtIOBlockReq *req)

{

    if (req) {

        g_slice_free(VirtQueueElement, req->elem);

        g_slice_free(VirtIOBlockReq, req);

    }

}
