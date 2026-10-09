/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1646
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c572f23a3e7180dbeab5e86583e43ea2afed6271
 */

static void v9fs_getlock(void *opaque)
{
    size_t offset = 7;
    struct stat stbuf;
    V9fsFidState *fidp;
    V9fsGetlock *glock;
    int32_t fid, err = 0;
    V9fsPDU *pdu = opaque;
    V9fsState *s = pdu->s;
    glock = g_malloc(sizeof(*glock));
    pdu_unmarshal(pdu, offset, "dbqqds", &fid, &glock->type,
                  &glock->start, &glock->length, &glock->proc_id,
                  &glock->client_id);
    trace_v9fs_getlock(pdu->tag, pdu->id, fid,
                       glock->type, glock->start, glock->length);
    fidp = get_fid(pdu, fid);
    if (fidp == NULL) {
        err = -ENOENT;
        goto out_nofid;
    }
    err = v9fs_co_fstat(pdu, fidp->fs.fd, &stbuf);
    if (err < 0) {
        goto out;
    }
    glock->type = P9_LOCK_TYPE_UNLCK;
    offset += pdu_marshal(pdu, offset, "bqqds", glock->type,
                          glock->start, glock->length, glock->proc_id,
                          &glock->client_id);
    err = offset;
out:
    put_fid(pdu, fidp);
out_nofid:
    complete_pdu(s, pdu, err);
    v9fs_string_free(&glock->client_id);
    g_free(glock);
}
