/* 
 * Benchmark Sample ID : devign_8125
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f897bf751fbd95e4015b95d202c706548586813a
 */

static VirtIOBlockReq *virtio_blk_alloc_request(VirtIOBlock *s)

{

    VirtIOBlockReq *req = g_slice_new(VirtIOBlockReq);

    req->dev = s;

    req->qiov.size = 0;

    req->next = NULL;

    req->elem = g_slice_new(VirtQueueElement);

    return req;

}
