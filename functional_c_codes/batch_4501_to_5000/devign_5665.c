/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5665
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void virtio_blk_rw_complete(void *opaque, int ret)

{

    VirtIOBlockReq *req = opaque;



    trace_virtio_blk_rw_complete(req, ret);



    if (ret) {

        int p = virtio_ldl_p(VIRTIO_DEVICE(req->dev), &req->out.type);

        bool is_read = !(p & VIRTIO_BLK_T_OUT);

        if (virtio_blk_handle_rw_error(req, -ret, is_read))

            return;

    }



    virtio_blk_req_complete(req, VIRTIO_BLK_S_OK);

    block_acct_done(bdrv_get_stats(req->dev->bs), &req->acct);

    virtio_blk_free_request(req);

}
