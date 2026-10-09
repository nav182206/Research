/* 
 * Benchmark Sample ID : devign_4872
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddca7f86ac022289840e0200fd4050b2b58e9176
 */

static void v9fs_remove(void *opaque)

{

    int32_t fid;

    int err = 0;

    size_t offset = 7;

    V9fsFidState *fidp;

    V9fsPDU *pdu = opaque;



    pdu_unmarshal(pdu, offset, "d", &fid);

    trace_v9fs_remove(pdu->tag, pdu->id, fid);



    fidp = get_fid(pdu, fid);

    if (fidp == NULL) {

        err = -EINVAL;

        goto out_nofid;

    }

    /* if fs driver is not path based, return EOPNOTSUPP */

    if (!(pdu->s->ctx.export_flags & V9FS_PATHNAME_FSCONTEXT)) {

        err = -EOPNOTSUPP;

        goto out_err;

    }

    /*

     * IF the file is unlinked, we cannot reopen

     * the file later. So don't reclaim fd

     */

    err = v9fs_mark_fids_unreclaim(pdu, &fidp->path);

    if (err < 0) {

        goto out_err;

    }

    err = v9fs_co_remove(pdu, &fidp->path);

    if (!err) {

        err = offset;

    }

out_err:

    /* For TREMOVE we need to clunk the fid even on failed remove */

    clunk_fid(pdu->s, fidp->fid);

    put_fid(pdu, fidp);

out_nofid:

    complete_pdu(pdu->s, pdu, err);

}
