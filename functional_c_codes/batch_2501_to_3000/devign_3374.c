/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3374
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cf29a570a7aa7abab66bf256fdf9540873590811
 */

static void quorum_aio_cb(void *opaque, int ret)

{

    QuorumChildRequest *sacb = opaque;

    QuorumAIOCB *acb = sacb->parent;

    BDRVQuorumState *s = acb->common.bs->opaque;



    sacb->ret = ret;

    acb->count++;

    if (ret == 0) {

        acb->success_count++;

    } else {

        quorum_report_bad(acb, sacb->aiocb->bs->node_name, ret);

    }

    assert(acb->count <= s->num_children);

    assert(acb->success_count <= s->num_children);

    if (acb->count < s->num_children) {

        return;

    }



    /* Do the vote on read */

    if (acb->is_read) {

        quorum_vote(acb);

    } else {

        quorum_has_too_much_io_failed(acb);

    }



    quorum_aio_finalize(acb);

}
