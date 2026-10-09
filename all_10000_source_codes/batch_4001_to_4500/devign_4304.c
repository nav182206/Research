/* 
 * Benchmark Sample ID : devign_4304
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a9db86b223030bd40bdd81b160788196bc95fe6f
 */

static void quorum_aio_finalize(QuorumAIOCB *acb)

{

    BDRVQuorumState *s = acb->common.bs->opaque;

    int i, ret = 0;



    if (acb->vote_ret) {

        ret = acb->vote_ret;

    }



    acb->common.cb(acb->common.opaque, ret);



    if (acb->is_read) {

        for (i = 0; i < s->num_children; i++) {

            qemu_vfree(acb->qcrs[i].buf);

            qemu_iovec_destroy(&acb->qcrs[i].qiov);

        }

    }



    g_free(acb->qcrs);

    qemu_aio_release(acb);

}
