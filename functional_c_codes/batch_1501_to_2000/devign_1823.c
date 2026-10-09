/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1823
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1753f3dc177a82f8b3c5ea8d2a32737db9411dd4
 */

static void nvme_rw_cb(void *opaque, int ret)

{

    NvmeRequest *req = opaque;

    NvmeSQueue *sq = req->sq;

    NvmeCtrl *n = sq->ctrl;

    NvmeCQueue *cq = n->cq[sq->cqid];



    block_acct_done(blk_get_stats(n->conf.blk), &req->acct);

    if (!ret) {

        req->status = NVME_SUCCESS;

    } else {

        req->status = NVME_INTERNAL_DEV_ERROR;

    }

    if (req->has_sg) {

        qemu_sglist_destroy(&req->qsg);

    }

    nvme_enqueue_req_completion(cq, req);

}
