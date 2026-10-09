/* 
 * Benchmark Sample ID : devign_3188
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f897bf751fbd95e4015b95d202c706548586813a
 */

static void virtio_blk_handle_scsi(VirtIOBlockReq *req)

{

    int status;



    status = virtio_blk_handle_scsi_req(req->dev, req->elem);

    virtio_blk_req_complete(req, status);

    virtio_blk_free_request(req);

}
