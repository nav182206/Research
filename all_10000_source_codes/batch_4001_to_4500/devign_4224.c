/* 
 * Benchmark Sample ID : devign_4224
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddca7f86ac022289840e0200fd4050b2b58e9176
 */

static void v9fs_fsync(void *opaque)

{

    int err;

    int32_t fid;

    int datasync;

    size_t offset = 7;

    V9fsFidState *fidp;

    V9fsPDU *pdu = opaque;

    V9fsState *s = pdu->s;



    pdu_unmarshal(pdu, offset, "dd", &fid, &datasync);

    trace_v9fs_fsync(pdu->tag, pdu->id, fid, datasync);



    fidp = get_fid(pdu, fid);

    if (fidp == NULL) {

        err = -ENOENT;

        goto out_nofid;

    }

    err = v9fs_co_fsync(pdu, fidp, datasync);

    if (!err) {

        err = offset;

    }

    put_fid(pdu, fidp);

out_nofid:

    complete_pdu(s, pdu, err);

}
