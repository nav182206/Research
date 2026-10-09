/* 
 * Benchmark Sample ID : devign_602
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=49dd946bb5419681c8668b09a6d10f42bc707b78
 */

static void coroutine_fn v9fs_rename(void *opaque)

{

    int32_t fid;

    ssize_t err = 0;

    size_t offset = 7;

    V9fsString name;

    int32_t newdirfid;

    V9fsFidState *fidp;

    V9fsPDU *pdu = opaque;

    V9fsState *s = pdu->s;



    v9fs_string_init(&name);

    err = pdu_unmarshal(pdu, offset, "dds", &fid, &newdirfid, &name);

    if (err < 0) {

        goto out_nofid;

    }



    if (name_is_illegal(name.data)) {

        err = -ENOENT;

        goto out_nofid;

    }



    if (!strcmp(".", name.data) || !strcmp("..", name.data)) {

        err = -EISDIR;

        goto out_nofid;

    }



    fidp = get_fid(pdu, fid);

    if (fidp == NULL) {

        err = -ENOENT;

        goto out_nofid;

    }

    BUG_ON(fidp->fid_type != P9_FID_NONE);

    /* if fs driver is not path based, return EOPNOTSUPP */

    if (!(pdu->s->ctx.export_flags & V9FS_PATHNAME_FSCONTEXT)) {

        err = -EOPNOTSUPP;

        goto out;

    }

    v9fs_path_write_lock(s);

    err = v9fs_complete_rename(pdu, fidp, newdirfid, &name);

    v9fs_path_unlock(s);

    if (!err) {

        err = offset;

    }

out:

    put_fid(pdu, fidp);

out_nofid:

    pdu_complete(pdu, err);

    v9fs_string_free(&name);

}
