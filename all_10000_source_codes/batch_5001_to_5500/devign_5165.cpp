/* 
 * Benchmark Sample ID : devign_5165
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c20fd872257fb9abd2ce99741937c0f65aa162b7
 */

static void virtio_blk_dma_restart_bh(void *opaque)

{

    VirtIOBlock *s = opaque;

    VirtIOBlockReq *req = s->rq;

    MultiReqBuffer mrb = {

        .num_writes = 0,

    };



    qemu_bh_delete(s->bh);

    s->bh = NULL;



    s->rq = NULL;



    while (req) {

        virtio_blk_handle_request(req, &mrb);

        req = req->next;

    }



    if (mrb.num_writes > 0) {

        do_multiwrite(s->bs, mrb.blkreq, mrb.num_writes);

    }

}
