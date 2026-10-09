/* 
 * Benchmark Sample ID : devign_8085
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=51b19ebe4320f3dcd93cea71235c1219318ddfd2
 */

VirtIOBlockReq *virtio_blk_alloc_request(VirtIOBlock *s)

{

    VirtIOBlockReq *req = g_new(VirtIOBlockReq, 1);

    req->dev = s;

    req->qiov.size = 0;

    req->in_len = 0;

    req->next = NULL;

    req->mr_next = NULL;

    return req;

}
