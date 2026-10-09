/* 
 * Benchmark Sample ID : devign_4126
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ddca7f86ac022289840e0200fd4050b2b58e9176
 */

static void v9fs_xattrcreate(void *opaque)

{

    int flags;

    int32_t fid;

    int64_t size;

    ssize_t err = 0;

    V9fsString name;

    size_t offset = 7;

    V9fsFidState *file_fidp;

    V9fsFidState *xattr_fidp;

    V9fsPDU *pdu = opaque;

    V9fsState *s = pdu->s;



    pdu_unmarshal(pdu, offset, "dsqd",

                  &fid, &name, &size, &flags);

    trace_v9fs_xattrcreate(pdu->tag, pdu->id, fid, name.data, size, flags);



    file_fidp = get_fid(pdu, fid);

    if (file_fidp == NULL) {

        err = -EINVAL;

        goto out_nofid;

    }

    /* Make the file fid point to xattr */

    xattr_fidp = file_fidp;

    xattr_fidp->fid_type = P9_FID_XATTR;

    xattr_fidp->fs.xattr.copied_len = 0;

    xattr_fidp->fs.xattr.len = size;

    xattr_fidp->fs.xattr.flags = flags;

    v9fs_string_init(&xattr_fidp->fs.xattr.name);

    v9fs_string_copy(&xattr_fidp->fs.xattr.name, &name);

    if (size) {

        xattr_fidp->fs.xattr.value = g_malloc(size);

    } else {

        xattr_fidp->fs.xattr.value = NULL;

    }

    err = offset;

    put_fid(pdu, file_fidp);

out_nofid:

    complete_pdu(s, pdu, err);

    v9fs_string_free(&name);

}
